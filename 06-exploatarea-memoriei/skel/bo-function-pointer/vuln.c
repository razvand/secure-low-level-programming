#include <stdio.h>

static void hidden(void)
{
	puts("You've got it. Congratulations!");
}

static void public(void)
{
	puts("Not yet. Try again!");
}

static void do_nasty(void)
{
	void (*f)(void) = public;
	unsigned int v = 0xAABBCCDD;
	char buffer[64];

	printf("gimme message: ");
	fgets(buffer, 128, stdin);
	printf("hello, %s\n", buffer);

	f();
}

int main(void)
{
	do_nasty();

	return 0;
}
