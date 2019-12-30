`default_nettype none
`timescale 1ns / 1ps

module gbdmg_pulse(
  input in_clk,
  input in_rst,
  input [10:0] in_freq,
  input [1:0] in_duty,
  output out_bit);

  reg [10:0] counter;
  reg [1:0] clk_div;
  reg [7:0] duty;

  reg [1:0] old_duty;
  wire reload_duty = (old_duty != in_duty);

  assign out_bit = duty[0];

  always @(posedge in_clk) begin
    if (in_rst) begin
      counter <= 11'd0;
      old_duty <= ~in_duty;
      clk_div <= 2'd0;
      duty <= 8'b10000111;
    end else begin
      if (clk_div == 0) begin
        if (counter == 0) begin
          counter <= in_freq;  // perhaps ~in_freq
          duty <= { duty[0], duty[7:1] };
        end else begin
          counter <= counter + 11'd1;
        end
      end
      clk_div <= clk_div + 2'd1;
      old_duty <= in_duty;
    end
  end
endmodule

module gbdmg(
  input in_clk,
  input in_rst,
  input [5:0] in_reg,
  input [7:0] in_val,
  input in_wr,
  output [15:0] out_lr
);
  // volume table ROM
  reg [15:0] AMP_TABLE[32];
  initial $readmemh("gbdmg_dac.txt", AMP_TABLE);

  // internal registers
  //
  // 0x20 - 0x2F    32 4bit wave samples  (MSN first LSN second, etc)
  //
  reg [7:0] r [64];

  wire [10:0] pulse0_freq = { r['h04][2:0], r['h03] };
  wire [1:0] pulse0_duty = r['h01][7:6];
  wire pulse0_out;
  gbdmg_pulse pulse0(in_clk, in_rst, pulse0_freq, pulse0_duty, pulse0_out);

  wire [10:0] pulse1_freq = { r['h09][2:0], r['h08] };
  wire [1:0] pulse1_duty = r['h06][7:6];
  wire pulse1_out;
  gbdmg_pulse pulse1(in_clk, in_rst, pulse1_freq, pulse1_duty, pulse1_out);

  reg wr_old;
  wire wr_posedge = ((in_wr == 1'b1) && (wr_old == 1'b0));

  wire [15:0] mix_out =
    AMP_TABLE[ { pulse0_out, 4'hf } ] +
    AMP_TABLE[ { pulse1_out, 4'hf } ];
  assign out_lr = mix_out;

  always @(posedge in_clk) begin
    if (in_rst) begin
      // on reset
    end else begin
      if (wr_posedge) begin
        r[ in_reg ] <= in_val;
      end
    end
    wr_old <= in_wr;
  end

endmodule
