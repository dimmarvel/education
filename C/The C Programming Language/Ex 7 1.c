#include <stdio.h>
#include <string.h>
#include <ctype.h>

main(int argc, char* argv[])
{

	int c;
	argc = 2;
	argv[argc] = "upper";

	if (strcmp(argv[argc], "upper"))
	{
		while ((c = getchar()) != EOF)
		{
			putchar(toupper(c));
		}
	}
	else if (strcmp(argv[argc], "lower"))
	{
		while ((c = getchar()) != EOF)
		{
			putchar(tolower(c));
		}
	}
	return 0;
}