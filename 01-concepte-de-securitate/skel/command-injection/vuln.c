#include <stdio.h>
#include <stdlib.h>

static void list_user(const char *user)
{
	char buffer[128];

	snprintf(buffer, 128, "id %s", user);
	system(buffer);
}

static void print_usage(const char *argv0)
{
	fprintf(stderr, "Show information about a user. Provide username.\n\n");
	fprintf(stderr, "Usage: %s <username>\n", argv0);
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		print_usage(argv[0]);
		exit(EXIT_FAILURE);
	}
	list_user(argv[1]);

	return 0;
}
