CFLAGS = -m32 -Wall -fno-stack-protector -fno-PIC
LDFLAGS = -m32 -no-pie

.PHONY: all clean

all: vuln

vuln: vuln.o

vuln.o: vuln.c

clean:
	-rm -f vuln vuln.o
	-rm -f *~
