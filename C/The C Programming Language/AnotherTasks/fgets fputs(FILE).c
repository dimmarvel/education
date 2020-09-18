#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

main(int argc, char* argv[])
{
}

char* fgets(char *s, int n, FILE *iop)
{
	register int c;
	register char* cs;

	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF)
	{
		if ((*cs++ = c) == '\n')
		{
			break;
		}
		*cs = '\0';
	}
	return (c == EOF && cs == s) ? NULL : s;
}

int fputs(char *s, FILE *iop)
{
	int c;

	while (c = *s++)
	{
		putc(c, iop);
	}

	return ferror(iop) ? EOF : 0;
}