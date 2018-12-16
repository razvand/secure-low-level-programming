#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *f;

	f = fopen("data", "rb");
	if (!f) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	while (1) {
		char c;
		c = fgetc(f);
		if (c == EOF)
			break;
		printf("c: 0x%02x (%c)\n", c, c);
	}

	fclose(f);
	return 0;
}
