#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void do_nasty1(void)
{
	char password[] = "GOURANGA";
	char buffer[32];

	/* This is rather stupid. We use it to highlight the issue. */
	memset(buffer, 'a', sizeof(buffer));
	puts(buffer);
}

static void do_nasty2(void)
{
	char buffer[32];

	/* This is rather stupid. We use it to highlight the issue. */
	memset(buffer, 'a', sizeof(buffer));
	puts(buffer);
}

int main(int argc, char **argv)
{
	do_nasty1();
	do_nasty2();
	return 0;
}
