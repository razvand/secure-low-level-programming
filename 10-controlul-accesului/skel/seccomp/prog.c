#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <seccomp.h>

static void use_seccomp(void)
{
	int rc = -1;
	scmp_filter_ctx ctx;

	ctx = seccomp_init(SCMP_ACT_ERRNO(42));
	if (ctx == NULL)
		goto out;

	rc = seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(close), 0);
	if (rc < 0)
		goto out;

	rc = seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit_group), 0);
	if (rc < 0)
		goto out;

	rc = seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit), 0);
	if (rc < 0)
		goto out;

	rc = seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0);
	if (rc < 0)
		goto out;

	rc = seccomp_load(ctx);
	if (rc < 0)
		goto out;

out:
	seccomp_release(ctx);
}

int main(int argc, char *argv[])
{
	FILE *f_sudoers, *f_shadow;

	puts("beginning");
	f_sudoers = fopen("/etc/hosts", "rt");
	if (f_sudoers == NULL)
		perror("fopen(\"/etc/hosts\")");

	/* Give up setuid privilege. */
	use_seccomp();
	puts("after sandboxing");

	f_shadow = fopen("/etc/passwd", "rt");
	if (f_shadow == NULL)
		perror("fopen(\"/etc/passwd\")");

}
