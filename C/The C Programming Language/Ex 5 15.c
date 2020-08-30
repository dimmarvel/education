#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NUMERIC 1
#define DECR 2
#define FOLD 4
#define ALLOCSIZE 10000
#define MAXLINES 5000
#define MAXLEN 1000

static char allocbuf[ALLOCSIZE];
static char* allocp = allocbuf;
char* lineptr[MAXLINES];
int decr = 0;

int readlines(char*[], int);
void writelines(char*[], int);
void qsort(int, int, int(*)(void*, void*));
int numcmp(char*, char*);

main(int argc, char* argv[])
{
	int nlines, c;
	int option = 0;

	while (--argc > 0 && (*++argv)[0] == '-')
	{
		while (c = *++argv[0])
		{
			switch (c)
			{
			case 'f':
				option |= FOLD;
				break;
			case 'n':
				option |= NUMERIC;
				break;
			case 'r':
				decr = DECR;
				break;
			}
		}
	}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
	{
		qsort(0, nlines - 1, (int(*)(void*, void*))(option & NUMERIC ? numcmp : option & FOLD ? _stricmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("Error\n");
		return 1;
	}
}

void qsort(int left, int right, int(*comp)(void*, void*))
{
	int i, last;

	void swap(void*[], int, int);

	if (left >= right)
	{
		return;
	}

	swap(lineptr, left, (left + right) / 2);

	last = left;

	for (i = left + 1; i <= right; i++)
	{
		if (decr == 0 && (*comp)(lineptr[i], lineptr[left]) < 0)
		{
			swap(lineptr, ++last, i);
		}
		else if (decr != 0 && (*comp)(lineptr[i], lineptr[left]) > 0)
		{
			swap(lineptr, ++last, i);
		}
	}

	swap(lineptr, left, last);
	qsort(left, last - 1, comp);
	qsort(last + 1, right, comp);
}

void swap(void* v[], int i, int j)
{
	void* temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

int numcmp(char* s1, char* s2)
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

int readlines(char* lineptr[], int maxlines)
{
	int len, nlines;
	char* p, line[MAXLEN];

	int getline(char*, int);
	char* alloc(int);

	nlines = 0;

	while ((len = getline(line, MAXLEN)) > 0)
	{
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
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

void writelines(char* lineptr[], int nlines)
{
	while (nlines-- > 0)
	{
		printf("%s\n", *lineptr++);
	}
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

char* alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n;
	}
	else
	{
		return NULL;
	}
}