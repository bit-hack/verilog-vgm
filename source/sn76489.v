`default_nettype none
`timescale 1ns / 1ps

module sn76489(
  input in_clk,
  input in_rst,
  input [7:0] in_val,
  input in_wr,
  output [15:0] out_lr
);

  // volume table ROM
  reg [15:0] AMP_TABLE[32];
  initial $readmemh("sn76489_dac.txt", AMP_TABLE);

  // track change in WR
  reg OLD_WR;

  reg [9:0] C_FREQ [3];
  reg [9:0] C_TONE [3];
  reg [3:0] C_AMP  [4];
  reg       C_BIT  [3];

  // output mix
  reg [15:0] MIX_OUT;
  assign out_lr = MIX_OUT;

  // clock divider
  reg [3:0] CLK_DIV;

  // channel that was last accessed
  reg [1:0] LATCH_CHAN;

  wire [1:0] IN_CHAN    = in_val[6:5];
  wire       IN_MSB     = in_val[7];
  wire [3:0] IN_DATA_LO = in_val[3:0];
  wire [5:0] IN_DATA_HI = in_val[5:0];

  // '0' for tone update, '1' for amp update
  wire IN_KIND = in_val[4];

  // per channel mix
  wire [15:0] C0_MIX;
  wire [15:0] C1_MIX;
  wire [15:0] C2_MIX;

  always @(posedge in_clk) begin

    if (in_rst) begin

      C_AMP[0] <= 4'h0;
      C_AMP[1] <= 4'h0;
      C_AMP[2] <= 4'h0;
      C_AMP[3] <= 4'h0;

    end else begin

      // on posedge of WR
      if ((in_wr == 1'b1) && (OLD_WR == 1'b0)) begin

        // decode received byte
        casez (in_val)
        8'b1??0????: begin
            if (IN_CHAN != 2'd3) begin
              // freq data low update
              C_FREQ[ IN_CHAN ] <= { C_FREQ[ IN_CHAN ][9:4], IN_DATA_LO };
            end
            LATCH_CHAN <= IN_CHAN;
          end
        8'b0???????:
          if (LATCH_CHAN != 2'd3) begin
            // freq data high update
            C_FREQ[ LATCH_CHAN ] <= { IN_DATA_HI, C_FREQ[ LATCH_CHAN ][3:0] };
          end
        8'b1??1????:
          // attenuation update
          C_AMP[ IN_CHAN ] <= IN_DATA_LO;
        endcase

      end

      if (CLK_DIV == 0) begin

        // update tone generator A
        if (C_TONE[0] == 0) begin
          C_BIT[0] <= ~C_BIT[0];
          C_TONE[0] <= C_FREQ[0];
        end else begin
          C_TONE[0] <= C_TONE[0] - 10'b1;
        end

        // update tone generator B
        if (C_TONE[1] == 0) begin
          C_BIT[1] <= ~C_BIT[1];
          C_TONE[1] <= C_FREQ[1];
        end else begin
          C_TONE[1] <= C_TONE[1] - 10'b1;
        end

        // update tone generator C
        if (C_TONE[2] == 0) begin
          C_BIT[2] <= ~C_BIT[2];
          C_TONE[2] <= C_FREQ[2];
        end else begin
          C_TONE[2] <= C_TONE[2] - 10'b1;
        end

      end

    end

    // increment clock dividers
    CLK_DIV <= CLK_DIV + 3'b1;

    // track the old WR register
    OLD_WR <= in_wr;
  end

  // per channel mix
  assign C0_MIX = AMP_TABLE[{C_BIT[0], C_AMP[0]}];
  assign C1_MIX = AMP_TABLE[{C_BIT[1], C_AMP[1]}];
  assign C2_MIX = AMP_TABLE[{C_BIT[2], C_AMP[2]}];

  // channel mixer
  assign MIX_OUT = C0_MIX + C1_MIX + C2_MIX;

endmodule
