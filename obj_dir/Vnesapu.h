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
    VL_IN8(in_reg,3,0);
    VL_IN8(in_val,7,0);
    VL_IN8(in_wr,0,0);
    //char	__VpadToAlign5[1];
    VL_OUT16(out_lr,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    VL_SIG8(__Vclklast__TOP__in_clk,0,0);
    //char	__VpadToAlign17[3];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
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
    static void	_eval(Vnesapu__Syms* __restrict vlSymsp);
    static void	_eval_initial(Vnesapu__Syms* __restrict vlSymsp);
    static void	_eval_settle(Vnesapu__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif  /*guard*/
