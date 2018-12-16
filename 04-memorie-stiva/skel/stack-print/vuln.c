#include <stdio.h>
#include <stdlib.h>

static unsigned long *start;
static unsigned long *stop;

static void print_stack(void)
{
	unsigned long *p;

	for (p = start; p <= stop; p++)
		printf("%p: 0x%016lx\n", p, *p);
}

static void g(void)
{
	unsigned int a = 0x11223344;
	unsigned int b = 0x55667788;
	unsigned int sum;
	unsigned long placeholder = 0x4444444444444444;

	sum = a+b;

	start = &placeholder;
	print_stack();
}

static void f(void)
{
	char buffer[128];
	size_t i;

	for (i = 0; i < 128; i++)
		buffer[i] = i;

	g();
}

int main(void)
{
	unsigned long placeholder = 0x3333333333333333;
	stop = &placeholder;

	f();

	return 0;
}
