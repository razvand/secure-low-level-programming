#include <stdio.h>

static void hidden(void)
{
	puts("You've got it. Congratulations!");
}

static void do_nasty(void)
{
	char buffer[64];

	printf("gimme message: ");
	fgets(buffer, 128, stdin);
	printf("hello, %s\n", buffer);
}

int main(void)
{
	do_nasty();

	return 0;
}
