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
    v__DOT__old_wr = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    v__DOT__c_freq[__Vi0] = VL_RAND_RESET_I(10);
    }}
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    v__DOT__c_tone[__Vi0] = VL_RAND_RESET_I(10);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    v__DOT__c_amp[__Vi0] = VL_RAND_RESET_I(4);
    }}
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    v__DOT__c_bit[__Vi0] = VL_RAND_RESET_I(1);
    }}
    v__DOT__lfsr = VL_RAND_RESET_I(16);
    v__DOT__clk_div = VL_RAND_RESET_I(8);
    v__DOT__latch_chan = VL_RAND_RESET_I(2);
    v__DOT__c0_mix = VL_RAND_RESET_I(16);
    v__DOT__c1_mix = VL_RAND_RESET_I(16);
    v__DOT__c2_mix = VL_RAND_RESET_I(16);
    v__DOT__nz_mix = VL_RAND_RESET_I(16);
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
    VL_SIG8(__Vdlyvset__v__DOT__c_amp__v0,0,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__c_freq__v0,1,0);
    VL_SIG8(__Vdlyvset__v__DOT__c_freq__v0,0,0);
    VL_SIG8(__Vdly__v__DOT__latch_chan,1,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__c_freq__v1,1,0);
    VL_SIG8(__Vdlyvset__v__DOT__c_freq__v1,0,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__c_amp__v4,1,0);
    VL_SIG8(__Vdlyvval__v__DOT__c_amp__v4,3,0);
    VL_SIG8(__Vdlyvset__v__DOT__c_amp__v4,0,0);
    VL_SIG8(__Vdlyvval__v__DOT__c_bit__v0,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__c_bit__v0,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__c_tone__v1,0,0);
    VL_SIG8(__Vdlyvval__v__DOT__c_bit__v1,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__c_bit__v1,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__c_tone__v3,0,0);
    VL_SIG8(__Vdlyvval__v__DOT__c_bit__v2,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__c_bit__v2,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__c_tone__v5,0,0);
    VL_SIG8(__Vdly__v__DOT__clk_div,7,0);
    VL_SIG8(__Vdly__v__DOT__old_wr,0,0);
    VL_SIG16(__Vdly__v__DOT__lfsr,15,0);
    VL_SIG16(__Vdlyvval__v__DOT__c_freq__v0,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__c_freq__v1,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__c_tone__v0,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__c_tone__v1,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__c_tone__v2,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__c_tone__v3,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__c_tone__v4,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__c_tone__v5,9,0);
    //char	__VpadToAlign82[2];
    // Body
    __Vdly__v__DOT__old_wr = vlTOPp->v__DOT__old_wr;
    __Vdly__v__DOT__latch_chan = vlTOPp->v__DOT__latch_chan;
    __Vdly__v__DOT__clk_div = vlTOPp->v__DOT__clk_div;
    __Vdly__v__DOT__lfsr = vlTOPp->v__DOT__lfsr;
    __Vdlyvset__v__DOT__c_freq__v0 = 0;
    __Vdlyvset__v__DOT__c_freq__v1 = 0;
    __Vdlyvset__v__DOT__c_amp__v0 = 0;
    __Vdlyvset__v__DOT__c_amp__v4 = 0;
    __Vdlyvset__v__DOT__c_tone__v1 = 0;
    __Vdlyvset__v__DOT__c_tone__v3 = 0;
    __Vdlyvset__v__DOT__c_tone__v5 = 0;
    __Vdlyvset__v__DOT__c_bit__v0 = 0;
    __Vdlyvset__v__DOT__c_bit__v1 = 0;
    __Vdlyvset__v__DOT__c_bit__v2 = 0;
    // ALWAYS at source/sn76489.v:64
    if (vlTOPp->in_rst) {
	__Vdlyvset__v__DOT__c_amp__v0 = 1;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__clk_div))) {
	    __Vdly__v__DOT__lfsr = (0xffff & ((0 == (IData)(vlTOPp->v__DOT__lfsr))
					       ? 1 : 
					      ((0x8000 
						& (((IData)(vlTOPp->v__DOT__lfsr) 
						    << 0xf) 
						   ^ 
						   (0xffff8000 
						    & ((IData)(vlTOPp->v__DOT__lfsr) 
						       << 0xc)))) 
					       | (0x7fff 
						  & ((IData)(vlTOPp->v__DOT__lfsr) 
						     >> 1)))));
	}
	if (((IData)(vlTOPp->in_wr) & (~ (IData)(vlTOPp->v__DOT__old_wr)))) {
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
						       (IData)(vlTOPp->v__DOT__c_freq)
						       [
						       (3 
							& ((IData)(vlTOPp->in_val) 
							   >> 5))]
						        : 0)) 
						   | (0xf 
						      & (IData)(vlTOPp->in_val)));
		    if (((3 & ((IData)(vlTOPp->in_val) 
			       >> 5)) <= 2)) {
			__Vdlyvval__v__DOT__c_freq__v0 
			    = vlTOPp->v__DOT____Vlvbound1;
			__Vdlyvset__v__DOT__c_freq__v0 = 1;
			__Vdlyvdim0__v__DOT__c_freq__v0 
			    = (3 & ((IData)(vlTOPp->in_val) 
				    >> 5));
		    }
		}
		__Vdly__v__DOT__latch_chan = (3 & ((IData)(vlTOPp->in_val) 
						   >> 5));
	    } else {
		if ((0 == (0x80 & (IData)(vlTOPp->in_val)))) {
		    if ((3 != (IData)(vlTOPp->v__DOT__latch_chan))) {
			vlTOPp->v__DOT____Vlvbound2 
			    = ((0x3f0 & ((IData)(vlTOPp->in_val) 
					 << 4)) | (0xf 
						   & (((IData)(vlTOPp->v__DOT__latch_chan) 
						       <= 2)
						       ? 
						      (IData)(vlTOPp->v__DOT__c_freq)
						      [(IData)(vlTOPp->v__DOT__latch_chan)]
						       : 0)));
			if (((IData)(vlTOPp->v__DOT__latch_chan) 
			     <= 2)) {
			    __Vdlyvval__v__DOT__c_freq__v1 
				= vlTOPp->v__DOT____Vlvbound2;
			    __Vdlyvset__v__DOT__c_freq__v1 = 1;
			    __Vdlyvdim0__v__DOT__c_freq__v1 
				= vlTOPp->v__DOT__latch_chan;
			}
		    }
		} else {
		    if ((0x90 == (0x90 & (IData)(vlTOPp->in_val)))) {
			__Vdlyvval__v__DOT__c_amp__v4 
			    = (0xf & (IData)(vlTOPp->in_val));
			__Vdlyvset__v__DOT__c_amp__v4 = 1;
			__Vdlyvdim0__v__DOT__c_amp__v4 
			    = (3 & ((IData)(vlTOPp->in_val) 
				    >> 5));
		    }
		}
	    }
	}
	if ((0 == (0xf & (IData)(vlTOPp->v__DOT__clk_div)))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__c_tone)
		 [0])) {
		__Vdlyvval__v__DOT__c_bit__v0 = (1 
						 & (~ 
						    (IData)(vlTOPp->v__DOT__c_bit)
						    [0]));
		__Vdlyvset__v__DOT__c_bit__v0 = 1;
		__Vdlyvval__v__DOT__c_tone__v0 = (IData)(vlTOPp->v__DOT__c_freq)
		    [0];
	    } else {
		__Vdlyvval__v__DOT__c_tone__v1 = (0x3ff 
						  & ((IData)(vlTOPp->v__DOT__c_tone)
						     [0] 
						     - (IData)(1)));
		__Vdlyvset__v__DOT__c_tone__v1 = 1;
	    }
	    if ((0 == (IData)(vlTOPp->v__DOT__c_tone)
		 [1])) {
		__Vdlyvval__v__DOT__c_bit__v1 = (1 
						 & (~ 
						    (IData)(vlTOPp->v__DOT__c_bit)
						    [1]));
		__Vdlyvset__v__DOT__c_bit__v1 = 1;
		__Vdlyvval__v__DOT__c_tone__v2 = (IData)(vlTOPp->v__DOT__c_freq)
		    [1];
	    } else {
		__Vdlyvval__v__DOT__c_tone__v3 = (0x3ff 
						  & ((IData)(vlTOPp->v__DOT__c_tone)
						     [1] 
						     - (IData)(1)));
		__Vdlyvset__v__DOT__c_tone__v3 = 1;
	    }
	    if ((0 == (IData)(vlTOPp->v__DOT__c_tone)
		 [2])) {
		__Vdlyvval__v__DOT__c_bit__v2 = (1 
						 & (~ 
						    (IData)(vlTOPp->v__DOT__c_bit)
						    [2]));
		__Vdlyvset__v__DOT__c_bit__v2 = 1;
		__Vdlyvval__v__DOT__c_tone__v4 = (IData)(vlTOPp->v__DOT__c_freq)
		    [2];
	    } else {
		__Vdlyvval__v__DOT__c_tone__v5 = (0x3ff 
						  & ((IData)(vlTOPp->v__DOT__c_tone)
						     [2] 
						     - (IData)(1)));
		__Vdlyvset__v__DOT__c_tone__v5 = 1;
	    }
	}
    }
    __Vdly__v__DOT__clk_div = (0xff & ((IData)(1) + (IData)(vlTOPp->v__DOT__clk_div)));
    __Vdly__v__DOT__old_wr = vlTOPp->in_wr;
    vlTOPp->v__DOT__old_wr = __Vdly__v__DOT__old_wr;
    vlTOPp->v__DOT__clk_div = __Vdly__v__DOT__clk_div;
    vlTOPp->v__DOT__latch_chan = __Vdly__v__DOT__latch_chan;
    // ALWAYSPOST at source/sn76489.v:83
    if (__Vdlyvset__v__DOT__c_freq__v0) {
	vlTOPp->v__DOT__c_freq[(IData)(__Vdlyvdim0__v__DOT__c_freq__v0)] 
	    = __Vdlyvval__v__DOT__c_freq__v0;
    }
    if (__Vdlyvset__v__DOT__c_freq__v1) {
	vlTOPp->v__DOT__c_freq[(IData)(__Vdlyvdim0__v__DOT__c_freq__v1)] 
	    = __Vdlyvval__v__DOT__c_freq__v1;
    }
    // ALWAYSPOST at source/sn76489.v:114
    if (__Vdlyvset__v__DOT__c_bit__v0) {
	vlTOPp->v__DOT__c_tone[0] = __Vdlyvval__v__DOT__c_tone__v0;
    }
    if (__Vdlyvset__v__DOT__c_tone__v1) {
	vlTOPp->v__DOT__c_tone[0] = __Vdlyvval__v__DOT__c_tone__v1;
    }
    if (__Vdlyvset__v__DOT__c_bit__v1) {
	vlTOPp->v__DOT__c_tone[1] = __Vdlyvval__v__DOT__c_tone__v2;
    }
    if (__Vdlyvset__v__DOT__c_tone__v3) {
	vlTOPp->v__DOT__c_tone[1] = __Vdlyvval__v__DOT__c_tone__v3;
    }
    if (__Vdlyvset__v__DOT__c_bit__v2) {
	vlTOPp->v__DOT__c_tone[2] = __Vdlyvval__v__DOT__c_tone__v4;
    }
    if (__Vdlyvset__v__DOT__c_tone__v5) {
	vlTOPp->v__DOT__c_tone[2] = __Vdlyvval__v__DOT__c_tone__v5;
    }
    vlTOPp->v__DOT__lfsr = __Vdly__v__DOT__lfsr;
    // ALWAYSPOST at source/sn76489.v:113
    if (__Vdlyvset__v__DOT__c_bit__v0) {
	vlTOPp->v__DOT__c_bit[0] = __Vdlyvval__v__DOT__c_bit__v0;
    }
    if (__Vdlyvset__v__DOT__c_bit__v1) {
	vlTOPp->v__DOT__c_bit[1] = __Vdlyvval__v__DOT__c_bit__v1;
    }
    if (__Vdlyvset__v__DOT__c_bit__v2) {
	vlTOPp->v__DOT__c_bit[2] = __Vdlyvval__v__DOT__c_bit__v2;
    }
    // ALWAYSPOST at source/sn76489.v:68
    if (__Vdlyvset__v__DOT__c_amp__v0) {
	vlTOPp->v__DOT__c_amp[0] = 0;
	vlTOPp->v__DOT__c_amp[1] = 0;
	vlTOPp->v__DOT__c_amp[2] = 0;
	vlTOPp->v__DOT__c_amp[3] = 0;
    }
    if (__Vdlyvset__v__DOT__c_amp__v4) {
	vlTOPp->v__DOT__c_amp[(IData)(__Vdlyvdim0__v__DOT__c_amp__v4)] 
	    = __Vdlyvval__v__DOT__c_amp__v4;
    }
    vlTOPp->v__DOT__c0_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__c_bit)[0] << 4) 
	  | (IData)(vlTOPp->v__DOT__c_amp)[0])];
    vlTOPp->v__DOT__c1_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__c_bit)[1] << 4) 
	  | (IData)(vlTOPp->v__DOT__c_amp)[1])];
    vlTOPp->v__DOT__c2_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__c_bit)[2] << 4) 
	  | (IData)(vlTOPp->v__DOT__c_amp)[2])];
    vlTOPp->v__DOT__nz_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__lfsr) << 4)) 
	  | (IData)(vlTOPp->v__DOT__c_amp)[3])];
}

void Vsn76489::_settle__TOP__2(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_settle__TOP__2\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__c0_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__c_bit)[0] << 4) 
	  | (IData)(vlTOPp->v__DOT__c_amp)[0])];
    vlTOPp->v__DOT__c1_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__c_bit)[1] << 4) 
	  | (IData)(vlTOPp->v__DOT__c_amp)[1])];
    vlTOPp->v__DOT__c2_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__c_bit)[2] << 4) 
	  | (IData)(vlTOPp->v__DOT__c_amp)[2])];
    vlTOPp->v__DOT__nz_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__lfsr) << 4)) 
	  | (IData)(vlTOPp->v__DOT__c_amp)[3])];
    vlTOPp->out_lr = (0xffff & ((((IData)(vlTOPp->v__DOT__c0_mix) 
				  + (IData)(vlTOPp->v__DOT__c1_mix)) 
				 + (IData)(vlTOPp->v__DOT__c2_mix)) 
				+ (IData)(vlTOPp->v__DOT__nz_mix)));
}

void Vsn76489::_sequent__TOP__3(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_sequent__TOP__3\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out_lr = (0xffff & ((((IData)(vlTOPp->v__DOT__c0_mix) 
				  + (IData)(vlTOPp->v__DOT__c1_mix)) 
				 + (IData)(vlTOPp->v__DOT__c2_mix)) 
				+ (IData)(vlTOPp->v__DOT__nz_mix)));
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
