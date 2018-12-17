#include <stdio.h>
#include <stdlib.h>
#include <sys/capability.h>

static void print_caps(const char *msg)
{
	cap_t caps;
	cap_flag_value_t flag;

	caps = cap_get_proc();
	if (caps == NULL) {
		perror("cap_get_proc");
		exit(EXIT_FAILURE);
	}
	if (cap_get_flag(caps, CAP_DAC_READ_SEARCH, CAP_EFFECTIVE, &flag) < 0) {
		perror("cap_get_flag");
		exit(EXIT_FAILURE);
	}
	printf("[%s] cap: CAP_DAC_READ_SEARCH: %u\n", msg, flag);
}

int main(void)
{
	cap_t caps;
	cap_value_t cap_list[1] = {CAP_DAC_READ_SEARCH};
	FILE *f_sudoers, *f_shadow;

	print_caps("beginning");
	f_sudoers = fopen("/etc/sudoers", "rt");
	if (f_sudoers == NULL)
		perror("fopen(\"/etc/sudoers\")");

	/* Give up setuid privilege. */
	caps = cap_get_proc();
	if (caps == NULL) {
		perror("cap_get_proc");
		exit(EXIT_FAILURE);
	}
	if (cap_set_flag(caps, CAP_EFFECTIVE, 1, cap_list, CAP_CLEAR) < 0) {
		perror("cap_set_flag");
		exit(EXIT_FAILURE);
	}
	cap_set_proc(caps);
	print_caps("after privilege drop");

	f_shadow = fopen("/etc/shadow", "rt");
	if (f_shadow == NULL)
		perror("fopen(\"/etc/shadow\")");

	return 0;
}
