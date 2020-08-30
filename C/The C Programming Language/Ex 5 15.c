#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum com {NUMERIC, DEC, FOLD};

#define MAXLENS 500
char *lineptr[MAXLENS];
int dec = 0;

int numcmp(char *, char *);

void qsort(void *lineptr[], int left, int right, int(*comp)(void*, void*));
void writelines(char *lineptr[], int nlines, int enter);
int readlines(char *lineptr[], int maxlines);
void swap(void *v[], int i, int j);
int getline(char*, int);
//--------------------------------------
#define ALLOCSIZE 1000

static char allocbuff[ALLOCSIZE];
static char *allocp = allocbuff;

char* alloc(int n);

//--------------------------------------


main(int argc, char* argv[])
{
	int nlines;
	int numeric = 0;

	argc = 4;
	argv[0] = "sort ";
	argv[1] = "-n";
	argv[2] = "-r";
	argv[3] = "-f";
	writelines(argv, argc, 0);

	while (argc > 0)
	{
		if (strcmp(argv[--argc], "-n"))
		{
			numeric = NUMERIC;
		}
		else if (strcmp(argv[--argc], "-r"))
		{
			dec = DEC;
		}
		else if (strcmp(argv[--argc], "-f"))
		{
			dec = DEC;
		}
	}

	if ((nlines = readlines(lineptr, MAXLENS)) >= 0)
	{
		qsort((void **)lineptr, 0, nlines - 1, (int(*)(void*, void*))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines, 1);
		return 0;
	}
	else
	{
		printf("input too big to sort/n");
		return 1;
	}

	return 0;
}

/*compare strings for number value*/
int numcmp(char * s1, char * s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if (v1 < v2)
	{
		return -1;
	}
	else if (v1 > v2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void qsort(void *v[], int left, int right, int(*comp)(void*, void*))
{
	int i, last;

	void swap(void*[], int, int);

	if (left >= right)
	{
		return;
	}

	swap(v, left, (left + right) / 2);

	last = left;

	for (i = left + 1; i <= right; i++)
	{
		if (dec == 0 && (*comp)(v[i], v[left]) < 0)
		{
			swap(v, ++last, i);
		}
		else if (dec != 0 && (*comp)(v[i], v[left]) > 0)
		{
			swap(v, ++last, i);
		}
	}

	swap(v, left, last);
	qsort(v, left, last - 1, comp);
	qsort(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j)
{
	void* temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

char* alloc(int n)
{
	if (allocbuff + ALLOCSIZE - allocp >= 0)
	{
		allocp += n;
		return (allocp - n);
	}
	else
	{
		return 0;
	}
}

void free(char* ptr)
{
	if (ptr > allocbuff && ptr < allocbuff + ALLOCSIZE)
	{
		allocp = ptr;
	}
}

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines = 0;

	char* p, line[MAXLENS];

	while ((len = getline(line, MAXLENS)) > 0)
	{
		if (nlines >= maxlines || ((p = alloc(len)) == NULL))
		{
			return -1;
		}
		else
		{
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines, int enter)
{

	for (int i = 0; i < nlines; i++)
	{
		if (enter == 1)
		{
			printf("%s\n", lineptr[i]);
		}
		else
		{
			printf("%s", lineptr[i]);
		}
	}
	if (enter == 0) printf("\n");

}

int getline(char* s, int lim)
{
	int c;
	char* temp = s;

	while (s < s + lim - 1 && (c = getchar()) != EOF && c != '\n')
	{
		*s++ = c;
	}

	if (c == '\n')
	{
		*s++ = c;
	}

	*s = '\0';

	return s - temp;
}
