CFLAGS = -Wall -g -fno-PIC -fno-stack-protector -mpreferred-stack-boundary=4
LDFLAGS = -fno-pie -zexecstack

all: vuln

vuln: vuln.o

clean:
	-rm -f vuln vuln.o
	-rm -f *~
