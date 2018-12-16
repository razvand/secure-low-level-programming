#include <stdio.h>

int main(void)
{
	unsigned int m = 'abcde';
	unsigned int n = 0x12345678ab;
	printf("sizeof('a'): %zu, sizeof('\\0'): %zu, sizeof(NULL): %zu\n", sizeof('a'), sizeof('\0'), sizeof(NULL));
	printf("sizeof('bcd'): %zu\n", sizeof('bcd'));
	printf("m: 0x%08x\n", m);
	printf("n: 0x%08x\n", n);
	return 0;
}
