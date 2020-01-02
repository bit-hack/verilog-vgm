`default_nettype none
`timescale 1ns / 1ps

// in NES runs from ~1.79 MHz clock
// frame clock is ~240Hz

// TODO:
// - Noise Period
// - Sweep
// - Linear Counter
// - Pulse Duty

module nesapu_env(
  input in_clk,
  input in_rst,
  input [3:0] in_vol,
  input in_loop,
  input in_const,
  input in_start,
  input [11:0] in_frame_cnt,
  input [4:0]  in_frame_step,
  output [3:0] out_decay
);

  assign out_decay = in_const ? in_vol : decay;

  reg [3:0] decay;
  reg [3:0] divider;
  reg start;

  wire tick = (in_frame_cnt == 0) && (in_frame_step != 4);

  always @(posedge in_clk) begin
    if (in_rst) begin
      decay <= 4'h0;
      divider <= 4'd0;
    end else begin
      if (in_start) begin
        start <= 1;
      end else begin
        if (tick) begin
          if (start) begin
            start <= 0;
            decay <= 4'hf;
            divider <= in_vol;
          end else begin
            if (divider == 0) begin
              if (decay == 0) begin
                if (in_loop) begin
                  decay <= 4'hf;
                  divider <= in_vol;
                end
              end else begin
                divider <= in_vol;
                decay <= decay - 4'd1;
              end
            end else begin
              divider <= divider - 4'd1;
            end
          end
        end
      end
    end
  end
endmodule


module nesapu_pulse(
  input in_clk,
  input in_rst,
  input [1:0] in_duty,
  input [10:0] in_freq,
  output out_bit
);

  wire [31:0] duty = { 8'b10011111, 8'b01111000, 8'b01100000, 8'b01000000 };

  reg [10:0] counter;
  reg [3:0] index;

  assign out_bit = duty[ { in_duty, index[3:1] } ];

  always @(posedge in_clk) begin
    if (in_rst) begin
      counter <= 11'd0;
      index <= 4'd0;
    end else begin
      if (counter == 'd0) begin
        counter <= in_freq + 11'b1;
        index <= index + 4'd1;
      end else begin
        counter <= counter - 11'd1;
      end
    end
  end
endmodule


module nesapu_length(
  input in_clk,
  input in_rst,
  input in_tick,
  input in_reload,
  input in_halt,
  input [7:0] in_count,
  output out_enable
);
  reg [7:0] count;
  assign out_enable = count != 8'd0;

  always @(posedge in_clk) begin
    if (in_rst) begin
      count <= 8'd0;
    end else begin
      if (in_reload) begin
        count <= in_count;
      end else begin
        if (in_tick && !in_halt) begin
          count <= (count == 8'd0) ? 8'd0 : (count - 8'd1);
        end
      end
    end
  end
endmodule


module nesapu_noise(
  input in_clk,
  input in_rst,
  input in_reload,
  input in_mode,
  input [3:0] in_freq,
  output out_bit);

  reg [11:0] count;
  reg [11:0] max_count;
  reg [14:0] lfsr;

  wire new_bit = lfsr[0] ^ (in_mode ? lfsr[6] : lfsr[1]);

  assign out_bit = lfsr[0];

  always @(posedge in_clk) begin
    if (in_rst) begin
      lfsr <= 15'h1;
    end else begin
      case (in_freq)
      'h0: max_count <= 12'd4;
      'h1: max_count <= 12'd8;
      'h2: max_count <= 12'd16;
      'h3: max_count <= 12'd32;
      'h4: max_count <= 12'd64;
      'h5: max_count <= 12'd96;
      'h6: max_count <= 12'd128;
      'h7: max_count <= 12'd160;
      'h8: max_count <= 12'd202;
      'h9: max_count <= 12'd254;
      'ha: max_count <= 12'd380;
      'hb: max_count <= 12'd508;
      'hc: max_count <= 12'd762;
      'hd: max_count <= 12'd1016;
      'he: max_count <= 12'd2034;
      'hf: max_count <= 12'd4068;
      endcase

      if (count == 'd0) begin
        count <= max_count;
        lfsr <= { new_bit, lfsr[14:1] };
      end else begin
        count <= count - 'd1;
      end

    end
  end

endmodule

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

  wire [1:0]  pulse0_duty = apu_reg[0][7:6];
  wire [3:0]  pulse0_vol  = apu_reg[0][3:0];
  wire [10:0] pulse0_freq = { apu_reg[3][2:0], apu_reg[2] };

  wire [1:0]  pulse1_duty = apu_reg[4][7:6];
  wire [3:0]  pulse1_vol  = apu_reg[4][3:0];
  wire [10:0] pulse1_freq = { apu_reg[7][2:0], apu_reg[6] };

  wire pulse0_bit, pulse1_bit;
  nesapu_pulse pulse0(in_clk, in_rst, pulse0_duty, pulse0_freq, pulse0_bit);
  nesapu_pulse pulse1(in_clk, in_rst, pulse1_duty, pulse1_freq, pulse1_bit);

  // triangle channel
  wire [10:0] tri_freq = { apu_reg['hb][2:0], apu_reg['ha] };
  reg [10:0] tri_int;  // internal counter
  reg [4:0] tri_step;

  // noise channel
  wire lfsr_mode = apu_reg[ 'he ][7];
  wire [3:0] lfsr_vol = apu_reg['hc][3:0];
  wire [3:0] lfsr_freq = apu_reg['he][3:0];
  wire noise_bit;
  nesapu_noise noise(in_clk, in_rst, 0, lfsr_mode, lfsr_freq, noise_bit);

  // internal clock divider
  reg [7:0] clk_div;

  // frame counter internals
  reg [11:0] frame_cnt;
  reg [4:0] frame_step;
  wire frame_mode = apu_reg['h17][7];

  wire [15:0] pulse0_out = AMP_TABLE[ { pulse0_bit, pulse0_env_out } ];
  wire [15:0] pulse1_out = AMP_TABLE[ { pulse1_bit, pulse1_env_out } ];
  wire [7:0] tri_out = TRI_TABLE[ tri_step ];
  wire [15:0] lfsr_out = AMP_TABLE[ { noise_bit, lfsr_env_out } ];

  wire pulse0_mute = (~pulse0_enable || ~len0_on);
  wire pulse1_mute = (~pulse1_enable || ~len1_on);
  wire    tri_mute = (~tri_enable    || ~len2_on);
  wire   lfsr_mute = (~noise_enable  || ~len3_on);

  wire [15:0] mixer =
    (pulse0_mute ? 16'h0 : pulse0_out) +
    (pulse1_mute ? 16'h0 : pulse1_out) +
       (tri_mute ? 16'h0 : { tri_out, 8'h00 }) +
      (lfsr_mute ? 16'h0 : lfsr_out) +
    16'h0;
  assign out_lr = mixer;

  wire [3:0] pulse0_env_out;
  reg pulse0_env_start;
  nesapu_env pulse0_env(
    in_clk,
    in_rst,
    apu_reg['h0][3:0],  // vol
    apu_reg['h0][5],    // loop
    apu_reg['h0][4],    // const
    pulse0_env_start,
    frame_cnt,
    frame_step,
    pulse0_env_out
  );

  wire [3:0] pulse1_env_out;
  reg pulse1_env_start;
  nesapu_env pulse1_env(
    in_clk,
    in_rst,
    apu_reg['h4][3:0],  // vol
    apu_reg['h4][5],    // loop
    apu_reg['h4][4],    // const
    pulse1_env_start,
    frame_cnt,
    frame_step,
    pulse1_env_out
  );

  wire [3:0] lfsr_env_out;
  reg lfsr_env_start;
  nesapu_env lfsr_env(
    in_clk,
    in_rst,
    apu_reg['hc][3:0],  // vol
    apu_reg['hc][5],    // loop
    apu_reg['hc][4],    // const
    lfsr_env_start,
    frame_cnt,
    frame_step,
    lfsr_env_out
  );

  reg tick_len;
  reg reload_len0, reload_len1, reload_len2, reload_len3;
  wire len0_on, len1_on, len2_on, len3_on;
  nesapu_length len0(in_clk, in_rst, tick_len, reload_len0, apu_reg['h00][5], LEN_TABLE[apu_reg['h3][7:3]], len0_on); // pulse0
  nesapu_length len1(in_clk, in_rst, tick_len, reload_len1, apu_reg['h04][5], LEN_TABLE[apu_reg['h7][7:3]], len1_on); // pulse1
  nesapu_length len2(in_clk, in_rst, tick_len, reload_len2, apu_reg['h08][7], LEN_TABLE[apu_reg['hb][7:3]], len2_on); // tri
  nesapu_length len3(in_clk, in_rst, tick_len, reload_len3, apu_reg['h0c][5], LEN_TABLE[apu_reg['hf][7:3]], len3_on); // noise


  wire posedge_wr = (in_wr == 1'b1) && (old_wr == 1'b0);

  always @(posedge in_clk) begin

    if (in_rst) begin

      apu_reg[ 'h15 ] <= 8'hff;
      apu_reg[ 'h0e ] <= 8'h80;

      frame_step <= 5'b00001;
      frame_cnt <= 0;

    end else begin

      // envelop re-triggers
      pulse0_env_start <= posedge_wr && (in_reg == 'h3);
      pulse1_env_start <= posedge_wr && (in_reg == 'h7);
      lfsr_env_start   <= posedge_wr && (in_reg == 'hf);

      reload_len0 <= posedge_wr && (in_reg == 'h03); // pulse0
      reload_len1 <= posedge_wr && (in_reg == 'h07); // pulse1
      reload_len2 <= posedge_wr && (in_reg == 'h0b); // tri
      reload_len3 <= posedge_wr && (in_reg == 'h0f); // noise

      // on posedge of WR
      if (posedge_wr) begin
        // update internal register
        apu_reg[ in_reg ] <= in_val;
      end

      tick_len <= (frame_cnt == 0 && (frame_step == 1 || frame_step == 4));

      if (frame_cnt == 0) begin

        // update at 240hz
        frame_cnt <= 12'd7457;

        // tick the frame counter
        // 4 3 2 1  0
        // 3 2 1 0 3/4
        frame_step <= { frame_step[3:0], frame_mode ? frame_step[3] : frame_step[4] };

      end else begin
        frame_cnt <= frame_cnt - 12'd1;
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
