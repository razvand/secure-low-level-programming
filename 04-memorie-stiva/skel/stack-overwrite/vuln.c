#include <stdio.h>
#include <stdlib.h>

static void idle(void)
{
}

void g(void)
{
	puts("You've got it. Congrats!");
}

static void f(void)
{
	void (*fn)(void) = idle;
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

	printf("Provide index and value to overwrite (end with 789)\n");
	while (1) {
		int n;
		unsigned long v;
		printf("(index) > ");
		scanf("%d", &n);
		if (n == 789)
			break;
		printf("(value) > ");
		scanf("%lu", &v);
		printf("writing 0x%016lx to buf[%d]\n", v, n);
		buffer[n] = v;
	}

	fn();
}

int main(void)
{
	f();
	return 0;
}
