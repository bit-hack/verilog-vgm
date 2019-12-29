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
    v__DOT__clk_div = VL_RAND_RESET_I(3);
    v__DOT__env_out = VL_RAND_RESET_I(4);
    v__DOT__env_mode = VL_RAND_RESET_I(4);
    v__DOT__env_period = VL_RAND_RESET_I(16);
    v__DOT__noise_period = VL_RAND_RESET_I(5);
    v__DOT__ca_freq = VL_RAND_RESET_I(12);
    v__DOT__cb_freq = VL_RAND_RESET_I(12);
    v__DOT__cc_freq = VL_RAND_RESET_I(12);
    v__DOT__reload_env = VL_RAND_RESET_I(1);
    v__DOT__env__DOT__value = VL_RAND_RESET_I(8);
    v__DOT__env__DOT__counter = VL_RAND_RESET_I(16);
    v__DOT__env__DOT__toggle = VL_RAND_RESET_I(1);
    v__DOT__noise__DOT__lfsr = VL_RAND_RESET_I(17);
    v__DOT__noise__DOT__clk_div = VL_RAND_RESET_I(4);
    v__DOT__noise__DOT__counter = VL_RAND_RESET_I(5);
    v__DOT__channel_a__DOT__tone_bit = VL_RAND_RESET_I(1);
    v__DOT__channel_a__DOT__counter = VL_RAND_RESET_I(12);
    v__DOT__channel_b__DOT__tone_bit = VL_RAND_RESET_I(1);
    v__DOT__channel_b__DOT__counter = VL_RAND_RESET_I(12);
    v__DOT__channel_c__DOT__tone_bit = VL_RAND_RESET_I(1);
    v__DOT__channel_c__DOT__counter = VL_RAND_RESET_I(12);
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
    // INITIAL at source/ym2149.v:141
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
    VL_SIG8(__Vdlyvdim0__v__DOT__r__v3,3,0);
    VL_SIG8(__Vdlyvval__v__DOT__r__v3,7,0);
    VL_SIG8(__Vdlyvset__v__DOT__r__v3,0,0);
    VL_SIG8(__Vdly__v__DOT__old_wr,0,0);
    VL_SIG8(__Vdly__v__DOT__clk_div,2,0);
    VL_SIG8(__Vdly__v__DOT__env__DOT__value,7,0);
    VL_SIG8(__Vdly__v__DOT__env__DOT__toggle,0,0);
    VL_SIG8(__Vdly__v__DOT__noise__DOT__clk_div,3,0);
    VL_SIG8(__Vdly__v__DOT__noise__DOT__counter,4,0);
    VL_SIG8(__Vdly__v__DOT__channel_a__DOT__tone_bit,0,0);
    VL_SIG8(__Vdly__v__DOT__channel_b__DOT__tone_bit,0,0);
    VL_SIG8(__Vdly__v__DOT__channel_c__DOT__tone_bit,0,0);
    //char	__VpadToAlign57[1];
    VL_SIG16(__Vdly__v__DOT__env__DOT__counter,15,0);
    VL_SIG16(__Vdly__v__DOT__channel_a__DOT__counter,11,0);
    VL_SIG16(__Vdly__v__DOT__channel_b__DOT__counter,11,0);
    VL_SIG16(__Vdly__v__DOT__channel_c__DOT__counter,11,0);
    //char	__VpadToAlign66[2];
    VL_SIG(__Vdly__v__DOT__noise__DOT__lfsr,16,0);
    // Body
    __Vdly__v__DOT__clk_div = vlTOPp->v__DOT__clk_div;
    __Vdly__v__DOT__channel_a__DOT__counter = vlTOPp->v__DOT__channel_a__DOT__counter;
    __Vdly__v__DOT__channel_b__DOT__counter = vlTOPp->v__DOT__channel_b__DOT__counter;
    __Vdly__v__DOT__channel_c__DOT__counter = vlTOPp->v__DOT__channel_c__DOT__counter;
    __Vdly__v__DOT__channel_a__DOT__tone_bit = vlTOPp->v__DOT__channel_a__DOT__tone_bit;
    __Vdly__v__DOT__channel_b__DOT__tone_bit = vlTOPp->v__DOT__channel_b__DOT__tone_bit;
    __Vdly__v__DOT__channel_c__DOT__tone_bit = vlTOPp->v__DOT__channel_c__DOT__tone_bit;
    __Vdly__v__DOT__noise__DOT__clk_div = vlTOPp->v__DOT__noise__DOT__clk_div;
    __Vdly__v__DOT__noise__DOT__counter = vlTOPp->v__DOT__noise__DOT__counter;
    __Vdly__v__DOT__noise__DOT__lfsr = vlTOPp->v__DOT__noise__DOT__lfsr;
    __Vdly__v__DOT__old_wr = vlTOPp->v__DOT__old_wr;
    __Vdly__v__DOT__env__DOT__counter = vlTOPp->v__DOT__env__DOT__counter;
    __Vdly__v__DOT__env__DOT__toggle = vlTOPp->v__DOT__env__DOT__toggle;
    __Vdly__v__DOT__env__DOT__value = vlTOPp->v__DOT__env__DOT__value;
    __Vdlyvset__v__DOT__r__v0 = 0;
    __Vdlyvset__v__DOT__r__v3 = 0;
    // ALWAYS at source/ym2149.v:230
    __Vdly__v__DOT__clk_div = (7 & ((IData)(1) + (IData)(vlTOPp->v__DOT__clk_div)));
    // ALWAYS at source/ym2149.v:112
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__channel_a__DOT__tone_bit = 1;
	__Vdly__v__DOT__channel_a__DOT__counter = 0;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__clk_div))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__channel_a__DOT__counter))) {
		__Vdly__v__DOT__channel_a__DOT__tone_bit 
		    = (1 & (~ (IData)(vlTOPp->v__DOT__channel_a__DOT__tone_bit)));
		__Vdly__v__DOT__channel_a__DOT__counter 
		    = vlTOPp->v__DOT__ca_freq;
	    } else {
		__Vdly__v__DOT__channel_a__DOT__counter 
		    = (0xfff & ((IData)(vlTOPp->v__DOT__channel_a__DOT__counter) 
				- (IData)(1)));
	    }
	}
    }
    // ALWAYS at source/ym2149.v:112
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__channel_b__DOT__tone_bit = 1;
	__Vdly__v__DOT__channel_b__DOT__counter = 0;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__clk_div))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__channel_b__DOT__counter))) {
		__Vdly__v__DOT__channel_b__DOT__tone_bit 
		    = (1 & (~ (IData)(vlTOPp->v__DOT__channel_b__DOT__tone_bit)));
		__Vdly__v__DOT__channel_b__DOT__counter 
		    = vlTOPp->v__DOT__cb_freq;
	    } else {
		__Vdly__v__DOT__channel_b__DOT__counter 
		    = (0xfff & ((IData)(vlTOPp->v__DOT__channel_b__DOT__counter) 
				- (IData)(1)));
	    }
	}
    }
    // ALWAYS at source/ym2149.v:112
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__channel_c__DOT__tone_bit = 1;
	__Vdly__v__DOT__channel_c__DOT__counter = 0;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__clk_div))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__channel_c__DOT__counter))) {
		__Vdly__v__DOT__channel_c__DOT__tone_bit 
		    = (1 & (~ (IData)(vlTOPp->v__DOT__channel_c__DOT__tone_bit)));
		__Vdly__v__DOT__channel_c__DOT__counter 
		    = vlTOPp->v__DOT__cc_freq;
	    } else {
		__Vdly__v__DOT__channel_c__DOT__counter 
		    = (0xfff & ((IData)(vlTOPp->v__DOT__channel_c__DOT__counter) 
				- (IData)(1)));
	    }
	}
    }
    // ALWAYS at source/ym2149.v:80
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__noise__DOT__clk_div = 0;
	__Vdly__v__DOT__noise__DOT__counter = 0;
	__Vdly__v__DOT__noise__DOT__lfsr = 0x1ffff;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__noise__DOT__clk_div))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__noise__DOT__counter))) {
		__Vdly__v__DOT__noise__DOT__lfsr = 
		    ((0x10000 & ((vlTOPp->v__DOT__noise__DOT__lfsr 
				  << 0x10) ^ (0xffff0000 
					      & (vlTOPp->v__DOT__noise__DOT__lfsr 
						 << 0xd)))) 
		     | (0xffff & (vlTOPp->v__DOT__noise__DOT__lfsr 
				  >> 1)));
		__Vdly__v__DOT__noise__DOT__counter 
		    = vlTOPp->v__DOT__noise_period;
	    } else {
		__Vdly__v__DOT__noise__DOT__counter 
		    = (0x1f & ((IData)(vlTOPp->v__DOT__noise__DOT__counter) 
			       - (IData)(1)));
	    }
	}
    }
    // ALWAYS at source/ym2149.v:30
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__env__DOT__counter = 0xffff;
	__Vdly__v__DOT__env__DOT__value = 0xff;
	__Vdly__v__DOT__env__DOT__toggle = 0;
    } else {
	if (vlTOPp->v__DOT__reload_env) {
	    __Vdly__v__DOT__env__DOT__value = 0xff;
	    __Vdly__v__DOT__env__DOT__counter = 0xffff;
	    __Vdly__v__DOT__env__DOT__toggle = 0;
	} else {
	    if ((0 == (IData)(vlTOPp->v__DOT__env__DOT__counter))) {
		if ((0 == (IData)(vlTOPp->v__DOT__env__DOT__value))) {
		    if ((8 & (IData)(vlTOPp->v__DOT__env_mode))) {
			__Vdly__v__DOT__env__DOT__toggle 
			    = (1 & ((((IData)(vlTOPp->v__DOT__env_mode) 
				      >> 1) & (IData)(vlTOPp->v__DOT__env_mode)) 
				    | ((2 & (IData)(vlTOPp->v__DOT__env_mode))
				        ? (~ (IData)(vlTOPp->v__DOT__env__DOT__toggle))
				        : (IData)(vlTOPp->v__DOT__env__DOT__toggle))));
			__Vdly__v__DOT__env__DOT__value 
			    = (0xff & ((1 & (IData)(vlTOPp->v__DOT__env_mode))
				        ? ((IData)(vlTOPp->v__DOT__env__DOT__value) 
					   - (IData)(1))
				        : (IData)(vlTOPp->v__DOT__env__DOT__value)));
		    } else {
			__Vdly__v__DOT__env__DOT__value = 0;
			__Vdly__v__DOT__env__DOT__toggle = 0;
		    }
		} else {
		    __Vdly__v__DOT__env__DOT__value 
			= (0xff & ((IData)(vlTOPp->v__DOT__env__DOT__value) 
				   - (IData)(1)));
		}
		__Vdly__v__DOT__env__DOT__counter = vlTOPp->v__DOT__env_period;
	    } else {
		__Vdly__v__DOT__env__DOT__counter = 
		    (0xffff & ((IData)(vlTOPp->v__DOT__env__DOT__counter) 
			       - (IData)(1)));
	    }
	}
    }
    vlTOPp->v__DOT__channel_a__DOT__counter = __Vdly__v__DOT__channel_a__DOT__counter;
    vlTOPp->v__DOT__channel_a__DOT__tone_bit = __Vdly__v__DOT__channel_a__DOT__tone_bit;
    vlTOPp->v__DOT__channel_b__DOT__counter = __Vdly__v__DOT__channel_b__DOT__counter;
    vlTOPp->v__DOT__channel_b__DOT__tone_bit = __Vdly__v__DOT__channel_b__DOT__tone_bit;
    vlTOPp->v__DOT__channel_c__DOT__counter = __Vdly__v__DOT__channel_c__DOT__counter;
    vlTOPp->v__DOT__clk_div = __Vdly__v__DOT__clk_div;
    vlTOPp->v__DOT__channel_c__DOT__tone_bit = __Vdly__v__DOT__channel_c__DOT__tone_bit;
    vlTOPp->v__DOT__noise__DOT__clk_div = __Vdly__v__DOT__noise__DOT__clk_div;
    vlTOPp->v__DOT__noise__DOT__counter = __Vdly__v__DOT__noise__DOT__counter;
    vlTOPp->v__DOT__noise__DOT__lfsr = __Vdly__v__DOT__noise__DOT__lfsr;
    vlTOPp->v__DOT__env__DOT__counter = __Vdly__v__DOT__env__DOT__counter;
    vlTOPp->v__DOT__env__DOT__value = __Vdly__v__DOT__env__DOT__value;
    vlTOPp->v__DOT__env__DOT__toggle = __Vdly__v__DOT__env__DOT__toggle;
    // ALWAYS at source/ym2149.v:212
    if (vlTOPp->in_rst) {
	__Vdlyvset__v__DOT__r__v0 = 1;
    } else {
	if (((IData)(vlTOPp->in_wr) & (~ (IData)(vlTOPp->v__DOT__old_wr)))) {
	    __Vdlyvval__v__DOT__r__v3 = vlTOPp->in_val;
	    __Vdlyvset__v__DOT__r__v3 = 1;
	    __Vdlyvdim0__v__DOT__r__v3 = vlTOPp->in_reg;
	    vlTOPp->v__DOT__reload_env = (0xf == (IData)(vlTOPp->in_reg));
	} else {
	    vlTOPp->v__DOT__reload_env = 0;
	}
    }
    __Vdly__v__DOT__old_wr = vlTOPp->in_wr;
    vlTOPp->v__DOT__old_wr = __Vdly__v__DOT__old_wr;
    // ALWAYSPOST at source/ym2149.v:215
    if (__Vdlyvset__v__DOT__r__v0) {
	vlTOPp->v__DOT__r[0xa] = 0;
	vlTOPp->v__DOT__r[0xb] = 0;
	vlTOPp->v__DOT__r[0xc] = 0;
    }
    if (__Vdlyvset__v__DOT__r__v3) {
	vlTOPp->v__DOT__r[(IData)(__Vdlyvdim0__v__DOT__r__v3)] 
	    = __Vdlyvval__v__DOT__r__v3;
    }
    vlTOPp->v__DOT__env_period = (((IData)(vlTOPp->v__DOT__r)
				   [0xe] << 8) | (IData)(vlTOPp->v__DOT__r)
				  [0xd]);
    vlTOPp->v__DOT__noise_period = (0x1f & (IData)(vlTOPp->v__DOT__r)
				    [6]);
    vlTOPp->v__DOT__ca_freq = ((0xf00 & ((IData)(vlTOPp->v__DOT__r)
					 [1] << 8)) 
			       | (IData)(vlTOPp->v__DOT__r)
			       [0]);
    vlTOPp->v__DOT__cb_freq = ((0xf00 & ((IData)(vlTOPp->v__DOT__r)
					 [3] << 8)) 
			       | (IData)(vlTOPp->v__DOT__r)
			       [2]);
    vlTOPp->v__DOT__cc_freq = ((0xf00 & ((IData)(vlTOPp->v__DOT__r)
					 [5] << 8)) 
			       | (IData)(vlTOPp->v__DOT__r)
			       [4]);
    vlTOPp->v__DOT__ca_tone_enable = (1 & (~ (IData)(vlTOPp->v__DOT__r)
					   [7]));
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
    vlTOPp->v__DOT__env_mode = (0xf & (IData)(vlTOPp->v__DOT__r)
				[0xd]);
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
    vlTOPp->v__DOT__noise_period = (0x1f & (IData)(vlTOPp->v__DOT__r)
				    [6]);
    vlTOPp->v__DOT__env_period = (((IData)(vlTOPp->v__DOT__r)
				   [0xe] << 8) | (IData)(vlTOPp->v__DOT__r)
				  [0xd]);
    vlTOPp->v__DOT__ca_tone_enable = (1 & (~ (IData)(vlTOPp->v__DOT__r)
					   [7]));
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
    vlTOPp->v__DOT__env_mode = (0xf & (IData)(vlTOPp->v__DOT__r)
				[0xd]);
    vlTOPp->v__DOT__env_out = (0xf & ((1 & (((IData)(vlTOPp->v__DOT__env_mode) 
					     >> 2) 
					    ^ (IData)(vlTOPp->v__DOT__env__DOT__toggle)))
				       ? ((IData)(0xf) 
					  - ((IData)(vlTOPp->v__DOT__env__DOT__value) 
					     >> 4))
				       : ((IData)(vlTOPp->v__DOT__env__DOT__value) 
					  >> 4)));
}

void Vym2149::_sequent__TOP__3(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_sequent__TOP__3\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__env_out = (0xf & ((1 & (((IData)(vlTOPp->v__DOT__env_mode) 
					     >> 2) 
					    ^ (IData)(vlTOPp->v__DOT__env__DOT__toggle)))
				       ? ((IData)(0xf) 
					  - ((IData)(vlTOPp->v__DOT__env__DOT__value) 
					     >> 4))
				       : ((IData)(vlTOPp->v__DOT__env__DOT__value) 
					  >> 4)));
    vlTOPp->v__DOT__ca_amp = (0xf & ((0x10 & (IData)(vlTOPp->v__DOT__r)
				      [8]) ? (IData)(vlTOPp->v__DOT__env_out)
				      : (IData)(vlTOPp->v__DOT__r)
				     [8]));
    vlTOPp->v__DOT__cb_amp = (0xf & ((0x10 & (IData)(vlTOPp->v__DOT__r)
				      [9]) ? (IData)(vlTOPp->v__DOT__env_out)
				      : (IData)(vlTOPp->v__DOT__r)
				     [9]));
    vlTOPp->v__DOT__cc_amp = (0xf & ((0x10 & (IData)(vlTOPp->v__DOT__r)
				      [0xa]) ? (IData)(vlTOPp->v__DOT__env_out)
				      : (IData)(vlTOPp->v__DOT__r)
				     [0xa]));
}

void Vym2149::_settle__TOP__4(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_settle__TOP__4\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__ca_amp = (0xf & ((0x10 & (IData)(vlTOPp->v__DOT__r)
				      [8]) ? (IData)(vlTOPp->v__DOT__env_out)
				      : (IData)(vlTOPp->v__DOT__r)
				     [8]));
    vlTOPp->v__DOT__cb_amp = (0xf & ((0x10 & (IData)(vlTOPp->v__DOT__r)
				      [9]) ? (IData)(vlTOPp->v__DOT__env_out)
				      : (IData)(vlTOPp->v__DOT__r)
				     [9]));
    vlTOPp->v__DOT__cc_amp = (0xf & ((0x10 & (IData)(vlTOPp->v__DOT__r)
				      [0xa]) ? (IData)(vlTOPp->v__DOT__env_out)
				      : (IData)(vlTOPp->v__DOT__r)
				     [0xa]));
    vlTOPp->v__DOT__ca_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__channel_a__DOT__tone_bit) 
	     & (IData)(vlTOPp->v__DOT__ca_tone_enable)) 
	    ^ (vlTOPp->v__DOT__noise__DOT__lfsr & (IData)(vlTOPp->v__DOT__ca_lfsr_enable))) 
	   << 4) | (IData)(vlTOPp->v__DOT__ca_amp))];
    vlTOPp->v__DOT__cb_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__channel_b__DOT__tone_bit) 
	     & (IData)(vlTOPp->v__DOT__cb_tone_enable)) 
	    ^ (vlTOPp->v__DOT__noise__DOT__lfsr & (IData)(vlTOPp->v__DOT__cb_lfsr_enable))) 
	   << 4) | (IData)(vlTOPp->v__DOT__cb_amp))];
    vlTOPp->v__DOT__cc_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__channel_c__DOT__tone_bit) 
	     & (IData)(vlTOPp->v__DOT__cc_tone_enable)) 
	    ^ (vlTOPp->v__DOT__noise__DOT__lfsr & (IData)(vlTOPp->v__DOT__cc_lfsr_enable))) 
	   << 4) | (IData)(vlTOPp->v__DOT__cc_amp))];
}

void Vym2149::_sequent__TOP__5(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_sequent__TOP__5\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__ca_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__channel_a__DOT__tone_bit) 
	     & (IData)(vlTOPp->v__DOT__ca_tone_enable)) 
	    ^ (vlTOPp->v__DOT__noise__DOT__lfsr & (IData)(vlTOPp->v__DOT__ca_lfsr_enable))) 
	   << 4) | (IData)(vlTOPp->v__DOT__ca_amp))];
    vlTOPp->v__DOT__cb_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__channel_b__DOT__tone_bit) 
	     & (IData)(vlTOPp->v__DOT__cb_tone_enable)) 
	    ^ (vlTOPp->v__DOT__noise__DOT__lfsr & (IData)(vlTOPp->v__DOT__cb_lfsr_enable))) 
	   << 4) | (IData)(vlTOPp->v__DOT__cb_amp))];
    vlTOPp->v__DOT__cc_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__channel_c__DOT__tone_bit) 
	     & (IData)(vlTOPp->v__DOT__cc_tone_enable)) 
	    ^ (vlTOPp->v__DOT__noise__DOT__lfsr & (IData)(vlTOPp->v__DOT__cc_lfsr_enable))) 
	   << 4) | (IData)(vlTOPp->v__DOT__cc_amp))];
    vlTOPp->out_lr = (0xffff & (((IData)(vlTOPp->v__DOT__ca_mix) 
				 + (IData)(vlTOPp->v__DOT__cb_mix)) 
				+ (IData)(vlTOPp->v__DOT__cc_mix)));
}

void Vym2149::_settle__TOP__6(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_settle__TOP__6\n"); );
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
	vlTOPp->_sequent__TOP__5(vlSymsp);
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
    vlTOPp->_settle__TOP__6(vlSymsp);
}

IData Vym2149::_change_request(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_change_request\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    return __req;
}
