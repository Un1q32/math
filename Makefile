SRCS := $(wildcard src/*.c)
BINS := $(patsubst src/%.c,bin/%,$(SRCS))

.PHONY := all clean

all: $(BINS)

bin/%: src/%.c
	@mkdir -p bin
	$(CC) -g -o $@ $<

clean:
	rm -rf bin
