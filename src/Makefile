#
# OMNeT++/OMNEST Makefile for grapevine_interest
#
# This file was generated with the command:
#  opp_makemake -f --deep -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/networklayer/arp -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/transport/sctp -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/world -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/transport/contract -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/linklayer/mfcore -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/applications/udpapp -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/linklayer/ethernet -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/util -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/networklayer/ted -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/linklayer/ieee80211/mac -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/networklayer/queue -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/networklayer/ipv6 -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/networklayer/common -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/applications/pingapp -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/networklayer/ldp -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/linklayer/radio/errormodel -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/transport/tcp -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/util/headerserializers -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/networklayer/rsvp_te -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/transport/udp -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/networklayer/ipv4 -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/networklayer/icmpv6 -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/base -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/networklayer/contract -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/linklayer/ieee80211/mgmt -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/networklayer/manetrouting/base -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/networklayer/mpls -I/Users/egrim/Projects/omnet_workspace/inetmanet/src/linklayer/contract -L/Users/egrim/Projects/omnet_workspace/inetmanet/out/$(CONFIGNAME)/src -linet -KINETMANET_PROJ=/Users/egrim/Projects/omnet_workspace/inetmanet
#

# Name of target to be created (-o option)
TARGET = grapevine_interest$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I$(INETMANET_PROJ)/src/networklayer/arp \
    -I$(INETMANET_PROJ)/src/transport/sctp \
    -I$(INETMANET_PROJ)/src/world \
    -I$(INETMANET_PROJ)/src/transport/contract \
    -I$(INETMANET_PROJ)/src/linklayer/mfcore \
    -I$(INETMANET_PROJ)/src/applications/udpapp \
    -I$(INETMANET_PROJ)/src/linklayer/ethernet \
    -I$(INETMANET_PROJ)/src/util \
    -I$(INETMANET_PROJ)/src/networklayer/ted \
    -I$(INETMANET_PROJ)/src/linklayer/ieee80211/mac \
    -I$(INETMANET_PROJ)/src/networklayer/queue \
    -I$(INETMANET_PROJ)/src/networklayer/ipv6 \
    -I$(INETMANET_PROJ)/src/networklayer/common \
    -I$(INETMANET_PROJ)/src/applications/pingapp \
    -I$(INETMANET_PROJ)/src/networklayer/ldp \
    -I$(INETMANET_PROJ)/src/linklayer/radio/errormodel \
    -I$(INETMANET_PROJ)/src/transport/tcp \
    -I$(INETMANET_PROJ)/src/util/headerserializers \
    -I$(INETMANET_PROJ)/src/networklayer/rsvp_te \
    -I$(INETMANET_PROJ)/src/transport/udp \
    -I$(INETMANET_PROJ)/src/networklayer/ipv4 \
    -I$(INETMANET_PROJ)/src/networklayer/icmpv6 \
    -I$(INETMANET_PROJ)/src/base \
    -I$(INETMANET_PROJ)/src/networklayer/contract \
    -I$(INETMANET_PROJ)/src/linklayer/ieee80211/mgmt \
    -I$(INETMANET_PROJ)/src/networklayer/manetrouting/base \
    -I$(INETMANET_PROJ)/src/networklayer/mpls \
    -I$(INETMANET_PROJ)/src/linklayer/contract \
    -I.

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L$(INETMANET_PROJ)/out/$(CONFIGNAME)/src  -linet
LIBS += -Wl,-rpath,`abspath $(INETMANET_PROJ)/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc and .msg files
OBJS = $O/ContextSummary.o $O/Grapevine.o $O/GrapevinePacket.o $O/GrapevinePacket_m.o

# Message files
MSGFILES = \
    GrapevinePacket.msg

# Other makefile variables (-K)
INETMANET_PROJ=/Users/egrim/Projects/omnet_workspace/inetmanet

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(CXX) -c $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(MSGC) -s _m.cc $(MSGCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

clean:
	-rm -rf $O
	-rm -f grapevine_interest grapevine_interest.exe libgrapevine_interest.so libgrapevine_interest.a libgrapevine_interest.dll libgrapevine_interest.dylib
	-rm -f ./*_m.cc ./*_m.h

cleanall: clean
	-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES)  ./*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/ContextSummary.o: ContextSummary.cc \
	ContextSummary.h
$O/Grapevine.o: Grapevine.cc \
	ContextSummary.h \
	Grapevine.h \
	GrapevinePacket.h \
	GrapevinePacket_m.h \
	$(INETMANET_PROJ)/src/applications/udpapp/UDPAppBase.h \
	$(INETMANET_PROJ)/src/base/INETDefs.h \
	$(INETMANET_PROJ)/src/networklayer/contract/IPAddress.h \
	$(INETMANET_PROJ)/src/networklayer/contract/IPAddressResolver.h \
	$(INETMANET_PROJ)/src/networklayer/contract/IPv6Address.h \
	$(INETMANET_PROJ)/src/networklayer/contract/IPvXAddress.h \
	$(INETMANET_PROJ)/src/transport/contract/UDPControlInfo_m.h \
	$(INETMANET_PROJ)/src/transport/contract/UDPSocket.h
$O/GrapevinePacket.o: GrapevinePacket.cc \
	ContextSummary.h \
	GrapevinePacket.h \
	GrapevinePacket_m.h
$O/GrapevinePacket_m.o: GrapevinePacket_m.cc \
	ContextSummary.h \
	GrapevinePacket_m.h

