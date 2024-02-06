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

.PHONY := all debug clean tests clangd

all: libowomath.a

debug: OPTFLAGS := -g
debug: all

tests: OPTFLAGS := -g
tests: all $(TESTEXES)

libowomath.a: $(OBJS)
	@printf " \033[1;34mAR\033[0m libowomath.a\n"
	$(V)$(AR) rcs libowomath.a $(OBJS)

%.o: %.c
	@src=$<; src=$${src##*/}; printf " \033[1;32mCC\033[0m %s\n" "$$src"
	$(V)$(CC) $(_REQFLAGS) $(CFLAGS) $(OPTFLAGS) -c $< -o $@

tests/bin/%: tests/%.c libowomath.a
	@src=$<; src=$${src##*/}; printf " \033[1;32mCC\033[0m %s\n" "$$src"
	$(V)$(CC) $(_REQFLAGS) $(CFLAGS) $(OPTFLAGS) -c $< -o tests/$*.o
	$(V)$(CC) $(_REQFLAGS) $(LDFLAGS) $(OPTFLAGS) libowomath.a tests/$*.o -o $@

clean:
	@printf "Cleaning up...\n"
	$(V)rm -rf libowomath.a src/*.o tests/*.o tests/bin/*

clangd:
	@printf "Generating clangd config...\n"
	$(V)printf 'CompileFlags:\n  Add: [-I$(PWD)/include]\n' > .clangd
