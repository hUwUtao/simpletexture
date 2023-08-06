SRCS = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRCS))

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -ansi -O3 -std=c99

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<
	chmod +x $@

clean:
	rm -f $(PROGS)
