// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vgbdmg_H_
#define _Vgbdmg_H_

#include "verilated.h"
class Vgbdmg__Syms;

//----------

VL_MODULE(Vgbdmg) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(in_clk,0,0);
    VL_IN8(in_rst,0,0);
    VL_IN8(in_reg,5,0);
    VL_IN8(in_val,7,0);
    VL_IN8(in_wr,0,0);
    //char	__VpadToAlign5[1];
    VL_OUT16(out_lr,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT__trigger_env0,0,0);
    VL_SIG8(v__DOT__trigger_env1,0,0);
    VL_SIG8(v__DOT__trigger_env2,0,0);
    VL_SIG8(v__DOT__wr_old,0,0);
    VL_SIG8(v__DOT__wr_posedge,0,0);
    VL_SIG8(v__DOT__frame_seq,2,0);
    VL_SIG8(v__DOT__tick_env,0,0);
    VL_SIG8(v__DOT__noise__DOT__xor_bit,0,0);
    VL_SIG8(v__DOT__env2__DOT__value,3,0);
    VL_SIG8(v__DOT__env2__DOT__clk_div,2,0);
    VL_SIG16(v__DOT__noise_mix,15,0);
    VL_SIG16(v__DOT__frame_clk_div,9,0);
    VL_SIG16(v__DOT__noise__DOT__period_dec,10,0);
    VL_SIG16(v__DOT__noise__DOT__counter,10,0);
    VL_SIG16(v__DOT__noise__DOT__lfsr,14,0);
    VL_SIG16(v__DOT__AMP_TABLE[32],15,0);
    VL_SIG8(v__DOT__r[64],7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT____Vcellinp__noise____pinNumber5,0,0);
    VL_SIG8(v__DOT____Vcellinp__noise____pinNumber4,2,0);
    VL_SIG8(v__DOT____Vcellinp__noise____pinNumber3,3,0);
    VL_SIG8(v__DOT____Vcellinp__env2____pinNumber5,0,0);
    VL_SIG8(v__DOT____Vcellinp__env2____pinNumber4,2,0);
    VL_SIG8(v__DOT____Vcellinp__env2____pinNumber3,3,0);
    VL_SIG8(__Vdlyvset__v__DOT__r__v0,0,0);
    VL_SIG8(__VinpClk__TOP__v__DOT__trigger_env2,0,0);
    VL_SIG8(__VinpClk__TOP__v__DOT__trigger_env0,0,0);
    VL_SIG8(__VinpClk__TOP__v__DOT__trigger_env1,0,0);
    VL_SIG8(__Vclklast__TOP__in_clk,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env2,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env0,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env1,0,0);
    VL_SIG8(__Vchglast__TOP__v__DOT__trigger_env0,0,0);
    VL_SIG8(__Vchglast__TOP__v__DOT__trigger_env1,0,0);
    VL_SIG8(__Vchglast__TOP__v__DOT__trigger_env2,0,0);
    //char	__VpadToAlign181[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign188[4];
    Vgbdmg__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vgbdmg& operator= (const Vgbdmg&);	///< Copying not allowed
    Vgbdmg(const Vgbdmg&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vgbdmg(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vgbdmg();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vgbdmg__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vgbdmg__Syms* symsp, bool first);
  private:
    static IData	_change_request(Vgbdmg__Syms* __restrict vlSymsp);
  public:
    static void	_combo__TOP__8(Vgbdmg__Syms* __restrict vlSymsp);
    static void	_eval(Vgbdmg__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vgbdmg__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vgbdmg__Syms* __restrict vlSymsp);
    static void	_initial__TOP(Vgbdmg__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(Vgbdmg__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__2(Vgbdmg__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__4(Vgbdmg__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__5(Vgbdmg__Syms* __restrict vlSymsp);
    static void	_settle__TOP__3(Vgbdmg__Syms* __restrict vlSymsp);
    static void	_settle__TOP__9(Vgbdmg__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
