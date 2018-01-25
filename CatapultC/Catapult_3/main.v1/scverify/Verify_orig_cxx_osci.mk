# ----------------------------------------------------------------------------
# Original Design + Testbench
#
#    HLS version: 10.0a/269363 Production Release
#       HLS date: Wed Nov  9 17:38:00 PST 2016
#  Flow Packages: HDL_Tcl 8.0a, SCVerify 8.0a
#
#   Generated by: xph3sle509@ocaepc57
# Generated date: Tue Jan 16 13:49:42 CET 2018
#
# ----------------------------------------------------------------------------
# ===================================================
# DEFAULT GOAL is the help target
.PHONY: all
all: help

# ===================================================
# Directories (at the time this makefile was created)
#   MGC_HOME      /softl3/catapultc10_0a/64bit/Mgc_home
#   PROJECT_HOME  /tp-fmr/sle3_509
#   SOLUTION_DIR  /tp-fmr/sle3_509/Catapult_3/main.v1
#   WORKING_DIR   /tp-fmr/sle3_509/Catapult_3/main.v1/.

# ===================================================
# VARIABLES
# 
MGC_HOME          = /softl3/catapultc10_0a/64bit/Mgc_home
export MGC_HOME

WORK_DIR  = $(CURDIR)
WORK2PROJ = ../..
WORK2SOLN = .
PROJ2WORK = ./Catapult_3/main.v1
PROJ2SOLN = ./Catapult_3/main.v1
export WORK_DIR
export WORK2PROJ
export WORK2SOLN
export PROJ2WORK
export PROJ2SOLN

# Variables that can be overridden from the make command line
ifeq "$(INCL_DIRS)" ""
INCL_DIRS                   =  .
endif
export INCL_DIRS
ifeq "$(STAGE)" ""
STAGE                       = orig
endif
export STAGE
ifeq "$(NETLIST_LEAF)" ""
NETLIST_LEAF                = orig
endif
export NETLIST_LEAF
ifeq "$(SIMTOOL)" ""
SIMTOOL                     = osci
endif
export SIMTOOL
ifeq "$(NETLIST)" ""
NETLIST                     = cxx
endif
export NETLIST
ifeq "$(RTL_NETLIST_FNAME)" ""
RTL_NETLIST_FNAME           = /tp-fmr/sle3_509/Catapult_3/main.v1/orig
endif
export RTL_NETLIST_FNAME
ifeq "$(TARGET)" ""
TARGET                      = scverify/$(NETLIST_LEAF)_$(NETLIST)_$(SIMTOOL)
endif
export TARGET
ifeq "$(INVOKE_ARGS)" ""
INVOKE_ARGS                 = 
endif
export INVOKE_ARGS
export SCVLIBS
LINK_SYSTEMC             := true
TOP_HDL_ENTITY           := main
TOP_DU                   := scverify_top
LINK_SYSTEMC             := true
export TOP_HDL_ENTITY

ifeq ($(RECUR),)
ifeq ($(STAGE),mapped)
ifeq ($(RTLTOOL),)
   $(error This makefile requires specifying the RTLTOOL variable on the make command line)
endif
endif
endif
# ===================================================
# Include environment variables set by flow options
include ./ccs_env.mk

# ===================================================
# Include makefile for default commands and variables
include $(MGC_HOME)/shared/include/mkfiles/ccs_default_cmds.mk

# ===================================================
# SOURCES
# 
# Specify list of Modelsim libraries to create
HDL_LIB_NAMES = work
# Specify list of source files - MUST be ordered properly
ifeq ($(STAGE),gate)
ifeq ($(RTLTOOL),)
ifeq ($(GATE_VHDL_DEP),)
GATE_VHDL_DEP = 
endif
ifeq ($(GATE_VLOG_DEP),)
GATE_VLOG_DEP = 
endif
endif
VHDL_SRC +=  $(GATE_VHDL_DEP)
VLOG_SRC +=  $(GATE_VLOG_DEP)
else
VHDL_SRC += 
VLOG_SRC += 
endif
CXX_SRC  = ../../3D_mono_camera/mask.cpp/mask.cpp.cxxts ../../3D_mono_camera/depth.cpp/depth.cpp.cxxts ../../3D_mono_camera/main.cpp/main.cpp.cxxts
# Specify RTL synthesis scripts (if any)
RTL_SCRIPT = 

# Specify hold time file name (for verifying synthesized netlists)
HLD_CONSTRAINT_FNAME = top_gate_constraints.cpp

# ===================================================
# GLOBAL OPTIONS
# 
# CXXFLAGS - global C++ options (apply to all C++ compilations) except for include file search paths
CXXFLAGS += -DSC_INCLUDE_DYNAMIC_PROCESSES -DSC_USE_STD_STRING -DCCS_MISMATCHED_OUTPUTS_ONLY
# 
# If the make command line includes a definition of the special variable MC_DEFAULT_TRANSACTOR_LOG
# then define that value for all compilations as well
ifneq "$(MC_DEFAULT_TRANSACTOR_LOG)" ""
CXXFLAGS += -DMC_DEFAULT_TRANSACTOR_LOG=$(MC_DEFAULT_TRANSACTOR_LOG)
endif
# 
# CXX_INCLUDES - include file search paths
CXX_INCLUDES = . ../..
# 
# TCL shell
TCLSH_CMD = /softl3/catapultc10_0a/64bit/Mgc_home/bin/tclsh8.5

# Pass along SCVerify_DEADLOCK_DETECTION option
ifneq "$(SCVerify_DEADLOCK_DETECTION)" "false"
CXXFLAGS += -DDEADLOCK_DETECTION
endif
# ===================================================
# PER SOURCE FILE SPECIALIZATIONS
# 
# Specify source file paths
ifeq ($(STAGE),gate)
ifneq ($(GATE_VHDL_DEP),)
$(TARGET)/$(notdir $(GATE_VHDL_DEP)): $(dir $(GATE_VHDL_DEP))
endif
ifneq ($(GATE_VLOG_DEP),)
$(TARGET)/$(notdir $(GATE_VLOG_DEP)): $(dir $(GATE_VLOG_DEP))
endif
endif
$(TARGET)/mask.cpp.cxxts: ../../3D_mono_camera/mask.cpp
$(TARGET)/depth.cpp.cxxts: ../../3D_mono_camera/depth.cpp
$(TARGET)/main.cpp.cxxts: ../../3D_mono_camera/main.cpp
# 
# Specify additional C++ options per C++ source by setting CXX_OPTS
$(TARGET)/mask.cpp.cxxts: CXX_OPTS=
$(TARGET)/main.cpp.cxxts: CXX_OPTS=
$(TARGET)/depth.cpp.cxxts: CXX_OPTS=
# 
# Specify dependencies
$(TARGET)/mask.cpp.cxxts: .ccs_env_opts/SCVerify_USE_CCS_BLOCK.ts
$(TARGET)/depth.cpp.cxxts: .ccs_env_opts/SCVerify_USE_CCS_BLOCK.ts
$(TARGET)/main.cpp.cxxts: .ccs_env_opts/SCVerify_USE_CCS_BLOCK.ts
# 
# Specify compilation library for HDL source
ifeq ($(STAGE),gate)
ifneq ($(GATE_VHDL_DEP),)
$(TARGET)/$(notdir $(GATE_VHDL_DEP)): HDL_LIB=work
endif
ifneq ($(GATE_VLOG_DEP),)
$(TARGET)/$(notdir $(GATE_VLOG_DEP)): HDL_LIB=work
endif
endif
# 
# Specify additional HDL source compilation options if any
# 
# Specify top design unit for HDL source

# Specify top design unit

ifneq "$(RTLTOOL)" ""
# ===================================================
# Include makefile for RTL synthesis
include $(MGC_HOME)/shared/include/mkfiles/ccs_$(RTLTOOL).mk
else
# ===================================================
# Include makefile for simulator
include $(MGC_HOME)/shared/include/mkfiles/ccs_$(SIMTOOL).mk
endif
