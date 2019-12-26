// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vym2149_H_
#define _Vym2149_H_

#include "verilated.h"
class Vym2149__Syms;

//----------

VL_MODULE(Vym2149) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(in_clk,0,0);
    VL_IN8(in_rst,0,0);
    VL_IN8(in_reg,3,0);
    VL_IN8(in_val,7,0);
    VL_IN8(in_wr,0,0);
    //char	__VpadToAlign5[1];
    VL_OUT16(out_lr,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    VL_SIG8(v__DOT__old_wr,0,0);
    VL_SIG8(v__DOT__ca_bit,0,0);
    VL_SIG8(v__DOT__cb_bit,0,0);
    VL_SIG8(v__DOT__cc_bit,0,0);
    VL_SIG8(v__DOT__ca_tone_enable,0,0);
    VL_SIG8(v__DOT__cb_tone_enable,0,0);
    VL_SIG8(v__DOT__cc_tone_enable,0,0);
    VL_SIG8(v__DOT__ca_lfsr_enable,0,0);
    VL_SIG8(v__DOT__cb_lfsr_enable,0,0);
    VL_SIG8(v__DOT__cc_lfsr_enable,0,0);
    VL_SIG8(v__DOT__ca_amp,3,0);
    VL_SIG8(v__DOT__cb_amp,3,0);
    VL_SIG8(v__DOT__cc_amp,3,0);
    VL_SIG8(v__DOT__clk_div,2,0);
    VL_SIG8(v__DOT__noz_div,2,0);
    //char	__VpadToAlign27[1];
    VL_SIG16(v__DOT__ca_freq,11,0);
    VL_SIG16(v__DOT__cb_freq,11,0);
    VL_SIG16(v__DOT__cc_freq,11,0);
    VL_SIG16(v__DOT__ca_tone,11,0);
    VL_SIG16(v__DOT__cb_tone,11,0);
    VL_SIG16(v__DOT__cc_tone,11,0);
    VL_SIG16(v__DOT__ca_mix,15,0);
    VL_SIG16(v__DOT__cb_mix,15,0);
    VL_SIG16(v__DOT__cc_mix,15,0);
    //char	__VpadToAlign46[2];
    VL_SIG(v__DOT__lfsr,16,0);
    //char	__VpadToAlign52[4];
    VL_SIG16(v__DOT__AMP_TABLE[32],15,0);
    VL_SIG8(v__DOT__r[16],7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__in_clk,0,0);
    //char	__VpadToAlign141[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    //char	__VpadToAlign148[4];
    Vym2149__Syms*	__VlSymsp;		// Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    Vym2149& operator= (const Vym2149&);	///< Copying not allowed
    Vym2149(const Vym2149&);	///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible WRT DPI scope names.
    Vym2149(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vym2149();
    
    // USER METHODS
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vym2149__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vym2149__Syms* symsp, bool first);
  private:
    static IData	_change_request(Vym2149__Syms* __restrict vlSymsp);
  public:
    static void	_eval(Vym2149__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vym2149__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vym2149__Syms* __restrict vlSymsp);
    static void	_initial__TOP(Vym2149__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__1(Vym2149__Syms* __restrict vlSymsp);
    static void	_sequent__TOP__3(Vym2149__Syms* __restrict vlSymsp);
    static void	_settle__TOP__2(Vym2149__Syms* __restrict vlSymsp);
    static void	_settle__TOP__4(Vym2149__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
