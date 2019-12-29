`default_nettype none
`timescale 1ns / 1ps


module sn76489_tone(
  input in_clk,
  input in_rst,
  input [9:0] in_freq,
  input tick,
  output out_bit);

  reg phase;
  reg [9:0] counter;

  assign out_bit = phase;

  always @(posedge in_clk) begin
    if (in_rst) begin
      counter <= 10'd0;
      phase <= 0;
    end else begin
      if (tick) begin
        if (counter == 0) begin
          phase <= ~phase;
          counter <= in_freq;
        end else begin
          counter <= counter - 10'b1;
        end
      end
    end
  end
endmodule


module sn76489_noise(
  input in_clk,
  input in_rst,
  input [1:0] in_period,
  input in_tone2,
  input in_feedback,
  input in_reset,
  output out_noise
);
  // noise linear feedback shift register
  reg [15:0] lfsr;

  wire out_noise = lfsr[0];
  wire [15:0] lfsr_next = in_feedback ?
      ((lfsr == 0) ? 1 : { lfsr[0] ^ lfsr[3], lfsr[15:1] }) :  // sms genesis gamegear
//      ((lfsr == 0) ? 1 : { 0, lfsr[0] ^ lfsr[1], lfsr[14:1] }) :  // bbc-micro
//      ((lfsr == 0) ? 1 : { 0, lfsr[0] ^ lfsr[3], lfsr[14:1] }) : // tandy
      { lfsr[0], lfsr[15:1] };

  // noise period down counter
  reg [11:0] counter;
  // track old tone2
  reg old_tone2;

  always @(posedge in_clk, posedge in_reset) begin
    if (in_rst) begin
      counter <= 0;
    end else begin
      if (in_reset) begin
        lfsr <= 16'h0001;
      end else begin
        if (in_period == 'd3) begin
          lfsr <= (in_tone2 != old_tone2) ? lfsr_next : lfsr;
        end else begin
          if (counter == 0) begin
            // reload the counter
            case (in_period)
            'd0: counter <= 'd512;
            'd1: counter <= 'd1024;
            'd2: counter <= 'd2048;
            endcase
            // white noise
            lfsr <= lfsr_next;
          end else begin
            counter <= counter - 'd1;
          end
        end
      end
    end
    old_tone2 <= in_tone2;
  end
endmodule


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
  reg [3:0] c_amp  [4];

  // tone generators
  wire tone0_out, tone1_out, tone2_out;
  wire tone_tick = (clk_div[3:0] == 4'd0);
  sn76489_tone tone0(in_clk, in_rst, c_freq[0], tone_tick, tone0_out);
  sn76489_tone tone1(in_clk, in_rst, c_freq[1], tone_tick, tone1_out);
  sn76489_tone tone2(in_clk, in_rst, c_freq[2], tone_tick, tone2_out);

  wire noise_out;
  sn76489_noise noise(in_clk, in_rst, noise_shift, tone2_out, noise_fb, noise_clear, noise_out);

  // /512 /1024 /2048 /tone3
  reg [1:0] noise_shift;
  // '0' periodic noise '1' white noise
  reg noise_fb;
  wire noise_clear = (posedge_wr && (in_val[7:4] == 4'b1110));

  // output mix
  reg [15:0] mix_out;
  assign out_lr = mix_out;

  // clock divider
  reg [3:0] clk_div;

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
  wire [15:0] c0_mix = AMP_TABLE[{tone0_out, c_amp[0]}];
  wire [15:0] c1_mix = AMP_TABLE[{tone1_out, c_amp[1]}];
  wire [15:0] c2_mix = AMP_TABLE[{tone2_out, c_amp[2]}];
  wire [15:0] nz_mix = AMP_TABLE[{noise_out, c_amp[3]}];

  // channel mixer
  assign mix_out = c0_mix + c1_mix + c2_mix + nz_mix;

  wire posedge_wr = ((in_wr == 1'b1) && (old_wr == 1'b0));

  always @(posedge in_clk) begin
    if (in_rst) begin
      c_amp[0] <= 4'h0;
      c_amp[1] <= 4'h0;
      c_amp[2] <= 4'h0;
      c_amp[3] <= 4'h0;
    end else begin
      // on posedge of wr
      if (posedge_wr) begin
        // decode received byte
        casez (in_val)
        8'b1??0????: begin
            if (in_chan == 2'd3) begin
              // update noise
              noise_shift <= in_val[1:0];
              noise_fb    <= in_val[2];
            end else begin
              // freq data low update
              c_freq[ in_chan ] <= { c_freq[ in_chan ][9:4], in_data_lo };
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
    end

    // increment clock dividers
    clk_div <= clk_div + 4'b1;

    // track the old wr register
    old_wr <= in_wr;
  end

endmodule
