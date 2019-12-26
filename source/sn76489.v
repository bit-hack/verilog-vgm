`default_nettype none
`timescale 1ns / 1ps

module sn76489(
  input in_clk,
  input in_rst,
  input [7:0] in_val,
  input in_wr,
  output [15:0] out_lr
);

  // volume table rom
  reg [15:0] AMP_TABLE[32];
  initial $readmemh("sn76489_dac.txt", AMP_TABLE);

  // track change in wr
  reg old_wr;

  // internal registers
  reg [9:0] c_freq [3];
  reg [9:0] c_tone [3];
  reg [3:0] c_amp  [4];
  reg       c_bit  [3];

  // noise linear feedback shift register
  reg [15:0] lfsr;
  wire lfsr_in, lfsr_out;
  assign lfsr_in = lfsr[0] ^ lfsr[3];
  assign lfsr_out = lfsr[0];

  // /512 /1024 /2048 /tone3
  reg [1:0] noise_shift;
  // '0' periodic noise '1' white noise
  reg noise_fb;

  // output mix
  reg [15:0] mix_out;
  assign out_lr = mix_out;

  // clock divider
  reg [7:0] clk_div;

  // channel that was last accessed
  reg [1:0] latch_chan;

  // decode input byte
  wire [1:0] in_chan    = in_val[6:5];
  wire       in_msb     = in_val[7];
  wire [3:0] in_data_lo = in_val[3:0];
  wire [5:0] in_data_hi = in_val[5:0];

  // '0' for tone update, '1' for amp update
  wire in_kind = in_val[4];

  // per channel intermediate mix
  wire [15:0] c0_mix = AMP_TABLE[{c_bit[0], c_amp[0]}];
  wire [15:0] c1_mix = AMP_TABLE[{c_bit[1], c_amp[1]}];
  wire [15:0] c2_mix = AMP_TABLE[{c_bit[2], c_amp[2]}];
  wire [15:0] nz_mix = AMP_TABLE[{lfsr_out, c_amp[3]}];

  // channel mixer
  assign mix_out = c0_mix + c1_mix + c2_mix + nz_mix;

  always @(posedge in_clk) begin

    if (in_rst) begin

      c_amp[0] <= 4'h0;
      c_amp[1] <= 4'h0;
      c_amp[2] <= 4'h0;
      c_amp[3] <= 4'h0;

    end else begin

      // on posedge of wr
      if ((in_wr == 1'b1) && (old_wr == 1'b0)) begin

        // decode received byte
        casez (in_val)
        8'b1??0????: begin
            if (in_chan != 2'd3) begin
              // freq data low update
              c_freq[ in_chan ] <= { c_freq[ in_chan ][9:4], in_data_lo };
            end else begin
              // update noise
              noise_shift <= in_val[2:1];
              noise_fb <= in_val[0];
            end
            latch_chan <= in_chan;
          end
        8'b0???????:
          if (latch_chan != 2'd3) begin
            // freq data high update
            c_freq[ latch_chan ] <= { in_data_hi, c_freq[ latch_chan ][3:0] };
          end
        8'b1??1????:
          // attenuation update
          c_amp[ in_chan ] <= in_data_lo;
        endcase
      end

      // update noise generator
      if (clk_div[7:0] == 0) begin
        // white noise
        lfsr <= (lfsr == 0) ? 1 : { lfsr_in, lfsr[15:1] };
      end

      // update tone generators
      if (clk_div[3:0] == 0) begin

        // update tone generator a
        if (c_tone[0] == 0) begin
          c_bit[0] <= ~c_bit[0];
          c_tone[0] <= c_freq[0];
        end else begin
          c_tone[0] <= c_tone[0] - 10'b1;
        end

        // update tone generator b
        if (c_tone[1] == 0) begin
          c_bit[1] <= ~c_bit[1];
          c_tone[1] <= c_freq[1];
        end else begin
          c_tone[1] <= c_tone[1] - 10'b1;
        end

        // update tone generator c
        if (c_tone[2] == 0) begin
          c_bit[2] <= ~c_bit[2];
          c_tone[2] <= c_freq[2];
        end else begin
          c_tone[2] <= c_tone[2] - 10'b1;
        end
      end
    end

    // increment clock dividers
    clk_div <= clk_div + 8'b1;

    // track the old wr register
    old_wr <= in_wr;
  end

endmodule
