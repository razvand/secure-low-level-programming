#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* useful macro for handling error codes */
#define DIE(assertion, call_description)				\
	do {								\
		if (assertion) {					\
			fprintf(stderr, "(%s, %d): ",			\
					__FILE__, __LINE__);		\
			perror(call_description);			\
			exit(EXIT_FAILURE);				\
		}							\
	} while(0)

static void msg_and_wait(const char *msg)
{
	char buf[256];

	puts(msg);
	fputs("     Press ENTER to continue ...", stdout); fflush(stdout);

	while (1) {
		fgets(buf, 256, stdin);
		if (buf[strlen(buf)-1] == '\n')
			break;
	}
}

static void work_with_stack(void)
{
	msg_and_wait("Before first allocation on stack");

	{
		char buffer1[1024*1024];
		buffer1[0] = 'a';
		buffer1[1024*1024-1] = 'b';

		msg_and_wait("Before second allocation on stack");

		{
			char buffer2[1024*1024];
			buffer2[0] = 'a';
			buffer2[1024*1024-1] = 'b';

			msg_and_wait("Before second dellocation on stack");
		}
		msg_and_wait("Before first dellocation on stack");
	}
	msg_and_wait("Ending stack deallocation");
}

static void work_with_heap(void)
{
	char *p1, *p2, *p3, *p4;
	msg_and_wait("Before first allocation on heap");
	p1 = malloc(32 * 1024);
	p1[0] = 'a';
	p1[32*1024-1] = 'b';
	msg_and_wait("Before second allocation on heap");
	p2 = malloc(32 * 1024);
	p2[0] = 'a';
	p2[32*1024-1] = 'b';
	msg_and_wait("Before third allocation on heap");
	p3 = malloc(4 * 1024 * 1024);
	p3[0] = 'a';
	p3[4*1024*1024-1] = 'b';
	msg_and_wait("Before fourth allocation on heap");
	p4 = malloc(4 * 1024 * 1024);
	p4[0] = 'a';
	p4[4*1024*1024-1] = 'b';
	msg_and_wait("Before first deallocation on heap");
	free(p1);
	msg_and_wait("Before second deallocation on heap");
	free(p2);
	msg_and_wait("Before third deallocation on heap");
	free(p3);
	msg_and_wait("Before fourth deallocation on heap");
	free(p4);
	msg_and_wait("Ending heap deallocation");
}

int main(void)
{
	work_with_stack();
	work_with_heap();

	return 0;
}
