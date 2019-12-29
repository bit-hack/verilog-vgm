`default_nettype none
`timescale 1ns / 1ps

module ym3812(
  input in_clk,
  input in_rst,
  input [7:0] in_reg,
  input [7:0] in_val,
  input in_wr,
  output [15:0] out_lr
);

  // internal registers
  reg [7:0] r [256];

  // track posedge of wr
  reg wr_old;
  wire wr_edge = (in_wr == 1'b1) && (wr_old == 1'b0);
  
  always @(posedge in_clk) begin

    if (in_rst) begin
      // do reset
    end else begin
      // register write
      if (wr_edge) begin
        r[ in_reg ] <= in_val;
      end

      

      // track wr edge
      wr_old <= in_wr;
    end
  end

endmodule
