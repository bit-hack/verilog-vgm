`default_nettype none
`timescale 1ns / 1ps

// todo:
// - noise period
// - envelopes

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

  // channel frequencies
  wire [11:0] ca_freq = { r[1][3:0], r[0][7:0] };
  wire [11:0] cb_freq = { r[3][3:0], r[2][7:0] };
  wire [11:0] cc_freq = { r[5][3:0], r[4][7:0] };

  // pre-dac channel mixer
  wire ca_bit_mix = (ca_bit & ca_tone_enable) ^ (lfsr_out & ca_lfsr_enable);
  wire cb_bit_mix = (cb_bit & cb_tone_enable) ^ (lfsr_out & cb_lfsr_enable);
  wire cc_bit_mix = (cc_bit & cc_tone_enable) ^ (lfsr_out & cc_lfsr_enable);

  // channel mixer
  reg [15:0] mix_out = ca_mix + cb_mix + cc_mix;

  // tone counters
  reg [11:0] ca_tone;
  reg [11:0] cb_tone;
  reg [11:0] cc_tone;

  // channel output bits
  reg ca_bit;
  reg cb_bit;
  reg cc_bit;

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
  wire [3:0] ca_amp = r[8][3:0];
  wire [3:0] cb_amp = r[9][3:0];
  wire [3:0] cc_amp = r[10][3:0];

  // volume is fixed when '0' or envelope controlled when '1'
  wire ca_amp_mode = r[8][4];
  wire cb_amp_mode = r[9][4];
  wire cc_amp_mode = r[10][4];

  // noise linear feedback shift register
  reg [16:0] lfsr;
  wire lfsr_in = lfsr[0] ^ lfsr[3];
  wire lfsr_out = lfsr[0];

  // output mix
  assign out_lr = mix_out;

  // clock dividers
  reg [2:0] clk_div;
  reg [2:0] noz_div;

  always @(posedge in_clk) begin

    if (in_rst) begin
      // clear frequencies
      r[0] <= 8'hff;
      r[1] <= 8'hff;
      r[2] <= 8'hff;
      r[3] <= 8'hff;
      r[4] <= 8'hff;
      r[5] <= 8'hff;

      // zero the amplitude registers
      r[10] <= 8'h00;
      r[11] <= 8'h00;
      r[12] <= 8'h00;

      // reset tone generator
      ca_tone <= 12'b0;
      cb_tone <= 12'b0;
      cc_tone <= 12'b0;

      ca_bit  <= 1'b0;
      cb_bit  <= 1'b0;
      cc_bit  <= 1'b0;

      // reset noise register
      lfsr <= 17'h1ffff;

    end else begin
      // register write
      if ((in_wr == 1'b1) && (old_wr == 1'b0)) begin
        r[ in_reg ] <= in_val;
      end

      if (clk_div == 0) begin

        // update tone generator a
        if (ca_tone == 0) begin
          ca_bit <= ~ca_bit;
          ca_tone <= ca_freq;
        end else begin
          ca_tone <= ca_tone - 12'b1;
        end

        // update tone generator b
        if (cb_tone == 0) begin
          cb_bit <= ~cb_bit;
          cb_tone <= cb_freq;
        end else begin
          cb_tone <= cb_tone - 12'b1;
        end

        // update tone generator c
        if (cc_tone == 0) begin
          cc_bit <= ~cc_bit;
          cc_tone <= cc_freq;
        end else begin
          cc_tone <= cc_tone - 12'b1;
        end

      end

      if (noz_div == 0) begin
        lfsr <= { lfsr_in, lfsr[16:1] };
      end
    end

    // increment clock dividers
    clk_div <= clk_div + 3'b1;
    noz_div <= noz_div + 3'b1;

    // track the old wr register
    old_wr <= in_wr;
  end

endmodule
