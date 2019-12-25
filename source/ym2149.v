`default_nettype none
`timescale 1ns / 1ps

// TODO:
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

  // volume table ROM
  reg [15:0] AMP_TABLE[32];
  initial $readmemh("ym2149_dac.txt", AMP_TABLE);

  // track change in WR
  reg OLD_WR;

  // internal registers
  reg [7:0] R [16];

  // channel frequencies
  wire [11:0] CA_FREQ = { R[1][3:0], R[0][7:0] };
  wire [11:0] CB_FREQ = { R[3][3:0], R[2][7:0] };
  wire [11:0] CC_FREQ = { R[5][3:0], R[4][7:0] };

  // pre-dac channel mixer
  wire CA_BIT_MIX = (CA_BIT & CA_TONE_ENABLE) ^ (LFSR_OUT & CA_LFSR_ENABLE);
  wire CB_BIT_MIX = (CB_BIT & CB_TONE_ENABLE) ^ (LFSR_OUT & CB_LFSR_ENABLE);
  wire CC_BIT_MIX = (CC_BIT & CC_TONE_ENABLE) ^ (LFSR_OUT & CC_LFSR_ENABLE);

  // channel mixer
  reg [15:0] MIX_OUT = CA_MIX + CB_MIX + CC_MIX;

  // tone counters
  reg [11:0] CA_TONE;
  reg [11:0] CB_TONE;
  reg [11:0] CC_TONE;

  // channel output bits
  reg CA_BIT;
  reg CB_BIT;
  reg CC_BIT;

  // per channel mix
  wire [15:0] CA_MIX = AMP_TABLE[{CA_BIT_MIX, CA_AMP}];
  wire [15:0] CB_MIX = AMP_TABLE[{CB_BIT_MIX, CB_AMP}];
  wire [15:0] CC_MIX = AMP_TABLE[{CC_BIT_MIX, CC_AMP}];

  // invert so channel enabled when '1' and mute when '0'
  wire CA_TONE_ENABLE = ~R[7][0];
  wire CB_TONE_ENABLE = ~R[7][1];
  wire CC_TONE_ENABLE = ~R[7][2];
  wire CA_LFSR_ENABLE = ~R[7][3];
  wire CB_LFSR_ENABLE = ~R[7][4];
  wire CC_LFSR_ENABLE = ~R[7][5];

  // four bit index into AMP_TABLE
  wire [3:0] CA_AMP = R[8][3:0];
  wire [3:0] CB_AMP = R[9][3:0];
  wire [3:0] CC_AMP = R[10][3:0];

  // volume is fixed when '0' or envelope controlled when '1'
  wire CA_AMP_MODE = R[8][4];
  wire CB_AMP_MODE = R[9][4];
  wire CC_AMP_MODE = R[10][4];

  // noise linear feedback shift register
  reg [16:0] LFSR;
  wire LFSR_IN = LFSR[0] ^ LFSR[3];
  wire LFSR_OUT = LFSR[0];

  // output mix
  assign out_lr = MIX_OUT;

  // clock dividers
  reg [2:0] CLK_DIV;
  reg [2:0] NOZ_DIV;

  always @(posedge in_clk) begin

    if (in_rst) begin
      // clear frequencies
      R[0] <= 8'hff;
      R[1] <= 8'hff;
      R[2] <= 8'hff;
      R[3] <= 8'hff;
      R[4] <= 8'hff;
      R[5] <= 8'hff;

      // zero the amplitude registers
      R[10] <= 8'h00;
      R[11] <= 8'h00;
      R[12] <= 8'h00;

      // reset tone generator
      CA_TONE <= 12'b0;
      CB_TONE <= 12'b0;
      CC_TONE <= 12'b0;

      CA_BIT  <= 1'b0;
      CB_BIT  <= 1'b0;
      CC_BIT  <= 1'b0;

      // reset noise register
      LFSR <= 17'h1ffff;

    end else begin
      // register write
      if ((in_wr == 1'b1) && (OLD_WR == 1'b0)) begin
        R[ in_reg ] <= in_val;
      end

      if (CLK_DIV == 0) begin

        // update tone generator A
        if (CA_TONE == 0) begin
          CA_BIT <= ~CA_BIT;
          CA_TONE <= CA_FREQ;
        end else begin
          CA_TONE <= CA_TONE - 12'b1;
        end

        // update tone generator B
        if (CB_TONE == 0) begin
          CB_BIT <= ~CB_BIT;
          CB_TONE <= CB_FREQ;
        end else begin
          CB_TONE <= CB_TONE - 12'b1;
        end

        // update tone generator C
        if (CC_TONE == 0) begin
          CC_BIT <= ~CC_BIT;
          CC_TONE <= CC_FREQ;
        end else begin
          CC_TONE <= CC_TONE - 12'b1;
        end

      end

      if (NOZ_DIV == 0) begin
        LFSR <= { LFSR_IN, LFSR[16:1] };
      end
    end

    // increment clock dividers
    CLK_DIV <= CLK_DIV + 3'b1;
    NOZ_DIV <= NOZ_DIV + 3'b1;

    // track the old WR register
    OLD_WR <= in_wr;
  end

endmodule
