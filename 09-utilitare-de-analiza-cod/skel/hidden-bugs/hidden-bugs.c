/*
 * There are eight bugs in the code below. Find them.
 * From Jared DeMott, Crucial Security, Inc., Black Hat 2008
 */

#include <syslog.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFLEN 16
#define WORDSIZE 2
#define DWORDSIZE WORDSIZE+WORDSIZE

static void mylog(int kind, char *msg)
{
	syslog(LOG_USER | kind, msg);
}

static void mycpy(char *dst, char *src)
{
	if(strlen(src) < BUFLEN - 1)
		while(*src)
			*dst++ = *src++;
	*dst = '\x00';
}

int main(int argc, char *argv[])
{
	char buf1[16];
	char buf2[16];
	char buf3[BUFLEN];
	char *buf4;
	char *buf5;
	char buf6[16];
	char *buf7;
	int i, len;

	if (argc != 12)
		exit(0);

	strncpy(buf1, argv[1], sizeof(buf1));
	len = atoi(argv[2]);
	if (len < 16)
		memcpy(buf2, argv[3], len);
	else {
		char *buf = malloc(len + 20);
		if(buf){
			snprintf(buf, len+20, "String too long: %s", argv[3]);
			mylog(LOG_ERR, buf);
		}
	}
	mycpy(buf3, argv[4]);
	strncat(buf3, argv[5], sizeof(buf3)-1);
	if (fork())
		execl("/bin/ls", "/bin/ls", argv[6], 0);

	// filter metacharacters
	char *p;
	if (p = strchr(argv[7], '&'))
		*p = 0;
	if (p = strchr(argv[7], '`'))
		*p = 0;
	if (p = strchr(argv[7], ';'))
		*p = 0;
	if (p = strchr(argv[7], '|'))
		*p = 0;
	if (strlen(argv[7]) < 1024){
		buf4 = malloc(20 + strlen(argv[7]));
		sprintf(buf4, "/bin/cat %s", argv[7]);
		system(buf4);
	}

	buf5 = malloc(strlen(argv[8]) + strlen(argv[9]) + 2);
	strcpy(buf5, argv[8]);
	strcat(buf5, argv[9]);
	memcpy(buf6, argv[10], strlen(argv[10]));
	buf7 = malloc(4 * DWORDSIZE);

	for(i=0; i<4; i++){
		memcpy(buf7 + 4 * i, argv[11] + 4 * i, DWORDSIZE);
	}

	printf("\nGot %s, (%d) %s, %s, %s, %s, %s, %s\n",
			buf1, len, buf2, buf3, buf4, buf5, buf6, buf7);
}
