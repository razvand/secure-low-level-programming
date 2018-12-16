CPPFLAGS = -D_FORTIFY_SOURCE=2
CFLAGS = -Wall -g -fno-stack-protector -O1

.PHONY: all clean

all: prog

prog: prog.o

prog.o: prog.c

clean:
	-rm -f prog prog.o
	-rm -f *~
