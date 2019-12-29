// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vym3812.h for the primary calling header

#include "Vym3812.h"           // For This
#include "Vym3812__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vym3812) {
    Vym3812__Syms* __restrict vlSymsp = __VlSymsp = new Vym3812__Syms(this, name());
    Vym3812* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    in_clk = 0;
    in_rst = 0;
    in_reg = VL_RAND_RESET_I(8);
    in_val = VL_RAND_RESET_I(8);
    in_wr = 0;
    out_lr = VL_RAND_RESET_I(16);
    __Vclklast__TOP__in_clk = 0;
}

void Vym3812::__Vconfigure(Vym3812__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vym3812::~Vym3812() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vym3812::eval() {
    Vym3812__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vym3812* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vym3812::eval\n"); );
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

void Vym3812::_eval_initial_loop(Vym3812__Syms* __restrict vlSymsp) {
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

void Vym3812::_eval(Vym3812__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym3812::_eval\n"); );
    Vym3812* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Final
    vlTOPp->__Vclklast__TOP__in_clk = vlTOPp->in_clk;
}

void Vym3812::_eval_initial(Vym3812__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym3812::_eval_initial\n"); );
    Vym3812* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vym3812::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vym3812::final\n"); );
    // Variables
    Vym3812__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vym3812* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vym3812::_eval_settle(Vym3812__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym3812::_eval_settle\n"); );
    Vym3812* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

IData Vym3812::_change_request(Vym3812__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym3812::_change_request\n"); );
    Vym3812* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    return __req;
}
