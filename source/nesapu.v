`default_nettype none
`timescale 1ns / 1ps

// in NES runs from ~1.79 MHz clock
// frame clock is ~240Hz

module nesapu(
  input in_clk,
  input in_rst,
  input [3:0] in_reg,
  input [7:0] in_val,
  input in_wr,
  output [15:0] out_lr
);

  // track change in WR
  reg old_wr;

  // internal registers
  reg [7:0] apu_reg [16];

  // pulse 0 channel
  wire [1:0]  pulse0_duty = apu_reg[0][7:6];
  wire [3:0]  pulse0_vol  = apu_reg[0][3:0];
  wire [10:0] pulse0_freq = { apu_reg[3][2:0], apu_reg[2] };
  reg [10:0] pulse0_int;

  // internal clock divider
  reg [7:0] clk_div;

  always @(posedge in_clk) begin

    if (in_rst) begin

      // do reset

    end else begin

      // on posedge of WR
      if ((in_wr == 1'b1) && (old_wr == 1'b0)) begin
        // update internal register
        apu_reg[ in_reg ] <= in_val;
      end

      if (clk_div[3:0] == 0) begin

        // update tone channel 0
        if (pulse0_int == 0) begin
          pulse0_int <= pulse0_freq + 11'b1;
        end else begin
          pulse0_int <= pulse0_int - 11'd1;
        end
      end
    end

    // increment clock dividers
    clk_div <= clk_div + 8'b1;

    // track the old WR register
    old_wr <= in_wr;
  end

endmodule
