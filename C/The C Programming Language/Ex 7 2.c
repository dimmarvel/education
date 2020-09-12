#include <stdio.h>
#include <ctype.h>
#define MAXLINE 25 //maximum number of characters in line
#define OCTLEN 8 //length of the octal value

int main()
{
	int c, pos;

	pos = 0; //position in string    
	while ((c = getchar()) != EOF)
		if (iscntrl(c) || isspace(c))
		{
			if (pos + OCTLEN < MAXLINE)
				pos = pos + OCTLEN;
			else
			{
				putchar('\n');
				pos = OCTLEN;
			}
			printf("\\%03o", c);
			if (c == '\n')
			{
				pos = 0;
				putchar('\n');
			}
		}
		else
		{
			if (pos + 1 < MAXLINE)
				pos = pos + 1;
			else
			{
				putchar('\n');
				pos = 1;
			}
			putchar(c);
		}
	return 0;
}