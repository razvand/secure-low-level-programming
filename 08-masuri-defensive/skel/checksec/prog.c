#include <stdio.h>

static void do_nasty(void)
{
	unsigned int v = 0xAABBCCDD;
	char buffer[64];

	printf("gimme message: ");
	fgets(buffer, 128, stdin);
	printf("hello, %s\n", buffer);

	printf("v: 0x%08x\n", v);
	if (v == 0x11223344)
		puts("You've got it. Congratulations!");
}

int main(void)
{
	do_nasty();

	return 0;
}
