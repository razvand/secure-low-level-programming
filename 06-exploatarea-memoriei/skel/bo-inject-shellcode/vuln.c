#include <stdio.h>

static char shellcode[128];

static void do_nasty(void)
{
	char buffer[64];

	printf("gimme message: ");
	fgets(buffer, 128, stdin);
	printf("hello, %s\n", buffer);
}

int main(void)
{
	printf("Give shellcode: ");
	fgets(shellcode, 128, stdin);

	do_nasty();

	return 0;
}
