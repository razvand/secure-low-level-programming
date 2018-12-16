#include <stdio.h>

static char shellcode[128];

int main(void)
{
	void (*fn)(void) = (void (*)(void)) shellcode;

	printf("Give shellcode: ");
	fgets(shellcode, 128, stdin);

	fn();

	return 0;
}
