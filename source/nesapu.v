`default_nettype none
`timescale 1ns / 1ps

// in NES runs from ~1.79 MHz clock
// frame clock is ~240Hz

module nesapu(
  input in_clk,
  input in_rst,
  input [4:0] in_reg,
  input [7:0] in_val,
  input in_wr,
  output [15:0] out_lr
);
  // volume table ROM
  reg [15:0] AMP_TABLE[32];
  initial $readmemh("nesapu_dac.txt", AMP_TABLE);

  // triangle table ROM
  reg [7:0] TRI_TABLE[32];
  initial $readmemh("nesapu_tri.txt", TRI_TABLE);

  // length table ROM
  reg [7:0] LEN_TABLE[32];
  initial $readmemh("nesapu_len.txt", LEN_TABLE);

  // track change in WR
  reg old_wr;

  // internal registers
  reg [7:0] apu_reg [23];
  wire pulse0_enable = apu_reg[ 'h15 ][0];
  wire pulse1_enable = apu_reg[ 'h15 ][1];
  wire tri_enable    = apu_reg[ 'h15 ][2];
  wire noise_enable  = apu_reg[ 'h15 ][3];

  // pulse 0 channel
  wire [3:0]  pulse0_vol  = apu_reg[0][3:0];
  wire [10:0] pulse0_freq = { apu_reg[3][2:0], apu_reg[2] };
  reg [10:0] pulse0_int;  // internal counter
  reg [7:0] pulse0_seq;
  reg pulse0_bit;
  reg [7:0] pulse0_length;
  wire [7:0] pulse0_length_next = (pulse0_length == 0) ? 8'd0 : (pulse0_length - 8'd1);

  // pulse 1 channel
  wire [3:0]  pulse1_vol  = apu_reg[4][3:0];
  wire [10:0] pulse1_freq = { apu_reg[7][2:0], apu_reg[6] };
  reg [10:0] pulse1_int;  // internal counter
  reg [7:0] pulse1_seq;
  reg pulse1_bit;
  reg [7:0] pulse1_length;
  wire [7:0] pulse1_length_next = (pulse1_length == 0) ? 8'd0 : (pulse1_length - 8'd1);

  // triangle channel
  wire [10:0] tri_freq = { apu_reg['hb][2:0], apu_reg['ha] };
  reg [10:0] tri_int;  // internal counter
  reg [4:0] tri_step;
  reg [7:0] tri_length;
  wire [7:0] tri_length_next = (tri_length == 0) ? 8'd0 : (tri_length - 8'd1);

  // noise channel
  wire [3:0] lfsr_vol = apu_reg['hc][3:0];
  wire lfsr_mode = apu_reg[ 'he ][7];
  reg [14:0] lfsr;
  wire lfsr_in = lfsr[0] ^ lfsr[1];
  reg [7:0] lfsr_length;
  wire [7:0] lfsr_length_next = (lfsr_length == 0) ? 8'd0 : (lfsr_length - 8'd1);

  // internal clock divider
  reg [7:0] clk_div;

  // frame counter internals
  reg [11:0] frame_clk;
  reg [4:0] frame_step;
  wire frame_mode = apu_reg['h17][7];

  wire [15:0] pulse0_out = AMP_TABLE[ { pulse0_seq[0], pulse0_vol } ];
  wire [15:0] pulse1_out = AMP_TABLE[ { pulse1_seq[0], pulse1_vol } ];
  wire [7:0] tri_out = TRI_TABLE[ tri_step ];
  wire [15:0] lfsr_out = AMP_TABLE[ { lfsr[0], lfsr_vol } ];

  wire pulse0_mute = (pulse0_enable == 0) || (pulse0_length == 0);
  wire pulse1_mute = (pulse1_enable == 0) || (pulse1_length == 0);
  wire    tri_mute =    (tri_enable == 0) ||    (tri_length == 0);
  wire   lfsr_mute =  (noise_enable == 0) ||   (lfsr_length == 0);

  wire [15:0] mixer =
    (pulse0_mute ? 16'h0 : pulse0_out) +
    (pulse1_mute ? 16'h0 : pulse1_out) +
       (tri_mute ? 16'h0 : { tri_out, 8'h00 }) +
      (lfsr_mute ? 16'h0 : lfsr_out) +
    16'h0;
  assign out_lr = mixer;

  wire posedge_wr = (in_wr == 1'b1) && (old_wr == 1'b0);

  wire [7:0] in_timer = LEN_TABLE[ in_val[ 7:3 ] ];

  always @(posedge in_clk) begin

    if (in_rst) begin

      pulse0_seq <= 8'b01111000;
      pulse1_seq <= 8'b01111000;

      apu_reg[ 'h15 ] <= 8'hff;
      apu_reg[ 'h0e ] <= 8'h80;

      lfsr <= 15'b1;

      frame_step <= 5'b00001;
      frame_clk <= 0;

    end else begin

      // on posedge of WR
      if (posedge_wr) begin

        // update internal register
        apu_reg[ in_reg ] <= in_val;

        // update length counters
        case (in_reg)
        'h3: pulse0_length <= in_timer;
        'h7: pulse1_length <= in_timer;
        'hb: tri_length    <= in_timer;
        'hf: lfsr_length   <= in_timer;
        endcase

      end else begin

        if (frame_clk == 0) begin
          frame_clk <= 12'd3728;

          if (frame_step == 1 || frame_step == 4) begin
            pulse0_length <= pulse0_length_next;
            pulse1_length <= pulse1_length_next;
            tri_length    <= tri_length_next;
            lfsr_length   <= lfsr_length_next;
          end

          if (frame_step == 0 || frame_step == 1 || frame_step == 2 || frame_step == 4) begin
            // tick envelopes
            // triangle linear counter
          end

          // tick the frame counter
          // 4 3 2 1  0
          // 3 2 1 0 3/4
          frame_step <= 
            (frame_step == 0) ? 5'b1 :
            { frame_step[3:0], frame_mode ? frame_step[3] : frame_step[4] };
        end
      else
        frame_clk <= frame_clk - 12'd1;
      end

      if (clk_div[0] == 0) begin

        // update tone channel 0
        if (pulse0_int == 0) begin
          pulse0_int <= pulse0_freq + 11'b1;
          pulse0_seq <= { pulse0_seq[0], pulse0_seq[7:1] };
        end else begin
          pulse0_int <= pulse0_int - 11'd1;
        end

        // update tone channel 1
        if (pulse1_int == 0) begin
          pulse1_int <= pulse1_freq + 11'b1;
          pulse1_seq <= { pulse1_seq[0], pulse1_seq[7:1] };
        end else begin
          pulse1_int <= pulse1_int - 11'd1;
        end

      end

      if (clk_div[3:0] == 0) begin
        // update lfsr
        lfsr <= { lfsr_in, lfsr[14:1] }; 
      end

      // update tone triangle
      if (tri_int == 0) begin
        tri_int <= tri_freq + 11'b1;
        tri_step <= tri_step + 5'b1;
      end else begin
        tri_int <= tri_int - 11'd1;
      end

    end

    // increment clock dividers
    clk_div <= clk_div + 8'b1;

    // track the old WR register
    old_wr <= in_wr;
  end

endmodule
