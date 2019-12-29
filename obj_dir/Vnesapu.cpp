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
    in_reg = VL_RAND_RESET_I(5);
    in_val = VL_RAND_RESET_I(8);
    in_wr = 0;
    out_lr = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    v__DOT__AMP_TABLE[__Vi0] = VL_RAND_RESET_I(16);
    }}
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    v__DOT__TRI_TABLE[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    v__DOT__LEN_TABLE[__Vi0] = VL_RAND_RESET_I(8);
    }}
    v__DOT__old_wr = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<23; ++__Vi0) {
	    v__DOT__apu_reg[__Vi0] = VL_RAND_RESET_I(8);
    }}
    v__DOT__pulse0_enable = VL_RAND_RESET_I(1);
    v__DOT__pulse1_enable = VL_RAND_RESET_I(1);
    v__DOT__tri_enable = VL_RAND_RESET_I(1);
    v__DOT__noise_enable = VL_RAND_RESET_I(1);
    v__DOT__pulse0_freq = VL_RAND_RESET_I(11);
    v__DOT__pulse0_int = VL_RAND_RESET_I(11);
    v__DOT__pulse0_seq = VL_RAND_RESET_I(8);
    v__DOT__pulse0_length = VL_RAND_RESET_I(8);
    v__DOT__pulse1_freq = VL_RAND_RESET_I(11);
    v__DOT__pulse1_int = VL_RAND_RESET_I(11);
    v__DOT__pulse1_seq = VL_RAND_RESET_I(8);
    v__DOT__pulse1_length = VL_RAND_RESET_I(8);
    v__DOT__tri_freq = VL_RAND_RESET_I(11);
    v__DOT__tri_int = VL_RAND_RESET_I(11);
    v__DOT__tri_step = VL_RAND_RESET_I(5);
    v__DOT__tri_length = VL_RAND_RESET_I(8);
    v__DOT__lfsr = VL_RAND_RESET_I(15);
    v__DOT__lfsr_length = VL_RAND_RESET_I(8);
    v__DOT__clk_div = VL_RAND_RESET_I(8);
    v__DOT__frame_cnt = VL_RAND_RESET_I(12);
    v__DOT__frame_step = VL_RAND_RESET_I(5);
    v__DOT__pulse0_out = VL_RAND_RESET_I(16);
    v__DOT__pulse1_out = VL_RAND_RESET_I(16);
    v__DOT__tri_out = VL_RAND_RESET_I(8);
    v__DOT__lfsr_out = VL_RAND_RESET_I(16);
    v__DOT__pulse0_env_start = VL_RAND_RESET_I(1);
    v__DOT____Vcellinp__pulse0_env____pinNumber5 = 0;
    v__DOT____Vcellinp__pulse0_env____pinNumber4 = 0;
    v__DOT____Vcellinp__pulse0_env____pinNumber3 = VL_RAND_RESET_I(4);
    v__DOT__pulse1_env_start = VL_RAND_RESET_I(1);
    v__DOT____Vcellinp__pulse1_env____pinNumber5 = 0;
    v__DOT____Vcellinp__pulse1_env____pinNumber4 = 0;
    v__DOT____Vcellinp__pulse1_env____pinNumber3 = VL_RAND_RESET_I(4);
    v__DOT__lfsr_env_start = VL_RAND_RESET_I(1);
    v__DOT____Vcellinp__lfsr_env____pinNumber5 = 0;
    v__DOT____Vcellinp__lfsr_env____pinNumber4 = 0;
    v__DOT____Vcellinp__lfsr_env____pinNumber3 = VL_RAND_RESET_I(4);
    v__DOT__posedge_wr = VL_RAND_RESET_I(1);
    v__DOT__in_timer = VL_RAND_RESET_I(8);
    v__DOT____Vlvbound1 = 0;
    v__DOT__pulse0_env__DOT__decay = VL_RAND_RESET_I(4);
    v__DOT__pulse0_env__DOT__divider = VL_RAND_RESET_I(4);
    v__DOT__pulse0_env__DOT__start = VL_RAND_RESET_I(1);
    v__DOT__pulse1_env__DOT__decay = VL_RAND_RESET_I(4);
    v__DOT__pulse1_env__DOT__divider = VL_RAND_RESET_I(4);
    v__DOT__pulse1_env__DOT__start = VL_RAND_RESET_I(1);
    v__DOT__lfsr_env__DOT__decay = VL_RAND_RESET_I(4);
    v__DOT__lfsr_env__DOT__divider = VL_RAND_RESET_I(4);
    v__DOT__lfsr_env__DOT__start = VL_RAND_RESET_I(1);
    __VinpClk__TOP__v__DOT__pulse1_env_start = VL_RAND_RESET_I(1);
    __VinpClk__TOP__v__DOT__lfsr_env_start = VL_RAND_RESET_I(1);
    __VinpClk__TOP__v__DOT__pulse0_env_start = VL_RAND_RESET_I(1);
    __Vclklast__TOP__in_clk = 0;
    __Vclklast__TOP____VinpClk__TOP__v__DOT__pulse1_env_start = 0;
    __Vclklast__TOP____VinpClk__TOP__v__DOT__lfsr_env_start = 0;
    __Vclklast__TOP____VinpClk__TOP__v__DOT__pulse0_env_start = 0;
    __Vchglast__TOP__v__DOT__pulse0_env_start = VL_RAND_RESET_I(1);
    __Vchglast__TOP__v__DOT__pulse1_env_start = VL_RAND_RESET_I(1);
    __Vchglast__TOP__v__DOT__lfsr_env_start = VL_RAND_RESET_I(1);
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

void Vnesapu::_initial__TOP(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_initial__TOP\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    //char	__VpadToAlign4[4];
    VL_SIGW(__Vtemp1,111,0,4);
    VL_SIGW(__Vtemp2,111,0,4);
    VL_SIGW(__Vtemp3,111,0,4);
    // Body
    // INITIAL at source/nesapu.v:77
    __Vtemp1[0] = 0x2e747874;
    __Vtemp1[1] = 0x5f646163;
    __Vtemp1[2] = 0x73617075;
    __Vtemp1[3] = 0x6e65;
    VL_READMEM_W (true,16,32, 0,4, __Vtemp1, vlTOPp->v__DOT__AMP_TABLE
		  ,0,~0);
    // INITIAL at source/nesapu.v:81
    __Vtemp2[0] = 0x2e747874;
    __Vtemp2[1] = 0x5f747269;
    __Vtemp2[2] = 0x73617075;
    __Vtemp2[3] = 0x6e65;
    VL_READMEM_W (true,8,32, 0,4, __Vtemp2, vlTOPp->v__DOT__TRI_TABLE
		  ,0,~0);
    // INITIAL at source/nesapu.v:85
    __Vtemp3[0] = 0x2e747874;
    __Vtemp3[1] = 0x5f6c656e;
    __Vtemp3[2] = 0x73617075;
    __Vtemp3[3] = 0x6e65;
    VL_READMEM_W (true,8,32, 0,4, __Vtemp3, vlTOPp->v__DOT__LEN_TABLE
		  ,0,~0);
    // INITIAL at source/nesapu.v:171
    vlTOPp->v__DOT__pulse1_env_start = ((IData)(vlTOPp->v__DOT__posedge_wr) 
					& (7 == (IData)(vlTOPp->in_reg)));
    // INITIAL at source/nesapu.v:185
    vlTOPp->v__DOT__lfsr_env_start = ((IData)(vlTOPp->v__DOT__posedge_wr) 
				      & (3 == (IData)(vlTOPp->in_reg)));
}

void Vnesapu::_sequent__TOP__1(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_sequent__TOP__1\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__pulse1_env__DOT__decay,3,0);
    VL_SIG8(__Vdly__v__DOT__pulse1_env__DOT__divider,3,0);
    VL_SIG8(__Vdly__v__DOT__pulse1_env__DOT__start,0,0);
    //char	__VpadToAlign79[1];
    // Body
    __Vdly__v__DOT__pulse1_env__DOT__divider = vlTOPp->v__DOT__pulse1_env__DOT__divider;
    __Vdly__v__DOT__pulse1_env__DOT__start = vlTOPp->v__DOT__pulse1_env__DOT__start;
    __Vdly__v__DOT__pulse1_env__DOT__decay = vlTOPp->v__DOT__pulse1_env__DOT__decay;
    // ALWAYS at source/nesapu.v:33
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__pulse1_env__DOT__decay = 0;
	__Vdly__v__DOT__pulse1_env__DOT__divider = 0;
    } else {
	if (vlTOPp->v__DOT__pulse1_env_start) {
	    __Vdly__v__DOT__pulse1_env__DOT__start = 1;
	} else {
	    if (((0 == (IData)(vlTOPp->v__DOT__frame_cnt)) 
		 & (4 != (IData)(vlTOPp->v__DOT__frame_step)))) {
		if (vlTOPp->v__DOT__pulse1_env__DOT__start) {
		    __Vdly__v__DOT__pulse1_env__DOT__start = 0;
		    __Vdly__v__DOT__pulse1_env__DOT__decay = 0xf;
		    __Vdly__v__DOT__pulse1_env__DOT__divider 
			= vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber3;
		} else {
		    if ((0 == (IData)(vlTOPp->v__DOT__pulse1_env__DOT__divider))) {
			if ((0 == (IData)(vlTOPp->v__DOT__pulse1_env__DOT__decay))) {
			    if (vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber4) {
				__Vdly__v__DOT__pulse1_env__DOT__decay = 0xf;
				__Vdly__v__DOT__pulse1_env__DOT__divider 
				    = vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber3;
			    }
			} else {
			    __Vdly__v__DOT__pulse1_env__DOT__decay 
				= (0xf & ((IData)(vlTOPp->v__DOT__pulse1_env__DOT__decay) 
					  - (IData)(1)));
			    __Vdly__v__DOT__pulse1_env__DOT__divider 
				= vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber3;
			}
		    } else {
			__Vdly__v__DOT__pulse1_env__DOT__divider 
			    = (0xf & ((IData)(vlTOPp->v__DOT__pulse1_env__DOT__divider) 
				      - (IData)(1)));
		    }
		}
	    }
	}
    }
    vlTOPp->v__DOT__pulse1_env__DOT__start = __Vdly__v__DOT__pulse1_env__DOT__start;
    vlTOPp->v__DOT__pulse1_env__DOT__divider = __Vdly__v__DOT__pulse1_env__DOT__divider;
    vlTOPp->v__DOT__pulse1_env__DOT__decay = __Vdly__v__DOT__pulse1_env__DOT__decay;
}

void Vnesapu::_sequent__TOP__2(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_sequent__TOP__2\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__lfsr_env__DOT__decay,3,0);
    VL_SIG8(__Vdly__v__DOT__lfsr_env__DOT__divider,3,0);
    VL_SIG8(__Vdly__v__DOT__lfsr_env__DOT__start,0,0);
    //char	__VpadToAlign103[1];
    // Body
    __Vdly__v__DOT__lfsr_env__DOT__start = vlTOPp->v__DOT__lfsr_env__DOT__start;
    __Vdly__v__DOT__lfsr_env__DOT__divider = vlTOPp->v__DOT__lfsr_env__DOT__divider;
    __Vdly__v__DOT__lfsr_env__DOT__decay = vlTOPp->v__DOT__lfsr_env__DOT__decay;
    // ALWAYS at source/nesapu.v:33
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__lfsr_env__DOT__decay = 0;
	__Vdly__v__DOT__lfsr_env__DOT__divider = 0;
    } else {
	if (vlTOPp->v__DOT__lfsr_env_start) {
	    __Vdly__v__DOT__lfsr_env__DOT__start = 1;
	} else {
	    if (((0 == (IData)(vlTOPp->v__DOT__frame_cnt)) 
		 & (4 != (IData)(vlTOPp->v__DOT__frame_step)))) {
		if (vlTOPp->v__DOT__lfsr_env__DOT__start) {
		    __Vdly__v__DOT__lfsr_env__DOT__start = 0;
		    __Vdly__v__DOT__lfsr_env__DOT__decay = 0xf;
		    __Vdly__v__DOT__lfsr_env__DOT__divider 
			= vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber3;
		} else {
		    if ((0 == (IData)(vlTOPp->v__DOT__lfsr_env__DOT__divider))) {
			if ((0 == (IData)(vlTOPp->v__DOT__lfsr_env__DOT__decay))) {
			    if (vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber4) {
				__Vdly__v__DOT__lfsr_env__DOT__decay = 0xf;
				__Vdly__v__DOT__lfsr_env__DOT__divider 
				    = vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber3;
			    }
			} else {
			    __Vdly__v__DOT__lfsr_env__DOT__decay 
				= (0xf & ((IData)(vlTOPp->v__DOT__lfsr_env__DOT__decay) 
					  - (IData)(1)));
			    __Vdly__v__DOT__lfsr_env__DOT__divider 
				= vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber3;
			}
		    } else {
			__Vdly__v__DOT__lfsr_env__DOT__divider 
			    = (0xf & ((IData)(vlTOPp->v__DOT__lfsr_env__DOT__divider) 
				      - (IData)(1)));
		    }
		}
	    }
	}
    }
    vlTOPp->v__DOT__lfsr_env__DOT__start = __Vdly__v__DOT__lfsr_env__DOT__start;
    vlTOPp->v__DOT__lfsr_env__DOT__divider = __Vdly__v__DOT__lfsr_env__DOT__divider;
    vlTOPp->v__DOT__lfsr_env__DOT__decay = __Vdly__v__DOT__lfsr_env__DOT__decay;
}

void Vnesapu::_sequent__TOP__3(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_sequent__TOP__3\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__pulse0_env__DOT__decay,3,0);
    VL_SIG8(__Vdly__v__DOT__pulse0_env__DOT__divider,3,0);
    VL_SIG8(__Vdly__v__DOT__pulse0_env__DOT__start,0,0);
    //char	__VpadToAlign127[1];
    // Body
    __Vdly__v__DOT__pulse0_env__DOT__start = vlTOPp->v__DOT__pulse0_env__DOT__start;
    __Vdly__v__DOT__pulse0_env__DOT__divider = vlTOPp->v__DOT__pulse0_env__DOT__divider;
    __Vdly__v__DOT__pulse0_env__DOT__decay = vlTOPp->v__DOT__pulse0_env__DOT__decay;
    // ALWAYS at source/nesapu.v:33
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__pulse0_env__DOT__decay = 0;
	__Vdly__v__DOT__pulse0_env__DOT__divider = 0;
    } else {
	if (vlTOPp->v__DOT__pulse0_env_start) {
	    __Vdly__v__DOT__pulse0_env__DOT__start = 1;
	} else {
	    if (((0 == (IData)(vlTOPp->v__DOT__frame_cnt)) 
		 & (4 != (IData)(vlTOPp->v__DOT__frame_step)))) {
		if (vlTOPp->v__DOT__pulse0_env__DOT__start) {
		    __Vdly__v__DOT__pulse0_env__DOT__start = 0;
		    __Vdly__v__DOT__pulse0_env__DOT__decay = 0xf;
		    __Vdly__v__DOT__pulse0_env__DOT__divider 
			= vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber3;
		} else {
		    if ((0 == (IData)(vlTOPp->v__DOT__pulse0_env__DOT__divider))) {
			if ((0 == (IData)(vlTOPp->v__DOT__pulse0_env__DOT__decay))) {
			    if (vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber4) {
				__Vdly__v__DOT__pulse0_env__DOT__decay = 0xf;
				__Vdly__v__DOT__pulse0_env__DOT__divider 
				    = vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber3;
			    }
			} else {
			    __Vdly__v__DOT__pulse0_env__DOT__decay 
				= (0xf & ((IData)(vlTOPp->v__DOT__pulse0_env__DOT__decay) 
					  - (IData)(1)));
			    __Vdly__v__DOT__pulse0_env__DOT__divider 
				= vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber3;
			}
		    } else {
			__Vdly__v__DOT__pulse0_env__DOT__divider 
			    = (0xf & ((IData)(vlTOPp->v__DOT__pulse0_env__DOT__divider) 
				      - (IData)(1)));
		    }
		}
	    }
	}
    }
    vlTOPp->v__DOT__pulse0_env__DOT__start = __Vdly__v__DOT__pulse0_env__DOT__start;
    vlTOPp->v__DOT__pulse0_env__DOT__divider = __Vdly__v__DOT__pulse0_env__DOT__divider;
    vlTOPp->v__DOT__pulse0_env__DOT__decay = __Vdly__v__DOT__pulse0_env__DOT__decay;
}

void Vnesapu::_sequent__TOP__4(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_sequent__TOP__4\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__pulse0_seq,7,0);
    VL_SIG8(__Vdly__v__DOT__pulse1_seq,7,0);
    VL_SIG8(__Vdlyvset__v__DOT__apu_reg__v0,0,0);
    VL_SIG8(__Vdly__v__DOT__frame_step,4,0);
    VL_SIG8(__Vdlyvset__v__DOT__apu_reg__v1,0,0);
    VL_SIG8(__Vdly__v__DOT__tri_step,4,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__apu_reg__v2,4,0);
    VL_SIG8(__Vdlyvval__v__DOT__apu_reg__v2,7,0);
    VL_SIG8(__Vdlyvset__v__DOT__apu_reg__v2,0,0);
    VL_SIG8(__Vdly__v__DOT__pulse0_length,7,0);
    VL_SIG8(__Vdly__v__DOT__pulse1_length,7,0);
    VL_SIG8(__Vdly__v__DOT__tri_length,7,0);
    VL_SIG8(__Vdly__v__DOT__lfsr_length,7,0);
    VL_SIG8(__Vdly__v__DOT__clk_div,7,0);
    VL_SIG16(__Vdly__v__DOT__lfsr,14,0);
    VL_SIG16(__Vdly__v__DOT__frame_cnt,11,0);
    VL_SIG16(__Vdly__v__DOT__pulse0_int,10,0);
    VL_SIG16(__Vdly__v__DOT__pulse1_int,10,0);
    VL_SIG16(__Vdly__v__DOT__tri_int,10,0);
    // Body
    __Vdly__v__DOT__clk_div = vlTOPp->v__DOT__clk_div;
    __Vdly__v__DOT__frame_step = vlTOPp->v__DOT__frame_step;
    __Vdly__v__DOT__frame_cnt = vlTOPp->v__DOT__frame_cnt;
    __Vdly__v__DOT__tri_int = vlTOPp->v__DOT__tri_int;
    __Vdly__v__DOT__pulse1_int = vlTOPp->v__DOT__pulse1_int;
    __Vdly__v__DOT__pulse0_int = vlTOPp->v__DOT__pulse0_int;
    __Vdly__v__DOT__pulse1_length = vlTOPp->v__DOT__pulse1_length;
    __Vdly__v__DOT__tri_length = vlTOPp->v__DOT__tri_length;
    __Vdly__v__DOT__lfsr_length = vlTOPp->v__DOT__lfsr_length;
    __Vdly__v__DOT__pulse0_length = vlTOPp->v__DOT__pulse0_length;
    __Vdly__v__DOT__tri_step = vlTOPp->v__DOT__tri_step;
    __Vdly__v__DOT__pulse1_seq = vlTOPp->v__DOT__pulse1_seq;
    __Vdly__v__DOT__pulse0_seq = vlTOPp->v__DOT__pulse0_seq;
    __Vdly__v__DOT__lfsr = vlTOPp->v__DOT__lfsr;
    __Vdlyvset__v__DOT__apu_reg__v0 = 0;
    __Vdlyvset__v__DOT__apu_reg__v1 = 0;
    __Vdlyvset__v__DOT__apu_reg__v2 = 0;
    // ALWAYS at source/nesapu.v:202
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__pulse0_seq = 0x78;
	__Vdly__v__DOT__pulse1_seq = 0x78;
	__Vdlyvset__v__DOT__apu_reg__v0 = 1;
	__Vdly__v__DOT__lfsr = 1;
	__Vdly__v__DOT__frame_step = 1;
	__Vdly__v__DOT__frame_cnt = 0;
	__Vdlyvset__v__DOT__apu_reg__v1 = 1;
    } else {
	if ((0 == (1 & (IData)(vlTOPp->v__DOT__clk_div)))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__pulse0_int))) {
		__Vdly__v__DOT__pulse0_seq = ((0x80 
					       & ((IData)(vlTOPp->v__DOT__pulse0_seq) 
						  << 7)) 
					      | (0x7f 
						 & ((IData)(vlTOPp->v__DOT__pulse0_seq) 
						    >> 1)));
		__Vdly__v__DOT__pulse0_int = (0x7ff 
					      & ((IData)(1) 
						 + (IData)(vlTOPp->v__DOT__pulse0_freq)));
	    } else {
		__Vdly__v__DOT__pulse0_int = (0x7ff 
					      & ((IData)(vlTOPp->v__DOT__pulse0_int) 
						 - (IData)(1)));
	    }
	    if ((0 == (IData)(vlTOPp->v__DOT__pulse1_int))) {
		__Vdly__v__DOT__pulse1_seq = ((0x80 
					       & ((IData)(vlTOPp->v__DOT__pulse1_seq) 
						  << 7)) 
					      | (0x7f 
						 & ((IData)(vlTOPp->v__DOT__pulse1_seq) 
						    >> 1)));
		__Vdly__v__DOT__pulse1_int = (0x7ff 
					      & ((IData)(1) 
						 + (IData)(vlTOPp->v__DOT__pulse1_freq)));
	    } else {
		__Vdly__v__DOT__pulse1_int = (0x7ff 
					      & ((IData)(vlTOPp->v__DOT__pulse1_int) 
						 - (IData)(1)));
	    }
	}
	if ((0 == (0xf & (IData)(vlTOPp->v__DOT__clk_div)))) {
	    __Vdly__v__DOT__lfsr = ((0x4000 & (((IData)(vlTOPp->v__DOT__lfsr) 
						<< 0xe) 
					       ^ (0xffffc000 
						  & ((IData)(vlTOPp->v__DOT__lfsr) 
						     << 0xd)))) 
				    | (0x3fff & ((IData)(vlTOPp->v__DOT__lfsr) 
						 >> 1)));
	}
	if ((0 == (IData)(vlTOPp->v__DOT__tri_int))) {
	    __Vdly__v__DOT__tri_step = (0x1f & ((IData)(1) 
						+ (IData)(vlTOPp->v__DOT__tri_step)));
	    __Vdly__v__DOT__tri_int = (0x7ff & ((IData)(1) 
						+ (IData)(vlTOPp->v__DOT__tri_freq)));
	} else {
	    __Vdly__v__DOT__tri_int = (0x7ff & ((IData)(vlTOPp->v__DOT__tri_int) 
						- (IData)(1)));
	}
	if (vlTOPp->v__DOT__posedge_wr) {
	    vlTOPp->v__DOT____Vlvbound1 = vlTOPp->in_val;
	    if (((IData)(vlTOPp->in_reg) <= 0x16)) {
		__Vdlyvval__v__DOT__apu_reg__v2 = vlTOPp->v__DOT____Vlvbound1;
		__Vdlyvset__v__DOT__apu_reg__v2 = 1;
		__Vdlyvdim0__v__DOT__apu_reg__v2 = vlTOPp->in_reg;
	    }
	    if ((3 == (IData)(vlTOPp->in_reg))) {
		__Vdly__v__DOT__pulse0_length = vlTOPp->v__DOT__in_timer;
	    } else {
		if ((7 == (IData)(vlTOPp->in_reg))) {
		    __Vdly__v__DOT__pulse1_length = vlTOPp->v__DOT__in_timer;
		} else {
		    if ((0xb == (IData)(vlTOPp->in_reg))) {
			__Vdly__v__DOT__tri_length 
			    = vlTOPp->v__DOT__in_timer;
		    } else {
			if ((0xf == (IData)(vlTOPp->in_reg))) {
			    __Vdly__v__DOT__lfsr_length 
				= vlTOPp->v__DOT__in_timer;
			}
		    }
		}
	    }
	} else {
	    if ((0 == (IData)(vlTOPp->v__DOT__frame_cnt))) {
		if (((1 == (IData)(vlTOPp->v__DOT__frame_step)) 
		     | (4 == (IData)(vlTOPp->v__DOT__frame_step)))) {
		    __Vdly__v__DOT__pulse0_length = 
			(0xff & ((0 == (IData)(vlTOPp->v__DOT__pulse0_length))
				  ? 0 : ((IData)(vlTOPp->v__DOT__pulse0_length) 
					 - (IData)(1))));
		    __Vdly__v__DOT__pulse1_length = 
			(0xff & ((0 == (IData)(vlTOPp->v__DOT__pulse1_length))
				  ? 0 : ((IData)(vlTOPp->v__DOT__pulse1_length) 
					 - (IData)(1))));
		    __Vdly__v__DOT__tri_length = (0xff 
						  & ((0 
						      == (IData)(vlTOPp->v__DOT__tri_length))
						      ? 0
						      : 
						     ((IData)(vlTOPp->v__DOT__tri_length) 
						      - (IData)(1))));
		    __Vdly__v__DOT__lfsr_length = (0xff 
						   & ((0 
						       == (IData)(vlTOPp->v__DOT__lfsr_length))
						       ? 0
						       : 
						      ((IData)(vlTOPp->v__DOT__lfsr_length) 
						       - (IData)(1))));
		}
		__Vdly__v__DOT__frame_step = ((0 == (IData)(vlTOPp->v__DOT__frame_step))
					       ? 1 : 
					      ((0x1e 
						& ((IData)(vlTOPp->v__DOT__frame_step) 
						   << 1)) 
					       | (1 
						  & ((IData)(vlTOPp->v__DOT__frame_step) 
						     >> 4))));
		__Vdly__v__DOT__frame_cnt = 0x1d21;
	    } else {
		__Vdly__v__DOT__frame_cnt = (0xfff 
					     & ((IData)(vlTOPp->v__DOT__frame_cnt) 
						- (IData)(1)));
	    }
	}
    }
    __Vdly__v__DOT__clk_div = (0xff & ((IData)(1) + (IData)(vlTOPp->v__DOT__clk_div)));
    vlTOPp->v__DOT__old_wr = vlTOPp->in_wr;
    vlTOPp->v__DOT__tri_int = __Vdly__v__DOT__tri_int;
    vlTOPp->v__DOT__clk_div = __Vdly__v__DOT__clk_div;
    vlTOPp->v__DOT__pulse0_int = __Vdly__v__DOT__pulse0_int;
    vlTOPp->v__DOT__pulse1_int = __Vdly__v__DOT__pulse1_int;
    vlTOPp->v__DOT__frame_step = __Vdly__v__DOT__frame_step;
    vlTOPp->v__DOT__frame_cnt = __Vdly__v__DOT__frame_cnt;
    vlTOPp->v__DOT__lfsr_length = __Vdly__v__DOT__lfsr_length;
    vlTOPp->v__DOT__tri_length = __Vdly__v__DOT__tri_length;
    vlTOPp->v__DOT__pulse1_length = __Vdly__v__DOT__pulse1_length;
    vlTOPp->v__DOT__pulse0_length = __Vdly__v__DOT__pulse0_length;
    vlTOPp->v__DOT__tri_step = __Vdly__v__DOT__tri_step;
    vlTOPp->v__DOT__lfsr = __Vdly__v__DOT__lfsr;
    vlTOPp->v__DOT__pulse1_seq = __Vdly__v__DOT__pulse1_seq;
    vlTOPp->v__DOT__pulse0_seq = __Vdly__v__DOT__pulse0_seq;
    // ALWAYSPOST at source/nesapu.v:209
    if (__Vdlyvset__v__DOT__apu_reg__v0) {
	vlTOPp->v__DOT__apu_reg[0x15] = 0xff;
    }
    if (__Vdlyvset__v__DOT__apu_reg__v1) {
	vlTOPp->v__DOT__apu_reg[0xe] = 0x80;
    }
    if (__Vdlyvset__v__DOT__apu_reg__v2) {
	vlTOPp->v__DOT__apu_reg[(IData)(__Vdlyvdim0__v__DOT__apu_reg__v2)] 
	    = __Vdlyvval__v__DOT__apu_reg__v2;
    }
    vlTOPp->v__DOT__tri_out = (IData)(vlTOPp->v__DOT__TRI_TABLE)
	[(IData)(vlTOPp->v__DOT__tri_step)];
    vlTOPp->v__DOT__pulse0_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__apu_reg)
					     [3] << 8)) 
				   | (IData)(vlTOPp->v__DOT__apu_reg)
				   [2]);
    vlTOPp->v__DOT__pulse1_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__apu_reg)
					     [7] << 8)) 
				   | (IData)(vlTOPp->v__DOT__apu_reg)
				   [6]);
    vlTOPp->v__DOT__tri_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__apu_reg)
					  [0xb] << 8)) 
				| (IData)(vlTOPp->v__DOT__apu_reg)
				[0xa]);
    vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber4 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0] 
		>> 5));
    vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber4 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[4] 
		>> 5));
    vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber4 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0xc] 
		>> 5));
    vlTOPp->v__DOT__pulse0_enable = (1 & (IData)(vlTOPp->v__DOT__apu_reg)
				     [0x15]);
    vlTOPp->v__DOT__noise_enable = (1 & ((IData)(vlTOPp->v__DOT__apu_reg)
					 [0x15] >> 3));
    vlTOPp->v__DOT__tri_enable = (1 & ((IData)(vlTOPp->v__DOT__apu_reg)
				       [0x15] >> 2));
    vlTOPp->v__DOT__pulse1_enable = (1 & ((IData)(vlTOPp->v__DOT__apu_reg)
					  [0x15] >> 1));
    vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber3 
	= (0xf & (IData)(vlTOPp->v__DOT__apu_reg)[0xc]);
    vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0xc] 
		>> 4));
    vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber3 
	= (0xf & (IData)(vlTOPp->v__DOT__apu_reg)[4]);
    vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[4] 
		>> 4));
    vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber3 
	= (0xf & (IData)(vlTOPp->v__DOT__apu_reg)[0]);
    vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0] 
		>> 4));
}

void Vnesapu::_combo__TOP__5(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_combo__TOP__5\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__in_timer = (IData)(vlTOPp->v__DOT__LEN_TABLE)
	[(0x1f & ((IData)(vlTOPp->in_val) >> 3))];
    vlTOPp->v__DOT__posedge_wr = ((IData)(vlTOPp->in_wr) 
				  & (~ (IData)(vlTOPp->v__DOT__old_wr)));
}

void Vnesapu::_settle__TOP__6(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_settle__TOP__6\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__in_timer = (IData)(vlTOPp->v__DOT__LEN_TABLE)
	[(0x1f & ((IData)(vlTOPp->in_val) >> 3))];
    vlTOPp->v__DOT__posedge_wr = ((IData)(vlTOPp->in_wr) 
				  & (~ (IData)(vlTOPp->v__DOT__old_wr)));
    vlTOPp->v__DOT__tri_out = (IData)(vlTOPp->v__DOT__TRI_TABLE)
	[(IData)(vlTOPp->v__DOT__tri_step)];
    vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber4 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0xc] 
		>> 5));
    vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber4 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[4] 
		>> 5));
    vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber4 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0] 
		>> 5));
    vlTOPp->v__DOT__tri_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__apu_reg)
					  [0xb] << 8)) 
				| (IData)(vlTOPp->v__DOT__apu_reg)
				[0xa]);
    vlTOPp->v__DOT__pulse1_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__apu_reg)
					     [7] << 8)) 
				   | (IData)(vlTOPp->v__DOT__apu_reg)
				   [6]);
    vlTOPp->v__DOT__pulse0_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__apu_reg)
					     [3] << 8)) 
				   | (IData)(vlTOPp->v__DOT__apu_reg)
				   [2]);
    vlTOPp->v__DOT__noise_enable = (1 & ((IData)(vlTOPp->v__DOT__apu_reg)
					 [0x15] >> 3));
    vlTOPp->v__DOT__tri_enable = (1 & ((IData)(vlTOPp->v__DOT__apu_reg)
				       [0x15] >> 2));
    vlTOPp->v__DOT__pulse1_enable = (1 & ((IData)(vlTOPp->v__DOT__apu_reg)
					  [0x15] >> 1));
    vlTOPp->v__DOT__pulse0_enable = (1 & (IData)(vlTOPp->v__DOT__apu_reg)
				     [0x15]);
    vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0] 
		>> 4));
    vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber3 
	= (0xf & (IData)(vlTOPp->v__DOT__apu_reg)[0]);
    vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[4] 
		>> 4));
    vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber3 
	= (0xf & (IData)(vlTOPp->v__DOT__apu_reg)[4]);
    vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0xc] 
		>> 4));
    vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber3 
	= (0xf & (IData)(vlTOPp->v__DOT__apu_reg)[0xc]);
    vlTOPp->v__DOT__pulse0_env_start = ((IData)(vlTOPp->v__DOT__posedge_wr) 
					& (3 == (IData)(vlTOPp->in_reg)));
    vlTOPp->v__DOT__pulse0_out = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__pulse0_seq) 
		   << 4)) | ((IData)(vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber5)
			      ? (IData)(vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber3)
			      : (IData)(vlTOPp->v__DOT__pulse0_env__DOT__decay)))];
    vlTOPp->v__DOT__pulse1_out = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__pulse1_seq) 
		   << 4)) | ((IData)(vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber5)
			      ? (IData)(vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber3)
			      : (IData)(vlTOPp->v__DOT__pulse1_env__DOT__decay)))];
    vlTOPp->v__DOT__lfsr_out = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__lfsr) << 4)) 
	  | ((IData)(vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber5)
	      ? (IData)(vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber3)
	      : (IData)(vlTOPp->v__DOT__lfsr_env__DOT__decay)))];
}

void Vnesapu::_combo__TOP__7(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_combo__TOP__7\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__pulse0_env_start = ((IData)(vlTOPp->v__DOT__posedge_wr) 
					& (3 == (IData)(vlTOPp->in_reg)));
}

void Vnesapu::_sequent__TOP__8(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_sequent__TOP__8\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__pulse0_out = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__pulse0_seq) 
		   << 4)) | ((IData)(vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber5)
			      ? (IData)(vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber3)
			      : (IData)(vlTOPp->v__DOT__pulse0_env__DOT__decay)))];
}

void Vnesapu::_sequent__TOP__9(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_sequent__TOP__9\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__pulse1_out = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__pulse1_seq) 
		   << 4)) | ((IData)(vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber5)
			      ? (IData)(vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber3)
			      : (IData)(vlTOPp->v__DOT__pulse1_env__DOT__decay)))];
}

void Vnesapu::_sequent__TOP__10(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_sequent__TOP__10\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__lfsr_out = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__lfsr) << 4)) 
	  | ((IData)(vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber5)
	      ? (IData)(vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber3)
	      : (IData)(vlTOPp->v__DOT__lfsr_env__DOT__decay)))];
}

void Vnesapu::_multiclk__TOP__11(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_multiclk__TOP__11\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out_lr = (0xffff & ((((((0 == (IData)(vlTOPp->v__DOT__pulse0_enable)) 
				    | (0 == (IData)(vlTOPp->v__DOT__pulse0_length)))
				    ? 0 : (IData)(vlTOPp->v__DOT__pulse0_out)) 
				  + (((0 == (IData)(vlTOPp->v__DOT__pulse1_enable)) 
				      | (0 == (IData)(vlTOPp->v__DOT__pulse1_length)))
				      ? 0 : (IData)(vlTOPp->v__DOT__pulse1_out))) 
				 + (((0 == (IData)(vlTOPp->v__DOT__tri_enable)) 
				     | (0 == (IData)(vlTOPp->v__DOT__tri_length)))
				     ? 0 : ((IData)(vlTOPp->v__DOT__tri_out) 
					    << 8))) 
				+ (((0 == (IData)(vlTOPp->v__DOT__noise_enable)) 
				    | (0 == (IData)(vlTOPp->v__DOT__lfsr_length)))
				    ? 0 : (IData)(vlTOPp->v__DOT__lfsr_out))));
}

void Vnesapu::_eval(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_eval\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__pulse1_env_start) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__pulse1_env_start))))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if ((((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__lfsr_env_start) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__lfsr_env_start))))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__pulse0_env_start) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__pulse0_env_start))))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk)))) {
	vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    vlTOPp->_combo__TOP__7(vlSymsp);
    if ((((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__pulse0_env_start) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__pulse0_env_start))))) {
	vlTOPp->_sequent__TOP__8(vlSymsp);
    }
    if ((((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__pulse1_env_start) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__pulse1_env_start))))) {
	vlTOPp->_sequent__TOP__9(vlSymsp);
    }
    if ((((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__lfsr_env_start) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__lfsr_env_start))))) {
	vlTOPp->_sequent__TOP__10(vlSymsp);
    }
    if ((((((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk))) 
	   | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__lfsr_env_start) 
	      & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__lfsr_env_start)))) 
	  | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__pulse0_env_start) 
	     & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__pulse0_env_start)))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__pulse1_env_start) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__pulse1_env_start))))) {
	vlTOPp->_multiclk__TOP__11(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__in_clk = vlTOPp->in_clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__pulse1_env_start 
	= vlTOPp->__VinpClk__TOP__v__DOT__pulse1_env_start;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__lfsr_env_start 
	= vlTOPp->__VinpClk__TOP__v__DOT__lfsr_env_start;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__pulse0_env_start 
	= vlTOPp->__VinpClk__TOP__v__DOT__pulse0_env_start;
    vlTOPp->__VinpClk__TOP__v__DOT__pulse1_env_start 
	= vlTOPp->v__DOT__pulse1_env_start;
    vlTOPp->__VinpClk__TOP__v__DOT__lfsr_env_start 
	= vlTOPp->v__DOT__lfsr_env_start;
    vlTOPp->__VinpClk__TOP__v__DOT__pulse0_env_start 
	= vlTOPp->v__DOT__pulse0_env_start;
}

void Vnesapu::_eval_initial(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_eval_initial\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP(vlSymsp);
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
    // Body
    vlTOPp->_settle__TOP__6(vlSymsp);
    vlTOPp->_multiclk__TOP__11(vlSymsp);
}

IData Vnesapu::_change_request(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_change_request\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    __req |= ((vlTOPp->v__DOT__pulse0_env_start ^ vlTOPp->__Vchglast__TOP__v__DOT__pulse0_env_start)
	 | (vlTOPp->v__DOT__pulse1_env_start ^ vlTOPp->__Vchglast__TOP__v__DOT__pulse1_env_start)
	 | (vlTOPp->v__DOT__lfsr_env_start ^ vlTOPp->__Vchglast__TOP__v__DOT__lfsr_env_start));
    VL_DEBUG_IF( if(__req && ((vlTOPp->v__DOT__pulse0_env_start ^ vlTOPp->__Vchglast__TOP__v__DOT__pulse0_env_start))) VL_PRINTF("	CHANGE: source/nesapu.v:157: v.pulse0_env_start\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->v__DOT__pulse1_env_start ^ vlTOPp->__Vchglast__TOP__v__DOT__pulse1_env_start))) VL_PRINTF("	CHANGE: source/nesapu.v:171: v.pulse1_env_start\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->v__DOT__lfsr_env_start ^ vlTOPp->__Vchglast__TOP__v__DOT__lfsr_env_start))) VL_PRINTF("	CHANGE: source/nesapu.v:185: v.lfsr_env_start\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__v__DOT__pulse0_env_start 
	= vlTOPp->v__DOT__pulse0_env_start;
    vlTOPp->__Vchglast__TOP__v__DOT__pulse1_env_start 
	= vlTOPp->v__DOT__pulse1_env_start;
    vlTOPp->__Vchglast__TOP__v__DOT__lfsr_env_start 
	= vlTOPp->v__DOT__lfsr_env_start;
    return __req;
}
