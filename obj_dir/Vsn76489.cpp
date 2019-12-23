// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsn76489.h for the primary calling header

#include "Vsn76489.h"          // For This
#include "Vsn76489__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vsn76489) {
    Vsn76489__Syms* __restrict vlSymsp = __VlSymsp = new Vsn76489__Syms(this, name());
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    in_clk = 0;
    in_rst = 0;
    in_reg = VL_RAND_RESET_I(4);
    in_val = VL_RAND_RESET_I(8);
    in_wr = 0;
    out_lr = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    v__DOT__AMP_TABLE[__Vi0] = VL_RAND_RESET_I(16);
    }}
    v__DOT__MIX_OUT = VL_RAND_RESET_I(16);
    __Vclklast__TOP__in_clk = 0;
}

void Vsn76489::__Vconfigure(Vsn76489__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vsn76489::~Vsn76489() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vsn76489::eval() {
    Vsn76489__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vsn76489::eval\n"); );
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

void Vsn76489::_eval_initial_loop(Vsn76489__Syms* __restrict vlSymsp) {
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

void Vsn76489::_initial__TOP(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_initial__TOP\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    //char	__VpadToAlign4[4];
    VL_SIGW(__Vtemp1,119,0,4);
    // Body
    // INITIAL at source/sn76489.v:15
    __Vtemp1[0] = 0x2e747874;
    __Vtemp1[1] = 0x5f646163;
    __Vtemp1[2] = 0x36343839;
    __Vtemp1[3] = 0x736e37;
    VL_READMEM_W (true,16,32, 0,4, __Vtemp1, vlTOPp->v__DOT__AMP_TABLE
		  ,0,~0);
}

void Vsn76489::_settle__TOP__1(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_settle__TOP__1\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out_lr = vlTOPp->v__DOT__MIX_OUT;
}

void Vsn76489::_eval(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_eval\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Final
    vlTOPp->__Vclklast__TOP__in_clk = vlTOPp->in_clk;
}

void Vsn76489::_eval_initial(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_eval_initial\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP(vlSymsp);
}

void Vsn76489::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::final\n"); );
    // Variables
    Vsn76489__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsn76489::_eval_settle(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_eval_settle\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
}

IData Vsn76489::_change_request(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_change_request\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    return __req;
}
