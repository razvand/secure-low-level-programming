#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int global_rw = 10;
static const int global_ro = 100;
static int tmp;

static void read_global_rw(void)
{
	puts("Reading from global read-write data ...");
	tmp = global_rw;
}

static void write_global_rw(void)
{
	puts("Writing to global read-write data ...");
	global_rw = 20;
}

static void read_global_ro(void)
{
	int *p = &global_ro;
	puts("Reading from global read-only data ...");
	tmp = *p;
}

static void write_global_ro(void)
{
	int *p = &global_ro;
	puts("Writing to global read-only data ...");
	*p = 200;
}

static void read_lobal(void)
{
	int local = 300;
	puts("Reading from local data ...");
	tmp = local;
}

static void write_local(void)
{
	int local = 300;
	puts("Writing to local data ...");
	local = 400;
}

static void read_heap(void)
{
	int *p = malloc(sizeof(*p));
	puts("Reading from heap data ...");
	tmp = *p;
}

static void write_heap(void)
{
	int *p = malloc(sizeof(*p));
	puts("Writing to heap data ...");
	*p = 500;
}

static void read_code(void)
{
	puts("Reading from code ...");
	tmp = *((unsigned int *) read_code);
}

static void write_code(void)
{
	puts("Writing to code ...");
	*((unsigned int *) read_code) = 600;
}

static void (*funcs[])(void) = {
	read_global_rw,
	write_global_rw,
	read_global_ro,
	write_global_ro,
	read_lobal,
	write_local,
	read_heap,
	write_heap,
	read_code,
	write_code
};

int main(void)
{
	char buf[128];
	long option;

	puts("Here's what you can do:");
	puts("\t0: read from global read-write data");
	puts("\t1: write to global read-write data");
	puts("\t2: read from global read-only data");
	puts("\t3: write to global read-only data");
	puts("\t4: read from local data");
	puts("\t5: write to local data");
	puts("\t6: read from heap data");
	puts("\t7: write to heap data");
	puts("\t8: read from code");
	puts("\t9: write to code");

	printf("\nEnter your option: ");
	fgets(buf, 128, stdin);
	option = strtol(buf, NULL, 10);

	if (option < 0 || option > 9) {
		fprintf(stderr, "Invalid option.\n");
		exit(EXIT_FAILURE);
	}

	funcs[option]();

	return 0;
}
