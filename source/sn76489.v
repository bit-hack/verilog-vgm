`default_nettype none
`timescale 1ns / 1ps

module sn76489(
  input in_clk,
  input in_rst,
  input [3:0] in_reg,
  input [7:0] in_val,
  input in_wr,
  output [15:0] out_lr
);

  // volume table ROM
  reg [15:0] AMP_TABLE[32];
  initial $readmemh("sn76489_dac.txt", AMP_TABLE);

  // track change in WR
  reg OLD_WR;

  reg [9:0] CA_FREQ;
  reg [9:0] CA_TONE;
  reg CA_BIT;

  // output mix
  reg [15:0] MIX_OUT;
  assign out_lr = MIX_OUT;

  // clock divider
  reg [3:0] CLK_DIV;

  always @(posedge in_clk) begin

    if (in_rst) begin

    end else begin

      // register write
      if ((in_wr == 1'b1) && (OLD_WR == 1'b0)) begin
        
      end

      if (CLK_DIV == 0) begin

        // update tone generator A
        if (CA_TONE == 0) begin
          CA_BIT <= ~CA_BIT;
          CA_TONE <= CA_FREQ;
        end else begin
          CA_TONE <= CA_TONE - 10'b1;
        end

      end

    end

    // increment clock dividers
    CLK_DIV <= CLK_DIV + 3'b1;

    // track the old WR register
    OLD_WR <= in_wr;
  end

endmodule
