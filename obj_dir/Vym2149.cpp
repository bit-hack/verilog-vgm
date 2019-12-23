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
    v__DOT__OLD_WR = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    v__DOT__R[__Vi0] = VL_RAND_RESET_I(8);
    }}
    v__DOT__CA_FREQ = VL_RAND_RESET_I(12);
    v__DOT__CB_FREQ = VL_RAND_RESET_I(12);
    v__DOT__CC_FREQ = VL_RAND_RESET_I(12);
    v__DOT__CA_TONE = VL_RAND_RESET_I(12);
    v__DOT__CB_TONE = VL_RAND_RESET_I(12);
    v__DOT__CC_TONE = VL_RAND_RESET_I(12);
    v__DOT__CA_BIT = VL_RAND_RESET_I(1);
    v__DOT__CB_BIT = VL_RAND_RESET_I(1);
    v__DOT__CC_BIT = VL_RAND_RESET_I(1);
    v__DOT__CA_MIX = VL_RAND_RESET_I(16);
    v__DOT__CB_MIX = VL_RAND_RESET_I(16);
    v__DOT__CC_MIX = VL_RAND_RESET_I(16);
    v__DOT__CA_TONE_ENABLE = VL_RAND_RESET_I(1);
    v__DOT__CB_TONE_ENABLE = VL_RAND_RESET_I(1);
    v__DOT__CC_TONE_ENABLE = VL_RAND_RESET_I(1);
    v__DOT__CA_LFSR_ENABLE = VL_RAND_RESET_I(1);
    v__DOT__CB_LFSR_ENABLE = VL_RAND_RESET_I(1);
    v__DOT__CC_LFSR_ENABLE = VL_RAND_RESET_I(1);
    v__DOT__CA_AMP = VL_RAND_RESET_I(4);
    v__DOT__CB_AMP = VL_RAND_RESET_I(4);
    v__DOT__CC_AMP = VL_RAND_RESET_I(4);
    v__DOT__LFSR = VL_RAND_RESET_I(17);
    v__DOT__CLK_DIV = VL_RAND_RESET_I(3);
    v__DOT__NOZ_DIV = VL_RAND_RESET_I(3);
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
    VL_SIG8(__Vdlyvset__v__DOT__R__v0,0,0);
    VL_SIG8(__Vdly__v__DOT__CA_BIT,0,0);
    VL_SIG8(__Vdly__v__DOT__CB_BIT,0,0);
    VL_SIG8(__Vdly__v__DOT__CC_BIT,0,0);
    VL_SIG8(__Vdlyvset__v__DOT__R__v1,0,0);
    VL_SIG8(__Vdlyvdim0__v__DOT__R__v9,3,0);
    VL_SIG8(__Vdlyvval__v__DOT__R__v9,7,0);
    VL_SIG8(__Vdlyvset__v__DOT__R__v9,0,0);
    VL_SIG8(__Vdly__v__DOT__CLK_DIV,2,0);
    VL_SIG8(__Vdly__v__DOT__NOZ_DIV,2,0);
    VL_SIG8(__Vdly__v__DOT__OLD_WR,0,0);
    //char	__VpadToAlign55[1];
    VL_SIG16(__Vdly__v__DOT__CA_TONE,11,0);
    VL_SIG16(__Vdly__v__DOT__CB_TONE,11,0);
    VL_SIG16(__Vdly__v__DOT__CC_TONE,11,0);
    //char	__VpadToAlign62[2];
    VL_SIG(__Vdly__v__DOT__LFSR,16,0);
    // Body
    __Vdly__v__DOT__CC_TONE = vlTOPp->v__DOT__CC_TONE;
    __Vdly__v__DOT__CB_TONE = vlTOPp->v__DOT__CB_TONE;
    __Vdly__v__DOT__CA_TONE = vlTOPp->v__DOT__CA_TONE;
    __Vdly__v__DOT__CLK_DIV = vlTOPp->v__DOT__CLK_DIV;
    __Vdly__v__DOT__OLD_WR = vlTOPp->v__DOT__OLD_WR;
    __Vdly__v__DOT__NOZ_DIV = vlTOPp->v__DOT__NOZ_DIV;
    __Vdly__v__DOT__CC_BIT = vlTOPp->v__DOT__CC_BIT;
    __Vdly__v__DOT__CA_BIT = vlTOPp->v__DOT__CA_BIT;
    __Vdly__v__DOT__CB_BIT = vlTOPp->v__DOT__CB_BIT;
    __Vdly__v__DOT__LFSR = vlTOPp->v__DOT__LFSR;
    __Vdlyvset__v__DOT__R__v0 = 0;
    __Vdlyvset__v__DOT__R__v1 = 0;
    __Vdlyvset__v__DOT__R__v9 = 0;
    // ALWAYS at source/ym2149.v:79
    if (vlTOPp->in_rst) {
	__Vdlyvset__v__DOT__R__v0 = 1;
	__Vdly__v__DOT__CA_TONE = 0;
	__Vdly__v__DOT__CB_TONE = 0;
	__Vdly__v__DOT__CC_TONE = 0;
	__Vdly__v__DOT__CA_BIT = 0;
	__Vdly__v__DOT__CB_BIT = 0;
	__Vdly__v__DOT__CC_BIT = 0;
	__Vdly__v__DOT__LFSR = 0x1ffff;
	__Vdlyvset__v__DOT__R__v1 = 1;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__CLK_DIV))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__CA_TONE))) {
		__Vdly__v__DOT__CA_BIT = (1 & (~ (IData)(vlTOPp->v__DOT__CA_BIT)));
		__Vdly__v__DOT__CA_TONE = vlTOPp->v__DOT__CA_FREQ;
	    } else {
		__Vdly__v__DOT__CA_TONE = (0xfff & 
					   ((IData)(vlTOPp->v__DOT__CA_TONE) 
					    - (IData)(1)));
	    }
	    if ((0 == (IData)(vlTOPp->v__DOT__CB_TONE))) {
		__Vdly__v__DOT__CB_BIT = (1 & (~ (IData)(vlTOPp->v__DOT__CB_BIT)));
		__Vdly__v__DOT__CB_TONE = vlTOPp->v__DOT__CB_FREQ;
	    } else {
		__Vdly__v__DOT__CB_TONE = (0xfff & 
					   ((IData)(vlTOPp->v__DOT__CB_TONE) 
					    - (IData)(1)));
	    }
	    if ((0 == (IData)(vlTOPp->v__DOT__CC_TONE))) {
		__Vdly__v__DOT__CC_BIT = (1 & (~ (IData)(vlTOPp->v__DOT__CC_BIT)));
		__Vdly__v__DOT__CC_TONE = vlTOPp->v__DOT__CC_FREQ;
	    } else {
		__Vdly__v__DOT__CC_TONE = (0xfff & 
					   ((IData)(vlTOPp->v__DOT__CC_TONE) 
					    - (IData)(1)));
	    }
	}
	if ((0 == (IData)(vlTOPp->v__DOT__NOZ_DIV))) {
	    __Vdly__v__DOT__LFSR = ((0x10000 & ((vlTOPp->v__DOT__LFSR 
						 << 0x10) 
						^ (0xffff0000 
						   & (vlTOPp->v__DOT__LFSR 
						      << 0xd)))) 
				    | (0xffff & (vlTOPp->v__DOT__LFSR 
						 >> 1)));
	}
	if (((IData)(vlTOPp->in_wr) & (~ (IData)(vlTOPp->v__DOT__OLD_WR)))) {
	    __Vdlyvval__v__DOT__R__v9 = vlTOPp->in_val;
	    __Vdlyvset__v__DOT__R__v9 = 1;
	    __Vdlyvdim0__v__DOT__R__v9 = vlTOPp->in_reg;
	}
    }
    __Vdly__v__DOT__CLK_DIV = (7 & ((IData)(1) + (IData)(vlTOPp->v__DOT__CLK_DIV)));
    __Vdly__v__DOT__NOZ_DIV = (7 & ((IData)(1) + (IData)(vlTOPp->v__DOT__NOZ_DIV)));
    __Vdly__v__DOT__OLD_WR = vlTOPp->in_wr;
    vlTOPp->v__DOT__OLD_WR = __Vdly__v__DOT__OLD_WR;
    vlTOPp->v__DOT__CB_TONE = __Vdly__v__DOT__CB_TONE;
    vlTOPp->v__DOT__CLK_DIV = __Vdly__v__DOT__CLK_DIV;
    vlTOPp->v__DOT__NOZ_DIV = __Vdly__v__DOT__NOZ_DIV;
    vlTOPp->v__DOT__CC_TONE = __Vdly__v__DOT__CC_TONE;
    vlTOPp->v__DOT__CA_TONE = __Vdly__v__DOT__CA_TONE;
    vlTOPp->v__DOT__CC_BIT = __Vdly__v__DOT__CC_BIT;
    vlTOPp->v__DOT__CB_BIT = __Vdly__v__DOT__CB_BIT;
    vlTOPp->v__DOT__CA_BIT = __Vdly__v__DOT__CA_BIT;
    vlTOPp->v__DOT__LFSR = __Vdly__v__DOT__LFSR;
    // ALWAYSPOST at source/ym2149.v:83
    if (__Vdlyvset__v__DOT__R__v0) {
	vlTOPp->v__DOT__R[0] = 0xff;
    }
    if (__Vdlyvset__v__DOT__R__v1) {
	vlTOPp->v__DOT__R[1] = 0xff;
	vlTOPp->v__DOT__R[2] = 0xff;
	vlTOPp->v__DOT__R[3] = 0xff;
	vlTOPp->v__DOT__R[4] = 0xff;
	vlTOPp->v__DOT__R[5] = 0xff;
	vlTOPp->v__DOT__R[0xa] = 0;
	vlTOPp->v__DOT__R[0xb] = 0;
	vlTOPp->v__DOT__R[0xc] = 0;
    }
    if (__Vdlyvset__v__DOT__R__v9) {
	vlTOPp->v__DOT__R[(IData)(__Vdlyvdim0__v__DOT__R__v9)] 
	    = __Vdlyvval__v__DOT__R__v9;
    }
    vlTOPp->v__DOT__CA_FREQ = ((0xf00 & ((IData)(vlTOPp->v__DOT__R)
					 [1] << 8)) 
			       | (IData)(vlTOPp->v__DOT__R)
			       [0]);
    vlTOPp->v__DOT__CC_FREQ = ((0xf00 & ((IData)(vlTOPp->v__DOT__R)
					 [5] << 8)) 
			       | (IData)(vlTOPp->v__DOT__R)
			       [4]);
    vlTOPp->v__DOT__CB_FREQ = ((0xf00 & ((IData)(vlTOPp->v__DOT__R)
					 [3] << 8)) 
			       | (IData)(vlTOPp->v__DOT__R)
			       [2]);
    vlTOPp->v__DOT__CB_TONE_ENABLE = (1 & (~ ((IData)(vlTOPp->v__DOT__R)
					      [7] >> 1)));
    vlTOPp->v__DOT__CA_TONE_ENABLE = (1 & (~ (IData)(vlTOPp->v__DOT__R)
					   [7]));
    vlTOPp->v__DOT__CC_AMP = (0xf & (IData)(vlTOPp->v__DOT__R)
			      [0xa]);
    vlTOPp->v__DOT__CB_AMP = (0xf & (IData)(vlTOPp->v__DOT__R)
			      [9]);
    vlTOPp->v__DOT__CA_AMP = (0xf & (IData)(vlTOPp->v__DOT__R)
			      [8]);
    vlTOPp->v__DOT__CC_LFSR_ENABLE = (1 & (~ ((IData)(vlTOPp->v__DOT__R)
					      [7] >> 5)));
    vlTOPp->v__DOT__CB_LFSR_ENABLE = (1 & (~ ((IData)(vlTOPp->v__DOT__R)
					      [7] >> 4)));
    vlTOPp->v__DOT__CA_LFSR_ENABLE = (1 & (~ ((IData)(vlTOPp->v__DOT__R)
					      [7] >> 3)));
    vlTOPp->v__DOT__CC_TONE_ENABLE = (1 & (~ ((IData)(vlTOPp->v__DOT__R)
					      [7] >> 2)));
}

void Vym2149::_settle__TOP__2(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_settle__TOP__2\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    vlTOPp->v__DOT__CC_AMP = (0xf & (IData)(vlTOPp->v__DOT__R)
			      [0xa]);
    vlTOPp->v__DOT__CB_AMP = (0xf & (IData)(vlTOPp->v__DOT__R)
			      [9]);
    vlTOPp->v__DOT__CA_AMP = (0xf & (IData)(vlTOPp->v__DOT__R)
			      [8]);
    vlTOPp->v__DOT__CC_LFSR_ENABLE = (1 & (~ ((IData)(vlTOPp->v__DOT__R)
					      [7] >> 5)));
    vlTOPp->v__DOT__CB_LFSR_ENABLE = (1 & (~ ((IData)(vlTOPp->v__DOT__R)
					      [7] >> 4)));
    vlTOPp->v__DOT__CA_LFSR_ENABLE = (1 & (~ ((IData)(vlTOPp->v__DOT__R)
					      [7] >> 3)));
    vlTOPp->v__DOT__CC_TONE_ENABLE = (1 & (~ ((IData)(vlTOPp->v__DOT__R)
					      [7] >> 2)));
    vlTOPp->v__DOT__CB_TONE_ENABLE = (1 & (~ ((IData)(vlTOPp->v__DOT__R)
					      [7] >> 1)));
    vlTOPp->v__DOT__CA_TONE_ENABLE = (1 & (~ (IData)(vlTOPp->v__DOT__R)
					   [7]));
    vlTOPp->v__DOT__CC_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__CC_BIT) & (IData)(vlTOPp->v__DOT__CC_TONE_ENABLE)) 
	    ^ (vlTOPp->v__DOT__LFSR & (IData)(vlTOPp->v__DOT__CC_LFSR_ENABLE))) 
	   << 4) | (IData)(vlTOPp->v__DOT__CC_AMP))];
    vlTOPp->v__DOT__CB_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__CB_BIT) & (IData)(vlTOPp->v__DOT__CB_TONE_ENABLE)) 
	    ^ (vlTOPp->v__DOT__LFSR & (IData)(vlTOPp->v__DOT__CB_LFSR_ENABLE))) 
	   << 4) | (IData)(vlTOPp->v__DOT__CB_AMP))];
    vlTOPp->v__DOT__CA_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__CA_BIT) & (IData)(vlTOPp->v__DOT__CA_TONE_ENABLE)) 
	    ^ (vlTOPp->v__DOT__LFSR & (IData)(vlTOPp->v__DOT__CA_LFSR_ENABLE))) 
	   << 4) | (IData)(vlTOPp->v__DOT__CA_AMP))];
}

void Vym2149::_sequent__TOP__3(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_sequent__TOP__3\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__CC_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__CC_BIT) & (IData)(vlTOPp->v__DOT__CC_TONE_ENABLE)) 
	    ^ (vlTOPp->v__DOT__LFSR & (IData)(vlTOPp->v__DOT__CC_LFSR_ENABLE))) 
	   << 4) | (IData)(vlTOPp->v__DOT__CC_AMP))];
    vlTOPp->v__DOT__CB_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__CB_BIT) & (IData)(vlTOPp->v__DOT__CB_TONE_ENABLE)) 
	    ^ (vlTOPp->v__DOT__LFSR & (IData)(vlTOPp->v__DOT__CB_LFSR_ENABLE))) 
	   << 4) | (IData)(vlTOPp->v__DOT__CB_AMP))];
    vlTOPp->v__DOT__CA_MIX = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[(((((IData)(vlTOPp->v__DOT__CA_BIT) & (IData)(vlTOPp->v__DOT__CA_TONE_ENABLE)) 
	    ^ (vlTOPp->v__DOT__LFSR & (IData)(vlTOPp->v__DOT__CA_LFSR_ENABLE))) 
	   << 4) | (IData)(vlTOPp->v__DOT__CA_AMP))];
    vlTOPp->out_lr = (0xffff & (((IData)(vlTOPp->v__DOT__CA_MIX) 
				 + (IData)(vlTOPp->v__DOT__CB_MIX)) 
				+ (IData)(vlTOPp->v__DOT__CC_MIX)));
}

void Vym2149::_settle__TOP__4(Vym2149__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vym2149::_settle__TOP__4\n"); );
    Vym2149* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out_lr = (0xffff & (((IData)(vlTOPp->v__DOT__CA_MIX) 
				 + (IData)(vlTOPp->v__DOT__CB_MIX)) 
				+ (IData)(vlTOPp->v__DOT__CC_MIX)));
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
