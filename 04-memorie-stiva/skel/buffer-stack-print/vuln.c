#include <stdio.h>
#include <stdlib.h>

static void f(void)
{
	size_t i;
	unsigned int a = 0x11223344;
	unsigned int b = 0x55667788;
	unsigned int sum;
	unsigned long buffer[16];

	for (i = 0; i < 16; i++)
		buffer[i] = i;
	for (i = 32; i > 0; i--)
		printf("buffer[-%3zu], %p: %016lx\n", i, buffer-i, *(buffer-i));
	for (i = 0; i < 32; i++)
		printf("buffer[%3zu], %p: %016lx\n", i, buffer+i, buffer[i]);
}

int main(void)
{
	f();
	return 0;
}
