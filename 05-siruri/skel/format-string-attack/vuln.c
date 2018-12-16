#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static unsigned int v = 10;

static void do_nasty(void)
{
	char buffer[16];
	char fmt_buffer[32];

	fgets(buffer, 16, stdin);
	fgets(fmt_buffer, 32, stdin);
	printf(fmt_buffer, buffer);

	printf("v = %u\n", v);
	if (v == 100)
		puts("You've got it. Congratulations!");
}

int main(void)
{
	do_nasty();
	return 0;
}
