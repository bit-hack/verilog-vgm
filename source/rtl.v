module ym2149(
  input in_clk,
  input in_rst,
  input [7:0] in_reg,
  input [7:0] in_val,
  input in_wr,
  output [15:0] out_lr
);

  reg [15:0] count;

  always @(posedge in_clk) begin
    if (in_rst) begin
      count <= 0;
    end else begin
      count <= count + 16'h01;
    end
    out_lr <= count;
  end

endmodule
