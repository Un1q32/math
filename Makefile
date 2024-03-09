CFLAGS := -Wall -Wextra -Werror
OPTFLAGS := -O3
_REQFLAGS := -std=c89 -Iinclude

SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)
TESTSRCS := $(wildcard tests/*.c)
TESTEXES := $(TESTSRCS:tests/%.c=tests/bin/%)

ifndef VERBOSE
V := @
endif

.PHONY := all debug clean tests debugtests clangd

all: libuniqmath.a

debug: OPTFLAGS := -g
debug: all

tests: all $(TESTEXES)

debugtests: OPTFLAGS := -g
debugtests: all $(TESTEXES)

libuniqmath.a: $(OBJS)
	@printf " \033[1;34mAR\033[0m libuniqmath.a\n"
	$(V)$(AR) rcs libuniqmath.a $(OBJS)

%.o: %.c
	@src=$@; src=$${src##*/}; printf " \033[1;32mCC\033[0m %s\n" "$$src"
	$(V)$(CC) $(_REQFLAGS) $(CFLAGS) $(OPTFLAGS) -c $< -o $@

tests/bin/%: tests/%.c libuniqmath.a
	@printf " \033[1;32mCC\033[0m $@\n"
	$(V)$(CC) $(_REQFLAGS) $(CFLAGS) $(OPTFLAGS) -c $< -o tests/$*.o
	$(V)$(CC) $(_REQFLAGS) $(LDFLAGS) $(OPTFLAGS) libuniqmath.a tests/$*.o -o $@

clean:
	@printf "Cleaning up...\n"
	$(V)rm -rf libuniqmath.a src/*.o tests/*.o tests/bin/*

clangd:
	@printf "Generating clangd config...\n"
	$(V)printf 'CompileFlags:\n  Add: [-I$(PWD)/include]\n' > .clangd
