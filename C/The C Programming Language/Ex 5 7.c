#include <stdio.h>
#include <string.h>

#define MAXLINES 50
#define ALLOCSIZE 10000

char* lineptr[MAXLINES];
static char allocbuff[ALLOCSIZE];
static char* allocp = allocbuff;

int readlines(char* lineptr[], int nlines);
void writelines(char* lineptr[], int nlines);
void qsort(char* lineptr[], int left, int right);

main()
{
    int nlines;
    printf("%p\n", lineptr);
    nlines = readlines(lineptr, MAXLINES);
    printf("%p\n", lineptr);
    if (nlines >= 0)
    {
        writelines(lineptr, nlines);
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
    system("pause");
}

#define MAXLEN 100
int getline(char[], int);
char* alloc(int);

int readlines(char* lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

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
    int i;
    while (nlines-- > 0)
    {
        printf("%s\n", *lineptr++);
    }
}

int getline(char s[], int lim)
{
    int c;
    int i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n' && c != '\0'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

void swap(char* v[], int i, int j)
{
    char* temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(char* v[], int left, int right)
{

    int i, last;

    void swap(char* v[], int i, int j);

    if (left >= right)
    {
        return;
    }

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

char* alloc(int n)
{
    if (allocbuff + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    }
    else
    {
        return 0;
    }
}

void free(char* ptr)
{
    if (ptr >= allocbuff && ptr < allocbuff + ALLOCSIZE)
    {
        allocp = ptr;
    }
}
