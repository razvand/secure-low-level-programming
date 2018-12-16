LINK.o = $(LINK.cc) # Link using g++
CXXFLAGS = -Wall -g

.PHONY: all clean

all: vuln

vuln: vuln.o

vuln.o: vuln.cpp

clean:
	-rm -f vuln vuln.o
	-rm -f *~
