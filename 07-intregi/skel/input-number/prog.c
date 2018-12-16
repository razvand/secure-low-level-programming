#include <stdio.h>
#include <stdlib.h>

static void usage(const char *argv0)
{
	fprintf(stderr, "Usage: %s <number>\n", argv0);
}

int main(int argc, char **argv)
{
	int x;
	size_t sx;

	if (argc != 2) {
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}

	x = atoi(argv[1]);
	sx = x;

	printf("%%d (int): %d\n", x);
	printf("%%u (int): %u\n", x);
	printf("%%x (int): 0x%x\n", x);
	printf("%%d (size_t): %d\n", sx);
	printf("%%u (size_t): %zu\n", sx);
	printf("%%x (size_t): 0x%lx\n", sx);

	return 0;
}
