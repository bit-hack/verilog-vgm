#include <cstdint>
#include <cstdio>
#include <vector>

#include "vgm.h"
#include "wave.h"

#include "Vym2149.h"

// static const uint64_t MCLK = 1789750;
static const uint64_t SAMPLE_RATE = 44100;
static const uint64_t MAX_SAMPLES = ~0ull;

struct vgm_stream_ext_t: public vgm_stream_t {

  vgm_stream_ext_t(Vym2149 &c, vgm_t &vgm)
    : chip(c)
    , vgm_stream_t(vgm)
  {}

  virtual void write_ay8910(uint8_t reg, uint8_t value) {
    chip.in_reg = reg;
    chip.in_val = value;
    for (int i = 0; i < 8; ++i) {
      chip.in_wr = (i < 4);
      chip.in_clk ^= 1;
      chip.eval();
    }
  }

  Vym2149 &chip;
};

int main(int argc, char **args) {

  // output samples
  std::vector<uint16_t> samples;

  // create our chip
  Vym2149 ym2149;
  ym2149.in_clk = 1;
  ym2149.in_reg = 0;
  ym2149.in_val = 0;
  ym2149.in_rst = 0;
  ym2149.in_wr  = 0;

  // create vgm stream
  vgm_t vgm;
  if (!vgm.load(
//    "C:/repos/vgmplayer/music/Metal_Gear_(MSX2)/05 Mercenary"
//    "C:/repos/vgmplayer/music/Vampire_Killer_(MSX2)/04 Wicked Child"
//    "C:/repos/vgmplayer/music/Vampire_Killer_(MSX2)/12 Nothing to Lose"
    "C:/repos/vgmplayer/music/Herzog_(Sharp_X1_Turbo,_PSG)/05 Back to Square One (Stage 1 Mercie)"
  )) {
    return 1;
  }
  vgm_hdr_t vgm_hdr{vgm};
  vgm_stream_ext_t vgm_stream{ym2149, vgm};

  uint64_t clk_ay8910 = vgm_hdr.clock_AY8910();

  // counter for output samples
  uint64_t counter_smp = 0;

  // number of samples rendered
  uint64_t samples_done = 0;

  // reset the chip
  for (int i = 0; i < 16; ++i) {
    ym2149.in_rst = (i < 8) ? 1 : 0;
    ym2149.in_clk ^= 1;
    ym2149.eval();
  }

  while (samples_done < MAX_SAMPLES && !vgm_stream.finished()) {

    while (vgm_stream.delay == 0) {
      if (vgm_stream.finished()) {
        break;
      }
      vgm_stream.advance();
      // convert delay to cycles
      vgm_stream.delay = (clk_ay8910 * uint64_t(vgm_stream.delay)) / 44100;
    }
    if (vgm_stream.delay) {
      vgm_stream.delay -= (ym2149.in_clk & 1);
    }

    // update our output sample counter
    if (counter_smp == 0) {
      counter_smp = clk_ay8910 / SAMPLE_RATE;
      ++samples_done;
      // output our sample
      const uint16_t sample = ym2149.out_lr;
      samples.emplace_back(sample);
    }
    else {
      counter_smp -= (ym2149.in_clk & 1);
    }

    // toggle the clock
    ym2149.in_clk ^= 1;

    // tick the simulation
    ym2149.eval();
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
