#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void do_nasty(const char *banner)
{
	char msg[] = "FLOW";
	char placeholder[7];
	char buffer[32];

	/* This is rather stupid. We use it to highlight the issue. */
	strcpy(buffer, banner);

	printf("placeholder[0]: %c, placeholder[6]: %c\n", placeholder[0], placeholder[6]);
	if (strcmp(msg, "MOOR") == 0)
		puts("You've got it. Congratulations!");
}

static void usage(const char *argv0)
{
	fprintf(stderr, "Provide string banner as argument.\n\n");
	fprintf(stderr, "Usage: %s <banner>\n", argv0);
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}

	do_nasty(argv[1]);
	return 0;
}
