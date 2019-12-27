// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vnesapu_H_
#define _Vnesapu_H_

#include "verilated.h"
class Vnesapu__Syms;

//----------

VL_MODULE(Vnesapu) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(in_clk,0,0);
    VL_IN8(in_rst,0,0);
    VL_IN8(in_reg,4,0);
    VL_IN8(in_val,7,0);
    VL_IN8(in_wr,0,0);
    //char	__VpadToAlign5[1];
    VL_OUT16(out_lr,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT__pulse0_env_start,0,0);
    VL_SIG8(v__DOT__pulse1_env_start,0,0);
    VL_SIG8(v__DOT__lfsr_env_start,0,0);
    VL_SIG8(v__DOT__old_wr,0,0);
    VL_SIG8(v__DOT__pulse0_enable,0,0);
    VL_SIG8(v__DOT__pulse1_enable,0,0);
    VL_SIG8(v__DOT__tri_enable,0,0);
    VL_SIG8(v__DOT__noise_enable,0,0);
    VL_SIG8(v__DOT__pulse0_seq,7,0);
    VL_SIG8(v__DOT__pulse0_length,7,0);
    VL_SIG8(v__DOT__pulse1_seq,7,0);
    VL_SIG8(v__DOT__pulse1_length,7,0);
    VL_SIG8(v__DOT__tri_step,4,0);
    VL_SIG8(v__DOT__tri_length,7,0);
    VL_SIG8(v__DOT__lfsr_length,7,0);
    VL_SIG8(v__DOT__clk_div,7,0);
    VL_SIG8(v__DOT__frame_step,4,0);
    VL_SIG8(v__DOT__tri_out,7,0);
    VL_SIG8(v__DOT__posedge_wr,0,0);
    VL_SIG8(v__DOT__in_timer,7,0);
    VL_SIG8(v__DOT__pulse0_env__DOT__decay,3,0);
    VL_SIG8(v__DOT__pulse0_env__DOT__divider,3,0);
    VL_SIG8(v__DOT__pulse0_env__DOT__start,0,0);
    VL_SIG8(v__DOT__pulse1_env__DOT__decay,3,0);
    VL_SIG8(v__DOT__pulse1_env__DOT__divider,3,0);
    VL_SIG8(v__DOT__pulse1_env__DOT__start,0,0);
    VL_SIG8(v__DOT__lfsr_env__DOT__decay,3,0);
    VL_SIG8(v__DOT__lfsr_env__DOT__divider,3,0);
    VL_SIG8(v__DOT__lfsr_env__DOT__start,0,0);
    //char	__VpadToAlign41[1];
    VL_SIG16(v__DOT__pulse0_freq,10,0);
    VL_SIG16(v__DOT__pulse0_int,10,0);
    VL_SIG16(v__DOT__pulse1_freq,10,0);
    VL_SIG16(v__DOT__pulse1_int,10,0);
    VL_SIG16(v__DOT__tri_freq,10,0);
    VL_SIG16(v__DOT__tri_int,10,0);
    VL_SIG16(v__DOT__lfsr,14,0);
    VL_SIG16(v__DOT__frame_cnt,11,0);
    VL_SIG16(v__DOT__pulse0_out,15,0);
    VL_SIG16(v__DOT__pulse1_out,15,0);
    VL_SIG16(v__DOT__lfsr_out,15,0);
    VL_SIG16(v__DOT__AMP_TABLE[32],15,0);
    VL_SIG8(v__DOT__TRI_TABLE[32],7,0);
    VL_SIG8(v__DOT__LEN_TABLE[32],7,0);
    VL_SIG8(v__DOT__apu_reg[23],7,0);
    //char	__VpadToAlign215[1];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT____Vcellinp__pulse0_env____pinNumber5,0,0);
    VL_SIG8(v__DOT____Vcellinp__pulse0_env____pinNumber4,0,0);
    VL_SIG8(v__DOT____Vcellinp__pulse0_env____pinNumber3,3,0);
    VL_SIG8(v__DOT____Vcellinp__pulse1_env____pinNumber5,0,0);
    VL_SIG8(v__DOT____Vcellinp__pulse1_env____pinNumber4,0,0);
    VL_SIG8(v__DOT____Vcellinp__pulse1_env____pinNumber3,3,0);
    VL_SIG8(v__DOT____Vcellinp__lfsr_env____pinNumber5,0,0);
    VL_SIG8(v__DOT____Vcellinp__lfsr_env____pinNumber4,0,0);
    VL_SIG8(v__DOT____Vcellinp__lfsr_env____pinNumber3,3,0);
    VL_SIG8(v__DOT____Vlvbound1,7,0);
    VL_SIG8(__VinpClk__TOP__v__DOT__pulse1_env_start,0,0);
    VL_SIG8(__VinpClk__TOP__v__DOT__lfsr_env_start,0,0);
    VL_SIG8(__VinpClk__TOP__v__DOT__pulse0_env_start,0,0);
    VL_SIG8(__Vclklast__TOP__in_clk,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__v__DOT__pulse1_env_start,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__v__DOT__lfsr_env_start,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__v__DOT__pulse0_env_start,0,0);
    VL_SIG8(__Vchglast__TOP__v__DOT__pulse0_env_start,0,0);
    VL_SIG8(__Vchglast__TOP__v__DOT__pulse1_env_start,0,0);
    VL_SIG8(__Vchglast__TOP__v__DOT__lfsr_env_start,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign244[4];
    Vnesapu__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vnesapu& operator= (const Vnesapu&);	///< Copying not allowed
    Vnesapu(const Vnesapu&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vnesapu(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vnesapu();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vnesapu__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vnesapu__Syms* symsp, bool first);
  private:
    static IData	_change_request(Vnesapu__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__5(Vnesapu__Syms* __restrict vlSymsp);
    static void	_combo__TOP__7(Vnesapu__Syms* __restrict vlSymsp);
    static void	_eval(Vnesapu__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vnesapu__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vnesapu__Syms* __restrict vlSymsp);
    static void	_initial__TOP(Vnesapu__Syms* __restrict vlSymsp);
    static void	_multiclk__TOP__11(Vnesapu__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(Vnesapu__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__10(Vnesapu__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__2(Vnesapu__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__3(Vnesapu__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__4(Vnesapu__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__8(Vnesapu__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__9(Vnesapu__Syms* __restrict vlSymsp);
    static void	_settle__TOP__6(Vnesapu__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
