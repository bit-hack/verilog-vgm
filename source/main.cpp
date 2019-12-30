#include <cstdint>
#include <cstdio>
#include <vector>

#include "vgm.h"
#include "wave.h"

#include "Vym2149.h"
#include "Vsn76489.h"
#include "Vnesapu.h"
#include "Vgbdmg.h"

#if 0
#define MCLK  clk_ay8910
#define CHIP  ym2149
#endif
#if 0
#define MCLK  clk_sn76489
#define CHIP  sn76489
#endif
#if 0
#define MCLK  clk_nesapu
#define CHIP  nesapu
#endif
#if 1
#define MCLK  clk_gbdmg
#define CHIP  gbdmg
#endif

static const uint64_t SAMPLE_RATE = 44100;
static const uint64_t MAX_SAMPLES = ~0ull;

Vnesapu nesapu;
Vym2149 ym2149;
Vsn76489 sn76489;
Vgbdmg gbdmg;

// output samples
std::vector<uint16_t> samples;

struct vgm_stream_ext_t: public vgm_stream_t {

  vgm_stream_ext_t(vgm_t &vgm)
    : vgm_stream_t(vgm)
  {}

  void write_ay8910(uint8_t reg, uint8_t value) override {
    if (reg >= 16) {
      return;
    }
    ym2149.in_reg = reg;
    ym2149.in_val = value;
    for (int i = 0; i < 8; ++i) {
      ym2149.in_wr = (i < 4);
      ym2149.eval();
      ym2149.in_clk ^= 1;
      ym2149.eval();
    }
  }

  void write_nesapu(uint8_t reg, uint8_t value) override {
    if (reg > 23) {
      return;
    }
    nesapu.in_reg = reg;
    nesapu.in_val = value;
    for (int i = 0; i < 8; ++i) {
      nesapu.in_wr = (i < 4);
      nesapu.eval();
      nesapu.in_clk ^= 1;
      nesapu.eval();
    }
  }

  void write_gbdmg(uint8_t reg, uint8_t value) override {
    if (reg >= 0x30) {
      return;
    }
    gbdmg.in_reg = reg;
    gbdmg.in_val = value;
    for (int i = 0; i < 8; ++i) {
      gbdmg.in_wr = (i < 4);
      gbdmg.eval();
      gbdmg.in_clk ^= 1;
      gbdmg.eval();
    }
  }

  void write_sn76489(uint8_t value) override {
    sn76489.in_val = value;
    for (int i = 0; i < 8; ++i) {
      sn76489.in_wr = (i < 4);
      sn76489.eval();
      sn76489.in_clk ^= 1;
      sn76489.eval();
    }
  }
};

int main(int argc, char **args) {

  // create our chip
  CHIP.in_clk = 1;
  CHIP.in_rst = 0;
  CHIP.in_wr  = 0;

  // create vgm stream
  vgm_t vgm;
  if (!vgm.load(
    // YM2149
//    "C:/repos/vgmplayer/music/Metal_Gear_(MSX2)/08 Return of Fox Hounder"
//    "C:/repos/vgmplayer/music/Vampire_Killer_(MSX2)/04 Wicked Child"
//    "C:/repos/vgmplayer/music/Vampire_Killer_(MSX2)/12 Nothing to Lose"
//    "C:/repos/vgmplayer/music/Herzog_(Sharp_X1_Turbo,_PSG)/05 Back to Square One (Stage 1 Mercie)"
//    "C:/repos/vgmverilator/music/ym2149/Penguin_Adventure_(MSX)/03 Forest Path"

    // SN76489
//    "C:/repos/vgmplayer/music/Zeliard_(Tandy_1000)/10 World of Ice"
//    "C:/repos/vgmverilator/music/sn76489/Sonic_the_Hedgehog's_GameWorld_(Sega_Pico)/14 Floor 4"
//    "C:/repos/vgmverilator/music/sn76489/Budokan_-_The_Martial_Spirit_(Tandy_1000)/04 Interlude"
//    "C:/repos/vgmverilator/music/sn76489/Maniac_Mansion_(Tandy_1000)/04 Main Theme (Enhanced Version)"

    // NESAPU
//    "C:/repos/vgmverilator/music/nesapu/Mega_Man_2_(NES)/25 Credit Roll"
//    "C:/repos/vgmverilator/music/nesapu/Castlevania_(NES)/06 Heart of Fire"
//    "C:/repos/vgmverilator/music/nesapu/Super_Mario_Bros._(NES)/01 Running About"
//    "C:/repos/vgmverilator/music/nesapu/Super_Mario_Bros._(NES)/03 Swimming Around"

    // GBDMG
    "C:/repos/vgmverilator/music/gbdmg/Pokemon_Card_GB2_-_GR-dan_Sanjou!_(Nintendo_Game_Boy_Color)/05 GR Island"
  )) {
    return 1;
  }
  vgm_hdr_t vgm_hdr{vgm};
  vgm_stream_ext_t vgm_stream{vgm};

  const uint64_t clk_ay8910  = vgm_hdr.clock_AY8910();
  const uint64_t clk_sn76489 = vgm_hdr.clock_SN76489();
  const uint64_t clk_nesapu  = vgm_hdr.clock_NESAPU();
  const uint64_t clk_gbdmg   = vgm_hdr.clock_GBDMG();

  // counter for output samples
  uint64_t counter_smp = 0;

  // number of samples rendered
  uint64_t samples_done = 0;

  // reset the chip
  for (int i = 0; i < 16; ++i) {
    CHIP.in_rst = (i < 8) ? 1 : 0;
    CHIP.in_clk ^= 1;
    CHIP.eval();
  }

  int64_t smp_accum = 0;
  int64_t smp_count = 0;

  while (samples_done < MAX_SAMPLES && !vgm_stream.finished()) {

    smp_accum += (int16_t)(CHIP.out_lr);
    smp_count += 1;

    while (vgm_stream.delay == 0) {
      if (vgm_stream.finished()) {
        break;
      }
      vgm_stream.advance();
      // convert delay to cycles
      vgm_stream.delay = (MCLK * uint64_t(vgm_stream.delay)) / 44100;
    }
    if (vgm_stream.delay) {
      vgm_stream.delay -= (CHIP.in_clk & 1);
    }

    // update our output sample counter
    if (counter_smp == 0) {
      counter_smp = MCLK / SAMPLE_RATE;
      ++samples_done;
      // output our sample
#if 0
      const uint16_t sample = CHIP.out_lr;
#else
      const uint16_t sample = smp_accum / smp_count;
#endif
      smp_accum = 0;
      smp_count = 0;
      samples.emplace_back(sample);
    }
    else {
      counter_smp -= (CHIP.in_clk & 1);
    }

    // toggle the clock
    CHIP.in_clk ^= 1;

    // tick the simulation
    CHIP.eval();
  }

  {
    wave_info_t winfo;
    winfo.channels = 1;
    winfo.depth = 16;
    winfo.rate = 44100;
    winfo.samples = samples.size();
    wave_t wave;
    wave.create(winfo);
    memcpy(wave.get<uint16_t>(), samples.data(), samples.size() * sizeof(uint16_t));
    wave.save("out.wav");
  }

  return 0;
}
