#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

main(int argc, char* argv[])
{
	FILE* fp;
	void filecopy(FILE *ifp, FILE *ofp);
	
	char* prog = argv[0];

	if (argc = 1)
	{
		filecopy(stdin, stdout);
	}
	else
	{
		while (--argc > 0)
		{
			if ((fp = fopen(fp, "r")) == NULL)
			{
				fprintf(stderr, "%s: can't open %s\n", prog, *argv);
				exit(1);
			}
			else
			{
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}
	if (ferror(stdout))
	{
		fprintf(stderr, "")
	}

	return 0;
}

void filecopy(FILE *ifp, FILE *ofp)
{
	int c;
	while ((c = getc(ifp)) != EOF)
	{
		putc(c, ofp);
	}
}
