# Makefile - build script

# build environment
CC=gcc

# source files
SOURCES := $(wildcard src/*.c)

# object files
OBJS := $(patsubst %.c,%.o,$(SOURCES))

# Build flags
INCLUDES    := -I include
# TODO : Compiling with optimizations is causing the compiler to do something
# which causes a segfault in showTable() during the strcat()'s...
#BASEFLAGS   := -O2
WARNFLAGS   := -Wall -Wextra -Wshadow -Wcast-align -Wwrite-strings -Winline
WARNFLAGS   += -Wno-attributes -Wno-deprecated-declarations
WARNFLAGS   += -Wno-div-by-zero -Wno-endif-labels -Wfloat-equal
WARNFLAGS   += -Wformat=2 -Wno-format-extra-args -Winit-self
WARNFLAGS   += -Winvalid-pch -Wmissing-format-attribute
WARNFLAGS   += -Wmissing-include-dirs -Wno-multichar -Wshadow
WARNFLAGS   += -Wno-sign-compare -Wswitch -Wsystem-headers
WARNFLAGS   += -Wno-pragmas -Wno-unused-but-set-parameter
WARNFLAGS   += -Wno-unused-but-set-variable -Wno-unused-result
WARNFLAGS   += -Wwrite-strings -Wdisabled-optimization -Wpointer-arith
#WARNFLAGS   += -Werror
CFLAGS      := $(INCLUDES) $(BASEFLAGS) $(WARNFLAGS)
CFLAGS      += -std=gnu99

# build rules
all: protolang

protolang: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o protolang

debug: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -g -o protolang

clean:
	$(RM) -f $(OBJS) protolang

