CFLAGS_NO = -Wall -g -fno-stack-protector
CFLAGS_SSP_PIC = -Wall -g -fstack-protector -fPIC
LDFLAGS_NO = -zexecstack -no-pie
LDFLAGS_DEP_PIE_FULL_RELRO = -pie -z relro -z now

.PHONY: all clean

all: prog_no prog_all

prog_no: prog_no.o
	$(CC) $(LDFLAGS_NO) -o $@ $^

prog_no.o: prog.c
	$(CC) $(CFLAGS_NO) -c -o $@ $^

prog_all: prog_all.o
	$(CC) $(LDFLAGS_DEP_PIE_FULL_RELRO) -o $@ $^

prog_all.o: prog.c
	$(CC) $(CFLAGS_SSP_PIC) -c -o $@ $^

clean:
	-rm -f prog_no prog_no.o
	-rm -f prog_all prog_all.o
	-rm -f *~
