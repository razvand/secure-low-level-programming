#include <stdio.h>
#include <stdlib.h>

static void list_user(void)
{
	system("id");
}

int main(void)
{
	list_user();

	return 0;
}
