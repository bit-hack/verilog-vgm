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
    v__DOT__wr_old = VL_RAND_RESET_I(1);
    v__DOT__wr_posedge = VL_RAND_RESET_I(1);
    v__DOT__frame_clk_div = VL_RAND_RESET_I(10);
    v__DOT__frame_seq = VL_RAND_RESET_I(3);
    v__DOT__tick_env = VL_RAND_RESET_I(1);
    v__DOT__trigger_env0 = VL_RAND_RESET_I(1);
    v__DOT__trigger_env1 = VL_RAND_RESET_I(1);
    v__DOT__trigger_env2 = VL_RAND_RESET_I(1);
    v__DOT____Vcellinp__env0____pinNumber5 = 0;
    v__DOT____Vcellinp__env0____pinNumber4 = VL_RAND_RESET_I(3);
    v__DOT____Vcellinp__env0____pinNumber3 = VL_RAND_RESET_I(4);
    v__DOT__pulse0__DOT__counter = VL_RAND_RESET_I(11);
    v__DOT__pulse0__DOT__clk_div = VL_RAND_RESET_I(2);
    v__DOT__pulse0__DOT__duty = VL_RAND_RESET_I(8);
    v__DOT__pulse0__DOT__old_duty = VL_RAND_RESET_I(2);
    v__DOT__pulse0__DOT__reload_duty = VL_RAND_RESET_I(1);
    v__DOT__env0__DOT__value = VL_RAND_RESET_I(4);
    v__DOT__env0__DOT__clk_div = VL_RAND_RESET_I(3);
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
    // INITIAL at source/gbdmg.v:198
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
    //char	__VpadToAlign47[1];
    VL_SIG16(__Vdly__v__DOT__frame_clk_div,9,0);
    VL_SIG16(__Vdly__v__DOT__pulse0__DOT__counter,10,0);
    // Body
    __Vdly__v__DOT__frame_seq = vlTOPp->v__DOT__frame_seq;
    __Vdly__v__DOT__frame_clk_div = vlTOPp->v__DOT__frame_clk_div;
    __Vdly__v__DOT__pulse0__DOT__counter = vlTOPp->v__DOT__pulse0__DOT__counter;
    __Vdly__v__DOT__pulse0__DOT__clk_div = vlTOPp->v__DOT__pulse0__DOT__clk_div;
    __Vdly__v__DOT__pulse0__DOT__duty = vlTOPp->v__DOT__pulse0__DOT__duty;
    vlTOPp->__Vdlyvset__v__DOT__r__v0 = 0;
    // ALWAYS at source/gbdmg.v:293
    if ((0 == (IData)(vlTOPp->v__DOT__frame_clk_div))) {
	__Vdly__v__DOT__frame_seq = (7 & ((IData)(1) 
					  + (IData)(vlTOPp->v__DOT__frame_seq)));
	__Vdly__v__DOT__frame_clk_div = 0x30d;
    } else {
	__Vdly__v__DOT__frame_clk_div = (0x3ff & ((IData)(vlTOPp->v__DOT__frame_clk_div) 
						  - (IData)(1)));
    }
    // ALWAYS at source/gbdmg.v:20
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
    vlTOPp->v__DOT__frame_clk_div = __Vdly__v__DOT__frame_clk_div;
    vlTOPp->v__DOT__frame_seq = __Vdly__v__DOT__frame_seq;
    vlTOPp->v__DOT__pulse0__DOT__clk_div = __Vdly__v__DOT__pulse0__DOT__clk_div;
    vlTOPp->v__DOT__pulse0__DOT__counter = __Vdly__v__DOT__pulse0__DOT__counter;
    vlTOPp->v__DOT__pulse0__DOT__duty = __Vdly__v__DOT__pulse0__DOT__duty;
}

void Vgbdmg::_sequent__TOP__2(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_sequent__TOP__2\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__env0__DOT__value,3,0);
    VL_SIG8(__Vdly__v__DOT__env0__DOT__clk_div,2,0);
    //char	__VpadToAlign74[2];
    // Body
    __Vdly__v__DOT__env0__DOT__clk_div = vlTOPp->v__DOT__env0__DOT__clk_div;
    __Vdly__v__DOT__env0__DOT__value = vlTOPp->v__DOT__env0__DOT__value;
    // ALWAYS at source/gbdmg.v:111
    if (vlTOPp->in_rst) {
	__Vdly__v__DOT__env0__DOT__value = 0;
	__Vdly__v__DOT__env0__DOT__clk_div = 0;
    } else {
	if (vlTOPp->v__DOT__trigger_env0) {
	    __Vdly__v__DOT__env0__DOT__value = vlTOPp->v__DOT____Vcellinp__env0____pinNumber3;
	    __Vdly__v__DOT__env0__DOT__clk_div = vlTOPp->v__DOT____Vcellinp__env0____pinNumber4;
	} else {
	    if (vlTOPp->v__DOT__tick_env) {
		if ((0 == (IData)(vlTOPp->v__DOT__env0__DOT__clk_div))) {
		    __Vdly__v__DOT__env0__DOT__value 
			= (0xf & ((IData)(vlTOPp->v__DOT____Vcellinp__env0____pinNumber5)
				   ? ((0 == (IData)(vlTOPp->v__DOT__env0__DOT__value))
				       ? (IData)(vlTOPp->v__DOT__env0__DOT__value)
				       : ((IData)(1) 
					  + (IData)(vlTOPp->v__DOT__env0__DOT__value)))
				   : ((0xf == (IData)(vlTOPp->v__DOT__env0__DOT__value))
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
    VL_SIG8(__Vdlyvdim0__v__DOT__r__v0,5,0);
    VL_SIG8(__Vdlyvval__v__DOT__r__v0,7,0);
    //char	__VpadToAlign98[2];
    // Body
    vlTOPp->v__DOT__tick_env = ((0 == (IData)(vlTOPp->v__DOT__frame_clk_div)) 
				& (7 == (IData)(vlTOPp->v__DOT__frame_seq)));
    // ALWAYS at source/gbdmg.v:277
    if ((1 & (~ (IData)(vlTOPp->in_rst)))) {
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
    // ALWAYSPOST at source/gbdmg.v:287
    if (vlTOPp->__Vdlyvset__v__DOT__r__v0) {
	vlTOPp->v__DOT__r[(IData)(__Vdlyvdim0__v__DOT__r__v0)] 
	    = __Vdlyvval__v__DOT__r__v0;
    }
    vlTOPp->v__DOT__pulse0_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__r)
					     [4] << 8)) 
				   | (IData)(vlTOPp->v__DOT__r)
				   [3]);
    vlTOPp->v__DOT____Vcellinp__env0____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__r)[2] >> 3));
    vlTOPp->v__DOT____Vcellinp__env0____pinNumber4 
	= (7 & (IData)(vlTOPp->v__DOT__r)[2]);
    vlTOPp->v__DOT____Vcellinp__env0____pinNumber3 
	= (0xf & ((IData)(vlTOPp->v__DOT__r)[2] >> 4));
    vlTOPp->v__DOT__pulse0_duty = (3 & ((IData)(vlTOPp->v__DOT__r)
					[1] >> 6));
}

void Vgbdmg::_settle__TOP__4(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_settle__TOP__4\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__tick_env = ((0 == (IData)(vlTOPp->v__DOT__frame_clk_div)) 
				& (7 == (IData)(vlTOPp->v__DOT__frame_seq)));
    vlTOPp->v__DOT__pulse0_mix = (IData)(vlTOPp->v__DOT__AMP_TABLE)
	[((0x10 & ((IData)(vlTOPp->v__DOT__pulse0__DOT__duty) 
		   << 4)) | (IData)(vlTOPp->v__DOT__env0__DOT__value))];
    vlTOPp->v__DOT__wr_posedge = ((IData)(vlTOPp->in_wr) 
				  & (~ (IData)(vlTOPp->v__DOT__wr_old)));
    vlTOPp->v__DOT__pulse0_freq = ((0x700 & ((IData)(vlTOPp->v__DOT__r)
					     [4] << 8)) 
				   | (IData)(vlTOPp->v__DOT__r)
				   [3]);
    vlTOPp->v__DOT____Vcellinp__env0____pinNumber5 
	= (1 & ((IData)(vlTOPp->v__DOT__r)[2] >> 3));
    vlTOPp->v__DOT____Vcellinp__env0____pinNumber4 
	= (7 & (IData)(vlTOPp->v__DOT__r)[2]);
    vlTOPp->v__DOT____Vcellinp__env0____pinNumber3 
	= (0xf & ((IData)(vlTOPp->v__DOT__r)[2] >> 4));
    vlTOPp->v__DOT__pulse0_duty = (3 & ((IData)(vlTOPp->v__DOT__r)
					[1] >> 6));
    vlTOPp->out_lr = vlTOPp->v__DOT__pulse0_mix;
    vlTOPp->v__DOT__pulse0__DOT__reload_duty = ((IData)(vlTOPp->v__DOT__pulse0__DOT__old_duty) 
						!= (IData)(vlTOPp->v__DOT__pulse0_duty));
}

void Vgbdmg::_combo__TOP__7(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_combo__TOP__7\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__wr_posedge = ((IData)(vlTOPp->in_wr) 
				  & (~ (IData)(vlTOPp->v__DOT__wr_old)));
}

void Vgbdmg::_sequent__TOP__8(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_sequent__TOP__8\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->out_lr = vlTOPp->v__DOT__pulse0_mix;
}

void Vgbdmg::_sequent__TOP__9(Vgbdmg__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_PRINTF("    Vgbdmg::_sequent__TOP__9\n"); );
    Vgbdmg* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->v__DOT__pulse0__DOT__reload_duty = ((IData)(vlTOPp->v__DOT__pulse0__DOT__old_duty) 
						!= (IData)(vlTOPp->v__DOT__pulse0_duty));
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
    if (((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    if ((((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk))) 
	 | ((IData)(vlTOPp->__VinpClk__TOP__v__DOT__trigger_env0) 
	    & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__v__DOT__trigger_env0))))) {
	vlTOPp->_sequent__TOP__8(vlSymsp);
    }
    if (((IData)(vlTOPp->in_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__in_clk)))) {
	vlTOPp->_sequent__TOP__9(vlSymsp);
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
    vlTOPp->_settle__TOP__4(vlSymsp);
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
    VL_DEBUG_IF( if(__req && ((vlTOPp->v__DOT__trigger_env0 ^ vlTOPp->__Vchglast__TOP__v__DOT__trigger_env0))) VL_PRINTF("	CHANGE: source/gbdmg.v:268: v.trigger_env0\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->v__DOT__trigger_env1 ^ vlTOPp->__Vchglast__TOP__v__DOT__trigger_env1))) VL_PRINTF("	CHANGE: source/gbdmg.v:268: v.trigger_env1\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->v__DOT__trigger_env2 ^ vlTOPp->__Vchglast__TOP__v__DOT__trigger_env2))) VL_PRINTF("	CHANGE: source/gbdmg.v:268: v.trigger_env2\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__v__DOT__trigger_env0 = vlTOPp->v__DOT__trigger_env0;
    vlTOPp->__Vchglast__TOP__v__DOT__trigger_env1 = vlTOPp->v__DOT__trigger_env1;
    vlTOPp->__Vchglast__TOP__v__DOT__trigger_env2 = vlTOPp->v__DOT__trigger_env2;
    return __req;
}
