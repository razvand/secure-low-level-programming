CC=gcc
CFLAGS=-lm -I.
DEPS = imglib.h
OBJ = imglib.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o
