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
    VL_SIG8(v__DOT__old_wr,0,0);
    VL_SIG8(v__DOT__pulse0_enable,0,0);
    VL_SIG8(v__DOT__pulse1_enable,0,0);
    VL_SIG8(v__DOT__tri_enable,0,0);
    VL_SIG8(v__DOT__noise_enable,0,0);
    VL_SIG8(v__DOT__pulse0_duty,1,0);
    VL_SIG8(v__DOT__pulse1_duty,1,0);
    VL_SIG8(v__DOT__tri_step,4,0);
    VL_SIG8(v__DOT__lfsr_mode,0,0);
    VL_SIG8(v__DOT__lfsr_freq,3,0);
    VL_SIG8(v__DOT__frame_step,4,0);
    VL_SIG8(v__DOT__tri_out,7,0);
    VL_SIG8(v__DOT__pulse0_env_start,0,0);
    VL_SIG8(v__DOT__pulse1_env_start,0,0);
    VL_SIG8(v__DOT__lfsr_env_start,0,0);
    VL_SIG8(v__DOT__tick_len,0,0);
    VL_SIG8(v__DOT__reload_len0,0,0);
    VL_SIG8(v__DOT__reload_len1,0,0);
    VL_SIG8(v__DOT__reload_len2,0,0);
    VL_SIG8(v__DOT__reload_len3,0,0);
    VL_SIG8(v__DOT__posedge_wr,0,0);
    VL_SIG8(v__DOT__pulse0__DOT__index,3,0);
    VL_SIG8(v__DOT__pulse1__DOT__index,3,0);
    VL_SIG8(v__DOT__pulse0_env__DOT__decay,3,0);
    VL_SIG8(v__DOT__pulse0_env__DOT__divider,3,0);
    VL_SIG8(v__DOT__pulse0_env__DOT__start,0,0);
    VL_SIG8(v__DOT__pulse1_env__DOT__decay,3,0);
    VL_SIG8(v__DOT__pulse1_env__DOT__divider,3,0);
    VL_SIG8(v__DOT__pulse1_env__DOT__start,0,0);
    VL_SIG8(v__DOT__lfsr_env__DOT__decay,3,0);
    VL_SIG8(v__DOT__lfsr_env__DOT__divider,3,0);
    VL_SIG8(v__DOT__lfsr_env__DOT__start,0,0);
    VL_SIG8(v__DOT__len0__DOT__count,7,0);
    VL_SIG8(v__DOT__len1__DOT__count,7,0);
    VL_SIG8(v__DOT__len2__DOT__count,7,0);
    VL_SIG8(v__DOT__len3__DOT__count,7,0);
    VL_SIG16(v__DOT__pulse0_freq,10,0);
    VL_SIG16(v__DOT__pulse1_freq,10,0);
    VL_SIG16(v__DOT__tri_freq,10,0);
    VL_SIG16(v__DOT__tri_int,10,0);
    VL_SIG16(v__DOT__frame_cnt,11,0);
    VL_SIG16(v__DOT__pulse0_out,15,0);
    VL_SIG16(v__DOT__pulse1_out,15,0);
    VL_SIG16(v__DOT__lfsr_out,15,0);
    VL_SIG16(v__DOT__pulse0__DOT__counter,10,0);
    VL_SIG16(v__DOT__pulse1__DOT__counter,10,0);
    VL_SIG16(v__DOT__noise__DOT__count,11,0);
    VL_SIG16(v__DOT__noise__DOT__max_count,11,0);
    VL_SIG16(v__DOT__noise__DOT__lfsr,14,0);
    //char	__VpadToAlign74[6];
    VL_SIG16(v__DOT__AMP_TABLE[32],15,0);
    VL_SIG8(v__DOT__TRI_TABLE[32],7,0);
    VL_SIG8(v__DOT__LEN_TABLE[32],7,0);
    VL_SIG8(v__DOT__apu_reg[23],7,0);
    //char	__VpadToAlign231[1];
    
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
    VL_SIG8(v__DOT____Vcellinp__len0____pinNumber6,7,0);
    VL_SIG8(v__DOT____Vcellinp__len0____pinNumber5,0,0);
    VL_SIG8(v__DOT____Vcellinp__len1____pinNumber6,7,0);
    VL_SIG8(v__DOT____Vcellinp__len1____pinNumber5,0,0);
    VL_SIG8(v__DOT____Vcellinp__len2____pinNumber6,7,0);
    VL_SIG8(v__DOT____Vcellinp__len2____pinNumber5,0,0);
    VL_SIG8(v__DOT____Vcellinp__len3____pinNumber6,7,0);
    VL_SIG8(v__DOT____Vcellinp__len3____pinNumber5,0,0);
    VL_SIG8(v__DOT____Vlvbound1,7,0);
    VL_SIG8(__Vclklast__TOP__in_clk,0,0);
    //char	__VpadToAlign255[1];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign260[4];
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
    static void	_combo__TOP__2(Vnesapu__Syms* __restrict vlSymsp);
    static void	_eval(Vnesapu__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vnesapu__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vnesapu__Syms* __restrict vlSymsp);
    static void	_initial__TOP(Vnesapu__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(Vnesapu__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__4(Vnesapu__Syms* __restrict vlSymsp);
    static void	_settle__TOP__3(Vnesapu__Syms* __restrict vlSymsp);
    static void	_settle__TOP__5(Vnesapu__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
