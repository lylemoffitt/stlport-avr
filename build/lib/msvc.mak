!if !EXIST(..\Makefiles\config.mak)
!error No config file found, please run 'configure --help' first.
!endif

!include ..\Makefiles\config.mak

!ifndef COMPILER_NAME
!error No compiler set, please run 'configure --help' first and chose a compiler.
!endif

!if (("$(COMPILER_NAME)" != "vc6") && \
     ("$(COMPILER_NAME)" != "vc70") && \
     ("$(COMPILER_NAME)" != "vc71") && \
     ("$(COMPILER_NAME)" != "vc8"))
!error '$(COMPILER_NAME)' not supported by this make file, please rerun 'configure' script and follow instructions.
!endif

SRCROOT=..

STLPORT_INCLUDE_DIR = ../../stlport
!include Makefile.inc

INCLUDES=$(INCLUDES) /I$(STLPORT_INCLUDE_DIR)

!if "$(COMPILER)" != "dmc"
INCLUDES=$(INCLUDES) /FI vc_warning_disable.h
!else
INCLUDES=$(INCLUDES) /D__BUILDING_STLPORT
!endif
# 

!ifdef STLP_BUILD_BOOST_PATH
INCLUDES=$(INCLUDES) /I "$(STLP_BUILD_BOOST_PATH)"
!endif

RC_FLAGS_REL = /I$(STLPORT_INCLUDE_DIR) /D "COMP=$(COMPILER_NAME)"
RC_FLAGS_DBG = /I$(STLPORT_INCLUDE_DIR) /D "COMP=$(COMPILER_NAME)"
RC_FLAGS_STLDBG = /I$(STLPORT_INCLUDE_DIR) /D "COMP=$(COMPILER_NAME)"

#Even if pure release and dbg targets do not need additionnal memory
#to be built they might if user wants to build a STL safe release build
#for instance.
OPT = /Zm800

!include $(SRCROOT)/Makefiles/nmake/top.mak