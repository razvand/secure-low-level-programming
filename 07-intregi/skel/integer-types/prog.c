#include <stdio.h>

int main(void)
{
	unsigned char uc = 0x80;
	signed char c = 0x80;
	unsigned int ui = uc;
	int i = c;
	unsigned int a = 0xf0e1d2c3;
	unsigned int my = 10;
	signed char your = -30;

	printf("uc: %hhu (0x%02hhx), c: %hhd (0x%02hhx)\n", uc, uc, c, c);
	printf("ui: %u (0x%08x), i: %u (0x%08x)\n", ui, ui, i, i);
	printf("%hhu, %hhd, %hu, %hd, %u, %d\n", a, a, a, a, a, a);
	printf("2^31: %u\n", 1U << 31);
	printf("2^63: %lu\n", 1UL << 63);
	printf("sizeof(1): %zu, sizeof(1U): %zu, sizeof(1L): %zu, sizeof(1UL): %zu, sizeof(1LL): %zu, sizeof(1ULL): %zu\n",
		sizeof(1), sizeof(1U), sizeof(1L), sizeof(1UL), sizeof(1LL), sizeof(1ULL));

	if (my < your)
		printf("10 < -30\n");

	return 0;
}
