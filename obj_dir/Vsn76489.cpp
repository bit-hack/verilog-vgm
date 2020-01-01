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
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    v__DOT__c_amp[__Vi0] = VL_RAND_RESET_I(4);
    }}
    v__DOT____Vcellinp__tone0____pinNumber3 = VL_RAND_RESET_I(10);
    v__DOT____Vcellinp__tone1____pinNumber3 = VL_RAND_RESET_I(10);
    v__DOT____Vcellinp__tone2____pinNumber3 = VL_RAND_RESET_I(10);
    v__DOT__noise_shift = VL_RAND_RESET_I(2);
    v__DOT__noise_fb = VL_RAND_RESET_I(1);
    v__DOT__noise_clear = VL_RAND_RESET_I(1);
    v__DOT__clk_div = VL_RAND_RESET_I(4);
    v__DOT__latch_chan = VL_RAND_RESET_I(2);
    v__DOT__c0_mix = VL_RAND_RESET_I(16);
    v__DOT__c1_mix = VL_RAND_RESET_I(16);
    v__DOT__c2_mix = VL_RAND_RESET_I(16);
    v__DOT__nz_mix = VL_RAND_RESET_I(16);
    v__DOT__posedge_wr = VL_RAND_RESET_I(1);
    v__DOT____Vlvbound1 = 0;
    v__DOT____Vlvbound2 = 0;
    v__DOT__tone0__DOT__phase = VL_RAND_RESET_I(1);
    v__DOT__tone0__DOT__counter = VL_RAND_RESET_I(10);
    v__DOT__tone1__DOT__phase = VL_RAND_RESET_I(1);
    v__DOT__tone1__DOT__counter = VL_RAND_RESET_I(10);
    v__DOT__tone2__DOT__phase = VL_RAND_RESET_I(1);
    v__DOT__tone2__DOT__counter = VL_RAND_RESET_I(10);
    v__DOT__noise__DOT__lfsr = VL_RAND_RESET_I(16);
    v__DOT__noise__DOT__lfsr_next = VL_RAND_RESET_I(16);
    v__DOT__noise__DOT__counter = VL_RAND_RESET_I(12);
    v__DOT__noise__DOT__old_tone2 = VL_RAND_RESET_I(1);
    __Vdlyvset__v__DOT__c_amp__v0 = 0;
    __Vdlyvset__v__DOT__c_freq__v0 = 0;
    __Vdly__v__DOT__latch_chan = VL_RAND_RESET_I(2);
    __Vdlyvset__v__DOT__c_freq__v1 = 0;
    __Vdlyvset__v__DOT__c_amp__v4 = 0;
    __Vdly__v__DOT__tone2__DOT__phase = VL_RAND_RESET_I(1);
    __VinpClk__TOP__v__DOT__noise_clear = VL_RAND_RESET_I(1);
    __Vclklast__TOP__in_clk = 0;
    __Vclklast__TOP____VinpClk__TOP__v__DOT__noise_clear = 0;
    __Vchglast__TOP__v__DOT__noise_clear = VL_RAND_RESET_I(1);
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
    // INITIAL at source/sn76489.v:99
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
    VL_SIG8(__Vdly__v__DOT__clk_div,3,0);
    VL_SIG8(__Vdly__v__DOT__tone0__DOT__phase,0,0);
    VL_SIG8(__Vdly__v__DOT__tone1__DOT__phase,0,0);
    //char	__VpadToAlign47[1];
    VL_SIG16(__Vdly__v__DOT__tone0__DOT__counter,9,0);
    VL_SIG16(__Vdly__v__DOT__tone1__DOT__counter,9,0);
    VL_SIG16(__Vdly__v__DOT__tone2__DOT__counter,9,0);
    //char	__VpadToAlign54[2];
    // Body
    __Vdly__v__DOT__clk_div = vlTOPp->v__DOT__clk_div;
    __Vdly__v__DOT__tone0__DOT__counter = vlTOPp->v__DOT__tone0__DOT__counter;
    __Vdly__v__DOT__tone1__DOT__counter = vlTOPp->v__DOT__tone1__DOT__counter;
    __Vdly__v__DOT__tone2__DOT__counter = vlTOPp->v__DOT__tone2__DOT__counter;
    __Vdly__v__DOT__tone1__DOT__phase = vlTOPp->v__DOT__tone1__DOT__phase;
    __Vdly__v__DOT__tone0__DOT__phase = vlTOPp->v__DOT__tone0__DOT__phase;
    vlTOPp->__Vdly__v__DOT__tone2__DOT__phase = vlTOPp->v__DOT__tone2__DOT__phase;
    vlTOPp->__Vdly__v__DOT__latch_chan = vlTOPp->v__DOT__latch_chan;
    vlTOPp->__Vdlyvset__v__DOT__c_freq__v0 = 0;
    vlTOPp->__Vdlyvset__v__DOT__c_freq__v1 = 0;
    vlTOPp->__Vdlyvset__v__DOT__c_amp__v0 = 0;
    vlTOPp->__Vdlyvset__v__DOT__c_amp__v4 = 0;
    // ALWAYS at source/sn76489.v:192
    __Vdly__v__DOT__clk_div = (0xf & ((IData)(1) + (IData)(vlTOPp->v__DOT__clk_div)));
    // ALWAYS at source/sn76489.v:17
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__tone1__DOT__counter = 0;
	__Vdly__v__DOT__tone1__DOT__phase = 0;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__clk_div))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__tone1__DOT__counter))) {
		__Vdly__v__DOT__tone1__DOT__phase = 
		    (1 & (~ (IData)(vlTOPp->v__DOT__tone1__DOT__phase)));
		__Vdly__v__DOT__tone1__DOT__counter 
		    = vlTOPp->v__DOT____Vcellinp__tone1____pinNumber3;
	    } else {
		__Vdly__v__DOT__tone1__DOT__counter 
		    = (0x3ff & ((IData)(vlTOPp->v__DOT__tone1__DOT__counter) 
				- (IData)(1)));
	    }
	}
    }
    // ALWAYS at source/sn76489.v:17
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__tone0__DOT__counter = 0;
	__Vdly__v__DOT__tone0__DOT__phase = 0;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__clk_div))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__tone0__DOT__counter))) {
		__Vdly__v__DOT__tone0__DOT__phase = 
		    (1 & (~ (IData)(vlTOPp->v__DOT__tone0__DOT__phase)));
		__Vdly__v__DOT__tone0__DOT__counter 
		    = vlTOPp->v__DOT____Vcellinp__tone0____pinNumber3;
	    } else {
		__Vdly__v__DOT__tone0__DOT__counter 
		    = (0x3ff & ((IData)(vlTOPp->v__DOT__tone0__DOT__counter) 
				- (IData)(1)));
	    }
	}
    }
    // ALWAYS at source/sn76489.v:17
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__tone2__DOT__counter = 0;
	vlTOPp->__Vdly__v__DOT__tone2__DOT__phase = 0;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__clk_div))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__tone2__DOT__counter))) {
		vlTOPp->__Vdly__v__DOT__tone2__DOT__phase 
		    = (1 & (~ (IData)(vlTOPp->v__DOT__tone2__DOT__phase)));
		__Vdly__v__DOT__tone2__DOT__counter 
		    = vlTOPp->v__DOT____Vcellinp__tone2____pinNumber3;
	    } else {
		__Vdly__v__DOT__tone2__DOT__counter 
		    = (0x3ff & ((IData)(vlTOPp->v__DOT__tone2__DOT__counter) 
				- (IData)(1)));
	    }
	}
    }
    vlTOPp->v__DOT__tone1__DOT__counter = __Vdly__v__DOT__tone1__DOT__counter;
    vlTOPp->v__DOT__tone1__DOT__phase = __Vdly__v__DOT__tone1__DOT__phase;
    vlTOPp->v__DOT__tone0__DOT__counter = __Vdly__v__DOT__tone0__DOT__counter;
    vlTOPp->v__DOT__tone0__DOT__phase = __Vdly__v__DOT__tone0__DOT__phase;
    vlTOPp->v__DOT__tone2__DOT__counter = __Vdly__v__DOT__tone2__DOT__counter;
    vlTOPp->v__DOT__clk_div = __Vdly__v__DOT__clk_div;
}

void Vsn76489::_sequent__TOP__2(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_sequent__TOP__2\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG16(__Vdly__v__DOT__noise__DOT__counter,11,0);
    VL_SIG16(__Vdly__v__DOT__noise__DOT__lfsr,15,0);
    // Body
    __Vdly__v__DOT__noise__DOT__counter = vlTOPp->v__DOT__noise__DOT__counter;
    __Vdly__v__DOT__noise__DOT__lfsr = vlTOPp->v__DOT__noise__DOT__lfsr;
    // ALWAYS at source/sn76489.v:60
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__noise__DOT__counter = 0;
    } else {
	if (vlTOPp->v__DOT__noise_clear) {
	    __Vdly__v__DOT__noise__DOT__lfsr = 1;
	} else {
	    if ((3 == (IData)(vlTOPp->v__DOT__noise_shift))) {
		__Vdly__v__DOT__noise__DOT__lfsr = 
		    (((IData)(vlTOPp->v__DOT__tone2__DOT__phase) 
		      != (IData)(vlTOPp->v__DOT__noise__DOT__old_tone2))
		      ? (IData)(vlTOPp->v__DOT__noise__DOT__lfsr_next)
		      : (IData)(vlTOPp->v__DOT__noise__DOT__lfsr));
	    } else {
		if ((0 == (IData)(vlTOPp->v__DOT__noise__DOT__counter))) {
		    if ((0 == (IData)(vlTOPp->v__DOT__noise_shift))) {
			__Vdly__v__DOT__noise__DOT__counter = 0x200;
		    } else {
			if ((1 == (IData)(vlTOPp->v__DOT__noise_shift))) {
			    __Vdly__v__DOT__noise__DOT__counter = 0x400;
			} else {
			    if ((2 == (IData)(vlTOPp->v__DOT__noise_shift))) {
				__Vdly__v__DOT__noise__DOT__counter = 0x800;
			    }
			}
		    }
		    __Vdly__v__DOT__noise__DOT__lfsr 
			= vlTOPp->v__DOT__noise__DOT__lfsr_next;
		} else {
		    __Vdly__v__DOT__noise__DOT__counter 
			= (0xfff & ((IData)(vlTOPp->v__DOT__noise__DOT__counter) 
				    - (IData)(1)));
		}
	    }
	}
    }
    vlTOPp->v__DOT__noise__DOT__counter = __Vdly__v__DOT__noise__DOT__counter;
    vlTOPp->v__DOT__noise__DOT__lfsr = __Vdly__v__DOT__noise__DOT__lfsr;
    // ALWAYS at source/sn76489.v:84
    vlTOPp->v__DOT__noise__DOT__old_tone2 = vlTOPp->v__DOT__tone2__DOT__phase;
}

void Vsn76489::_sequent__TOP__3(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_sequent__TOP__3\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__v__DOT__c_freq__v0,1,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__c_freq__v1,1,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__c_amp__v4,1,0);
    VL_SIG8(__Vdlyvval__v__DOT__c_amp__v4,3,0);
    VL_SIG16(__Vdlyvval__v__DOT__c_freq__v0,9,0);
    VL_SIG16(__Vdlyvval__v__DOT__c_freq__v1,9,0);
    // Body
    vlTOPp->v__DOT__tone2__DOT__phase = vlTOPp->__Vdly__v__DOT__tone2__DOT__phase;
    // ALWAYS at source/sn76489.v:155
    if (vlTOPp->in_rst) {
	vlTOPp->__Vdlyvset__v__DOT__c_amp__v0 = 1;
    } else {
	vlTOPp->v__DOT__noise_clear = ((IData)(vlTOPp->v__DOT__posedge_wr) 
				       & (0xe == (0xf 
						  & ((IData)(vlTOPp->in_val) 
						     >> 4))));
	if (vlTOPp->v__DOT__posedge_wr) {
	    if ((0x80 == (0x90 & (IData)(vlTOPp->in_val)))) {
		if ((3 == (3 & ((IData)(vlTOPp->in_val) 
				>> 5)))) {
		    vlTOPp->v__DOT__noise_shift = (3 
						   & (IData)(vlTOPp->in_val));
		    vlTOPp->v__DOT__noise_fb = (1 & 
						((IData)(vlTOPp->in_val) 
						 >> 2));
		} else {
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
			vlTOPp->__Vdlyvset__v__DOT__c_freq__v0 = 1;
			__Vdlyvdim0__v__DOT__c_freq__v0 
			    = (3 & ((IData)(vlTOPp->in_val) 
				    >> 5));
		    }
		}
		vlTOPp->__Vdly__v__DOT__latch_chan 
		    = (3 & ((IData)(vlTOPp->in_val) 
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
			    vlTOPp->__Vdlyvset__v__DOT__c_freq__v1 = 1;
			    __Vdlyvdim0__v__DOT__c_freq__v1 
				= vlTOPp->v__DOT__latch_chan;
			}
		    }
		} else {
		    if ((0x90 == (0x90 & (IData)(vlTOPp->in_val)))) {
			__Vdlyvval__v__DOT__c_amp__v4 
			    = (0xf & (IData)(vlTOPp->in_val));
			vlTOPp->__Vdlyvset__v__DOT__c_amp__v4 = 1;
			__Vdlyvdim0__v__DOT__c_amp__v4 
			    = (3 & ((IData)(vlTOPp->in_val) 
				    >> 5));
		    }
		}
	    }
	}
    }
    vlTOPp->v__DOT__old_wr = vlTOPp->in_wr;
    vlTOPp->v__DOT__latch_chan = vlTOPp->__Vdly__v__DOT__latch_chan;
    // ALWAYSPOST at source/sn76489.v:175
    if (vlTOPp->__Vdlyvset__v__DOT__c_freq__v0) {
	vlTOPp->v__DOT__c_freq[(IData)(__Vdlyvdim0__v__DOT__c_freq__v0)] 
	    = __Vdlyvval__v__DOT__c_freq__v0;
    }
    if (vlTOPp->__Vdlyvset__v__DOT__c_freq__v1) {
	vlTOPp->v__DOT__c_freq[(IData)(__Vdlyvdim0__v__DOT__c_freq__v1)] 
	    = __Vdlyvval__v__DOT__c_freq__v1;
    }
    // ALWAYSPOST at source/sn76489.v:156
    if (vlTOPp->__Vdlyvset__v__DOT__c_amp__v0) {
	vlTOPp->v__DOT__c_amp[0] = 0;
	vlTOPp->v__DOT__c_amp[1] = 0;
	vlTOPp->v__DOT__c_amp[2] = 0;
	vlTOPp->v__DOT__c_amp[3] = 0;
    }
    if (vlTOPp->__Vdlyvset__v__DOT__c_amp__v4) {
	vlTOPp->v__DOT__c_amp[(IData)(__Vdlyvdim0__v__DOT__c_amp__v4)] 
	    = __Vdlyvval__v__DOT__c_amp__v4;
    }
    vlTOPp->v__DOT____Vcellinp__tone0____pinNumber3 
	= (IData)(vlTOPp->v__DOT__c_freq)[0];
    vlTOPp->v__DOT____Vcellinp__tone1____pinNumber3 
	= (IData)(vlTOPp->v__DOT__c_freq)[1];
    vlTOPp->v__DOT____Vcellinp__tone2____pinNumber3 
	= (IData)(vlTOPp->v__DOT__c_freq)[2];
    vlTOPp->v__DOT__c0_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__tone0__DOT__phase) 
	   << 4) | (IData)(vlTOPp->v__DOT__c_amp)[0])];
    vlTOPp->v__DOT__c1_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__tone1__DOT__phase) 
	   << 4) | (IData)(vlTOPp->v__DOT__c_amp)[1])];
    vlTOPp->v__DOT__c2_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__tone2__DOT__phase) 
	   << 4) | (IData)(vlTOPp->v__DOT__c_amp)[2])];
}

void Vsn76489::_combo__TOP__4(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_combo__TOP__4\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__posedge_wr = ((IData)(vlTOPp->in_wr) 
				  & (~ (IData)(vlTOPp->v__DOT__old_wr)));
}

void Vsn76489::_settle__TOP__5(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_settle__TOP__5\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__posedge_wr = ((IData)(vlTOPp->in_wr) 
				  & (~ (IData)(vlTOPp->v__DOT__old_wr)));
    vlTOPp->v__DOT__noise__DOT__lfsr_next = (0xffff 
					     & ((IData)(vlTOPp->v__DOT__noise_fb)
						 ? 
						((0 
						  == (IData)(vlTOPp->v__DOT__noise__DOT__lfsr))
						  ? 1
						  : 
						 ((0x8000 
						   & (((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
						       << 0xf) 
						      ^ 
						      (0xffff8000 
						       & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
							  << 0xc)))) 
						  | (0x7fff 
						     & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
							>> 1))))
						 : 
						((0x8000 
						  & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
						     << 0xf)) 
						 | (0x7fff 
						    & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
						       >> 1)))));
    vlTOPp->v__DOT____Vcellinp__tone0____pinNumber3 
	= (IData)(vlTOPp->v__DOT__c_freq)[0];
    vlTOPp->v__DOT____Vcellinp__tone1____pinNumber3 
	= (IData)(vlTOPp->v__DOT__c_freq)[1];
    vlTOPp->v__DOT____Vcellinp__tone2____pinNumber3 
	= (IData)(vlTOPp->v__DOT__c_freq)[2];
    vlTOPp->v__DOT__c0_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__tone0__DOT__phase) 
	   << 4) | (IData)(vlTOPp->v__DOT__c_amp)[0])];
    vlTOPp->v__DOT__c1_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__tone1__DOT__phase) 
	   << 4) | (IData)(vlTOPp->v__DOT__c_amp)[1])];
    vlTOPp->v__DOT__c2_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((IData)(vlTOPp->v__DOT__tone2__DOT__phase) 
	   << 4) | (IData)(vlTOPp->v__DOT__c_amp)[2])];
    vlTOPp->v__DOT__nz_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
		   << 4)) | (IData)(vlTOPp->v__DOT__c_amp)
	  [3])];
}

void Vsn76489::_sequent__TOP__6(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_sequent__TOP__6\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__noise__DOT__lfsr_next = (0xffff 
					     & ((IData)(vlTOPp->v__DOT__noise_fb)
						 ? 
						((0 
						  == (IData)(vlTOPp->v__DOT__noise__DOT__lfsr))
						  ? 1
						  : 
						 ((0x8000 
						   & (((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
						       << 0xf) 
						      ^ 
						      (0xffff8000 
						       & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
							  << 0xc)))) 
						  | (0x7fff 
						     & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
							>> 1))))
						 : 
						((0x8000 
						  & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
						     << 0xf)) 
						 | (0x7fff 
						    & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
						       >> 1)))));
    vlTOPp->v__DOT__nz_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
		   << 4)) | (IData)(vlTOPp->v__DOT__c_amp)
	  [3])];
    vlTOPp->out_lr = (0xffff & ((((IData)(vlTOPp->v__DOT__c0_mix) 
				  + (IData)(vlTOPp->v__DOT__c1_mix)) 
				 + (IData)(vlTOPp->v__DOT__c2_mix)) 
				+ (IData)(vlTOPp->v__DOT__nz_mix)));
}

void Vsn76489::_settle__TOP__7(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_settle__TOP__7\n"); );
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
    }
    if ((((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__noise_clear) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__noise_clear))))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    if ((((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__noise_clear) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__noise_clear))))) {
	vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__in_clk = vlTOPp->in_clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__noise_clear 
	= vlTOPp->__VinpClk__TOP__v__DOT__noise_clear;
    vlTOPp->__VinpClk__TOP__v__DOT__noise_clear = vlTOPp->v__DOT__noise_clear;
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
    vlTOPp->_settle__TOP__5(vlSymsp);
    vlTOPp->_settle__TOP__7(vlSymsp);
}

IData Vsn76489::_change_request(Vsn76489__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vsn76489::_change_request\n"); );
    Vsn76489* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    __req |= ((vlTOPp->v__DOT__noise_clear ^ vlTOPp->__Vchglast__TOP__v__DOT__noise_clear));
    VL_DEBUG_IF( if(__req && ((vlTOPp->v__DOT__noise_clear ^ vlTOPp->__Vchglast__TOP__v__DOT__noise_clear))) VL_PRINTF("	CHANGE: source/sn76489.v:122: v.noise_clear\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__v__DOT__noise_clear = vlTOPp->v__DOT__noise_clear;
    return __req;
}
