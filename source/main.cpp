#include <stdint.h>
#include <stdio.h>

#include "tune.h"
#include "Vym2149.h"

static const uint64_t MCLK = 1789750;
static const uint64_t SAMPLE_RATE = 44100;
static const uint64_t MAX_SAMPLES = SAMPLE_RATE * 15;

int main(int argc, char **args) {

  // try to open an output file
  FILE *fd = fopen("out.pcm", "wb");

  // 
  const frame_t *frame = test_data;
  uint64_t counter_frame = 0;

  // counter for output samples
  uint64_t counter_smp = 0;

  // number of samples rendered
  uint64_t samples_done = 0;

  // create our chip
  Vym2149 ym2149;
  ym2149.in_clk = 0;
  ym2149.in_reg = 0;
  ym2149.in_val = 0;
  ym2149.in_rst = 0;
  ym2149.in_wr  = 0;

  for (uint64_t clk = 0; samples_done < MAX_SAMPLES; ++clk) {

    // assert the reset line for first 16 clocks
    ym2149.in_rst = (clk < 16) ? 1 : 0;

    // on negedge lets update the registers
    if ((clk & 0x1) == 0) {
      if (ym2149.in_wr == 0) {
        if (counter_frame >= frame->delay) {
          counter_frame = 0;
          ym2149.in_wr = 1;
          assert(frame->reg < 16);
          ym2149.in_reg = frame->reg;
          ym2149.in_val = frame->value;
          ++frame;
        } else {
          ++counter_frame;
        }
      }
      else {
        ym2149.in_wr = 0;
      }
    }

    // update our output sample counter
    if (counter_smp == 0) {
      counter_smp = MCLK / SAMPLE_RATE;
      ++samples_done;
      // output our sample
      if (fd) {
        const uint16_t sample = ym2149.out_lr;
        fwrite(&sample, 2, 1, fd);
      }
    }
    else {
      counter_smp -= clk & 1;
    }

    // toggle the clock
    ym2149.in_clk = clk & 1;

    // tick the simulation
    ym2149.eval();
  }

  if (fd) {
    fclose(fd);
  }

  return 0;
}
