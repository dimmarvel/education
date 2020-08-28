/*entab*/

#include <stdio.h>
#include <stdlib.h>

#define TAB 8

void entab(int m, int n);

void entab(int m, int n)
{
	int c, ntab, nspace, symv;

	symv = 1;
	ntab = 0;
	nspace = 0;
	m = -m;

	while ((c = getchar()) != EOF)
	{
		if (m-- > 0)
			putchar(c);
		else
			symv++;
		if (c == ' ')
		{
			if (symv < (-1 * m))
				putchar(c);
			if (symv % n == 0)
			{
				ntab++;
				nspace = 0;
			}
			else
				nspace++;
		}
		else
		{
			while (ntab > 0)
			{
				putchar('\t');
				ntab--;
			}
			if (c == '\t')
			{
				nspace = 0;
				putchar('\t');
				symv = symv + (n - (symv % n));
			}
			else
			{
				while (nspace > 0)
				{
					putchar(' ');
					nspace--;
				}
				putchar(c);
				if (c == '\n')
				{
					symv = 0;
					ntab = 0;
					nspace = 0;
				}
			}
		}
	}
}


int main(int argc, char *argv[])
{
	int pos, tabinc;

	if (argc > 3)
	{
		printf("ERROR, wrong parametrs\n");
		return 1;
	}
	if (argc <= 1)
		detab(0, TAB);
	else if (argc == 3 && argv[1] == '-' && argv[2] == '+')
	{
		pos = atoi(argv[1]);
		tabinc = atoi(argv[2]);
		detab(pos, tabinc);
	}
	else
	{
		pos = atoi(argv[1]);
		detab(pos, TAB);
	}
	return 0;


	/*int pos, tabinc;

	if (argc > 3)
	{
		printf("ERROR, wrong parameters\n");
		return 1;
	}
	if (argc <= 1)
		entab(0, TAB);
	else if (argc == 3 && *(argv + 1) == '-' && *(argv + 2) == '+')
	{
		pos = atoi(*(argv + 1));
		tabinc = atoi(*(argv + 2));
		entab(pos, tabinc);
	}
	else
	{
		pos = atoi(*(argv + 1));
		entab(pos, TAB);
	}
	return 0;*/
}


void detab(int m, int n)
{
	int c, i, symvol, ntab;

	m = -m;
	symvol = 1;
	while ((c = getchar()) != EOF)
	{
		if (m-- > 0)
			putchar(c);
		else
			if (c == '\t')
			{
				ntab = n - (symvol - 1);
				for (i = 0; i < ntab; i++)
					putchar(' ');
			}
			else if (c == '\n')
			{
				symvol = 0;
				printf("\n");
			}
			else
				putchar(c);
		symvol++;
		if (symvol == n)
			symvol = 0;
	}
}