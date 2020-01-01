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
    end else begin
      if (reload_duty) begin
        case (in_duty)
        2'd0: duty <= 8'b00000001;
        2'd1: duty <= 8'b10000001;
        2'd2: duty <= 8'b10000111;
        2'd3: duty <= 8'b01111110;
        endcase
      end
      if (clk_div == 0) begin
        if (counter == 0) begin
          counter <= in_freq;  // perhaps ~in_freq
          if (!reload_duty) begin
            duty <= { duty[0], duty[7:1] };
          end
        end else begin
          counter <= counter + 11'd1;
        end
      end
      clk_div <= clk_div + 2'd1;
      old_duty <= in_duty;
    end
  end
endmodule


module gbdmg_wave(
  input in_clk,
  input in_rst,
  input [10:0] in_freq,
  output [4:0] out_addr);

  reg [10:0] counter;
  reg clk_div;
  reg [4:0] wave_addr;

  assign out_addr = wave_addr;

  always @(posedge in_clk) begin
    if (in_rst) begin
      counter <= 11'd0;
      clk_div <= 0;
      wave_addr <= 5'd0;
    end else begin
      if (clk_div == 0) begin
        if (counter == 0) begin
          counter <= in_freq;
          wave_addr <= wave_addr + 5'd1;
        end else begin
          counter <= counter + 11'd1;
        end
      end
      clk_div <= ~clk_div;
    end
  end
endmodule


module gbdmg_wave_mem(
  input [7:0] in_data [16],
  input [4:0] in_addr,
  output [3:0] out_val
);
  wire addr_lo = in_addr[0];
  wire [3:0] addr_hi = in_addr[4:1];
  assign out_val = addr_lo ?
    (in_data[ addr_hi ][7:4]) :
    (in_data[ addr_hi ][3:0]);
endmodule


module gbdm_envelope(
  input in_clk,
  input in_rst,
  input [3:0] in_vol,
  input [2:0] in_period,
  input in_dir,
  input in_trigger,
  input in_tick,
  output [3:0] out_value);

  reg [3:0] value;
  assign out_value = value;

  reg [2:0] clk_div;

  always @(posedge in_clk, posedge in_trigger) begin
    if (in_rst) begin
      value <= 4'h0;
      clk_div <= 3'd0;
    end else begin
      if (in_trigger) begin
        value <= in_vol;
        clk_div <= in_period;
      end else begin
        if (in_tick) begin
          if (clk_div == 3'd0) begin
            clk_div <= in_period;
            if (in_dir) begin
              value <= (value == 4'h0) ? value : value + 4'd1;
            end else begin
              value <= (value == 4'hf) ? value : value - 4'd1;
            end
          end else begin
            clk_div <= clk_div - 3'd1;
          end
        end
      end
    end
  end
endmodule


module gbdmg_noise(
  input in_clk,
  input in_rst,
  input [3:0] in_shift,
  input [2:0] in_divisor,
  input in_mode,
  output out_bit);

  reg [10:0] period_dec;
  reg [10:0] counter;

  reg [14:0] lfsr;
  wire xor_bit = lfsr[1] ^ lfsr[0];

  wire [14:0] lfsr_next = in_mode ?
    ({ 8'd0, xor_bit, lfsr[5:0] }) :
    ({ xor_bit, lfsr[14:1] });

  assign out_bit = lfsr[0];

  always @(posedge in_clk) begin

    if (in_rst) begin
      lfsr <= 15'd1;
    end else begin
      // decode the noise period
      case (in_divisor)
     'd0: period_dec <= 11'd8;
     'd1: period_dec <= 11'd16;
     'd2: period_dec <= 11'd32;
     'd3: period_dec <= 11'd48;
     'd4: period_dec <= 11'd64;
     'd5: period_dec <= 11'd80;
     'd6: period_dec <= 11'd96;
     'd7: period_dec <= 11'd112;
      endcase

      // update the counter
      if (counter == 'd0) begin
        counter <= period_dec << in_shift;
        lfsr <= lfsr_next;
      end else begin
        counter <= counter - 10'd1;
      end
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
  reg [7:0] r [64];

  // pulse channel 0
  wire [10:0] pulse0_freq = { r['h04][2:0], r['h03] };
  wire [1:0] pulse0_duty = r['h01][7:6];
  wire pulse0_out;
  gbdmg_pulse pulse0(in_clk, in_rst, pulse0_freq, pulse0_duty, pulse0_out);
  wire [15:0] pulse0_mix = AMP_TABLE[ { pulse0_out, env0_value } ];

  // pulse channel 1
  wire [10:0] pulse1_freq = { r['h09][2:0], r['h08] };
  wire [1:0] pulse1_duty = r['h06][7:6];
  wire pulse1_out;
  gbdmg_pulse pulse1(in_clk, in_rst, pulse1_freq, pulse1_duty, pulse1_out);
  wire [15:0] pulse1_mix = AMP_TABLE[ { pulse1_out, env1_value } ];

  // wave channel
  wire [3:0] wave_out;
  wire [10:0] wave_freq = { r['h0e][2:0], r['h0d] };
  wire [4:0] wave_addr;
  gbdmg_wave_mem wave_mem(r[47:32], wave_addr, wave_out);
  gbdmg_wave wave(in_clk, in_rst, wave_freq, wave_addr);
  wire [15:0] wave_mix_int = ({ 2'd0, wave_out[3:0], 10'd0 } - 16'h2000);
  wire wave_mix_sign = wave_mix_int[15];
  // wave volume computation
  // TODO: use sign extending shifts instead
  wire [15:0] wave_mix =
    (wave_vol == 2'd0) ? 16'd0 :
      (wave_vol == 2'd1) ? wave_mix_int :
        (wave_vol == 2'd2) ? { wave_mix_sign, wave_mix_int[15:1] } :
          { wave_mix_sign, wave_mix_sign, wave_mix_int[15:2] };
  wire [1:0] wave_vol = r['hc][6:5];

  // noise channel
  wire noise_bit;
  gbdmg_noise noise(in_clk, in_rst, r['h12][7:4], r['h12][2:0], r['h12][3], noise_bit);
  wire [15:0] noise_mix = AMP_TABLE[ { noise_bit, env2_value } ];

  reg wr_old;
  wire wr_posedge = ((in_wr == 1'b1) && (wr_old == 1'b0));

  reg [9:0] frame_clk_div;
  reg [2:0] frame_seq;

  wire [15:0] mix_out =
    pulse0_mix +
//    pulse1_mix +
//    wave_mix +
//    noise_mix +
    16'd0;
  assign out_lr = mix_out;

  //    length    env     sweep
  //
  // 0  clock
  // 1
  // 2  clock             clock
  // 3
  // 4  clock
  // 5
  // 6  clock             clock
  // 7           clock
  wire tick_len_cnt = (frame_clk_div == 0) && (frame_seq[0] == 0);
  wire tick_env     = (frame_clk_div == 0) && (frame_seq == 3'd7);
  wire tick_sweep   = (frame_clk_div == 0) && (frame_seq == 3'd2 ||
                                               frame_seq == 3'd6);

  reg trigger_env0, trigger_env1, trigger_env2;

  wire [3:0] env0_value;
  wire [3:0] env1_value;
  wire [3:0] env2_value;
  gbdm_envelope env0(in_clk, in_rst, r['h02][7:4], r['h02][2:0], r['h02][3], trigger_env0, tick_env, env0_value);
  gbdm_envelope env1(in_clk, in_rst, r['h07][7:4], r['h07][2:0], r['h07][3], trigger_env1, tick_env, env1_value);
  gbdm_envelope env2(in_clk, in_rst, r['h11][7:4], r['h11][2:0], r['h11][3], trigger_env2, tick_env, env2_value);

  always @(posedge in_clk) begin
    if (in_rst) begin
      // on reset
    end else begin

      trigger_env0 <= wr_posedge && (in_reg == 'h04) && (in_val[7]);
      trigger_env1 <= wr_posedge && (in_reg == 'h09) && (in_val[7]);
      trigger_env2 <= wr_posedge && (in_reg == 'h13) && (in_val[7]);

      if (wr_posedge) begin
        r[ in_reg ] <= in_val;
      end
    end
    wr_old <= in_wr;
  end

  always @(posedge in_clk) begin
    if (frame_clk_div == 10'd0) begin
      frame_clk_div <= 10'd781;
      frame_seq <= frame_seq + 3'd1;
    end else begin
      frame_clk_div <= frame_clk_div - 10'd1;
    end
  end

endmodule
