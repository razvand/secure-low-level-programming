#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>

static void print_uids(const char *msg)
{
	static uid_t ruid, euid, suid;

	getresuid(&ruid, &euid, &suid);
	printf("[%s] ruid: %d, euid: %d, suid: %d\n", msg, ruid, euid, suid);
}

int main(void)
{
	uid_t ruid;
	FILE *f_sudoers, *f_shadow;

	print_uids("beginning");
	f_sudoers = fopen("/etc/sudoers", "rt");
	if (f_sudoers == NULL)
		perror("fopen(\"/etc/sudoers\")");

	/* Give up setuid privilege. */
	ruid = getuid();
	setresuid(ruid, ruid, ruid);
	print_uids("after privilege drop");

	f_shadow = fopen("/etc/shadow", "rt");
	if (f_shadow == NULL)
		perror("fopen(\"/etc/shadow\")");

	return 0;
}
