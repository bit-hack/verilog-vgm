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
    in_val = VL_RAND_RESET_I(8);
    in_wr = 0;
    out_lr = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    v__DOT__AMP_TABLE[__Vi0] = VL_RAND_RESET_I(16);
    }}
    v__DOT__OLD_WR = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    v__DOT__C_FREQ[__Vi0] = VL_RAND_RESET_I(10);
    }}
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    v__DOT__C_TONE[__Vi0] = VL_RAND_RESET_I(10);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    v__DOT__C_AMP[__Vi0] = VL_RAND_RESET_I(4);
    }}
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    v__DOT__C_BIT[__Vi0] = VL_RAND_RESET_I(1);
    }}
    v__DOT__CLK_DIV = VL_RAND_RESET_I(4);
    v__DOT__LATCH_CHAN = VL_RAND_RESET_I(2);
    v__DOT__C0_MIX = VL_RAND_RESET_I(16);
    v__DOT__C1_MIX = VL_RAND_RESET_I(16);
    v__DOT__C2_MIX = VL_RAND_RESET_I(16);
    v__DOT____Vlvbound1 = 0;
    v__DOT____Vlvbound2 = 0;
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
    // INITIAL at source/sn76489.v:14
    __Vtemp1[0] = 0x2e747874;
    __Vtemp1[1] = 0x5f646163;
    __Vtemp1[2] = 0x36343839;
    __Vtemp1[3] = 0x736e37;
    VL_READMEM_W (true,16,32, 0,4, __Vtemp1, vlTOPp->v__DOT__AMP_TABLE
		  ,0,~0);
}

void Vsn76489::_sequent__TOP__1(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_sequent__TOP__1\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvset__v__DOT__C_AMP__v0,0,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__C_FREQ__v0,1,0);
    VL_SIG8(__Vdlyvset__v__DOT__C_FREQ__v0,0,0);
    VL_SIG8(__Vdly__v__DOT__LATCH_CHAN,1,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__C_FREQ__v1,1,0);
    VL_SIG8(__Vdlyvset__v__DOT__C_FREQ__v1,0,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__C_AMP__v4,1,0);
    VL_SIG8(__Vdlyvval__v__DOT__C_AMP__v4,3,0);
    VL_SIG8(__Vdlyvset__v__DOT__C_AMP__v4,0,0);
    VL_SIG8(__Vdlyvval__v__DOT__C_BIT__v0,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__C_BIT__v0,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__C_TONE__v1,0,0);
    VL_SIG8(__Vdlyvval__v__DOT__C_BIT__v1,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__C_BIT__v1,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__C_TONE__v3,0,0);
    VL_SIG8(__Vdlyvval__v__DOT__C_BIT__v2,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__C_BIT__v2,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__C_TONE__v5,0,0);
    VL_SIG8(__Vdly__v__DOT__CLK_DIV,3,0);
    VL_SIG8(__Vdly__v__DOT__OLD_WR,0,0);
    VL_SIG16(__Vdlyvval__v__DOT__C_FREQ__v0,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__C_FREQ__v1,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__C_TONE__v0,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__C_TONE__v1,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__C_TONE__v2,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__C_TONE__v3,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__C_TONE__v4,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__C_TONE__v5,9,0);
    // Body
    __Vdly__v__DOT__CLK_DIV = vlTOPp->v__DOT__CLK_DIV;
    __Vdly__v__DOT__LATCH_CHAN = vlTOPp->v__DOT__LATCH_CHAN;
    __Vdly__v__DOT__OLD_WR = vlTOPp->v__DOT__OLD_WR;
    __Vdlyvset__v__DOT__C_FREQ__v0 = 0;
    __Vdlyvset__v__DOT__C_FREQ__v1 = 0;
    __Vdlyvset__v__DOT__C_AMP__v0 = 0;
    __Vdlyvset__v__DOT__C_AMP__v4 = 0;
    __Vdlyvset__v__DOT__C_TONE__v1 = 0;
    __Vdlyvset__v__DOT__C_TONE__v3 = 0;
    __Vdlyvset__v__DOT__C_TONE__v5 = 0;
    __Vdlyvset__v__DOT__C_BIT__v0 = 0;
    __Vdlyvset__v__DOT__C_BIT__v1 = 0;
    __Vdlyvset__v__DOT__C_BIT__v2 = 0;
    // ALWAYS at source/sn76489.v:47
    if (vlTOPp->in_rst) {
	__Vdlyvset__v__DOT__C_AMP__v0 = 1;
    } else {
	if (((IData)(vlTOPp->in_wr) & (~ (IData)(vlTOPp->v__DOT__OLD_WR)))) {
	    if ((0x80 == (0x90 & (IData)(vlTOPp->in_val)))) {
		if ((3 != (3 & ((IData)(vlTOPp->in_val) 
				>> 5)))) {
		    vlTOPp->v__DOT____Vlvbound1 = (
						   (0x3f0 
						    & (((3 
							 & ((IData)(vlTOPp->in_val) 
							    >> 5)) 
							<= 2)
						        ? 
						       (IData)(vlTOPp->v__DOT__C_FREQ)
						       [
						       (3 
							& ((IData)(vlTOPp->in_val) 
							   >> 5))]
						        : 0)) 
						   | (0xf 
						      & (IData)(vlTOPp->in_val)));
		    if (((3 & ((IData)(vlTOPp->in_val) 
			       >> 5)) <= 2)) {
			__Vdlyvval__v__DOT__C_FREQ__v0 
			    = vlTOPp->v__DOT____Vlvbound1;
			__Vdlyvset__v__DOT__C_FREQ__v0 = 1;
			__Vdlyvdim0__v__DOT__C_FREQ__v0 
			    = (3 & ((IData)(vlTOPp->in_val) 
				    >> 5));
		    }
		}
		__Vdly__v__DOT__LATCH_CHAN = (3 & ((IData)(vlTOPp->in_val) 
						   >> 5));
	    } else {
		if ((0 == (0x80 & (IData)(vlTOPp->in_val)))) {
		    if ((3 != (IData)(vlTOPp->v__DOT__LATCH_CHAN))) {
			vlTOPp->v__DOT____Vlvbound2 
			    = ((0x3f0 & ((IData)(vlTOPp->in_val) 
					 << 4)) | (0xf 
						   & (((IData)(vlTOPp->v__DOT__LATCH_CHAN) 
						       <= 2)
						       ? 
						      (IData)(vlTOPp->v__DOT__C_FREQ)
						      [(IData)(vlTOPp->v__DOT__LATCH_CHAN)]
						       : 0)));
			if (((IData)(vlTOPp->v__DOT__LATCH_CHAN) 
			     <= 2)) {
			    __Vdlyvval__v__DOT__C_FREQ__v1 
				= vlTOPp->v__DOT____Vlvbound2;
			    __Vdlyvset__v__DOT__C_FREQ__v1 = 1;
			    __Vdlyvdim0__v__DOT__C_FREQ__v1 
				= vlTOPp->v__DOT__LATCH_CHAN;
			}
		    }
		} else {
		    if ((0x90 == (0x90 & (IData)(vlTOPp->in_val)))) {
			__Vdlyvval__v__DOT__C_AMP__v4 
			    = (0xf & (IData)(vlTOPp->in_val));
			__Vdlyvset__v__DOT__C_AMP__v4 = 1;
			__Vdlyvdim0__v__DOT__C_AMP__v4 
			    = (3 & ((IData)(vlTOPp->in_val) 
				    >> 5));
		    }
		}
	    }
	}
	if ((0 == (IData)(vlTOPp->v__DOT__CLK_DIV))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__C_TONE)
		 [0])) {
		__Vdlyvval__v__DOT__C_BIT__v0 = (1 
						 & (~ 
						    (IData)(vlTOPp->v__DOT__C_BIT)
						    [0]));
		__Vdlyvset__v__DOT__C_BIT__v0 = 1;
		__Vdlyvval__v__DOT__C_TONE__v0 = (IData)(vlTOPp->v__DOT__C_FREQ)
		    [0];
	    } else {
		__Vdlyvval__v__DOT__C_TONE__v1 = (0x3ff 
						  & ((IData)(vlTOPp->v__DOT__C_TONE)
						     [0] 
						     - (IData)(1)));
		__Vdlyvset__v__DOT__C_TONE__v1 = 1;
	    }
	    if ((0 == (IData)(vlTOPp->v__DOT__C_TONE)
		 [1])) {
		__Vdlyvval__v__DOT__C_BIT__v1 = (1 
						 & (~ 
						    (IData)(vlTOPp->v__DOT__C_BIT)
						    [1]));
		__Vdlyvset__v__DOT__C_BIT__v1 = 1;
		__Vdlyvval__v__DOT__C_TONE__v2 = (IData)(vlTOPp->v__DOT__C_FREQ)
		    [1];
	    } else {
		__Vdlyvval__v__DOT__C_TONE__v3 = (0x3ff 
						  & ((IData)(vlTOPp->v__DOT__C_TONE)
						     [1] 
						     - (IData)(1)));
		__Vdlyvset__v__DOT__C_TONE__v3 = 1;
	    }
	    if ((0 == (IData)(vlTOPp->v__DOT__C_TONE)
		 [2])) {
		__Vdlyvval__v__DOT__C_BIT__v2 = (1 
						 & (~ 
						    (IData)(vlTOPp->v__DOT__C_BIT)
						    [2]));
		__Vdlyvset__v__DOT__C_BIT__v2 = 1;
		__Vdlyvval__v__DOT__C_TONE__v4 = (IData)(vlTOPp->v__DOT__C_FREQ)
		    [2];
	    } else {
		__Vdlyvval__v__DOT__C_TONE__v5 = (0x3ff 
						  & ((IData)(vlTOPp->v__DOT__C_TONE)
						     [2] 
						     - (IData)(1)));
		__Vdlyvset__v__DOT__C_TONE__v5 = 1;
	    }
	}
    }
    __Vdly__v__DOT__CLK_DIV = (0xf & ((IData)(1) + (IData)(vlTOPp->v__DOT__CLK_DIV)));
    __Vdly__v__DOT__OLD_WR = vlTOPp->in_wr;
    vlTOPp->v__DOT__OLD_WR = __Vdly__v__DOT__OLD_WR;
    vlTOPp->v__DOT__CLK_DIV = __Vdly__v__DOT__CLK_DIV;
    vlTOPp->v__DOT__LATCH_CHAN = __Vdly__v__DOT__LATCH_CHAN;
    // ALWAYSPOST at source/sn76489.v:66
    if (__Vdlyvset__v__DOT__C_FREQ__v0) {
	vlTOPp->v__DOT__C_FREQ[(IData)(__Vdlyvdim0__v__DOT__C_FREQ__v0)] 
	    = __Vdlyvval__v__DOT__C_FREQ__v0;
    }
    if (__Vdlyvset__v__DOT__C_FREQ__v1) {
	vlTOPp->v__DOT__C_FREQ[(IData)(__Vdlyvdim0__v__DOT__C_FREQ__v1)] 
	    = __Vdlyvval__v__DOT__C_FREQ__v1;
    }
    // ALWAYSPOST at source/sn76489.v:87
    if (__Vdlyvset__v__DOT__C_BIT__v0) {
	vlTOPp->v__DOT__C_TONE[0] = __Vdlyvval__v__DOT__C_TONE__v0;
    }
    if (__Vdlyvset__v__DOT__C_TONE__v1) {
	vlTOPp->v__DOT__C_TONE[0] = __Vdlyvval__v__DOT__C_TONE__v1;
    }
    if (__Vdlyvset__v__DOT__C_BIT__v1) {
	vlTOPp->v__DOT__C_TONE[1] = __Vdlyvval__v__DOT__C_TONE__v2;
    }
    if (__Vdlyvset__v__DOT__C_TONE__v3) {
	vlTOPp->v__DOT__C_TONE[1] = __Vdlyvval__v__DOT__C_TONE__v3;
    }
    if (__Vdlyvset__v__DOT__C_BIT__v2) {
	vlTOPp->v__DOT__C_TONE[2] = __Vdlyvval__v__DOT__C_TONE__v4;
    }
    if (__Vdlyvset__v__DOT__C_TONE__v5) {
	vlTOPp->v__DOT__C_TONE[2] = __Vdlyvval__v__DOT__C_TONE__v5;
    }
    // ALWAYSPOST at source/sn76489.v:51
    if (__Vdlyvset__v__DOT__C_AMP__v0) {
	vlTOPp->v__DOT__C_AMP[0] = 0;
	vlTOPp->v__DOT__C_AMP[1] = 0;
	vlTOPp->v__DOT__C_AMP[2] = 0;
	vlTOPp->v__DOT__C_AMP[3] = 0;
    }
    if (__Vdlyvset__v__DOT__C_AMP__v4) {
	vlTOPp->v__DOT__C_AMP[(IData)(__Vdlyvdim0__v__DOT__C_AMP__v4)] 
	    = __Vdlyvval__v__DOT__C_AMP__v4;
    }
    // ALWAYSPOST at source/sn76489.v:86
    if (__Vdlyvset__v__DOT__C_BIT__v0) {
	vlTOPp->v__DOT__C_BIT[0] = __Vdlyvval__v__DOT__C_BIT__v0;
    }
    if (__Vdlyvset__v__DOT__C_BIT__v1) {
	vlTOPp->v__DOT__C_BIT[1] = __Vdlyvval__v__DOT__C_BIT__v1;
    }
    if (__Vdlyvset__v__DOT__C_BIT__v2) {
	vlTOPp->v__DOT__C_BIT[2] = __Vdlyvval__v__DOT__C_BIT__v2;
    }
    vlTOPp->v__DOT__C0_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__C_BIT)[0] << 4) 
	  | (IData)(vlTOPp->v__DOT__C_AMP)[0])];
    vlTOPp->v__DOT__C1_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__C_BIT)[1] << 4) 
	  | (IData)(vlTOPp->v__DOT__C_AMP)[1])];
    vlTOPp->v__DOT__C2_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__C_BIT)[2] << 4) 
	  | (IData)(vlTOPp->v__DOT__C_AMP)[2])];
}

void Vsn76489::_settle__TOP__2(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_settle__TOP__2\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__C0_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__C_BIT)[0] << 4) 
	  | (IData)(vlTOPp->v__DOT__C_AMP)[0])];
    vlTOPp->v__DOT__C1_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__C_BIT)[1] << 4) 
	  | (IData)(vlTOPp->v__DOT__C_AMP)[1])];
    vlTOPp->v__DOT__C2_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__C_BIT)[2] << 4) 
	  | (IData)(vlTOPp->v__DOT__C_AMP)[2])];
    vlTOPp->out_lr = (0xffff & (((IData)(vlTOPp->v__DOT__C0_MIX) 
				 + (IData)(vlTOPp->v__DOT__C1_MIX)) 
				+ (IData)(vlTOPp->v__DOT__C2_MIX)));
}

void Vsn76489::_sequent__TOP__3(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_sequent__TOP__3\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out_lr = (0xffff & (((IData)(vlTOPp->v__DOT__C0_MIX) 
				 + (IData)(vlTOPp->v__DOT__C1_MIX)) 
				+ (IData)(vlTOPp->v__DOT__C2_MIX)));
}

void Vsn76489::_eval(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_eval\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
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
    vlTOPp->_settle__TOP__2(vlSymsp);
}

IData Vsn76489::_change_request(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_change_request\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    return __req;
}
