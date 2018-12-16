#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void show_if_root(void)
{
	if (strcmp(getenv("USER"), "root") == 0)
		puts("You got it! Congratulations!");
}

int main(void)
{
	show_if_root();

	return 0;
}
