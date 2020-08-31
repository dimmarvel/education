#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINES 5000 //max lines to be sorted
#define BUFSIZE 5000


char *lineptr[MAXLINES];

int readlines(char *lineptr[], char *buf, int maxlines);
void writelines(char *lineptr[], int nlines, int order);
void sort(void *v[], int left, int right,
	int(*comp) (void *, void *));
int numcmp(char *s1, char *s2);
int regcmp(char *r1, char *r2);

int numeric, order, reg, dir;
int pos1 = 0;
int pos2 = 0;

/* sort input lines */
int main(int argc, char *argv[])
{
	int nlines; //number of input lines read
	int c, wk; // 1 if numeric sort & order sort
	char buf[BUFSIZE];
	int(*pFunc)(int *);
	numeric = 0;
	order = 0;
	reg = 0;
	dir = 0;


	while (--argc > 0 && (c = (*++argv)[0]) == '-' || c == '+')
	{
		if (c == '-' && !isdigit(*(argv[0] + 1)))
			while (c = *++argv[0])
				switch (c)
				{
				case 'd'://directory order
					dir = 1;
					break;
				case 'n': //numerically sort
					numeric = 1;
					break;
				case 'f'://sort upper & lower case together
					reg = 1;
					break;
				case 'r'://sorting in reverse
					order = 1;
					break;
				default:
					printf("wrong key\n");
					wk = -1;
					argc = 1;
					break;
				}
		else if (c == '-')
			pos2 = atoi(argv[0] + 1);
		else if ((pos1 = atoi(argv[0] + 1)) < 0)
		{
			printf("ERROR\n");
			exit(1);
		}
	}
	if (argc || pos1 > pos2)
	{
		printf("ERROR\n");
		exit(1);
	}
	else
	{
		if ((nlines = readlines(lineptr, buf, MAXLINES)) >= 0)
		{
			if (numeric == 1)
				pFunc = numcmp;
			else if (reg == 1 || dir == 1)
				pFunc = regcmp;
			else
				pFunc = strcmp;
			sort((void **)lineptr, 0, nlines - 1,
				(int(*) (void*, void*)) *pFunc);
			writelines(lineptr, nlines, order);
		}
		else
		{
			printf("input too big to sort\n");
			wk = -1;
		}
	}
	return wk;
}



/* sort: sort v[left]...v[right] into increasing order */
void sort(void *v[], int left, int right,
	int(*comp) (void *, void *))
{
	int i, last;
	void swap(void *v[], int i, int j);

	if (left >= right) //do nothing if array contains
		return;       //fewer than two elements
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++)
		if ((*comp) (v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	sort(v, left, last - 1, comp);
	sort(v, last + 1, right, comp);
}

#include <stdlib.h>
#include <math.h>

#define MAXSTR 5000

void sortstr(char *s, char *t, int maxstr);

/* numcmp: compare s1 and s2 numericalli */
int numcmp(char *s1, char *s2)
{
	double v1, v2;
	char str[MAXSTR];

	sortstr(s1, str, MAXSTR);
	v1 = atof(str);
	sortstr(s2, str, MAXSTR);
	v2 = atof(str);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void sortstr(char *s, char *t, int maxstr)
{
	int i, j, len;

	len = strlen(s);
	if (pos2 > 0 && len > pos2)
		len = pos2;
	else if (pos2 > 0 && len < pos2)
	{
		printf("ERROR\n");
		exit(1);
	}
	for (i = 0, j = pos1; j < len; i++, j++)
		t[i] = s[j];
	t[i] = '\0';
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#define MAXLEN 1000 //max lenght of any input line


int getlin(char *, int);

/* readlines: read input lines */
int readlines(char *lineptr[], char *buf, int maxlines)
{
	int len, nlines;

	char line[MAXLEN];

	char *p = buf;
	char *bufstop = buf + BUFSIZE;

	nlines = 0;
	while ((len = getlin(line, MAXLEN)) > 0)
	{
		if (nlines >= maxlines || p + len > bufstop)
			return -1;
		else
		{
			line[len - 1] = '\0'; //delete newline
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}
	}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int order)
{
	int i;

	printf("\n");
	if (order == 0)
		for (i = 0; i < nlines; i++)
			printf("%s\n", lineptr[i]);
	else
		for (i = nlines - 1; i >= 0; i--)
			printf("%s\n", lineptr[i]);
}

int getlin(char *l, int lim)
{
	int c;
	char *tmp = l;

	for (; --lim > 0 && (c = getchar()) != EOF && c != '\n'; l++)
		*l = c;
	if (c == '\n')
		*l++ = c;
	*l = '\0';
	return l - tmp;
}

int regcmp(char *r1, char *r2)
{
	int i, j, lastpos;

	i = j = pos1;
	if (pos2 > 0)
		lastpos = pos2;
	else if ((lastpos = strlen(r1)) > strlen(r2))
		lastpos = strlen(r2);
	if (reg == 1 && dir == 0)
	{
		for (; tolower(r1[i]) == tolower(r2[j]) && i < lastpos && j < lastpos; i++, j++)
			if (r1[i] == '\0')
				return 0;
		return tolower(r1[i]) - tolower(r2[j]);
	}
	else if (reg == 0 && dir == 1)
	{
		while (r1[i] == r2[j] && i < lastpos && j < lastpos)
		{
			while (i < lastpos && !isalnum(r1[i]) && r1[i] != '\0' && r1[i] != ' ')
				i++;
			while (j < lastpos && !isalnum(r2[j]) && r2[j] != '\0' && r2[j] != ' ')
				j++;
		}
		if (r1[i] == r2[j] && r1[i] == '\0')
			return 0;
		else
			return r1[i] - r2[j];
	}
	else
	{
		while (r1[i] == r2[j] && i < lastpos && j < lastpos)
		{
			while (i < lastpos && !isalnum(tolower(r1[i])) && r1[i] != '\0' && r1[i] != ' ')
				i++;
			while (j < lastpos && !isalnum(tolower(r2[j])) && r2[j] != '\0' && r2[j] != ' ')
				j++;
		}
		if (tolower(r1[i]) == tolower(r2[j]) && r1[i] == '\0')
			return 0;
		else
			return tolower(r1[i]) - tolower(r2[j]);
	}
}
