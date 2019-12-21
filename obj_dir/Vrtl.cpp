// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrtl.h for the primary calling header

#include "Vrtl.h"              // For This
#include "Vrtl__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vrtl) {
    Vrtl__Syms* __restrict vlSymsp = __VlSymsp = new Vrtl__Syms(this, name());
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    in_clk = 0;
    in_rst = 0;
    in_reg = VL_RAND_RESET_I(8);
    in_val = VL_RAND_RESET_I(8);
    in_wr = 0;
    out_lr = VL_RAND_RESET_I(16);
    v__DOT__count = VL_RAND_RESET_I(16);
    __Vclklast__TOP__in_clk = 0;
}

void Vrtl::__Vconfigure(Vrtl__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vrtl::~Vrtl() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vrtl::eval() {
    Vrtl__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vrtl::eval\n"); );
    int __VclockLoop = 0;
    IData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
	vlSymsp->__Vm_activity = true;
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vrtl::_eval_initial_loop(Vrtl__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    IData __Vchange=1;
    while (VL_LIKELY(__Vchange)) {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	__Vchange = _change_request(vlSymsp);
	if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

void Vrtl::_sequent__TOP__1(Vrtl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vrtl::_sequent__TOP__1\n"); );
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG16(__Vdly__v__DOT__count,15,0);
    //char	__VpadToAlign6[2];
    // Body
    __Vdly__v__DOT__count = vlTOPp->v__DOT__count;
    // ALWAYS at source/rtl.v:12
    __Vdly__v__DOT__count = (0xffff & ((IData)(vlTOPp->in_rst)
				        ? 0 : ((IData)(1) 
					       + (IData)(vlTOPp->v__DOT__count))));
    vlTOPp->out_lr = vlTOPp->v__DOT__count;
    vlTOPp->v__DOT__count = __Vdly__v__DOT__count;
}

void Vrtl::_eval(Vrtl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vrtl::_eval\n"); );
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__in_clk = vlTOPp->in_clk;
}

void Vrtl::_eval_initial(Vrtl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vrtl::_eval_initial\n"); );
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vrtl::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vrtl::final\n"); );
    // Variables
    Vrtl__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vrtl::_eval_settle(Vrtl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vrtl::_eval_settle\n"); );
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

IData Vrtl::_change_request(Vrtl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vrtl::_change_request\n"); );
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    return __req;
}
