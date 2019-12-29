`default_nettype none
`timescale 1ns / 1ps

// todo:
// - create mixer module

module ym2149_env(
  input in_clk,
  input in_rst,
  input [15:0] in_period,
  input [3:0] in_mode,
  input reload,
  output [3:0] out_env);

  // Fe = fMaster / (256 * in_period)

  reg [7:0] value;
  reg [15:0] counter;
  reg toggle;

  // decode mode register
  wire mode_cont   = in_mode[3];
  wire mode_attack = in_mode[2];
  wire mode_alt    = in_mode[1];
  wire mode_hold   = in_mode[0];

  // take into account attack mode and toggle
  assign out_env = (mode_attack ^ toggle) ? (4'd15 - value[7:4]) : value[7:4];

  always @(posedge in_clk) begin
    if (in_rst) begin
      counter <= 16'hffff;
      value <= 8'hff;
      toggle <= 0;
    end else begin
      if (reload) begin
        value <= 8'hff;
        counter <= 16'hffff;
        toggle <= 0;
      end else begin
        if (counter == 16'd0) begin
          if (value == 8'd0) begin
            if (mode_cont) begin
              toggle <= (mode_alt && mode_hold) || (mode_alt ? ~toggle : toggle);
              value <= mode_hold ? value - 8'd1 : value;
            end else begin
              value <= 8'd0;
              toggle <= 0;
            end
          end else begin
            value <= value - 8'd1;
          end
          counter <= in_period;
        end else begin
          counter <= counter - 16'd1;
        end
      end
    end
  end
endmodule


module ym2149_noise(
  input in_clk,
  input in_rst,
  input [4:0] in_period,
  output out_noise);

  // Fn = fMaster / 16 * r[6][4:0]

  reg [16:0] lfsr;
  wire lfsr_in = lfsr[0] ^ lfsr[3];
  assign out_noise = lfsr[0];

  // divide by 16
  reg [3:0] clk_div;
  // period counter
  reg [4:0] counter;

  always @(posedge in_clk) begin
    if (in_rst) begin
      clk_div <= 4'h0;
      counter <= 5'h0;
      lfsr <= 17'h1ffff;
    end else begin
      if (clk_div == 4'h0) begin
        if (counter == 5'h0) begin
          counter <= in_period;
          lfsr <= { lfsr_in, lfsr[16:1] };
        end else begin
          counter <= counter - 5'h1;
        end
      end
    end
  end
endmodule


module ym2149_tone(
  input in_clk,
  input in_rst,
  input in_tick,
  input [11:0] in_freq,
  output out_bit
);

  reg tone_bit;
  reg [11:0] counter;

  assign out_bit = tone_bit;

  always @(posedge in_clk) begin
    if (in_rst) begin
      tone_bit <= 'b1;
      counter <= 12'd0;
    end else begin
      if (in_tick) begin
        if (counter == 12'h0) begin
          counter <= in_freq;
          tone_bit <= ~tone_bit;
        end else begin
          counter <= counter - 12'd1;
        end
      end
    end
  end
endmodule


module ym2149(
  input in_clk,
  input in_rst,
  input [3:0] in_reg,
  input [7:0] in_val,
  input in_wr,
  output [15:0] out_lr
);

  // volume table rom
  reg [15:0] AMP_TABLE[32];
  initial $readmemh("ym2149_dac.txt", AMP_TABLE);

  // track change in wr
  reg old_wr;

  // internal registers
  reg [7:0] r [16];

  // pre-dac channel mixer
  wire ca_bit_mix = (ca_bit & ca_tone_enable) ^ (noise_out & ca_lfsr_enable);
  wire cb_bit_mix = (cb_bit & cb_tone_enable) ^ (noise_out & cb_lfsr_enable);
  wire cc_bit_mix = (cc_bit & cc_tone_enable) ^ (noise_out & cc_lfsr_enable);

  // channel mixer
  reg [15:0] mix_out = ca_mix + cb_mix + cc_mix;

  // per channel mix
  wire [15:0] ca_mix = AMP_TABLE[{ca_bit_mix, ca_amp}];
  wire [15:0] cb_mix = AMP_TABLE[{cb_bit_mix, cb_amp}];
  wire [15:0] cc_mix = AMP_TABLE[{cc_bit_mix, cc_amp}];

  // invert so channel enabled when '1' and mute when '0'
  wire ca_tone_enable = ~r[7][0];
  wire cb_tone_enable = ~r[7][1];
  wire cc_tone_enable = ~r[7][2];
  wire ca_lfsr_enable = ~r[7][3];
  wire cb_lfsr_enable = ~r[7][4];
  wire cc_lfsr_enable = ~r[7][5];

  // four bit index into amp_table
  wire [3:0] ca_amp = (r[ 8][4]) ? env_out : r[ 8][3:0];
  wire [3:0] cb_amp = (r[ 9][4]) ? env_out : r[ 9][3:0];
  wire [3:0] cc_amp = (r[10][4]) ? env_out : r[10][3:0];

  // volume is fixed when '0' or envelope controlled when '1'
  wire ca_amp_mode = r[8][4];
  wire cb_amp_mode = r[9][4];
  wire cc_amp_mode = r[10][4];

  // output mix
  assign out_lr = mix_out;

  // clock dividers
  reg [2:0] clk_div;

  // envelope generator
  wire [3:0] env_out;
  wire [3:0] env_mode = r['hd][3:0];
  wire [15:0] env_period = { r[14], r[13] };
  ym2149_env env(in_clk, in_rst, env_period, env_mode, reload_env, env_out);

  // noise generator
  wire noise_out;
  wire [4:0] noise_period = r[6][4:0];
  ym2149_noise noise(in_clk, in_rst, noise_period, noise_out);

  // channel frequencies
  wire [11:0] ca_freq = { r[1][3:0], r[0][7:0] };
  wire [11:0] cb_freq = { r[3][3:0], r[2][7:0] };
  wire [11:0] cc_freq = { r[5][3:0], r[4][7:0] };

  // channel output bits
  wire ca_bit, cb_bit, cc_bit;
  ym2149_tone channel_a(in_clk, in_rst, clk_div == 0, ca_freq, ca_bit);
  ym2149_tone channel_b(in_clk, in_rst, clk_div == 0, cb_freq, cb_bit);
  ym2149_tone channel_c(in_clk, in_rst, clk_div == 0, cc_freq, cc_bit);

  reg reload_env;

  always @(posedge in_clk) begin

    if (in_rst) begin

      // zero the amplitude registers
      r[10] <= 8'h00;
      r[11] <= 8'h00;
      r[12] <= 8'h00;

    end else begin
      // register write
      if ((in_wr == 1'b1) && (old_wr == 1'b0)) begin
        r[ in_reg ] <= in_val;
        reload_env <= (in_reg == 4'd15);
      end else begin
        reload_env <= 0;
      end
    end

    // increment clock dividers
    clk_div <= clk_div + 3'b1;

    // track the old wr register
    old_wr <= in_wr;
  end

endmodule
