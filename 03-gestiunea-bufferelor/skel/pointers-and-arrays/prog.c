#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *p1 = "anaaremere";
static char p2[] = "anaaremere";
static const char *p3 = "anaaremere";
static const char * const p4 = "anaaremere";
static const char p5[] = "anaaremere";

static void work_size(void)
{
	printf("sizeof(char *p1) = %zu\n", sizeof(p1));
	printf("sizeof(char p2[]) = %zu\n", sizeof(p2));
	printf("sizeof(const char *p3) = %zu\n", sizeof(p3));
	printf("sizeof(char * const p4) = %zu\n", sizeof(p4));
	printf("sizeof(char p5[]) = %zu\n", sizeof(p5));
}

static void work_dereference(void)
{
	printf("*p1 = %c\n", *p1);
	printf("*p2 = %c\n", *p2);
	printf("*p3 = %c\n", *p3);
	printf("*p4 = %c\n", *p4);
	printf("*p5 = %c\n", *p5);
}

static void work_index(void)
{
	printf("p1[5] = %c\n", p1[5]);
	printf("p2[5] = %c\n", p2[5]);
	printf("p3[5] = %c\n", p3[5]);
	printf("p4[5] = %c\n", p4[5]);
	printf("p5[5] = %c\n", p5[5]);
}

static void work_rhs(void)
{
	char *q;

	q = p1;
	q = p2;
	q = p3;
	q = p4;
	q = p5;
}

static void work_lhs(void)
{
	char *q = "aaa";
	p1 = q;
	/* p2 = a; */
	p3 = q;
	/* p4 = q; */
	/* p5 = q; */
}

int main(void)
{
	work_size();
	work_dereference();
	work_index();
	work_rhs();
	work_lhs();

	return 0;
}
