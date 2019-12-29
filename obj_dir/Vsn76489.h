// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vsn76489_H_
#define _Vsn76489_H_

#include "verilated.h"
class Vsn76489__Syms;

//----------

VL_MODULE(Vsn76489) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(in_clk,0,0);
    VL_IN8(in_rst,0,0);
    VL_IN8(in_val,7,0);
    VL_IN8(in_wr,0,0);
    VL_OUT16(out_lr,15,0);
    //char	__VpadToAlign6[2];
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT__noise_clear,0,0);
    VL_SIG8(v__DOT__old_wr,0,0);
    VL_SIG8(v__DOT__noise_shift,1,0);
    VL_SIG8(v__DOT__noise_fb,0,0);
    VL_SIG8(v__DOT__clk_div,3,0);
    VL_SIG8(v__DOT__latch_chan,1,0);
    VL_SIG8(v__DOT__posedge_wr,0,0);
    VL_SIG8(v__DOT__tone0__DOT__phase,0,0);
    VL_SIG8(v__DOT__tone1__DOT__phase,0,0);
    VL_SIG8(v__DOT__tone2__DOT__phase,0,0);
    VL_SIG8(v__DOT__noise__DOT__old_tone2,0,0);
    //char	__VpadToAlign23[1];
    VL_SIG16(v__DOT__c0_mix,15,0);
    VL_SIG16(v__DOT__c1_mix,15,0);
    VL_SIG16(v__DOT__c2_mix,15,0);
    VL_SIG16(v__DOT__nz_mix,15,0);
    VL_SIG16(v__DOT__tone0__DOT__counter,9,0);
    VL_SIG16(v__DOT__tone1__DOT__counter,9,0);
    VL_SIG16(v__DOT__tone2__DOT__counter,9,0);
    VL_SIG16(v__DOT__noise__DOT__lfsr,15,0);
    VL_SIG16(v__DOT__noise__DOT__lfsr_next,15,0);
    VL_SIG16(v__DOT__noise__DOT__counter,11,0);
    //char	__VpadToAlign44[4];
    VL_SIG16(v__DOT__AMP_TABLE[32],15,0);
    //char	__VpadToAlign112[2];
    VL_SIG16(v__DOT__c_freq[3],9,0);
    VL_SIG8(v__DOT__c_amp[4],3,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vdlyvset__v__DOT__c_amp__v0,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__c_freq__v0,0,0);
    VL_SIG8(__Vdly__v__DOT__latch_chan,1,0);
    VL_SIG8(__Vdlyvset__v__DOT__c_freq__v1,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__c_amp__v4,0,0);
    VL_SIG8(__Vdly__v__DOT__tone2__DOT__phase,0,0);
    VL_SIG8(__VinpClk__TOP__v__DOT__noise_clear,0,0);
    VL_SIG8(__Vclklast__TOP__in_clk,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__v__DOT__noise_clear,0,0);
    VL_SIG8(__Vchglast__TOP__v__DOT__noise_clear,0,0);
    VL_SIG16(v__DOT____Vcellinp__tone0____pinNumber3,9,0);
    VL_SIG16(v__DOT____Vcellinp__tone1____pinNumber3,9,0);
    VL_SIG16(v__DOT____Vcellinp__tone2____pinNumber3,9,0);
    VL_SIG16(v__DOT____Vlvbound1,9,0);
    VL_SIG16(v__DOT____Vlvbound2,9,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vsn76489__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vsn76489& operator= (const Vsn76489&);	///< Copying not allowed
    Vsn76489(const Vsn76489&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vsn76489(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vsn76489();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vsn76489__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vsn76489__Syms* symsp, bool first);
  private:
    static IData	_change_request(Vsn76489__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__6(Vsn76489__Syms* __restrict vlSymsp);
    static void	_eval(Vsn76489__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vsn76489__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vsn76489__Syms* __restrict vlSymsp);
    static void	_initial__TOP(Vsn76489__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(Vsn76489__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__2(Vsn76489__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__3(Vsn76489__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__4(Vsn76489__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__7(Vsn76489__Syms* __restrict vlSymsp);
    static void	_settle__TOP__5(Vsn76489__Syms* __restrict vlSymsp);
    static void	_settle__TOP__8(Vsn76489__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
