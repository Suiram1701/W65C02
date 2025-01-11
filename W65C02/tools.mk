CL65_BINARY := /sdk/cc65/bin/cl65
LD65_BINARY := /sdk/cc65/bin/ld65

CL65_FLAGS := -v -c -t none --cpu 65C02 -O
LD65_FLAGS := -v -vm


MKDIR_BINARY := mkdir
RM_BINARY    := rm
MV_BINARY    := mv

MKDIR_FLAGS := -p
RM_FLAGS    := -rf
MV_FLAGS    :=