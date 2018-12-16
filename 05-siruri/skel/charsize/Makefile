CFLAGS = -Wall -g
CFLAGS32 = -m32 -Wall -g
LDFLAGS32 = -m32

.PHONY: all clean

all: prog prog32

prog: prog.o

prog.o: prog.c

prog32: prog32.o
	$(CC) $(LDFLAGS32) -o $@ $^

prog32.o: prog.c
	$(CC) $(CFLAGS32) -c -o $@ $<

clean:
	-rm -f prog prog.o
	-rm -f prog32 prog32.o
	-rm -f *~
