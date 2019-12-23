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
    in_reg = VL_RAND_RESET_I(4);
    in_val = VL_RAND_RESET_I(8);
    in_wr = 0;
    out_lr = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    v__DOT__AMP_TABLE[__Vi0] = VL_RAND_RESET_I(16);
    }}
    v__DOT__OLD_WR = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    v__DOT__R[__Vi0] = VL_RAND_RESET_I(8);
    }}
    v__DOT__CA_FREQ = VL_RAND_RESET_I(12);
    v__DOT__CA_TONE = VL_RAND_RESET_I(12);
    v__DOT__CB_TONE = VL_RAND_RESET_I(12);
    v__DOT__CC_TONE = VL_RAND_RESET_I(12);
    v__DOT__CA_OUT = VL_RAND_RESET_I(1);
    v__DOT__CB_OUT = VL_RAND_RESET_I(1);
    v__DOT__CC_OUT = VL_RAND_RESET_I(1);
    v__DOT__CA_MIX = VL_RAND_RESET_I(16);
    v__DOT__CB_MIX = VL_RAND_RESET_I(16);
    v__DOT__CC_MIX = VL_RAND_RESET_I(16);
    v__DOT__CB_FREQ = VL_RAND_RESET_I(12);
    v__DOT__CC_FREQ = VL_RAND_RESET_I(12);
    v__DOT__CA_ENABLE = VL_RAND_RESET_I(1);
    v__DOT__CB_ENABLE = VL_RAND_RESET_I(1);
    v__DOT__CC_ENABLE = VL_RAND_RESET_I(1);
    v__DOT__CA_AMP = VL_RAND_RESET_I(4);
    v__DOT__CB_AMP = VL_RAND_RESET_I(4);
    v__DOT__CC_AMP = VL_RAND_RESET_I(4);
    v__DOT__MIX_OUT = VL_RAND_RESET_I(16);
    v__DOT__CLK_DIV = VL_RAND_RESET_I(4);
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

void Vrtl::_initial__TOP(Vrtl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vrtl::_initial__TOP\n"); );
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    //char	__VpadToAlign4[4];
    VL_SIGW(__Vtemp1,103,0,4);
    // Body
    // INITIAL at source/rtl.v:15
    __Vtemp1[0] = 0x2e747874;
    __Vtemp1[1] = 0x41424c45;
    __Vtemp1[2] = 0x4d505f54;
    __Vtemp1[3] = 0x41;
    VL_READMEM_W (true,16,32, 0,4, __Vtemp1, vlTOPp->v__DOT__AMP_TABLE
		  ,0,~0);
}

void Vrtl::_sequent__TOP__1(Vrtl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vrtl::_sequent__TOP__1\n"); );
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvset__v__DOT__R__v0,0,0);
    VL_SIG8(__Vdly__v__DOT__CA_OUT,0,0);
    VL_SIG8(__Vdly__v__DOT__CB_OUT,0,0);
    VL_SIG8(__Vdly__v__DOT__CC_OUT,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__R__v1,0,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__R__v9,3,0);
    VL_SIG8(__Vdlyvval__v__DOT__R__v9,7,0);
    VL_SIG8(__Vdlyvset__v__DOT__R__v9,0,0);
    VL_SIG8(__Vdly__v__DOT__CLK_DIV,3,0);
    VL_SIG8(__Vdly__v__DOT__OLD_WR,0,0);
    VL_SIG16(__Vdly__v__DOT__CA_TONE,11,0);
    VL_SIG16(__Vdly__v__DOT__CB_TONE,11,0);
    VL_SIG16(__Vdly__v__DOT__CC_TONE,11,0);
    // Body
    __Vdly__v__DOT__CA_TONE = vlTOPp->v__DOT__CA_TONE;
    __Vdly__v__DOT__CB_TONE = vlTOPp->v__DOT__CB_TONE;
    __Vdly__v__DOT__CC_TONE = vlTOPp->v__DOT__CC_TONE;
    __Vdly__v__DOT__CLK_DIV = vlTOPp->v__DOT__CLK_DIV;
    __Vdly__v__DOT__OLD_WR = vlTOPp->v__DOT__OLD_WR;
    __Vdly__v__DOT__CC_OUT = vlTOPp->v__DOT__CC_OUT;
    __Vdly__v__DOT__CA_OUT = vlTOPp->v__DOT__CA_OUT;
    __Vdly__v__DOT__CB_OUT = vlTOPp->v__DOT__CB_OUT;
    __Vdlyvset__v__DOT__R__v0 = 0;
    __Vdlyvset__v__DOT__R__v1 = 0;
    __Vdlyvset__v__DOT__R__v9 = 0;
    // ALWAYS at source/rtl.v:128
    vlTOPp->v__DOT__MIX_OUT = (0xffff & ((((IData)(vlTOPp->v__DOT__CC_ENABLE)
					    ? 0 : (IData)(vlTOPp->v__DOT__CC_MIX)) 
					  + ((IData)(vlTOPp->v__DOT__CB_ENABLE)
					      ? 0 : (IData)(vlTOPp->v__DOT__CB_MIX))) 
					 + ((IData)(vlTOPp->v__DOT__CA_ENABLE)
					     ? 0 : (IData)(vlTOPp->v__DOT__CA_MIX))));
    // ALWAYS at source/rtl.v:67
    if (vlTOPp->in_rst) {
	__Vdlyvset__v__DOT__R__v0 = 1;
	__Vdly__v__DOT__CA_TONE = 0;
	__Vdly__v__DOT__CA_OUT = 0;
	__Vdly__v__DOT__CB_TONE = 0;
	__Vdly__v__DOT__CB_OUT = 0;
	__Vdly__v__DOT__CC_TONE = 0;
	__Vdly__v__DOT__CC_OUT = 0;
	__Vdlyvset__v__DOT__R__v1 = 1;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__CLK_DIV))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__CA_TONE))) {
		__Vdly__v__DOT__CA_OUT = (1 & (~ (IData)(vlTOPp->v__DOT__CA_OUT)));
		__Vdly__v__DOT__CA_TONE = vlTOPp->v__DOT__CA_FREQ;
	    } else {
		__Vdly__v__DOT__CA_TONE = (0xfff & 
					   ((IData)(vlTOPp->v__DOT__CA_TONE) 
					    - (IData)(1)));
	    }
	    if ((0 == (IData)(vlTOPp->v__DOT__CB_TONE))) {
		__Vdly__v__DOT__CB_OUT = (1 & (~ (IData)(vlTOPp->v__DOT__CB_OUT)));
		__Vdly__v__DOT__CB_TONE = vlTOPp->v__DOT__CB_FREQ;
	    } else {
		__Vdly__v__DOT__CB_TONE = (0xfff & 
					   ((IData)(vlTOPp->v__DOT__CB_TONE) 
					    - (IData)(1)));
	    }
	    if ((0 == (IData)(vlTOPp->v__DOT__CC_TONE))) {
		__Vdly__v__DOT__CC_OUT = (1 & (~ (IData)(vlTOPp->v__DOT__CC_OUT)));
		__Vdly__v__DOT__CC_TONE = vlTOPp->v__DOT__CC_FREQ;
	    } else {
		__Vdly__v__DOT__CC_TONE = (0xfff & 
					   ((IData)(vlTOPp->v__DOT__CC_TONE) 
					    - (IData)(1)));
	    }
	}
	if (((IData)(vlTOPp->in_wr) & (~ (IData)(vlTOPp->v__DOT__OLD_WR)))) {
	    __Vdlyvval__v__DOT__R__v9 = vlTOPp->in_val;
	    __Vdlyvset__v__DOT__R__v9 = 1;
	    __Vdlyvdim0__v__DOT__R__v9 = vlTOPp->in_reg;
	}
    }
    __Vdly__v__DOT__CLK_DIV = (0xf & ((IData)(1) + (IData)(vlTOPp->v__DOT__CLK_DIV)));
    __Vdly__v__DOT__OLD_WR = vlTOPp->in_wr;
    vlTOPp->v__DOT__CA_TONE = __Vdly__v__DOT__CA_TONE;
    vlTOPp->v__DOT__CC_TONE = __Vdly__v__DOT__CC_TONE;
    vlTOPp->v__DOT__CB_TONE = __Vdly__v__DOT__CB_TONE;
    vlTOPp->v__DOT__CLK_DIV = __Vdly__v__DOT__CLK_DIV;
    vlTOPp->v__DOT__OLD_WR = __Vdly__v__DOT__OLD_WR;
    vlTOPp->v__DOT__CA_OUT = __Vdly__v__DOT__CA_OUT;
    vlTOPp->v__DOT__CB_OUT = __Vdly__v__DOT__CB_OUT;
    vlTOPp->v__DOT__CC_OUT = __Vdly__v__DOT__CC_OUT;
    // ALWAYSPOST at source/rtl.v:70
    if (__Vdlyvset__v__DOT__R__v0) {
	vlTOPp->v__DOT__R[0] = 0xff;
    }
    if (__Vdlyvset__v__DOT__R__v1) {
	vlTOPp->v__DOT__R[1] = 0xff;
	vlTOPp->v__DOT__R[3] = 0xff;
	vlTOPp->v__DOT__R[4] = 0xff;
	vlTOPp->v__DOT__R[5] = 0xff;
	vlTOPp->v__DOT__R[6] = 0xff;
	vlTOPp->v__DOT__R[0xa] = 0;
	vlTOPp->v__DOT__R[0xb] = 0;
	vlTOPp->v__DOT__R[0xc] = 0;
    }
    if (__Vdlyvset__v__DOT__R__v9) {
	vlTOPp->v__DOT__R[(IData)(__Vdlyvdim0__v__DOT__R__v9)] 
	    = __Vdlyvval__v__DOT__R__v9;
    }
    vlTOPp->out_lr = vlTOPp->v__DOT__MIX_OUT;
    vlTOPp->v__DOT__CA_FREQ = ((0xf00 & ((IData)(vlTOPp->v__DOT__R)
					 [1] << 8)) 
			       | (IData)(vlTOPp->v__DOT__R)
			       [0]);
    vlTOPp->v__DOT__CC_ENABLE = (1 & ((IData)(vlTOPp->v__DOT__R)
				      [7] >> 2));
    vlTOPp->v__DOT__CB_ENABLE = (1 & ((IData)(vlTOPp->v__DOT__R)
				      [7] >> 1));
    vlTOPp->v__DOT__CA_ENABLE = (1 & (IData)(vlTOPp->v__DOT__R)
				 [7]);
    vlTOPp->v__DOT__CC_FREQ = ((0xf00 & ((IData)(vlTOPp->v__DOT__R)
					 [5] << 8)) 
			       | (IData)(vlTOPp->v__DOT__R)
			       [4]);
    vlTOPp->v__DOT__CB_FREQ = ((0xf00 & ((IData)(vlTOPp->v__DOT__R)
					 [3] << 8)) 
			       | (IData)(vlTOPp->v__DOT__R)
			       [2]);
    vlTOPp->v__DOT__CB_AMP = (0xf & (IData)(vlTOPp->v__DOT__R)
			      [0xb]);
    vlTOPp->v__DOT__CC_AMP = (0xf & (IData)(vlTOPp->v__DOT__R)
			      [0xc]);
    vlTOPp->v__DOT__CA_AMP = (0xf & (IData)(vlTOPp->v__DOT__R)
			      [0xa]);
}

void Vrtl::_settle__TOP__2(Vrtl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vrtl::_settle__TOP__2\n"); );
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out_lr = vlTOPp->v__DOT__MIX_OUT;
    vlTOPp->v__DOT__CC_ENABLE = (1 & ((IData)(vlTOPp->v__DOT__R)
				      [7] >> 2));
    vlTOPp->v__DOT__CB_ENABLE = (1 & ((IData)(vlTOPp->v__DOT__R)
				      [7] >> 1));
    vlTOPp->v__DOT__CA_ENABLE = (1 & (IData)(vlTOPp->v__DOT__R)
				 [7]);
    vlTOPp->v__DOT__CC_FREQ = ((0xf00 & ((IData)(vlTOPp->v__DOT__R)
					 [5] << 8)) 
			       | (IData)(vlTOPp->v__DOT__R)
			       [4]);
    vlTOPp->v__DOT__CB_FREQ = ((0xf00 & ((IData)(vlTOPp->v__DOT__R)
					 [3] << 8)) 
			       | (IData)(vlTOPp->v__DOT__R)
			       [2]);
    vlTOPp->v__DOT__CA_FREQ = ((0xf00 & ((IData)(vlTOPp->v__DOT__R)
					 [1] << 8)) 
			       | (IData)(vlTOPp->v__DOT__R)
			       [0]);
    vlTOPp->v__DOT__CA_AMP = (0xf & (IData)(vlTOPp->v__DOT__R)
			      [0xa]);
    vlTOPp->v__DOT__CB_AMP = (0xf & (IData)(vlTOPp->v__DOT__R)
			      [0xb]);
    vlTOPp->v__DOT__CC_AMP = (0xf & (IData)(vlTOPp->v__DOT__R)
			      [0xc]);
    vlTOPp->v__DOT__CA_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__CA_OUT) << 4) | (IData)(vlTOPp->v__DOT__CA_AMP))];
    vlTOPp->v__DOT__CB_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__CB_OUT) << 4) | (IData)(vlTOPp->v__DOT__CB_AMP))];
    vlTOPp->v__DOT__CC_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__CC_OUT) << 4) | (IData)(vlTOPp->v__DOT__CC_AMP))];
}

void Vrtl::_sequent__TOP__3(Vrtl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vrtl::_sequent__TOP__3\n"); );
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__CA_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__CA_OUT) << 4) | (IData)(vlTOPp->v__DOT__CA_AMP))];
    vlTOPp->v__DOT__CB_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__CB_OUT) << 4) | (IData)(vlTOPp->v__DOT__CB_AMP))];
    vlTOPp->v__DOT__CC_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__CC_OUT) << 4) | (IData)(vlTOPp->v__DOT__CC_AMP))];
}

void Vrtl::_eval(Vrtl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vrtl::_eval\n"); );
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__in_clk = vlTOPp->in_clk;
}

void Vrtl::_eval_initial(Vrtl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vrtl::_eval_initial\n"); );
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP(vlSymsp);
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
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

IData Vrtl::_change_request(Vrtl__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vrtl::_change_request\n"); );
    Vrtl* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    return __req;
}
