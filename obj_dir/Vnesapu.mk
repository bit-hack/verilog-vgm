# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f Vnesapu.mk

default: Vnesapu__ALL.a

### Constants...
# Perl executable (from $PERL)
PERL = perl
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = C:/MinGW20120426/msys/1.0/local/share/verilator
# Path to SystemPerl kit top (from $SYSTEMPERL)
SYSTEMPERL = 
# Path to SystemPerl kit includes (from $SYSTEMPERL_INCLUDE)
SYSTEMPERL_INCLUDE = 
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?= 
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?= 

### Switches...
# SystemPerl output mode?  0/1 (from --sp)
VM_SP = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# SystemPerl or SystemC output mode?  0/1 (from --sp/--sc)
VM_SP_OR_SC = 0
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = mingw32

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = Vnesapu
# Module prefix (from --prefix)
VM_MODPREFIX = Vnesapu
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \


### Default rules...
# Include list of all generated classes
include Vnesapu_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

# Verilated -*- Makefile -*-
