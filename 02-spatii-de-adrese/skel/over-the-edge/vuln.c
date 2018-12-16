#include <stdio.h>
#include <stdlib.h>

static unsigned int g_buffer[128];

static void access_over_data(void)
{
	printf("access over in data, g_buffer[140]: 0x%08x\n", g_buffer[140]);
}

static void access_over_stack(void)
{
	unsigned int l_buffer[128];
	printf("access over in stack, l_buffer[140]: 0x%08x\n", l_buffer[140]);
}

static void access_over_heap(void)
{
	unsigned int *p = malloc(128 * sizeof(*p));
	printf("access over in heap, p[140]: 0x%08x\n", p[140]);
}

int main(int argc, char **argv)
{
	access_over_data();
	access_over_stack();
	access_over_heap();

	return 0;
}
