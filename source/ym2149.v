`default_nettype none
`timescale 1ns / 1ps

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

  // channel A frequency
  wire [11:0] CA_FREQ;
  assign CA_FREQ = { R[1][3:0], R[0][7:0] };

  reg [11:0] CA_TONE;
  reg [11:0] CB_TONE;
  reg [11:0] CC_TONE;

  // output bit state from main oscillators
  reg CA_BIT;
  reg CB_BIT;
  reg CC_BIT;

  wire [15:0] CA_MIX;
  wire [15:0] CB_MIX;
  wire [15:0] CC_MIX;

  // channel B frequency
  wire [11:0] CB_FREQ;
  assign CB_FREQ = { R[3][3:0], R[2][7:0] };

  // channel C frequency
  wire [11:0] CC_FREQ;
  assign CC_FREQ = { R[5][3:0], R[4][7:0] };

  // channel enabled when '0' and mute when '1'
  wire CA_ENABLE = R[7][0];
  wire CB_ENABLE = R[7][1];
  wire CC_ENABLE = R[7][2];

  // four bit index into AMP_TABLE
  wire [3:0] CA_AMP = R[10][3:0];
  wire [3:0] CB_AMP = R[11][3:0];
  wire [3:0] CC_AMP = R[12][3:0];

  // volume is fixed when '0' or envelope controlled when '1'
  wire CA_AMP_MODE = R[10][4];
  wire CB_AMP_MODE = R[11][4];
  wire CC_AMP_MODE = R[12][4];

  // output mix
  reg [15:0] MIX_OUT;
  assign out_lr = MIX_OUT;

  // clock divider
  reg [3:0] CLK_DIV;

  always @(posedge in_clk) begin
    if (in_rst) begin

      // clear frequencies
      R[0] <= 8'hff;
      R[1] <= 8'hff;
      R[3] <= 8'hff;
      R[4] <= 8'hff;
      R[5] <= 8'hff;
      R[6] <= 8'hff;

      // zero amp
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

    end else begin
      // register write
      if ((in_wr == 1'b1) && (OLD_WR == 1'b0)) begin
        R[ in_reg ] <= in_val;
      end

      if (CLK_DIV == 4'd0) begin
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
            CB_BIT <= ~CB_BIT;
            CC_TONE <= CC_FREQ;
        end else begin
            CC_TONE <= CC_TONE - 12'b1;
        end

      end
    end

    // increment clock divider
    CLK_DIV <= CLK_DIV + 4'b1;

    // mixdown the channels
    MIX_OUT <=
      (CC_ENABLE ? 16'h0 : CC_MIX) +
      (CB_ENABLE ? 16'h0 : CB_MIX) +
      (CA_ENABLE ? 16'h0 : CA_MIX);

    // update the register
    OLD_WR <= in_wr;
  end

  assign CA_MIX = AMP_TABLE[{CA_BIT, CA_AMP}];
  assign CB_MIX = AMP_TABLE[{CB_BIT, CB_AMP}];
  assign CC_MIX = AMP_TABLE[{CC_BIT, CC_AMP}];

endmodule
