// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vnesapu.h for the primary calling header

#include "Vnesapu.h"           // For This
#include "Vnesapu__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vnesapu) {
    Vnesapu__Syms* __restrict vlSymsp = __VlSymsp = new Vnesapu__Syms(this, name());
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    in_clk = 0;
    in_rst = 0;
    in_reg = VL_RAND_RESET_I(4);
    in_val = VL_RAND_RESET_I(8);
    in_wr = 0;
    out_lr = VL_RAND_RESET_I(16);
    __Vclklast__TOP__in_clk = 0;
}

void Vnesapu::__Vconfigure(Vnesapu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vnesapu::~Vnesapu() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vnesapu::eval() {
    Vnesapu__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vnesapu::eval\n"); );
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

void Vnesapu::_eval_initial_loop(Vnesapu__Syms* __restrict vlSymsp) {
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

void Vnesapu::_eval(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_eval\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Final
    vlTOPp->__Vclklast__TOP__in_clk = vlTOPp->in_clk;
}

void Vnesapu::_eval_initial(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_eval_initial\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vnesapu::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::final\n"); );
    // Variables
    Vnesapu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vnesapu::_eval_settle(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_eval_settle\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

IData Vnesapu::_change_request(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_change_request\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    return __req;
}
