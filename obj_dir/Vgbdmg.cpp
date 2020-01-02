// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgbdmg.h for the primary calling header

#include "Vgbdmg.h"            // For This
#include "Vgbdmg__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vgbdmg) {
    Vgbdmg__Syms* __restrict vlSymsp = __VlSymsp = new Vgbdmg__Syms(this, name());
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    in_clk = 0;
    in_rst = 0;
    in_reg = VL_RAND_RESET_I(6);
    in_val = VL_RAND_RESET_I(8);
    in_wr = 0;
    out_lr = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    v__DOT__AMP_TABLE[__Vi0] = VL_RAND_RESET_I(16);
    }}
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
	    v__DOT__r[__Vi0] = VL_RAND_RESET_I(8);
    }}
    v__DOT__pulse0_freq = VL_RAND_RESET_I(11);
    v__DOT__pulse0_duty = VL_RAND_RESET_I(2);
    v__DOT__pulse0_mix = VL_RAND_RESET_I(16);
    v__DOT__pulse1_freq = VL_RAND_RESET_I(11);
    v__DOT__pulse1_duty = VL_RAND_RESET_I(2);
    v__DOT__pulse1_mix = VL_RAND_RESET_I(16);
    v__DOT__wave_out = VL_RAND_RESET_I(4);
    v__DOT__wave_freq = VL_RAND_RESET_I(11);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    v__DOT____Vcellinp__wave_mem____pinNumber1[__Vi0] = VL_RAND_RESET_I(8);
    }}
    v__DOT__wave_vol = VL_RAND_RESET_I(2);
    v__DOT____Vcellinp__noise____pinNumber5 = 0;
    v__DOT____Vcellinp__noise____pinNumber4 = VL_RAND_RESET_I(3);
    v__DOT____Vcellinp__noise____pinNumber3 = VL_RAND_RESET_I(4);
    v__DOT__noise_mix = VL_RAND_RESET_I(16);
    v__DOT____Vcellinp__len0____pinNumber6 = 0;
    v__DOT____Vcellinp__len0____pinNumber3 = VL_RAND_RESET_I(6);
    v__DOT____Vcellinp__len1____pinNumber6 = 0;
    v__DOT____Vcellinp__len1____pinNumber3 = VL_RAND_RESET_I(6);
    v__DOT__wr_old = VL_RAND_RESET_I(1);
    v__DOT__wr_posedge = VL_RAND_RESET_I(1);
    v__DOT__frame_clk_div = VL_RAND_RESET_I(14);
    v__DOT__frame_seq = VL_RAND_RESET_I(3);
    v__DOT__tick_len_cnt = VL_RAND_RESET_I(1);
    v__DOT__tick_env = VL_RAND_RESET_I(1);
    v__DOT__trigger_env0 = VL_RAND_RESET_I(1);
    v__DOT__trigger_env1 = VL_RAND_RESET_I(1);
    v__DOT__trigger_env2 = VL_RAND_RESET_I(1);
    v__DOT__trigger_len0 = VL_RAND_RESET_I(1);
    v__DOT____Vcellinp__env0____pinNumber5 = 0;
    v__DOT____Vcellinp__env0____pinNumber4 = VL_RAND_RESET_I(3);
    v__DOT____Vcellinp__env0____pinNumber3 = VL_RAND_RESET_I(4);
    v__DOT____Vcellinp__env1____pinNumber5 = 0;
    v__DOT____Vcellinp__env1____pinNumber4 = VL_RAND_RESET_I(3);
    v__DOT____Vcellinp__env1____pinNumber3 = VL_RAND_RESET_I(4);
    v__DOT____Vcellinp__env2____pinNumber5 = 0;
    v__DOT____Vcellinp__env2____pinNumber4 = VL_RAND_RESET_I(3);
    v__DOT____Vcellinp__env2____pinNumber3 = VL_RAND_RESET_I(4);
    v__DOT__pulse0__DOT__counter = VL_RAND_RESET_I(11);
    v__DOT__pulse0__DOT__clk_div = VL_RAND_RESET_I(2);
    v__DOT__pulse0__DOT__duty = VL_RAND_RESET_I(8);
    v__DOT__pulse0__DOT__old_duty = VL_RAND_RESET_I(2);
    v__DOT__pulse0__DOT__reload_duty = VL_RAND_RESET_I(1);
    v__DOT__pulse1__DOT__counter = VL_RAND_RESET_I(11);
    v__DOT__pulse1__DOT__clk_div = VL_RAND_RESET_I(2);
    v__DOT__pulse1__DOT__duty = VL_RAND_RESET_I(8);
    v__DOT__pulse1__DOT__old_duty = VL_RAND_RESET_I(2);
    v__DOT__pulse1__DOT__reload_duty = VL_RAND_RESET_I(1);
    v__DOT__wave__DOT__counter = VL_RAND_RESET_I(11);
    v__DOT__wave__DOT__clk_div = VL_RAND_RESET_I(1);
    v__DOT__wave__DOT__wave_addr = VL_RAND_RESET_I(5);
    v__DOT__noise__DOT__period_dec = VL_RAND_RESET_I(11);
    v__DOT__noise__DOT__counter = VL_RAND_RESET_I(11);
    v__DOT__noise__DOT__lfsr = VL_RAND_RESET_I(15);
    v__DOT__noise__DOT__xor_bit = VL_RAND_RESET_I(1);
    v__DOT__len0__DOT__counter = VL_RAND_RESET_I(6);
    v__DOT__len1__DOT__counter = VL_RAND_RESET_I(6);
    v__DOT__env0__DOT__value = VL_RAND_RESET_I(4);
    v__DOT__env0__DOT__clk_div = VL_RAND_RESET_I(3);
    v__DOT__env1__DOT__value = VL_RAND_RESET_I(4);
    v__DOT__env1__DOT__clk_div = VL_RAND_RESET_I(3);
    v__DOT__env2__DOT__value = VL_RAND_RESET_I(4);
    v__DOT__env2__DOT__clk_div = VL_RAND_RESET_I(3);
    __Vdlyvset__v__DOT__r__v0 = 0;
    __VinpClk__TOP__v__DOT__trigger_env0 = VL_RAND_RESET_I(1);
    __VinpClk__TOP__v__DOT__trigger_env2 = VL_RAND_RESET_I(1);
    __VinpClk__TOP__v__DOT__trigger_env1 = VL_RAND_RESET_I(1);
    __Vclklast__TOP__in_clk = 0;
    __Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env0 = 0;
    __Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env2 = 0;
    __Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env1 = 0;
    __Vchglast__TOP__v__DOT__trigger_env0 = VL_RAND_RESET_I(1);
    __Vchglast__TOP__v__DOT__trigger_env1 = VL_RAND_RESET_I(1);
    __Vchglast__TOP__v__DOT__trigger_env2 = VL_RAND_RESET_I(1);
}

void Vgbdmg::__Vconfigure(Vgbdmg__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vgbdmg::~Vgbdmg() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vgbdmg::eval() {
    Vgbdmg__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vgbdmg::eval\n"); );
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

void Vgbdmg::_eval_initial_loop(Vgbdmg__Syms* __restrict vlSymsp) {
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

void Vgbdmg::_initial__TOP(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_initial__TOP\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    //char	__VpadToAlign4[4];
    VL_SIGW(__Vtemp1,103,0,4);
    // Body
    // INITIAL at source/gbdmg.v:229
    __Vtemp1[0] = 0x2e747874;
    __Vtemp1[1] = 0x5f646163;
    __Vtemp1[2] = 0x62646d67;
    __Vtemp1[3] = 0x67;
    VL_READMEM_W (true,16,32, 0,4, __Vtemp1, vlTOPp->v__DOT__AMP_TABLE
		  ,0,~0);
}

void Vgbdmg::_sequent__TOP__1(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_sequent__TOP__1\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__frame_seq,2,0);
    VL_SIG8(__Vdly__v__DOT__pulse0__DOT__clk_div,1,0);
    VL_SIG8(__Vdly__v__DOT__pulse0__DOT__duty,7,0);
    VL_SIG8(__Vdly__v__DOT__pulse1__DOT__clk_div,1,0);
    VL_SIG8(__Vdly__v__DOT__pulse1__DOT__duty,7,0);
    VL_SIG8(__Vdly__v__DOT__wave__DOT__clk_div,0,0);
    VL_SIG8(__Vdly__v__DOT__wave__DOT__wave_addr,4,0);
    VL_SIG8(__Vdly__v__DOT__len0__DOT__counter,5,0);
    VL_SIG8(__Vdly__v__DOT__len1__DOT__counter,5,0);
    //char	__VpadToAlign53[1];
    VL_SIG16(__Vdly__v__DOT__frame_clk_div,13,0);
    VL_SIG16(__Vdly__v__DOT__pulse0__DOT__counter,10,0);
    VL_SIG16(__Vdly__v__DOT__pulse1__DOT__counter,10,0);
    VL_SIG16(__Vdly__v__DOT__wave__DOT__counter,10,0);
    VL_SIG16(__Vdly__v__DOT__noise__DOT__lfsr,14,0);
    VL_SIG16(__Vdly__v__DOT__noise__DOT__counter,10,0);
    VL_SIG16(__Vdly__v__DOT__noise__DOT__period_dec,10,0);
    // Body
    __Vdly__v__DOT__frame_clk_div = vlTOPp->v__DOT__frame_clk_div;
    __Vdly__v__DOT__frame_seq = vlTOPp->v__DOT__frame_seq;
    __Vdly__v__DOT__wave__DOT__counter = vlTOPp->v__DOT__wave__DOT__counter;
    __Vdly__v__DOT__wave__DOT__clk_div = vlTOPp->v__DOT__wave__DOT__clk_div;
    __Vdly__v__DOT__noise__DOT__period_dec = vlTOPp->v__DOT__noise__DOT__period_dec;
    __Vdly__v__DOT__noise__DOT__counter = vlTOPp->v__DOT__noise__DOT__counter;
    __Vdly__v__DOT__pulse1__DOT__counter = vlTOPp->v__DOT__pulse1__DOT__counter;
    __Vdly__v__DOT__pulse1__DOT__clk_div = vlTOPp->v__DOT__pulse1__DOT__clk_div;
    __Vdly__v__DOT__pulse0__DOT__clk_div = vlTOPp->v__DOT__pulse0__DOT__clk_div;
    __Vdly__v__DOT__pulse0__DOT__counter = vlTOPp->v__DOT__pulse0__DOT__counter;
    __Vdly__v__DOT__wave__DOT__wave_addr = vlTOPp->v__DOT__wave__DOT__wave_addr;
    __Vdly__v__DOT__pulse1__DOT__duty = vlTOPp->v__DOT__pulse1__DOT__duty;
    __Vdly__v__DOT__pulse0__DOT__duty = vlTOPp->v__DOT__pulse0__DOT__duty;
    __Vdly__v__DOT__noise__DOT__lfsr = vlTOPp->v__DOT__noise__DOT__lfsr;
    __Vdly__v__DOT__len0__DOT__counter = vlTOPp->v__DOT__len0__DOT__counter;
    __Vdly__v__DOT__len1__DOT__counter = vlTOPp->v__DOT__len1__DOT__counter;
    vlTOPp->__Vdlyvset__v__DOT__r__v0 = 0;
    // ALWAYS at source/gbdmg.v:338
    if ((0 == (IData)(vlTOPp->v__DOT__frame_clk_div))) {
	__Vdly__v__DOT__frame_seq = (7 & ((IData)(1) 
					  + (IData)(vlTOPp->v__DOT__frame_seq)));
	__Vdly__v__DOT__frame_clk_div = 0x2000;
    } else {
	__Vdly__v__DOT__frame_clk_div = (0x3fff & ((IData)(vlTOPp->v__DOT__frame_clk_div) 
						   - (IData)(1)));
    }
    // ALWAYS at source/gbdmg.v:64
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__wave__DOT__counter = 0;
	__Vdly__v__DOT__wave__DOT__clk_div = 0;
	__Vdly__v__DOT__wave__DOT__wave_addr = 0;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__wave__DOT__clk_div))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__wave__DOT__counter))) {
		__Vdly__v__DOT__wave__DOT__wave_addr 
		    = (0x1f & ((IData)(1) + (IData)(vlTOPp->v__DOT__wave__DOT__wave_addr)));
		__Vdly__v__DOT__wave__DOT__counter 
		    = vlTOPp->v__DOT__wave_freq;
	    } else {
		__Vdly__v__DOT__wave__DOT__counter 
		    = (0x7ff & ((IData)(1) + (IData)(vlTOPp->v__DOT__wave__DOT__counter)));
	    }
	}
	__Vdly__v__DOT__wave__DOT__clk_div = (1 & (~ (IData)(vlTOPp->v__DOT__wave__DOT__clk_div)));
    }
    // ALWAYS at source/gbdmg.v:21
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__pulse1__DOT__counter = 0;
	vlTOPp->v__DOT__pulse1__DOT__old_duty = (3 
						 & (~ (IData)(vlTOPp->v__DOT__pulse1_duty)));
	__Vdly__v__DOT__pulse1__DOT__clk_div = 0;
    } else {
	if (vlTOPp->v__DOT__pulse1__DOT__reload_duty) {
	    __Vdly__v__DOT__pulse1__DOT__duty = ((2 
						  & (IData)(vlTOPp->v__DOT__pulse1_duty))
						  ? 
						 ((1 
						   & (IData)(vlTOPp->v__DOT__pulse1_duty))
						   ? 0x7e
						   : 0x87)
						  : 
						 ((1 
						   & (IData)(vlTOPp->v__DOT__pulse1_duty))
						   ? 0x81
						   : 1));
	}
	if ((0 == (IData)(vlTOPp->v__DOT__pulse1__DOT__clk_div))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__pulse1__DOT__counter))) {
		if ((1 & (~ (IData)(vlTOPp->v__DOT__pulse1__DOT__reload_duty)))) {
		    __Vdly__v__DOT__pulse1__DOT__duty 
			= ((0x80 & ((IData)(vlTOPp->v__DOT__pulse1__DOT__duty) 
				    << 7)) | (0x7f 
					      & ((IData)(vlTOPp->v__DOT__pulse1__DOT__duty) 
						 >> 1)));
		}
		__Vdly__v__DOT__pulse1__DOT__counter 
		    = vlTOPp->v__DOT__pulse1_freq;
	    } else {
		__Vdly__v__DOT__pulse1__DOT__counter 
		    = (0x7ff & ((IData)(1) + (IData)(vlTOPp->v__DOT__pulse1__DOT__counter)));
	    }
	}
	vlTOPp->v__DOT__pulse1__DOT__old_duty = vlTOPp->v__DOT__pulse1_duty;
	__Vdly__v__DOT__pulse1__DOT__clk_div = (3 & 
						((IData)(1) 
						 + (IData)(vlTOPp->v__DOT__pulse1__DOT__clk_div)));
    }
    // ALWAYS at source/gbdmg.v:21
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__pulse0__DOT__counter = 0;
	vlTOPp->v__DOT__pulse0__DOT__old_duty = (3 
						 & (~ (IData)(vlTOPp->v__DOT__pulse0_duty)));
	__Vdly__v__DOT__pulse0__DOT__clk_div = 0;
    } else {
	if (vlTOPp->v__DOT__pulse0__DOT__reload_duty) {
	    __Vdly__v__DOT__pulse0__DOT__duty = ((2 
						  & (IData)(vlTOPp->v__DOT__pulse0_duty))
						  ? 
						 ((1 
						   & (IData)(vlTOPp->v__DOT__pulse0_duty))
						   ? 0x7e
						   : 0x87)
						  : 
						 ((1 
						   & (IData)(vlTOPp->v__DOT__pulse0_duty))
						   ? 0x81
						   : 1));
	}
	if ((0 == (IData)(vlTOPp->v__DOT__pulse0__DOT__clk_div))) {
	    if ((0 == (IData)(vlTOPp->v__DOT__pulse0__DOT__counter))) {
		if ((1 & (~ (IData)(vlTOPp->v__DOT__pulse0__DOT__reload_duty)))) {
		    __Vdly__v__DOT__pulse0__DOT__duty 
			= ((0x80 & ((IData)(vlTOPp->v__DOT__pulse0__DOT__duty) 
				    << 7)) | (0x7f 
					      & ((IData)(vlTOPp->v__DOT__pulse0__DOT__duty) 
						 >> 1)));
		}
		__Vdly__v__DOT__pulse0__DOT__counter 
		    = vlTOPp->v__DOT__pulse0_freq;
	    } else {
		__Vdly__v__DOT__pulse0__DOT__counter 
		    = (0x7ff & ((IData)(1) + (IData)(vlTOPp->v__DOT__pulse0__DOT__counter)));
	    }
	}
	vlTOPp->v__DOT__pulse0__DOT__old_duty = vlTOPp->v__DOT__pulse0_duty;
	__Vdly__v__DOT__pulse0__DOT__clk_div = (3 & 
						((IData)(1) 
						 + (IData)(vlTOPp->v__DOT__pulse0__DOT__clk_div)));
    }
    // ALWAYS at source/gbdmg.v:189
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__noise__DOT__lfsr = 1;
    } else {
	if ((0 == (IData)(vlTOPp->v__DOT__noise__DOT__counter))) {
	    __Vdly__v__DOT__noise__DOT__lfsr = ((IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber5)
						 ? 
						(((IData)(vlTOPp->v__DOT__noise__DOT__xor_bit) 
						  << 6) 
						 | (0x3f 
						    & (IData)(vlTOPp->v__DOT__noise__DOT__lfsr)))
						 : 
						(((IData)(vlTOPp->v__DOT__noise__DOT__xor_bit) 
						  << 0xe) 
						 | (0x3fff 
						    & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
						       >> 1))));
	    __Vdly__v__DOT__noise__DOT__counter = (0x7ff 
						   & ((IData)(vlTOPp->v__DOT__noise__DOT__period_dec) 
						      << (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber3)));
	} else {
	    __Vdly__v__DOT__noise__DOT__counter = (0x7ff 
						   & ((IData)(vlTOPp->v__DOT__noise__DOT__counter) 
						      - (IData)(1)));
	}
	if (((((((((0 == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4)) 
		   | (1 == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4))) 
		  | (2 == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4))) 
		 | (3 == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4))) 
		| (4 == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4))) 
	       | (5 == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4))) 
	      | (6 == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4))) 
	     | (7 == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4)))) {
	    __Vdly__v__DOT__noise__DOT__period_dec 
		= ((0 == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4))
		    ? 8 : ((1 == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4))
			    ? 0x10 : ((2 == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4))
				       ? 0x20 : ((3 
						  == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4))
						  ? 0x30
						  : 
						 ((4 
						   == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4))
						   ? 0x40
						   : 
						  ((5 
						    == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4))
						    ? 0x50
						    : 
						   ((6 
						     == (IData)(vlTOPp->v__DOT____Vcellinp__noise____pinNumber4))
						     ? 0x60
						     : 0x70)))))));
	}
    }
    // ALWAYS at source/gbdmg.v:155
    __Vdly__v__DOT__len0__DOT__counter = (0x3f & ((IData)(vlTOPp->in_rst)
						   ? 0
						   : 
						  ((IData)(vlTOPp->v__DOT__trigger_len0)
						    ? (IData)(vlTOPp->v__DOT____Vcellinp__len0____pinNumber3)
						    : 
						   (((IData)(vlTOPp->v__DOT__tick_len_cnt) 
						     & (0 
							!= (IData)(vlTOPp->v__DOT__len0__DOT__counter)))
						     ? 
						    ((IData)(1) 
						     + (IData)(vlTOPp->v__DOT__len0__DOT__counter))
						     : (IData)(vlTOPp->v__DOT__len0__DOT__counter)))));
    // ALWAYS at source/gbdmg.v:155
    __Vdly__v__DOT__len1__DOT__counter = (0x3f & ((IData)(vlTOPp->in_rst)
						   ? 0
						   : 
						  ((IData)(vlTOPp->v__DOT__trigger_len0)
						    ? (IData)(vlTOPp->v__DOT____Vcellinp__len1____pinNumber3)
						    : 
						   (((IData)(vlTOPp->v__DOT__tick_len_cnt) 
						     & (0 
							!= (IData)(vlTOPp->v__DOT__len1__DOT__counter)))
						     ? 
						    ((IData)(1) 
						     + (IData)(vlTOPp->v__DOT__len1__DOT__counter))
						     : (IData)(vlTOPp->v__DOT__len1__DOT__counter)))));
    vlTOPp->v__DOT__frame_clk_div = __Vdly__v__DOT__frame_clk_div;
    vlTOPp->v__DOT__frame_seq = __Vdly__v__DOT__frame_seq;
    vlTOPp->v__DOT__wave__DOT__clk_div = __Vdly__v__DOT__wave__DOT__clk_div;
    vlTOPp->v__DOT__wave__DOT__counter = __Vdly__v__DOT__wave__DOT__counter;
    vlTOPp->v__DOT__wave__DOT__wave_addr = __Vdly__v__DOT__wave__DOT__wave_addr;
    vlTOPp->v__DOT__pulse1__DOT__clk_div = __Vdly__v__DOT__pulse1__DOT__clk_div;
    vlTOPp->v__DOT__pulse1__DOT__counter = __Vdly__v__DOT__pulse1__DOT__counter;
    vlTOPp->v__DOT__pulse1__DOT__duty = __Vdly__v__DOT__pulse1__DOT__duty;
    vlTOPp->v__DOT__pulse0__DOT__clk_div = __Vdly__v__DOT__pulse0__DOT__clk_div;
    vlTOPp->v__DOT__pulse0__DOT__counter = __Vdly__v__DOT__pulse0__DOT__counter;
    vlTOPp->v__DOT__pulse0__DOT__duty = __Vdly__v__DOT__pulse0__DOT__duty;
    vlTOPp->v__DOT__noise__DOT__counter = __Vdly__v__DOT__noise__DOT__counter;
    vlTOPp->v__DOT__noise__DOT__period_dec = __Vdly__v__DOT__noise__DOT__period_dec;
    vlTOPp->v__DOT__noise__DOT__lfsr = __Vdly__v__DOT__noise__DOT__lfsr;
    vlTOPp->v__DOT__len0__DOT__counter = __Vdly__v__DOT__len0__DOT__counter;
    vlTOPp->v__DOT__len1__DOT__counter = __Vdly__v__DOT__len1__DOT__counter;
    vlTOPp->v__DOT__tick_len_cnt = ((0 == (IData)(vlTOPp->v__DOT__frame_clk_div)) 
				    & (0 == (1 & (IData)(vlTOPp->v__DOT__frame_seq))));
    vlTOPp->v__DOT__noise__DOT__xor_bit = (1 & (((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
						 >> 1) 
						^ (IData)(vlTOPp->v__DOT__noise__DOT__lfsr)));
}

void Vgbdmg::_sequent__TOP__2(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_sequent__TOP__2\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__env0__DOT__value,3,0);
    VL_SIG8(__Vdly__v__DOT__env0__DOT__clk_div,2,0);
    //char	__VpadToAlign90[2];
    // Body
    __Vdly__v__DOT__env0__DOT__clk_div = vlTOPp->v__DOT__env0__DOT__clk_div;
    __Vdly__v__DOT__env0__DOT__value = vlTOPp->v__DOT__env0__DOT__value;
    // ALWAYS at source/gbdmg.v:114
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__env0__DOT__value = 0;
	__Vdly__v__DOT__env0__DOT__clk_div = 0;
    } else {
	if (vlTOPp->v__DOT__trigger_env0) {
	    __Vdly__v__DOT__env0__DOT__value = vlTOPp->v__DOT____Vcellinp__env0____pinNumber3;
	    __Vdly__v__DOT__env0__DOT__clk_div = vlTOPp->v__DOT____Vcellinp__env0____pinNumber4;
	} else {
	    if (((IData)(vlTOPp->v__DOT__tick_env) 
		 & (0 != (IData)(vlTOPp->v__DOT____Vcellinp__env0____pinNumber4)))) {
		if ((0 == (IData)(vlTOPp->v__DOT__env0__DOT__clk_div))) {
		    __Vdly__v__DOT__env0__DOT__value 
			= (0xf & ((IData)(vlTOPp->v__DOT____Vcellinp__env0____pinNumber5)
				   ? ((0xf == (IData)(vlTOPp->v__DOT__env0__DOT__value))
				       ? (IData)(vlTOPp->v__DOT__env0__DOT__value)
				       : ((IData)(1) 
					  + (IData)(vlTOPp->v__DOT__env0__DOT__value)))
				   : ((0 == (IData)(vlTOPp->v__DOT__env0__DOT__value))
				       ? (IData)(vlTOPp->v__DOT__env0__DOT__value)
				       : ((IData)(vlTOPp->v__DOT__env0__DOT__value) 
					  - (IData)(1)))));
		    __Vdly__v__DOT__env0__DOT__clk_div 
			= vlTOPp->v__DOT____Vcellinp__env0____pinNumber4;
		} else {
		    __Vdly__v__DOT__env0__DOT__clk_div 
			= (7 & ((IData)(vlTOPp->v__DOT__env0__DOT__clk_div) 
				- (IData)(1)));
		}
	    }
	}
    }
    vlTOPp->v__DOT__env0__DOT__clk_div = __Vdly__v__DOT__env0__DOT__clk_div;
    vlTOPp->v__DOT__env0__DOT__value = __Vdly__v__DOT__env0__DOT__value;
    vlTOPp->v__DOT__pulse0_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__pulse0__DOT__duty) 
		   << 4)) | (IData)(vlTOPp->v__DOT__env0__DOT__value))];
}

void Vgbdmg::_sequent__TOP__3(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_sequent__TOP__3\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__env2__DOT__value,3,0);
    VL_SIG8(__Vdly__v__DOT__env2__DOT__clk_div,2,0);
    //char	__VpadToAlign114[2];
    // Body
    __Vdly__v__DOT__env2__DOT__clk_div = vlTOPp->v__DOT__env2__DOT__clk_div;
    __Vdly__v__DOT__env2__DOT__value = vlTOPp->v__DOT__env2__DOT__value;
    // ALWAYS at source/gbdmg.v:114
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__env2__DOT__value = 0;
	__Vdly__v__DOT__env2__DOT__clk_div = 0;
    } else {
	if (vlTOPp->v__DOT__trigger_env2) {
	    __Vdly__v__DOT__env2__DOT__value = vlTOPp->v__DOT____Vcellinp__env2____pinNumber3;
	    __Vdly__v__DOT__env2__DOT__clk_div = vlTOPp->v__DOT____Vcellinp__env2____pinNumber4;
	} else {
	    if (((IData)(vlTOPp->v__DOT__tick_env) 
		 & (0 != (IData)(vlTOPp->v__DOT____Vcellinp__env2____pinNumber4)))) {
		if ((0 == (IData)(vlTOPp->v__DOT__env2__DOT__clk_div))) {
		    __Vdly__v__DOT__env2__DOT__value 
			= (0xf & ((IData)(vlTOPp->v__DOT____Vcellinp__env2____pinNumber5)
				   ? ((0xf == (IData)(vlTOPp->v__DOT__env2__DOT__value))
				       ? (IData)(vlTOPp->v__DOT__env2__DOT__value)
				       : ((IData)(1) 
					  + (IData)(vlTOPp->v__DOT__env2__DOT__value)))
				   : ((0 == (IData)(vlTOPp->v__DOT__env2__DOT__value))
				       ? (IData)(vlTOPp->v__DOT__env2__DOT__value)
				       : ((IData)(vlTOPp->v__DOT__env2__DOT__value) 
					  - (IData)(1)))));
		    __Vdly__v__DOT__env2__DOT__clk_div 
			= vlTOPp->v__DOT____Vcellinp__env2____pinNumber4;
		} else {
		    __Vdly__v__DOT__env2__DOT__clk_div 
			= (7 & ((IData)(vlTOPp->v__DOT__env2__DOT__clk_div) 
				- (IData)(1)));
		}
	    }
	}
    }
    vlTOPp->v__DOT__env2__DOT__clk_div = __Vdly__v__DOT__env2__DOT__clk_div;
    vlTOPp->v__DOT__env2__DOT__value = __Vdly__v__DOT__env2__DOT__value;
    vlTOPp->v__DOT__noise_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
		   << 4)) | (IData)(vlTOPp->v__DOT__env2__DOT__value))];
}

void Vgbdmg::_sequent__TOP__4(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_sequent__TOP__4\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__env1__DOT__value,3,0);
    VL_SIG8(__Vdly__v__DOT__env1__DOT__clk_div,2,0);
    //char	__VpadToAlign138[2];
    // Body
    __Vdly__v__DOT__env1__DOT__clk_div = vlTOPp->v__DOT__env1__DOT__clk_div;
    __Vdly__v__DOT__env1__DOT__value = vlTOPp->v__DOT__env1__DOT__value;
    // ALWAYS at source/gbdmg.v:114
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__env1__DOT__value = 0;
	__Vdly__v__DOT__env1__DOT__clk_div = 0;
    } else {
	if (vlTOPp->v__DOT__trigger_env1) {
	    __Vdly__v__DOT__env1__DOT__value = vlTOPp->v__DOT____Vcellinp__env1____pinNumber3;
	    __Vdly__v__DOT__env1__DOT__clk_div = vlTOPp->v__DOT____Vcellinp__env1____pinNumber4;
	} else {
	    if (((IData)(vlTOPp->v__DOT__tick_env) 
		 & (0 != (IData)(vlTOPp->v__DOT____Vcellinp__env1____pinNumber4)))) {
		if ((0 == (IData)(vlTOPp->v__DOT__env1__DOT__clk_div))) {
		    __Vdly__v__DOT__env1__DOT__value 
			= (0xf & ((IData)(vlTOPp->v__DOT____Vcellinp__env1____pinNumber5)
				   ? ((0xf == (IData)(vlTOPp->v__DOT__env1__DOT__value))
				       ? (IData)(vlTOPp->v__DOT__env1__DOT__value)
				       : ((IData)(1) 
					  + (IData)(vlTOPp->v__DOT__env1__DOT__value)))
				   : ((0 == (IData)(vlTOPp->v__DOT__env1__DOT__value))
				       ? (IData)(vlTOPp->v__DOT__env1__DOT__value)
				       : ((IData)(vlTOPp->v__DOT__env1__DOT__value) 
					  - (IData)(1)))));
		    __Vdly__v__DOT__env1__DOT__clk_div 
			= vlTOPp->v__DOT____Vcellinp__env1____pinNumber4;
		} else {
		    __Vdly__v__DOT__env1__DOT__clk_div 
			= (7 & ((IData)(vlTOPp->v__DOT__env1__DOT__clk_div) 
				- (IData)(1)));
		}
	    }
	}
    }
    vlTOPp->v__DOT__env1__DOT__clk_div = __Vdly__v__DOT__env1__DOT__clk_div;
    vlTOPp->v__DOT__env1__DOT__value = __Vdly__v__DOT__env1__DOT__value;
    vlTOPp->v__DOT__pulse1_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__pulse1__DOT__duty) 
		   << 4)) | (IData)(vlTOPp->v__DOT__env1__DOT__value))];
}

void Vgbdmg::_settle__TOP__5(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_settle__TOP__5\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__tick_len_cnt = ((0 == (IData)(vlTOPp->v__DOT__frame_clk_div)) 
				    & (0 == (1 & (IData)(vlTOPp->v__DOT__frame_seq))));
    vlTOPp->v__DOT__noise__DOT__xor_bit = (1 & (((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
						 >> 1) 
						^ (IData)(vlTOPp->v__DOT__noise__DOT__lfsr)));
    vlTOPp->v__DOT__pulse0_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__pulse0__DOT__duty) 
		   << 4)) | (IData)(vlTOPp->v__DOT__env0__DOT__value))];
    vlTOPp->v__DOT__noise_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__noise__DOT__lfsr) 
		   << 4)) | (IData)(vlTOPp->v__DOT__env2__DOT__value))];
    vlTOPp->v__DOT__tick_env = ((0 == (IData)(vlTOPp->v__DOT__frame_clk_div)) 
				& (7 == (IData)(vlTOPp->v__DOT__frame_seq)));
    vlTOPp->v__DOT__pulse1_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__pulse1__DOT__duty) 
		   << 4)) | (IData)(vlTOPp->v__DOT__env1__DOT__value))];
}

void Vgbdmg::_sequent__TOP__6(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_sequent__TOP__6\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdlyvdim0__v__DOT__r__v0,5,0);
    VL_SIG8(__Vdlyvval__v__DOT__r__v0,7,0);
    //char	__VpadToAlign182[2];
    // Body
    vlTOPp->v__DOT__tick_env = ((0 == (IData)(vlTOPp->v__DOT__frame_clk_div)) 
				& (7 == (IData)(vlTOPp->v__DOT__frame_seq)));
    // ALWAYS at source/gbdmg.v:316
    if ((1 & (~ (IData)(vlTOPp->in_rst)))) {
	vlTOPp->v__DOT__trigger_len0 = ((IData)(vlTOPp->v__DOT__wr_posedge) 
					& (1 == (IData)(vlTOPp->in_reg)));
	vlTOPp->v__DOT__trigger_env0 = (((IData)(vlTOPp->v__DOT__wr_posedge) 
					 & (4 == (IData)(vlTOPp->in_reg))) 
					& ((IData)(vlTOPp->in_val) 
					   >> 7));
	vlTOPp->v__DOT__trigger_env1 = (((IData)(vlTOPp->v__DOT__wr_posedge) 
					 & (9 == (IData)(vlTOPp->in_reg))) 
					& ((IData)(vlTOPp->in_val) 
					   >> 7));
	vlTOPp->v__DOT__trigger_env2 = (((IData)(vlTOPp->v__DOT__wr_posedge) 
					 & (0x13 == (IData)(vlTOPp->in_reg))) 
					& ((IData)(vlTOPp->in_val) 
					   >> 7));
	if (vlTOPp->v__DOT__wr_posedge) {
	    __Vdlyvval__v__DOT__r__v0 = vlTOPp->in_val;
	    vlTOPp->__Vdlyvset__v__DOT__r__v0 = 1;
	    __Vdlyvdim0__v__DOT__r__v0 = vlTOPp->in_reg;
	}
    }
    vlTOPp->v__DOT__wr_old = vlTOPp->in_wr;
    // ALWAYSPOST at source/gbdmg.v:332
    if (vlTOPp->__Vdlyvset__v__DOT__r__v0) {
	vlTOPp->v__DOT__r[(IData)(__Vdlyvdim0__v__DOT__r__v0)] 
	    = __Vdlyvval__v__DOT__r__v0;
    }
    vlTOPp->v__DOT____Vcellinp__len1____pinNumber3 
	= (0x3f & (IData)(vlTOPp->v__DOT__r)[6]);
    vlTOPp->v__DOT____Vcellinp__env0____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__r)[2] >> 3));
    vlTOPp->v__DOT____Vcellinp__env0____pinNumber4 
	= (7 & (IData)(vlTOPp->v__DOT__r)[2]);
    vlTOPp->v__DOT____Vcellinp__env0____pinNumber3 
	= (0xf & ((IData)(vlTOPp->v__DOT__r)[2] >> 4));
    vlTOPp->v__DOT____Vcellinp__env1____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__r)[7] >> 3));
    vlTOPp->v__DOT____Vcellinp__env1____pinNumber4 
	= (7 & (IData)(vlTOPp->v__DOT__r)[7]);
    vlTOPp->v__DOT____Vcellinp__env1____pinNumber3 
	= (0xf & ((IData)(vlTOPp->v__DOT__r)[7] >> 4));
    vlTOPp->v__DOT____Vcellinp__env2____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__r)[0x11] >> 3));
    vlTOPp->v__DOT____Vcellinp__env2____pinNumber4 
	= (7 & (IData)(vlTOPp->v__DOT__r)[0x11]);
    vlTOPp->v__DOT____Vcellinp__env2____pinNumber3 
	= (0xf & ((IData)(vlTOPp->v__DOT__r)[0x11] 
		  >> 4));
    vlTOPp->v__DOT__pulse0_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__r)
					     [4] << 8)) 
				   | (IData)(vlTOPp->v__DOT__r)
				   [3]);
    vlTOPp->v__DOT____Vcellinp__len0____pinNumber3 
	= (0x3f & (IData)(vlTOPp->v__DOT__r)[1]);
    vlTOPp->v__DOT____Vcellinp__noise____pinNumber3 
	= (0xf & ((IData)(vlTOPp->v__DOT__r)[0x12] 
		  >> 4));
    vlTOPp->v__DOT____Vcellinp__noise____pinNumber4 
	= (7 & (IData)(vlTOPp->v__DOT__r)[0x12]);
    vlTOPp->v__DOT____Vcellinp__noise____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__r)[0x12] >> 3));
    vlTOPp->v__DOT__pulse1_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__r)
					     [9] << 8)) 
				   | (IData)(vlTOPp->v__DOT__r)
				   [8]);
    vlTOPp->v__DOT__wave_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__r)
					   [0xe] << 8)) 
				 | (IData)(vlTOPp->v__DOT__r)
				 [0xd]);
    vlTOPp->v__DOT__pulse0_duty = (3 & ((IData)(vlTOPp->v__DOT__r)
					[1] >> 6));
    vlTOPp->v__DOT__pulse1_duty = (3 & ((IData)(vlTOPp->v__DOT__r)
					[6] >> 6));
    vlTOPp->v__DOT____Vcellinp__len1____pinNumber6 
	= (1 & ((IData)(vlTOPp->v__DOT__r)[9] >> 6));
    vlTOPp->v__DOT____Vcellinp__len0____pinNumber6 
	= (1 & ((IData)(vlTOPp->v__DOT__r)[4] >> 6));
    vlTOPp->v__DOT__wave_vol = (3 & ((IData)(vlTOPp->v__DOT__r)
				     [0xc] >> 5));
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[0xc] 
	= (IData)(vlTOPp->v__DOT__r)[0x2c];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[6] 
	= (IData)(vlTOPp->v__DOT__r)[0x26];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[7] 
	= (IData)(vlTOPp->v__DOT__r)[0x27];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[8] 
	= (IData)(vlTOPp->v__DOT__r)[0x28];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[3] 
	= (IData)(vlTOPp->v__DOT__r)[0x23];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[9] 
	= (IData)(vlTOPp->v__DOT__r)[0x29];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[2] 
	= (IData)(vlTOPp->v__DOT__r)[0x22];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[0xa] 
	= (IData)(vlTOPp->v__DOT__r)[0x2a];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[0xb] 
	= (IData)(vlTOPp->v__DOT__r)[0x2b];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[4] 
	= (IData)(vlTOPp->v__DOT__r)[0x24];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[0xd] 
	= (IData)(vlTOPp->v__DOT__r)[0x2d];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[0xe] 
	= (IData)(vlTOPp->v__DOT__r)[0x2e];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[0xf] 
	= (IData)(vlTOPp->v__DOT__r)[0x2f];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[1] 
	= (IData)(vlTOPp->v__DOT__r)[0x21];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[0] 
	= (IData)(vlTOPp->v__DOT__r)[0x20];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[5] 
	= (IData)(vlTOPp->v__DOT__r)[0x25];
}

void Vgbdmg::_combo__TOP__7(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_combo__TOP__7\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__wr_posedge = ((IData)(vlTOPp->in_wr) 
				  & (~ (IData)(vlTOPp->v__DOT__wr_old)));
}

void Vgbdmg::_settle__TOP__8(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_settle__TOP__8\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__wr_posedge = ((IData)(vlTOPp->in_wr) 
				  & (~ (IData)(vlTOPp->v__DOT__wr_old)));
    vlTOPp->v__DOT____Vcellinp__noise____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__r)[0x12] >> 3));
    vlTOPp->v__DOT__pulse1_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__r)
					     [9] << 8)) 
				   | (IData)(vlTOPp->v__DOT__r)
				   [8]);
    vlTOPp->v__DOT__wave_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__r)
					   [0xe] << 8)) 
				 | (IData)(vlTOPp->v__DOT__r)
				 [0xd]);
    vlTOPp->v__DOT__pulse0_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__r)
					     [4] << 8)) 
				   | (IData)(vlTOPp->v__DOT__r)
				   [3]);
    vlTOPp->v__DOT____Vcellinp__noise____pinNumber4 
	= (7 & (IData)(vlTOPp->v__DOT__r)[0x12]);
    vlTOPp->v__DOT____Vcellinp__noise____pinNumber3 
	= (0xf & ((IData)(vlTOPp->v__DOT__r)[0x12] 
		  >> 4));
    vlTOPp->v__DOT____Vcellinp__len0____pinNumber3 
	= (0x3f & (IData)(vlTOPp->v__DOT__r)[1]);
    vlTOPp->v__DOT____Vcellinp__len1____pinNumber3 
	= (0x3f & (IData)(vlTOPp->v__DOT__r)[6]);
    vlTOPp->v__DOT____Vcellinp__env0____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__r)[2] >> 3));
    vlTOPp->v__DOT____Vcellinp__env0____pinNumber4 
	= (7 & (IData)(vlTOPp->v__DOT__r)[2]);
    vlTOPp->v__DOT____Vcellinp__env0____pinNumber3 
	= (0xf & ((IData)(vlTOPp->v__DOT__r)[2] >> 4));
    vlTOPp->v__DOT____Vcellinp__env1____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__r)[7] >> 3));
    vlTOPp->v__DOT____Vcellinp__env1____pinNumber4 
	= (7 & (IData)(vlTOPp->v__DOT__r)[7]);
    vlTOPp->v__DOT____Vcellinp__env1____pinNumber3 
	= (0xf & ((IData)(vlTOPp->v__DOT__r)[7] >> 4));
    vlTOPp->v__DOT____Vcellinp__env2____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__r)[0x11] >> 3));
    vlTOPp->v__DOT____Vcellinp__env2____pinNumber4 
	= (7 & (IData)(vlTOPp->v__DOT__r)[0x11]);
    vlTOPp->v__DOT____Vcellinp__env2____pinNumber3 
	= (0xf & ((IData)(vlTOPp->v__DOT__r)[0x11] 
		  >> 4));
    vlTOPp->v__DOT__pulse0_duty = (3 & ((IData)(vlTOPp->v__DOT__r)
					[1] >> 6));
    vlTOPp->v__DOT__pulse1_duty = (3 & ((IData)(vlTOPp->v__DOT__r)
					[6] >> 6));
    vlTOPp->v__DOT____Vcellinp__len1____pinNumber6 
	= (1 & ((IData)(vlTOPp->v__DOT__r)[9] >> 6));
    vlTOPp->v__DOT____Vcellinp__len0____pinNumber6 
	= (1 & ((IData)(vlTOPp->v__DOT__r)[4] >> 6));
    vlTOPp->v__DOT__wave_vol = (3 & ((IData)(vlTOPp->v__DOT__r)
				     [0xc] >> 5));
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[7] 
	= (IData)(vlTOPp->v__DOT__r)[0x27];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[0xf] 
	= (IData)(vlTOPp->v__DOT__r)[0x2f];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[0xe] 
	= (IData)(vlTOPp->v__DOT__r)[0x2e];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[0xd] 
	= (IData)(vlTOPp->v__DOT__r)[0x2d];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[0xc] 
	= (IData)(vlTOPp->v__DOT__r)[0x2c];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[0xb] 
	= (IData)(vlTOPp->v__DOT__r)[0x2b];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[0xa] 
	= (IData)(vlTOPp->v__DOT__r)[0x2a];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[9] 
	= (IData)(vlTOPp->v__DOT__r)[0x29];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[8] 
	= (IData)(vlTOPp->v__DOT__r)[0x28];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[6] 
	= (IData)(vlTOPp->v__DOT__r)[0x26];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[5] 
	= (IData)(vlTOPp->v__DOT__r)[0x25];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[4] 
	= (IData)(vlTOPp->v__DOT__r)[0x24];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[3] 
	= (IData)(vlTOPp->v__DOT__r)[0x23];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[2] 
	= (IData)(vlTOPp->v__DOT__r)[0x22];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[1] 
	= (IData)(vlTOPp->v__DOT__r)[0x21];
    vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1[0] 
	= (IData)(vlTOPp->v__DOT__r)[0x20];
    vlTOPp->v__DOT__pulse0__DOT__reload_duty = ((IData)(vlTOPp->v__DOT__pulse0__DOT__old_duty) 
						!= (IData)(vlTOPp->v__DOT__pulse0_duty));
    vlTOPp->v__DOT__pulse1__DOT__reload_duty = ((IData)(vlTOPp->v__DOT__pulse1__DOT__old_duty) 
						!= (IData)(vlTOPp->v__DOT__pulse1_duty));
    vlTOPp->v__DOT__wave_out = (0xf & ((1 & (IData)(vlTOPp->v__DOT__wave__DOT__wave_addr))
				        ? ((IData)(vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1)
					   [(0xf & 
					     ((IData)(vlTOPp->v__DOT__wave__DOT__wave_addr) 
					      >> 1))] 
					   >> 4) : 
				       (IData)(vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1)
				       [(0xf & ((IData)(vlTOPp->v__DOT__wave__DOT__wave_addr) 
						>> 1))]));
}

void Vgbdmg::_sequent__TOP__9(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_sequent__TOP__9\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__pulse0__DOT__reload_duty = ((IData)(vlTOPp->v__DOT__pulse0__DOT__old_duty) 
						!= (IData)(vlTOPp->v__DOT__pulse0_duty));
    vlTOPp->v__DOT__pulse1__DOT__reload_duty = ((IData)(vlTOPp->v__DOT__pulse1__DOT__old_duty) 
						!= (IData)(vlTOPp->v__DOT__pulse1_duty));
    vlTOPp->v__DOT__wave_out = (0xf & ((1 & (IData)(vlTOPp->v__DOT__wave__DOT__wave_addr))
				        ? ((IData)(vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1)
					   [(0xf & 
					     ((IData)(vlTOPp->v__DOT__wave__DOT__wave_addr) 
					      >> 1))] 
					   >> 4) : 
				       (IData)(vlTOPp->v__DOT____Vcellinp__wave_mem____pinNumber1)
				       [(0xf & ((IData)(vlTOPp->v__DOT__wave__DOT__wave_addr) 
						>> 1))]));
}

void Vgbdmg::_multiclk__TOP__10(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_multiclk__TOP__10\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out_lr = (0xffff & (((((1 & ((0 != (IData)(vlTOPp->v__DOT__len0__DOT__counter)) 
					 | (~ (IData)(vlTOPp->v__DOT____Vcellinp__len0____pinNumber6))))
				    ? (IData)(vlTOPp->v__DOT__pulse0_mix)
				    : 0) + ((1 & ((0 
						   != (IData)(vlTOPp->v__DOT__len1__DOT__counter)) 
						  | (~ (IData)(vlTOPp->v__DOT____Vcellinp__len1____pinNumber6))))
					     ? (IData)(vlTOPp->v__DOT__pulse1_mix)
					     : 0)) 
				 + ((0 == (IData)(vlTOPp->v__DOT__wave_vol))
				     ? 0 : ((1 == (IData)(vlTOPp->v__DOT__wave_vol))
					     ? (((IData)(vlTOPp->v__DOT__wave_out) 
						 << 9) 
						- (IData)(0x2000))
					     : ((2 
						 == (IData)(vlTOPp->v__DOT__wave_vol))
						 ? 
						((0x8000 
						  & (((IData)(vlTOPp->v__DOT__wave_out) 
						      << 9) 
						     - (IData)(0x2000))) 
						 | (0x7fff 
						    & ((((IData)(vlTOPp->v__DOT__wave_out) 
							 << 9) 
							- (IData)(0x2000)) 
						       >> 1)))
						 : 
						((0x8000 
						  & (((IData)(vlTOPp->v__DOT__wave_out) 
						      << 9) 
						     - (IData)(0x2000))) 
						 | ((0x4000 
						     & ((((IData)(vlTOPp->v__DOT__wave_out) 
							  << 9) 
							 - (IData)(0x2000)) 
							>> 1)) 
						    | (0x3fff 
						       & ((((IData)(vlTOPp->v__DOT__wave_out) 
							    << 9) 
							   - (IData)(0x2000)) 
							  >> 2)))))))) 
				+ (IData)(vlTOPp->v__DOT__noise_mix)));
}

void Vgbdmg::_eval(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_eval\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if ((((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__trigger_env0) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env0))))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__trigger_env2) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env2))))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if ((((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__trigger_env1) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env1))))) {
	vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk)))) {
	vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    if (((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk)))) {
	vlTOPp->_sequent__TOP__9(vlSymsp);
    }
    if ((((((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk))) 
	   | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__trigger_env0) 
	      & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env0)))) 
	  | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__trigger_env1) 
	     & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env1)))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__trigger_env2) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env2))))) {
	vlTOPp->_multiclk__TOP__10(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__in_clk = vlTOPp->in_clk;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env0 
	= vlTOPp->__VinpClk__TOP__v__DOT__trigger_env0;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env2 
	= vlTOPp->__VinpClk__TOP__v__DOT__trigger_env2;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env1 
	= vlTOPp->__VinpClk__TOP__v__DOT__trigger_env1;
    vlTOPp->__VinpClk__TOP__v__DOT__trigger_env0 = vlTOPp->v__DOT__trigger_env0;
    vlTOPp->__VinpClk__TOP__v__DOT__trigger_env2 = vlTOPp->v__DOT__trigger_env2;
    vlTOPp->__VinpClk__TOP__v__DOT__trigger_env1 = vlTOPp->v__DOT__trigger_env1;
}

void Vgbdmg::_eval_initial(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_eval_initial\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP(vlSymsp);
}

void Vgbdmg::final() {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::final\n"); );
    // Variables
    Vgbdmg__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vgbdmg::_eval_settle(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_eval_settle\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__5(vlSymsp);
    vlTOPp->_settle__TOP__8(vlSymsp);
    vlTOPp->_multiclk__TOP__10(vlSymsp);
}

IData Vgbdmg::_change_request(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_change_request\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    __req |= ((vlTOPp->v__DOT__trigger_env0 ^ vlTOPp->__Vchglast__TOP__v__DOT__trigger_env0)
	 | (vlTOPp->v__DOT__trigger_env1 ^ vlTOPp->__Vchglast__TOP__v__DOT__trigger_env1)
	 | (vlTOPp->v__DOT__trigger_env2 ^ vlTOPp->__Vchglast__TOP__v__DOT__trigger_env2));
    VL_DEBUG_IF( if(__req && ((vlTOPp->v__DOT__trigger_env0 ^ vlTOPp->__Vchglast__TOP__v__DOT__trigger_env0))) VL_PRINTF("	CHANGE: source/gbdmg.v:306: v.trigger_env0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->v__DOT__trigger_env1 ^ vlTOPp->__Vchglast__TOP__v__DOT__trigger_env1))) VL_PRINTF("	CHANGE: source/gbdmg.v:306: v.trigger_env1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->v__DOT__trigger_env2 ^ vlTOPp->__Vchglast__TOP__v__DOT__trigger_env2))) VL_PRINTF("	CHANGE: source/gbdmg.v:306: v.trigger_env2\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__v__DOT__trigger_env0 = vlTOPp->v__DOT__trigger_env0;
    vlTOPp->__Vchglast__TOP__v__DOT__trigger_env1 = vlTOPp->v__DOT__trigger_env1;
    vlTOPp->__Vchglast__TOP__v__DOT__trigger_env2 = vlTOPp->v__DOT__trigger_env2;
    return __req;
}
