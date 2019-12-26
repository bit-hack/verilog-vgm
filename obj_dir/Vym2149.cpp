// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vym2149.h for the primary calling header

#include "Vym2149.h"           // For This
#include "Vym2149__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vym2149) {
    Vym2149__Syms* __restrict vlSymsp = __VlSymsp = new Vym2149__Syms(this, name());
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
    v__DOT__old_wr = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    v__DOT__r[__Vi0] = VL_RAND_RESET_I(8);
    }}
    v__DOT__ca_freq = VL_RAND_RESET_I(12);
    v__DOT__cb_freq = VL_RAND_RESET_I(12);
    v__DOT__cc_freq = VL_RAND_RESET_I(12);
    v__DOT__ca_tone = VL_RAND_RESET_I(12);
    v__DOT__cb_tone = VL_RAND_RESET_I(12);
    v__DOT__cc_tone = VL_RAND_RESET_I(12);
    v__DOT__ca_bit = VL_RAND_RESET_I(1);
    v__DOT__cb_bit = VL_RAND_RESET_I(1);
    v__DOT__cc_bit = VL_RAND_RESET_I(1);
    v__DOT__ca_mix = VL_RAND_RESET_I(16);
    v__DOT__cb_mix = VL_RAND_RESET_I(16);
    v__DOT__cc_mix = VL_RAND_RESET_I(16);
    v__DOT__ca_tone_enable = VL_RAND_RESET_I(1);
    v__DOT__cb_tone_enable = VL_RAND_RESET_I(1);
    v__DOT__cc_tone_enable = VL_RAND_RESET_I(1);
    v__DOT__ca_lfsr_enable = VL_RAND_RESET_I(1);
    v__DOT__cb_lfsr_enable = VL_RAND_RESET_I(1);
    v__DOT__cc_lfsr_enable = VL_RAND_RESET_I(1);
    v__DOT__ca_amp = VL_RAND_RESET_I(4);
    v__DOT__cb_amp = VL_RAND_RESET_I(4);
    v__DOT__cc_amp = VL_RAND_RESET_I(4);
    v__DOT__lfsr = VL_RAND_RESET_I(17);
    v__DOT__clk_div = VL_RAND_RESET_I(3);
    v__DOT__noz_div = VL_RAND_RESET_I(3);
    __Vclklast__TOP__in_clk = 0;
}

void Vym2149::__Vconfigure(Vym2149__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vym2149::~Vym2149() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vym2149::eval() {
    Vym2149__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vym2149::eval\n"); );
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

void Vym2149::_eval_initial_loop(Vym2149__Syms* __restrict vlSymsp) {
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

void Vym2149::_initial__TOP(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_initial__TOP\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    //char	__VpadToAlign4[4];
    VL_SIGW(__Vtemp1,111,0,4);
    // Body
    // INITIAL at source/ym2149.v:19
    __Vtemp1[0] = 0x2e747874;
    __Vtemp1[1] = 0x5f646163;
    __Vtemp1[2] = 0x32313439;
    __Vtemp1[3] = 0x796d;
    VL_READMEM_W (true,16,32, 0,4, __Vtemp1, vlTOPp->v__DOT__AMP_TABLE
		  ,0,~0);
}

void Vym2149::_sequent__TOP__1(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_sequent__TOP__1\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvset__v__DOT__r__v0,0,0);
    VL_SIG8(__Vdly__v__DOT__ca_bit,0,0);
    VL_SIG8(__Vdly__v__DOT__cb_bit,0,0);
    VL_SIG8(__Vdly__v__DOT__cc_bit,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__r__v1,0,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__r__v9,3,0);
    VL_SIG8(__Vdlyvval__v__DOT__r__v9,7,0);
    VL_SIG8(__Vdlyvset__v__DOT__r__v9,0,0);
    VL_SIG8(__Vdly__v__DOT__clk_div,2,0);
    VL_SIG8(__Vdly__v__DOT__noz_div,2,0);
    VL_SIG8(__Vdly__v__DOT__old_wr,0,0);
    //char	__VpadToAlign55[1];
    VL_SIG16(__Vdly__v__DOT__ca_tone,11,0);
    VL_SIG16(__Vdly__v__DOT__cb_tone,11,0);
    VL_SIG16(__Vdly__v__DOT__cc_tone,11,0);
    //char	__VpadToAlign62[2];
    VL_SIG(__Vdly__v__DOT__lfsr,16,0);
    // Body
    __Vdly__v__DOT__cc_tone = vlTOPp->v__DOT__cc_tone;
    __Vdly__v__DOT__ca_tone = vlTOPp->v__DOT__ca_tone;
    __Vdly__v__DOT__cb_tone = vlTOPp->v__DOT__cb_tone;
    __Vdly__v__DOT__noz_div = vlTOPp->v__DOT__noz_div;
    __Vdly__v__DOT__clk_div = vlTOPp->v__DOT__clk_div;
    __Vdly__v__DOT__old_wr = vlTOPp->v__DOT__old_wr;
    __Vdly__v__DOT__cb_bit = vlTOPp->v__DOT__cb_bit;
    __Vdly__v__DOT__ca_bit = vlTOPp->v__DOT__ca_bit;
    __Vdly__v__DOT__cc_bit = vlTOPp->v__DOT__cc_bit;
    __Vdly__v__DOT__lfsr = vlTOPp->v__DOT__lfsr;
    __Vdlyvset__v__DOT__r__v0 = 0;
    __Vdlyvset__v__DOT__r__v1 = 0;
    __Vdlyvset__v__DOT__r__v9 = 0;
    // ALWAYS at source/ym2149.v:85
    if (vlTOPp->in_rst) {
	__Vdlyvset__v__DOT__r__v0 = 1;
	__Vdly__v__DOT__ca_tone = 0;
	__Vdly__v__DOT__cb_tone = 0;
	__Vdly__v__DOT__cc_tone = 0;
	__Vdly__v__DOT__ca_bit = 0;
	__Vdly__v__DOT__cb_bit = 0;
	__Vdly__v__DOT__cc_bit = 0;
	__Vdly__v__DOT__lfsr = 0x1ffff;
	__Vdlyvset__v__DOT__r__v1 = 1;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__clk_div))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__ca_tone))) {
		__Vdly__v__DOT__ca_bit = (1 & (~ (IData)(vlTOPp->v__DOT__ca_bit)));
		__Vdly__v__DOT__ca_tone = vlTOPp->v__DOT__ca_freq;
	    } else {
		__Vdly__v__DOT__ca_tone = (0xfff & 
					   ((IData)(vlTOPp->v__DOT__ca_tone) 
					    - (IData)(1)));
	    }
	    if ((0 == (IData)(vlTOPp->v__DOT__cb_tone))) {
		__Vdly__v__DOT__cb_bit = (1 & (~ (IData)(vlTOPp->v__DOT__cb_bit)));
		__Vdly__v__DOT__cb_tone = vlTOPp->v__DOT__cb_freq;
	    } else {
		__Vdly__v__DOT__cb_tone = (0xfff & 
					   ((IData)(vlTOPp->v__DOT__cb_tone) 
					    - (IData)(1)));
	    }
	    if ((0 == (IData)(vlTOPp->v__DOT__cc_tone))) {
		__Vdly__v__DOT__cc_bit = (1 & (~ (IData)(vlTOPp->v__DOT__cc_bit)));
		__Vdly__v__DOT__cc_tone = vlTOPp->v__DOT__cc_freq;
	    } else {
		__Vdly__v__DOT__cc_tone = (0xfff & 
					   ((IData)(vlTOPp->v__DOT__cc_tone) 
					    - (IData)(1)));
	    }
	}
	if ((0 == (IData)(vlTOPp->v__DOT__noz_div))) {
	    __Vdly__v__DOT__lfsr = ((0x10000 & ((vlTOPp->v__DOT__lfsr 
						 << 0x10) 
						^ (0xffff0000 
						   & (vlTOPp->v__DOT__lfsr 
						      << 0xd)))) 
				    | (0xffff & (vlTOPp->v__DOT__lfsr 
						 >> 1)));
	}
	if (((IData)(vlTOPp->in_wr) & (~ (IData)(vlTOPp->v__DOT__old_wr)))) {
	    __Vdlyvval__v__DOT__r__v9 = vlTOPp->in_val;
	    __Vdlyvset__v__DOT__r__v9 = 1;
	    __Vdlyvdim0__v__DOT__r__v9 = vlTOPp->in_reg;
	}
    }
    __Vdly__v__DOT__clk_div = (7 & ((IData)(1) + (IData)(vlTOPp->v__DOT__clk_div)));
    __Vdly__v__DOT__noz_div = (7 & ((IData)(1) + (IData)(vlTOPp->v__DOT__noz_div)));
    __Vdly__v__DOT__old_wr = vlTOPp->in_wr;
    vlTOPp->v__DOT__old_wr = __Vdly__v__DOT__old_wr;
    vlTOPp->v__DOT__cb_tone = __Vdly__v__DOT__cb_tone;
    vlTOPp->v__DOT__clk_div = __Vdly__v__DOT__clk_div;
    vlTOPp->v__DOT__noz_div = __Vdly__v__DOT__noz_div;
    vlTOPp->v__DOT__cc_tone = __Vdly__v__DOT__cc_tone;
    vlTOPp->v__DOT__ca_tone = __Vdly__v__DOT__ca_tone;
    vlTOPp->v__DOT__cc_bit = __Vdly__v__DOT__cc_bit;
    vlTOPp->v__DOT__cb_bit = __Vdly__v__DOT__cb_bit;
    vlTOPp->v__DOT__ca_bit = __Vdly__v__DOT__ca_bit;
    vlTOPp->v__DOT__lfsr = __Vdly__v__DOT__lfsr;
    // ALWAYSPOST at source/ym2149.v:89
    if (__Vdlyvset__v__DOT__r__v0) {
	vlTOPp->v__DOT__r[0] = 0xff;
    }
    if (__Vdlyvset__v__DOT__r__v1) {
	vlTOPp->v__DOT__r[1] = 0xff;
	vlTOPp->v__DOT__r[2] = 0xff;
	vlTOPp->v__DOT__r[3] = 0xff;
	vlTOPp->v__DOT__r[4] = 0xff;
	vlTOPp->v__DOT__r[5] = 0xff;
	vlTOPp->v__DOT__r[0xa] = 0;
	vlTOPp->v__DOT__r[0xb] = 0;
	vlTOPp->v__DOT__r[0xc] = 0;
    }
    if (__Vdlyvset__v__DOT__r__v9) {
	vlTOPp->v__DOT__r[(IData)(__Vdlyvdim0__v__DOT__r__v9)] 
	    = __Vdlyvval__v__DOT__r__v9;
    }
    vlTOPp->v__DOT__ca_freq = ((0xf00 & ((IData)(vlTOPp->v__DOT__r)
					 [1] << 8)) 
			       | (IData)(vlTOPp->v__DOT__r)
			       [0]);
    vlTOPp->v__DOT__cc_freq = ((0xf00 & ((IData)(vlTOPp->v__DOT__r)
					 [5] << 8)) 
			       | (IData)(vlTOPp->v__DOT__r)
			       [4]);
    vlTOPp->v__DOT__cb_freq = ((0xf00 & ((IData)(vlTOPp->v__DOT__r)
					 [3] << 8)) 
			       | (IData)(vlTOPp->v__DOT__r)
			       [2]);
    vlTOPp->v__DOT__cb_tone_enable = (1 & (~ ((IData)(vlTOPp->v__DOT__r)
					      [7] >> 1)));
    vlTOPp->v__DOT__ca_tone_enable = (1 & (~ (IData)(vlTOPp->v__DOT__r)
					   [7]));
    vlTOPp->v__DOT__cc_amp = (0xf & (IData)(vlTOPp->v__DOT__r)
			      [0xa]);
    vlTOPp->v__DOT__cb_amp = (0xf & (IData)(vlTOPp->v__DOT__r)
			      [9]);
    vlTOPp->v__DOT__ca_amp = (0xf & (IData)(vlTOPp->v__DOT__r)
			      [8]);
    vlTOPp->v__DOT__cc_lfsr_enable = (1 & (~ ((IData)(vlTOPp->v__DOT__r)
					      [7] >> 5)));
    vlTOPp->v__DOT__cb_lfsr_enable = (1 & (~ ((IData)(vlTOPp->v__DOT__r)
					      [7] >> 4)));
    vlTOPp->v__DOT__ca_lfsr_enable = (1 & (~ ((IData)(vlTOPp->v__DOT__r)
					      [7] >> 3)));
    vlTOPp->v__DOT__cc_tone_enable = (1 & (~ ((IData)(vlTOPp->v__DOT__r)
					      [7] >> 2)));
}

void Vym2149::_settle__TOP__2(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_settle__TOP__2\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__cc_freq = ((0xf00 & ((IData)(vlTOPp->v__DOT__r)
					 [5] << 8)) 
			       | (IData)(vlTOPp->v__DOT__r)
			       [4]);
    vlTOPp->v__DOT__cb_freq = ((0xf00 & ((IData)(vlTOPp->v__DOT__r)
					 [3] << 8)) 
			       | (IData)(vlTOPp->v__DOT__r)
			       [2]);
    vlTOPp->v__DOT__ca_freq = ((0xf00 & ((IData)(vlTOPp->v__DOT__r)
					 [1] << 8)) 
			       | (IData)(vlTOPp->v__DOT__r)
			       [0]);
    vlTOPp->v__DOT__cc_amp = (0xf & (IData)(vlTOPp->v__DOT__r)
			      [0xa]);
    vlTOPp->v__DOT__cb_amp = (0xf & (IData)(vlTOPp->v__DOT__r)
			      [9]);
    vlTOPp->v__DOT__ca_amp = (0xf & (IData)(vlTOPp->v__DOT__r)
			      [8]);
    vlTOPp->v__DOT__cc_lfsr_enable = (1 & (~ ((IData)(vlTOPp->v__DOT__r)
					      [7] >> 5)));
    vlTOPp->v__DOT__cb_lfsr_enable = (1 & (~ ((IData)(vlTOPp->v__DOT__r)
					      [7] >> 4)));
    vlTOPp->v__DOT__ca_lfsr_enable = (1 & (~ ((IData)(vlTOPp->v__DOT__r)
					      [7] >> 3)));
    vlTOPp->v__DOT__cc_tone_enable = (1 & (~ ((IData)(vlTOPp->v__DOT__r)
					      [7] >> 2)));
    vlTOPp->v__DOT__cb_tone_enable = (1 & (~ ((IData)(vlTOPp->v__DOT__r)
					      [7] >> 1)));
    vlTOPp->v__DOT__ca_tone_enable = (1 & (~ (IData)(vlTOPp->v__DOT__r)
					   [7]));
    vlTOPp->v__DOT__cc_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__cc_bit) & (IData)(vlTOPp->v__DOT__cc_tone_enable)) 
	    ^ (vlTOPp->v__DOT__lfsr & (IData)(vlTOPp->v__DOT__cc_lfsr_enable))) 
	   << 4) | (IData)(vlTOPp->v__DOT__cc_amp))];
    vlTOPp->v__DOT__cb_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__cb_bit) & (IData)(vlTOPp->v__DOT__cb_tone_enable)) 
	    ^ (vlTOPp->v__DOT__lfsr & (IData)(vlTOPp->v__DOT__cb_lfsr_enable))) 
	   << 4) | (IData)(vlTOPp->v__DOT__cb_amp))];
    vlTOPp->v__DOT__ca_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__ca_bit) & (IData)(vlTOPp->v__DOT__ca_tone_enable)) 
	    ^ (vlTOPp->v__DOT__lfsr & (IData)(vlTOPp->v__DOT__ca_lfsr_enable))) 
	   << 4) | (IData)(vlTOPp->v__DOT__ca_amp))];
}

void Vym2149::_sequent__TOP__3(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_sequent__TOP__3\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__cc_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__cc_bit) & (IData)(vlTOPp->v__DOT__cc_tone_enable)) 
	    ^ (vlTOPp->v__DOT__lfsr & (IData)(vlTOPp->v__DOT__cc_lfsr_enable))) 
	   << 4) | (IData)(vlTOPp->v__DOT__cc_amp))];
    vlTOPp->v__DOT__cb_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__cb_bit) & (IData)(vlTOPp->v__DOT__cb_tone_enable)) 
	    ^ (vlTOPp->v__DOT__lfsr & (IData)(vlTOPp->v__DOT__cb_lfsr_enable))) 
	   << 4) | (IData)(vlTOPp->v__DOT__cb_amp))];
    vlTOPp->v__DOT__ca_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__ca_bit) & (IData)(vlTOPp->v__DOT__ca_tone_enable)) 
	    ^ (vlTOPp->v__DOT__lfsr & (IData)(vlTOPp->v__DOT__ca_lfsr_enable))) 
	   << 4) | (IData)(vlTOPp->v__DOT__ca_amp))];
    vlTOPp->out_lr = (0xffff & (((IData)(vlTOPp->v__DOT__ca_mix) 
				 + (IData)(vlTOPp->v__DOT__cb_mix)) 
				+ (IData)(vlTOPp->v__DOT__cc_mix)));
}

void Vym2149::_settle__TOP__4(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_settle__TOP__4\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out_lr = (0xffff & (((IData)(vlTOPp->v__DOT__ca_mix) 
				 + (IData)(vlTOPp->v__DOT__cb_mix)) 
				+ (IData)(vlTOPp->v__DOT__cc_mix)));
}

void Vym2149::_eval(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_eval\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__in_clk = vlTOPp->in_clk;
}

void Vym2149::_eval_initial(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_eval_initial\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP(vlSymsp);
}

void Vym2149::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::final\n"); );
    // Variables
    Vym2149__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vym2149::_eval_settle(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_eval_settle\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->_settle__TOP__4(vlSymsp);
}

IData Vym2149::_change_request(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_change_request\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    return __req;
}
