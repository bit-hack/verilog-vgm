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
    v__DOT__pulse0_duty = VL_RAND_RESET_I(2);
    v__DOT__pulse0_freq = VL_RAND_RESET_I(11);
    v__DOT__pulse1_duty = VL_RAND_RESET_I(2);
    v__DOT__pulse1_freq = VL_RAND_RESET_I(11);
    v__DOT__tri_freq = VL_RAND_RESET_I(11);
    v__DOT__tri_int = VL_RAND_RESET_I(11);
    v__DOT__tri_step = VL_RAND_RESET_I(5);
    v__DOT__lfsr_mode = VL_RAND_RESET_I(1);
    v__DOT__lfsr_freq = VL_RAND_RESET_I(4);
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
    v__DOT__tick_len = VL_RAND_RESET_I(1);
    v__DOT__reload_len0 = VL_RAND_RESET_I(1);
    v__DOT__reload_len1 = VL_RAND_RESET_I(1);
    v__DOT__reload_len2 = VL_RAND_RESET_I(1);
    v__DOT__reload_len3 = VL_RAND_RESET_I(1);
    v__DOT____Vcellinp__len0____pinNumber6 = VL_RAND_RESET_I(8);
    v__DOT____Vcellinp__len0____pinNumber5 = 0;
    v__DOT____Vcellinp__len1____pinNumber6 = VL_RAND_RESET_I(8);
    v__DOT____Vcellinp__len1____pinNumber5 = 0;
    v__DOT____Vcellinp__len2____pinNumber6 = VL_RAND_RESET_I(8);
    v__DOT____Vcellinp__len2____pinNumber5 = 0;
    v__DOT____Vcellinp__len3____pinNumber6 = VL_RAND_RESET_I(8);
    v__DOT____Vcellinp__len3____pinNumber5 = 0;
    v__DOT__posedge_wr = VL_RAND_RESET_I(1);
    v__DOT____Vlvbound1 = 0;
    v__DOT__pulse0__DOT__counter = VL_RAND_RESET_I(11);
    v__DOT__pulse0__DOT__index = VL_RAND_RESET_I(4);
    v__DOT__pulse1__DOT__counter = VL_RAND_RESET_I(11);
    v__DOT__pulse1__DOT__index = VL_RAND_RESET_I(4);
    v__DOT__noise__DOT__count = VL_RAND_RESET_I(12);
    v__DOT__noise__DOT__max_count = VL_RAND_RESET_I(12);
    v__DOT__noise__DOT__lfsr = VL_RAND_RESET_I(15);
    v__DOT__pulse0_env__DOT__decay = VL_RAND_RESET_I(4);
    v__DOT__pulse0_env__DOT__divider = VL_RAND_RESET_I(4);
    v__DOT__pulse0_env__DOT__start = VL_RAND_RESET_I(1);
    v__DOT__pulse1_env__DOT__decay = VL_RAND_RESET_I(4);
    v__DOT__pulse1_env__DOT__divider = VL_RAND_RESET_I(4);
    v__DOT__pulse1_env__DOT__start = VL_RAND_RESET_I(1);
    v__DOT__lfsr_env__DOT__decay = VL_RAND_RESET_I(4);
    v__DOT__lfsr_env__DOT__divider = VL_RAND_RESET_I(4);
    v__DOT__lfsr_env__DOT__start = VL_RAND_RESET_I(1);
    v__DOT__len0__DOT__count = VL_RAND_RESET_I(8);
    v__DOT__len1__DOT__count = VL_RAND_RESET_I(8);
    v__DOT__len2__DOT__count = VL_RAND_RESET_I(8);
    v__DOT__len3__DOT__count = VL_RAND_RESET_I(8);
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

void Vnesapu::_initial__TOP(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_initial__TOP\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    //char	__VpadToAlign4[4];
    VL_SIGW(__Vtemp1,111,0,4);
    VL_SIGW(__Vtemp2,111,0,4);
    VL_SIGW(__Vtemp3,111,0,4);
    // Body
    // INITIAL at source/nesapu.v:188
    __Vtemp1[0] = 0x2e747874;
    __Vtemp1[1] = 0x5f646163;
    __Vtemp1[2] = 0x73617075;
    __Vtemp1[3] = 0x6e65;
    VL_READMEM_W (true,16,32, 0,4, __Vtemp1, vlTOPp->v__DOT__AMP_TABLE
		  ,0,~0);
    // INITIAL at source/nesapu.v:192
    __Vtemp2[0] = 0x2e747874;
    __Vtemp2[1] = 0x5f747269;
    __Vtemp2[2] = 0x73617075;
    __Vtemp2[3] = 0x6e65;
    VL_READMEM_W (true,8,32, 0,4, __Vtemp2, vlTOPp->v__DOT__TRI_TABLE
		  ,0,~0);
    // INITIAL at source/nesapu.v:196
    __Vtemp3[0] = 0x2e747874;
    __Vtemp3[1] = 0x5f6c656e;
    __Vtemp3[2] = 0x73617075;
    __Vtemp3[3] = 0x6e65;
    VL_READMEM_W (true,8,32, 0,4, __Vtemp3, vlTOPp->v__DOT__LEN_TABLE
		  ,0,~0);
}

void Vnesapu::_sequent__TOP__1(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_sequent__TOP__1\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvset__v__DOT__apu_reg__v0,0,0);
    VL_SIG8(__Vdly__v__DOT__frame_step,4,0);
    VL_SIG8(__Vdlyvset__v__DOT__apu_reg__v1,0,0);
    VL_SIG8(__Vdly__v__DOT__tri_step,4,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__apu_reg__v2,4,0);
    VL_SIG8(__Vdlyvval__v__DOT__apu_reg__v2,7,0);
    VL_SIG8(__Vdlyvset__v__DOT__apu_reg__v2,0,0);
    VL_SIG8(__Vdly__v__DOT__pulse0__DOT__index,3,0);
    VL_SIG8(__Vdly__v__DOT__pulse1__DOT__index,3,0);
    VL_SIG8(__Vdly__v__DOT__pulse0_env__DOT__decay,3,0);
    VL_SIG8(__Vdly__v__DOT__pulse0_env__DOT__divider,3,0);
    VL_SIG8(__Vdly__v__DOT__pulse0_env__DOT__start,0,0);
    VL_SIG8(__Vdly__v__DOT__pulse1_env__DOT__decay,3,0);
    VL_SIG8(__Vdly__v__DOT__pulse1_env__DOT__divider,3,0);
    VL_SIG8(__Vdly__v__DOT__pulse1_env__DOT__start,0,0);
    VL_SIG8(__Vdly__v__DOT__lfsr_env__DOT__decay,3,0);
    VL_SIG8(__Vdly__v__DOT__lfsr_env__DOT__divider,3,0);
    VL_SIG8(__Vdly__v__DOT__lfsr_env__DOT__start,0,0);
    VL_SIG8(__Vdly__v__DOT__len0__DOT__count,7,0);
    VL_SIG8(__Vdly__v__DOT__len1__DOT__count,7,0);
    VL_SIG8(__Vdly__v__DOT__len2__DOT__count,7,0);
    VL_SIG8(__Vdly__v__DOT__len3__DOT__count,7,0);
    VL_SIG16(__Vdly__v__DOT__frame_cnt,11,0);
    VL_SIG16(__Vdly__v__DOT__tri_int,10,0);
    VL_SIG16(__Vdly__v__DOT__pulse0__DOT__counter,10,0);
    VL_SIG16(__Vdly__v__DOT__pulse1__DOT__counter,10,0);
    VL_SIG16(__Vdly__v__DOT__noise__DOT__lfsr,14,0);
    VL_SIG16(__Vdly__v__DOT__noise__DOT__count,11,0);
    VL_SIG16(__Vdly__v__DOT__noise__DOT__max_count,11,0);
    // Body
    __Vdly__v__DOT__pulse1__DOT__counter = vlTOPp->v__DOT__pulse1__DOT__counter;
    __Vdly__v__DOT__pulse0__DOT__counter = vlTOPp->v__DOT__pulse0__DOT__counter;
    __Vdly__v__DOT__noise__DOT__count = vlTOPp->v__DOT__noise__DOT__count;
    __Vdly__v__DOT__noise__DOT__max_count = vlTOPp->v__DOT__noise__DOT__max_count;
    __Vdly__v__DOT__pulse1__DOT__index = vlTOPp->v__DOT__pulse1__DOT__index;
    __Vdly__v__DOT__pulse0__DOT__index = vlTOPp->v__DOT__pulse0__DOT__index;
    __Vdly__v__DOT__noise__DOT__lfsr = vlTOPp->v__DOT__noise__DOT__lfsr;
    __Vdly__v__DOT__frame_cnt = vlTOPp->v__DOT__frame_cnt;
    __Vdly__v__DOT__frame_step = vlTOPp->v__DOT__frame_step;
    __Vdly__v__DOT__tri_int = vlTOPp->v__DOT__tri_int;
    __Vdly__v__DOT__tri_step = vlTOPp->v__DOT__tri_step;
    __Vdly__v__DOT__lfsr_env__DOT__start = vlTOPp->v__DOT__lfsr_env__DOT__start;
    __Vdly__v__DOT__lfsr_env__DOT__divider = vlTOPp->v__DOT__lfsr_env__DOT__divider;
    __Vdly__v__DOT__pulse0_env__DOT__start = vlTOPp->v__DOT__pulse0_env__DOT__start;
    __Vdly__v__DOT__pulse1_env__DOT__start = vlTOPp->v__DOT__pulse1_env__DOT__start;
    __Vdly__v__DOT__pulse1_env__DOT__divider = vlTOPp->v__DOT__pulse1_env__DOT__divider;
    __Vdly__v__DOT__pulse0_env__DOT__divider = vlTOPp->v__DOT__pulse0_env__DOT__divider;
    __Vdly__v__DOT__lfsr_env__DOT__decay = vlTOPp->v__DOT__lfsr_env__DOT__decay;
    __Vdly__v__DOT__pulse1_env__DOT__decay = vlTOPp->v__DOT__pulse1_env__DOT__decay;
    __Vdly__v__DOT__pulse0_env__DOT__decay = vlTOPp->v__DOT__pulse0_env__DOT__decay;
    __Vdly__v__DOT__len0__DOT__count = vlTOPp->v__DOT__len0__DOT__count;
    __Vdly__v__DOT__len1__DOT__count = vlTOPp->v__DOT__len1__DOT__count;
    __Vdly__v__DOT__len2__DOT__count = vlTOPp->v__DOT__len2__DOT__count;
    __Vdly__v__DOT__len3__DOT__count = vlTOPp->v__DOT__len3__DOT__count;
    __Vdlyvset__v__DOT__apu_reg__v0 = 0;
    __Vdlyvset__v__DOT__apu_reg__v1 = 0;
    __Vdlyvset__v__DOT__apu_reg__v2 = 0;
    // ALWAYS at source/nesapu.v:83
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__pulse1__DOT__counter = 0;
	__Vdly__v__DOT__pulse1__DOT__index = 0;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__pulse1__DOT__counter))) {
	    __Vdly__v__DOT__pulse1__DOT__index = (0xf 
						  & ((IData)(1) 
						     + (IData)(vlTOPp->v__DOT__pulse1__DOT__index)));
	    __Vdly__v__DOT__pulse1__DOT__counter = 
		(0x7ff & ((IData)(1) + (IData)(vlTOPp->v__DOT__pulse1_freq)));
	} else {
	    __Vdly__v__DOT__pulse1__DOT__counter = 
		(0x7ff & ((IData)(vlTOPp->v__DOT__pulse1__DOT__counter) 
			  - (IData)(1)));
	}
    }
    // ALWAYS at source/nesapu.v:83
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__pulse0__DOT__counter = 0;
	__Vdly__v__DOT__pulse0__DOT__index = 0;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__pulse0__DOT__counter))) {
	    __Vdly__v__DOT__pulse0__DOT__index = (0xf 
						  & ((IData)(1) 
						     + (IData)(vlTOPp->v__DOT__pulse0__DOT__index)));
	    __Vdly__v__DOT__pulse0__DOT__counter = 
		(0x7ff & ((IData)(1) + (IData)(vlTOPp->v__DOT__pulse0_freq)));
	} else {
	    __Vdly__v__DOT__pulse0__DOT__counter = 
		(0x7ff & ((IData)(vlTOPp->v__DOT__pulse0__DOT__counter) 
			  - (IData)(1)));
	}
    }
    // ALWAYS at source/nesapu.v:143
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__noise__DOT__lfsr = 1;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__noise__DOT__count))) {
	    __Vdly__v__DOT__noise__DOT__lfsr = ((0x4000 
						 & (((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
						     ^ 
						     ((IData)(vlTOPp->v__DOT__lfsr_mode)
						       ? 
						      ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
						       >> 6)
						       : 
						      ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
						       >> 1))) 
						    << 0xe)) 
						| (0x3fff 
						   & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
						      >> 1)));
	    __Vdly__v__DOT__noise__DOT__count = vlTOPp->v__DOT__noise__DOT__max_count;
	} else {
	    __Vdly__v__DOT__noise__DOT__count = (0xfff 
						 & ((IData)(vlTOPp->v__DOT__noise__DOT__count) 
						    - (IData)(1)));
	}
	if (((((((((0 == (IData)(vlTOPp->v__DOT__lfsr_freq)) 
		   | (1 == (IData)(vlTOPp->v__DOT__lfsr_freq))) 
		  | (2 == (IData)(vlTOPp->v__DOT__lfsr_freq))) 
		 | (3 == (IData)(vlTOPp->v__DOT__lfsr_freq))) 
		| (4 == (IData)(vlTOPp->v__DOT__lfsr_freq))) 
	       | (5 == (IData)(vlTOPp->v__DOT__lfsr_freq))) 
	      | (6 == (IData)(vlTOPp->v__DOT__lfsr_freq))) 
	     | (7 == (IData)(vlTOPp->v__DOT__lfsr_freq)))) {
	    __Vdly__v__DOT__noise__DOT__max_count = 
		((0 == (IData)(vlTOPp->v__DOT__lfsr_freq))
		  ? 4 : ((1 == (IData)(vlTOPp->v__DOT__lfsr_freq))
			  ? 8 : ((2 == (IData)(vlTOPp->v__DOT__lfsr_freq))
				  ? 0x10 : ((3 == (IData)(vlTOPp->v__DOT__lfsr_freq))
					     ? 0x20
					     : ((4 
						 == (IData)(vlTOPp->v__DOT__lfsr_freq))
						 ? 0x40
						 : 
						((5 
						  == (IData)(vlTOPp->v__DOT__lfsr_freq))
						  ? 0x60
						  : 
						 ((6 
						   == (IData)(vlTOPp->v__DOT__lfsr_freq))
						   ? 0x80
						   : 0xa0)))))));
	} else {
	    if (((((((((8 == (IData)(vlTOPp->v__DOT__lfsr_freq)) 
		       | (9 == (IData)(vlTOPp->v__DOT__lfsr_freq))) 
		      | (0xa == (IData)(vlTOPp->v__DOT__lfsr_freq))) 
		     | (0xb == (IData)(vlTOPp->v__DOT__lfsr_freq))) 
		    | (0xc == (IData)(vlTOPp->v__DOT__lfsr_freq))) 
		   | (0xd == (IData)(vlTOPp->v__DOT__lfsr_freq))) 
		  | (0xe == (IData)(vlTOPp->v__DOT__lfsr_freq))) 
		 | (0xf == (IData)(vlTOPp->v__DOT__lfsr_freq)))) {
		__Vdly__v__DOT__noise__DOT__max_count 
		    = ((8 == (IData)(vlTOPp->v__DOT__lfsr_freq))
		        ? 0xca : ((9 == (IData)(vlTOPp->v__DOT__lfsr_freq))
				   ? 0xfe : ((0xa == (IData)(vlTOPp->v__DOT__lfsr_freq))
					      ? 0x17c
					      : ((0xb 
						  == (IData)(vlTOPp->v__DOT__lfsr_freq))
						  ? 0x1fc
						  : 
						 ((0xc 
						   == (IData)(vlTOPp->v__DOT__lfsr_freq))
						   ? 0x2fa
						   : 
						  ((0xd 
						    == (IData)(vlTOPp->v__DOT__lfsr_freq))
						    ? 0x3f8
						    : 
						   ((0xe 
						     == (IData)(vlTOPp->v__DOT__lfsr_freq))
						     ? 0x7f2
						     : 0xfe4)))))));
	    }
	}
    }
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
    // ALWAYS at source/nesapu.v:111
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__len0__DOT__count = 0;
    } else {
	if (vlTOPp->v__DOT__reload_len0) {
	    __Vdly__v__DOT__len0__DOT__count = vlTOPp->v__DOT____Vcellinp__len0____pinNumber6;
	} else {
	    if (((IData)(vlTOPp->v__DOT__tick_len) 
		 & (~ (IData)(vlTOPp->v__DOT____Vcellinp__len0____pinNumber5)))) {
		__Vdly__v__DOT__len0__DOT__count = 
		    (0xff & ((0 == (IData)(vlTOPp->v__DOT__len0__DOT__count))
			      ? 0 : ((IData)(vlTOPp->v__DOT__len0__DOT__count) 
				     - (IData)(1))));
	    }
	}
    }
    // ALWAYS at source/nesapu.v:111
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__len1__DOT__count = 0;
    } else {
	if (vlTOPp->v__DOT__reload_len1) {
	    __Vdly__v__DOT__len1__DOT__count = vlTOPp->v__DOT____Vcellinp__len1____pinNumber6;
	} else {
	    if (((IData)(vlTOPp->v__DOT__tick_len) 
		 & (~ (IData)(vlTOPp->v__DOT____Vcellinp__len1____pinNumber5)))) {
		__Vdly__v__DOT__len1__DOT__count = 
		    (0xff & ((0 == (IData)(vlTOPp->v__DOT__len1__DOT__count))
			      ? 0 : ((IData)(vlTOPp->v__DOT__len1__DOT__count) 
				     - (IData)(1))));
	    }
	}
    }
    // ALWAYS at source/nesapu.v:111
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__len2__DOT__count = 0;
    } else {
	if (vlTOPp->v__DOT__reload_len2) {
	    __Vdly__v__DOT__len2__DOT__count = vlTOPp->v__DOT____Vcellinp__len2____pinNumber6;
	} else {
	    if (((IData)(vlTOPp->v__DOT__tick_len) 
		 & (~ (IData)(vlTOPp->v__DOT____Vcellinp__len2____pinNumber5)))) {
		__Vdly__v__DOT__len2__DOT__count = 
		    (0xff & ((0 == (IData)(vlTOPp->v__DOT__len2__DOT__count))
			      ? 0 : ((IData)(vlTOPp->v__DOT__len2__DOT__count) 
				     - (IData)(1))));
	    }
	}
    }
    // ALWAYS at source/nesapu.v:111
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__len3__DOT__count = 0;
    } else {
	if (vlTOPp->v__DOT__reload_len3) {
	    __Vdly__v__DOT__len3__DOT__count = vlTOPp->v__DOT____Vcellinp__len3____pinNumber6;
	} else {
	    if (((IData)(vlTOPp->v__DOT__tick_len) 
		 & (~ (IData)(vlTOPp->v__DOT____Vcellinp__len3____pinNumber5)))) {
		__Vdly__v__DOT__len3__DOT__count = 
		    (0xff & ((0 == (IData)(vlTOPp->v__DOT__len3__DOT__count))
			      ? 0 : ((IData)(vlTOPp->v__DOT__len3__DOT__count) 
				     - (IData)(1))));
	    }
	}
    }
    vlTOPp->v__DOT__pulse1__DOT__counter = __Vdly__v__DOT__pulse1__DOT__counter;
    vlTOPp->v__DOT__pulse1__DOT__index = __Vdly__v__DOT__pulse1__DOT__index;
    vlTOPp->v__DOT__pulse0__DOT__counter = __Vdly__v__DOT__pulse0__DOT__counter;
    vlTOPp->v__DOT__pulse0__DOT__index = __Vdly__v__DOT__pulse0__DOT__index;
    vlTOPp->v__DOT__noise__DOT__count = __Vdly__v__DOT__noise__DOT__count;
    vlTOPp->v__DOT__noise__DOT__max_count = __Vdly__v__DOT__noise__DOT__max_count;
    vlTOPp->v__DOT__noise__DOT__lfsr = __Vdly__v__DOT__noise__DOT__lfsr;
    vlTOPp->v__DOT__lfsr_env__DOT__divider = __Vdly__v__DOT__lfsr_env__DOT__divider;
    vlTOPp->v__DOT__lfsr_env__DOT__start = __Vdly__v__DOT__lfsr_env__DOT__start;
    vlTOPp->v__DOT__lfsr_env__DOT__decay = __Vdly__v__DOT__lfsr_env__DOT__decay;
    vlTOPp->v__DOT__pulse1_env__DOT__divider = __Vdly__v__DOT__pulse1_env__DOT__divider;
    vlTOPp->v__DOT__pulse1_env__DOT__start = __Vdly__v__DOT__pulse1_env__DOT__start;
    vlTOPp->v__DOT__pulse1_env__DOT__decay = __Vdly__v__DOT__pulse1_env__DOT__decay;
    vlTOPp->v__DOT__pulse0_env__DOT__divider = __Vdly__v__DOT__pulse0_env__DOT__divider;
    vlTOPp->v__DOT__pulse0_env__DOT__start = __Vdly__v__DOT__pulse0_env__DOT__start;
    vlTOPp->v__DOT__pulse0_env__DOT__decay = __Vdly__v__DOT__pulse0_env__DOT__decay;
    vlTOPp->v__DOT__len0__DOT__count = __Vdly__v__DOT__len0__DOT__count;
    vlTOPp->v__DOT__len1__DOT__count = __Vdly__v__DOT__len1__DOT__count;
    vlTOPp->v__DOT__len2__DOT__count = __Vdly__v__DOT__len2__DOT__count;
    vlTOPp->v__DOT__len3__DOT__count = __Vdly__v__DOT__len3__DOT__count;
    // ALWAYS at source/nesapu.v:313
    if (vlTOPp->in_rst) {
	__Vdlyvset__v__DOT__apu_reg__v0 = 1;
	__Vdly__v__DOT__frame_step = 1;
	__Vdly__v__DOT__frame_cnt = 0;
	__Vdlyvset__v__DOT__apu_reg__v1 = 1;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__tri_int))) {
	    __Vdly__v__DOT__tri_step = (0x1f & ((IData)(1) 
						+ (IData)(vlTOPp->v__DOT__tri_step)));
	    __Vdly__v__DOT__tri_int = (0x7ff & ((IData)(1) 
						+ (IData)(vlTOPp->v__DOT__tri_freq)));
	} else {
	    __Vdly__v__DOT__tri_int = (0x7ff & ((IData)(vlTOPp->v__DOT__tri_int) 
						- (IData)(1)));
	}
	vlTOPp->v__DOT__pulse0_env_start = ((IData)(vlTOPp->v__DOT__posedge_wr) 
					    & (3 == (IData)(vlTOPp->in_reg)));
	vlTOPp->v__DOT__tick_len = ((0 == (IData)(vlTOPp->v__DOT__frame_cnt)) 
				    & ((1 == (IData)(vlTOPp->v__DOT__frame_step)) 
				       | (4 == (IData)(vlTOPp->v__DOT__frame_step))));
	vlTOPp->v__DOT__pulse1_env_start = ((IData)(vlTOPp->v__DOT__posedge_wr) 
					    & (7 == (IData)(vlTOPp->in_reg)));
	if ((0 == (IData)(vlTOPp->v__DOT__frame_cnt))) {
	    __Vdly__v__DOT__frame_step = ((0x1e & ((IData)(vlTOPp->v__DOT__frame_step) 
						   << 1)) 
					  | (1 & ((IData)(vlTOPp->v__DOT__frame_step) 
						  >> 4)));
	    __Vdly__v__DOT__frame_cnt = 0x1d21;
	} else {
	    __Vdly__v__DOT__frame_cnt = (0xfff & ((IData)(vlTOPp->v__DOT__frame_cnt) 
						  - (IData)(1)));
	}
	vlTOPp->v__DOT__lfsr_env_start = ((IData)(vlTOPp->v__DOT__posedge_wr) 
					  & (0xf == (IData)(vlTOPp->in_reg)));
	vlTOPp->v__DOT__reload_len0 = ((IData)(vlTOPp->v__DOT__posedge_wr) 
				       & (3 == (IData)(vlTOPp->in_reg)));
	vlTOPp->v__DOT__reload_len1 = ((IData)(vlTOPp->v__DOT__posedge_wr) 
				       & (7 == (IData)(vlTOPp->in_reg)));
	vlTOPp->v__DOT__reload_len2 = ((IData)(vlTOPp->v__DOT__posedge_wr) 
				       & (0xb == (IData)(vlTOPp->in_reg)));
	vlTOPp->v__DOT__reload_len3 = ((IData)(vlTOPp->v__DOT__posedge_wr) 
				       & (0xf == (IData)(vlTOPp->in_reg)));
	if (vlTOPp->v__DOT__posedge_wr) {
	    vlTOPp->v__DOT____Vlvbound1 = vlTOPp->in_val;
	    if (((IData)(vlTOPp->in_reg) <= 0x16)) {
		__Vdlyvval__v__DOT__apu_reg__v2 = vlTOPp->v__DOT____Vlvbound1;
		__Vdlyvset__v__DOT__apu_reg__v2 = 1;
		__Vdlyvdim0__v__DOT__apu_reg__v2 = vlTOPp->in_reg;
	    }
	}
    }
    vlTOPp->v__DOT__old_wr = vlTOPp->in_wr;
    vlTOPp->v__DOT__tri_int = __Vdly__v__DOT__tri_int;
    vlTOPp->v__DOT__frame_step = __Vdly__v__DOT__frame_step;
    vlTOPp->v__DOT__frame_cnt = __Vdly__v__DOT__frame_cnt;
    vlTOPp->v__DOT__tri_step = __Vdly__v__DOT__tri_step;
    // ALWAYSPOST at source/nesapu.v:315
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
    vlTOPp->v__DOT____Vcellinp__len3____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0xc] 
		>> 5));
    vlTOPp->v__DOT____Vcellinp__len2____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[8] 
		>> 7));
    vlTOPp->v__DOT____Vcellinp__len1____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[4] 
		>> 5));
    vlTOPp->v__DOT____Vcellinp__len0____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0] 
		>> 5));
    vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber4 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0xc] 
		>> 5));
    vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber4 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[4] 
		>> 5));
    vlTOPp->v__DOT__tri_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__apu_reg)
					  [0xb] << 8)) 
				| (IData)(vlTOPp->v__DOT__apu_reg)
				[0xa]);
    vlTOPp->v__DOT__pulse0_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__apu_reg)
					     [3] << 8)) 
				   | (IData)(vlTOPp->v__DOT__apu_reg)
				   [2]);
    vlTOPp->v__DOT__pulse1_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__apu_reg)
					     [7] << 8)) 
				   | (IData)(vlTOPp->v__DOT__apu_reg)
				   [6]);
    vlTOPp->v__DOT__lfsr_mode = (1 & ((IData)(vlTOPp->v__DOT__apu_reg)
				      [0xe] >> 7));
    vlTOPp->v__DOT__lfsr_freq = (0xf & (IData)(vlTOPp->v__DOT__apu_reg)
				 [0xe]);
    vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber4 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0] 
		>> 5));
    vlTOPp->v__DOT____Vcellinp__len0____pinNumber6 
	= (IData)(vlTOPp->v__DOT__LEN_TABLE)[(0x1f 
					      & ((IData)(vlTOPp->v__DOT__apu_reg)
						 [3] 
						 >> 3))];
    vlTOPp->v__DOT____Vcellinp__len1____pinNumber6 
	= (IData)(vlTOPp->v__DOT__LEN_TABLE)[(0x1f 
					      & ((IData)(vlTOPp->v__DOT__apu_reg)
						 [7] 
						 >> 3))];
    vlTOPp->v__DOT____Vcellinp__len2____pinNumber6 
	= (IData)(vlTOPp->v__DOT__LEN_TABLE)[(0x1f 
					      & ((IData)(vlTOPp->v__DOT__apu_reg)
						 [0xb] 
						 >> 3))];
    vlTOPp->v__DOT____Vcellinp__len3____pinNumber6 
	= (IData)(vlTOPp->v__DOT__LEN_TABLE)[(0x1f 
					      & ((IData)(vlTOPp->v__DOT__apu_reg)
						 [0xf] 
						 >> 3))];
    vlTOPp->v__DOT__pulse1_enable = (1 & ((IData)(vlTOPp->v__DOT__apu_reg)
					  [0x15] >> 1));
    vlTOPp->v__DOT__pulse0_enable = (1 & (IData)(vlTOPp->v__DOT__apu_reg)
				     [0x15]);
    vlTOPp->v__DOT__tri_enable = (1 & ((IData)(vlTOPp->v__DOT__apu_reg)
				       [0x15] >> 2));
    vlTOPp->v__DOT__noise_enable = (1 & ((IData)(vlTOPp->v__DOT__apu_reg)
					 [0x15] >> 3));
    vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber3 
	= (0xf & (IData)(vlTOPp->v__DOT__apu_reg)[0xc]);
    vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0xc] 
		>> 4));
    vlTOPp->v__DOT__pulse0_duty = (3 & ((IData)(vlTOPp->v__DOT__apu_reg)
					[0] >> 6));
    vlTOPp->v__DOT__pulse1_duty = (3 & ((IData)(vlTOPp->v__DOT__apu_reg)
					[4] >> 6));
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
}

void Vnesapu::_combo__TOP__2(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_combo__TOP__2\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__posedge_wr = ((IData)(vlTOPp->in_wr) 
				  & (~ (IData)(vlTOPp->v__DOT__old_wr)));
}

void Vnesapu::_settle__TOP__3(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_settle__TOP__3\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__posedge_wr = ((IData)(vlTOPp->in_wr) 
				  & (~ (IData)(vlTOPp->v__DOT__old_wr)));
    vlTOPp->v__DOT__tri_out = (IData)(vlTOPp->v__DOT__TRI_TABLE)
	[(IData)(vlTOPp->v__DOT__tri_step)];
    vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber4 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0xc] 
		>> 5));
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
    vlTOPp->v__DOT__lfsr_mode = (1 & ((IData)(vlTOPp->v__DOT__apu_reg)
				      [0xe] >> 7));
    vlTOPp->v__DOT__lfsr_freq = (0xf & (IData)(vlTOPp->v__DOT__apu_reg)
				 [0xe]);
    vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber4 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0] 
		>> 5));
    vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber4 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[4] 
		>> 5));
    vlTOPp->v__DOT____Vcellinp__len3____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0xc] 
		>> 5));
    vlTOPp->v__DOT____Vcellinp__len2____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[8] 
		>> 7));
    vlTOPp->v__DOT____Vcellinp__len1____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[4] 
		>> 5));
    vlTOPp->v__DOT____Vcellinp__len0____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0] 
		>> 5));
    vlTOPp->v__DOT____Vcellinp__len0____pinNumber6 
	= (IData)(vlTOPp->v__DOT__LEN_TABLE)[(0x1f 
					      & ((IData)(vlTOPp->v__DOT__apu_reg)
						 [3] 
						 >> 3))];
    vlTOPp->v__DOT____Vcellinp__len1____pinNumber6 
	= (IData)(vlTOPp->v__DOT__LEN_TABLE)[(0x1f 
					      & ((IData)(vlTOPp->v__DOT__apu_reg)
						 [7] 
						 >> 3))];
    vlTOPp->v__DOT____Vcellinp__len2____pinNumber6 
	= (IData)(vlTOPp->v__DOT__LEN_TABLE)[(0x1f 
					      & ((IData)(vlTOPp->v__DOT__apu_reg)
						 [0xb] 
						 >> 3))];
    vlTOPp->v__DOT____Vcellinp__len3____pinNumber6 
	= (IData)(vlTOPp->v__DOT__LEN_TABLE)[(0x1f 
					      & ((IData)(vlTOPp->v__DOT__apu_reg)
						 [0xf] 
						 >> 3))];
    vlTOPp->v__DOT__pulse0_enable = (1 & (IData)(vlTOPp->v__DOT__apu_reg)
				     [0x15]);
    vlTOPp->v__DOT__noise_enable = (1 & ((IData)(vlTOPp->v__DOT__apu_reg)
					 [0x15] >> 3));
    vlTOPp->v__DOT__tri_enable = (1 & ((IData)(vlTOPp->v__DOT__apu_reg)
				       [0x15] >> 2));
    vlTOPp->v__DOT__pulse1_enable = (1 & ((IData)(vlTOPp->v__DOT__apu_reg)
					  [0x15] >> 1));
    vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0xc] 
		>> 4));
    vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber3 
	= (0xf & (IData)(vlTOPp->v__DOT__apu_reg)[0xc]);
    vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber3 
	= (0xf & (IData)(vlTOPp->v__DOT__apu_reg)[4]);
    vlTOPp->v__DOT__pulse0_duty = (3 & ((IData)(vlTOPp->v__DOT__apu_reg)
					[0] >> 6));
    vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[4] 
		>> 4));
    vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber3 
	= (0xf & (IData)(vlTOPp->v__DOT__apu_reg)[0]);
    vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__apu_reg)[0] 
		>> 4));
    vlTOPp->v__DOT__pulse1_duty = (3 & ((IData)(vlTOPp->v__DOT__apu_reg)
					[4] >> 6));
    vlTOPp->v__DOT__lfsr_out = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
		   << 4)) | ((IData)(vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber5)
			      ? (IData)(vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber3)
			      : (IData)(vlTOPp->v__DOT__lfsr_env__DOT__decay)))];
    vlTOPp->v__DOT__pulse0_out = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((0x9f786040 >> (((IData)(vlTOPp->v__DOT__pulse0_duty) 
				    << 3) | (7 & ((IData)(vlTOPp->v__DOT__pulse0__DOT__index) 
						  >> 1)))) 
		   << 4)) | ((IData)(vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber5)
			      ? (IData)(vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber3)
			      : (IData)(vlTOPp->v__DOT__pulse0_env__DOT__decay)))];
    vlTOPp->v__DOT__pulse1_out = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((0x9f786040 >> (((IData)(vlTOPp->v__DOT__pulse1_duty) 
				    << 3) | (7 & ((IData)(vlTOPp->v__DOT__pulse1__DOT__index) 
						  >> 1)))) 
		   << 4)) | ((IData)(vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber5)
			      ? (IData)(vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber3)
			      : (IData)(vlTOPp->v__DOT__pulse1_env__DOT__decay)))];
}

void Vnesapu::_sequent__TOP__4(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_sequent__TOP__4\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__lfsr_out = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
		   << 4)) | ((IData)(vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber5)
			      ? (IData)(vlTOPp->v__DOT____Vcellinp__lfsr_env____pinNumber3)
			      : (IData)(vlTOPp->v__DOT__lfsr_env__DOT__decay)))];
    vlTOPp->v__DOT__pulse0_out = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((0x9f786040 >> (((IData)(vlTOPp->v__DOT__pulse0_duty) 
				    << 3) | (7 & ((IData)(vlTOPp->v__DOT__pulse0__DOT__index) 
						  >> 1)))) 
		   << 4)) | ((IData)(vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber5)
			      ? (IData)(vlTOPp->v__DOT____Vcellinp__pulse0_env____pinNumber3)
			      : (IData)(vlTOPp->v__DOT__pulse0_env__DOT__decay)))];
    vlTOPp->v__DOT__pulse1_out = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((0x9f786040 >> (((IData)(vlTOPp->v__DOT__pulse1_duty) 
				    << 3) | (7 & ((IData)(vlTOPp->v__DOT__pulse1__DOT__index) 
						  >> 1)))) 
		   << 4)) | ((IData)(vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber5)
			      ? (IData)(vlTOPp->v__DOT____Vcellinp__pulse1_env____pinNumber3)
			      : (IData)(vlTOPp->v__DOT__pulse1_env__DOT__decay)))];
    vlTOPp->out_lr = (0xffff & (((((1 & ((~ (IData)(vlTOPp->v__DOT__pulse0_enable)) 
					 | (0 == (IData)(vlTOPp->v__DOT__len0__DOT__count))))
				    ? 0 : (IData)(vlTOPp->v__DOT__pulse0_out)) 
				  + ((1 & ((~ (IData)(vlTOPp->v__DOT__pulse1_enable)) 
					   | (0 == (IData)(vlTOPp->v__DOT__len1__DOT__count))))
				      ? 0 : (IData)(vlTOPp->v__DOT__pulse1_out))) 
				 + ((1 & ((~ (IData)(vlTOPp->v__DOT__tri_enable)) 
					  | (0 == (IData)(vlTOPp->v__DOT__len2__DOT__count))))
				     ? 0 : ((IData)(vlTOPp->v__DOT__tri_out) 
					    << 8))) 
				+ ((1 & ((~ (IData)(vlTOPp->v__DOT__noise_enable)) 
					 | (0 == (IData)(vlTOPp->v__DOT__len3__DOT__count))))
				    ? 0 : (IData)(vlTOPp->v__DOT__lfsr_out))));
}

void Vnesapu::_settle__TOP__5(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_settle__TOP__5\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out_lr = (0xffff & (((((1 & ((~ (IData)(vlTOPp->v__DOT__pulse0_enable)) 
					 | (0 == (IData)(vlTOPp->v__DOT__len0__DOT__count))))
				    ? 0 : (IData)(vlTOPp->v__DOT__pulse0_out)) 
				  + ((1 & ((~ (IData)(vlTOPp->v__DOT__pulse1_enable)) 
					   | (0 == (IData)(vlTOPp->v__DOT__len1__DOT__count))))
				      ? 0 : (IData)(vlTOPp->v__DOT__pulse1_out))) 
				 + ((1 & ((~ (IData)(vlTOPp->v__DOT__tri_enable)) 
					  | (0 == (IData)(vlTOPp->v__DOT__len2__DOT__count))))
				     ? 0 : ((IData)(vlTOPp->v__DOT__tri_out) 
					    << 8))) 
				+ ((1 & ((~ (IData)(vlTOPp->v__DOT__noise_enable)) 
					 | (0 == (IData)(vlTOPp->v__DOT__len3__DOT__count))))
				    ? 0 : (IData)(vlTOPp->v__DOT__lfsr_out))));
}

void Vnesapu::_eval(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_eval\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__2(vlSymsp);
    if (((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk)))) {
	vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__in_clk = vlTOPp->in_clk;
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
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->_settle__TOP__5(vlSymsp);
}

IData Vnesapu::_change_request(Vnesapu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vnesapu::_change_request\n"); );
    Vnesapu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    return __req;
}
