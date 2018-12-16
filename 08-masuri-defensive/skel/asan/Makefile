CFLAGS = -Wall -g -fsanitize=address
LDLIBS = -lasan

.PHONY: all clean

all: prog

prog: prog.o

prog.o: prog.c

clean:
	-rm -f prog prog.o
	-rm -f *~
