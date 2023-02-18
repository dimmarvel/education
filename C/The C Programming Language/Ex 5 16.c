#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 // max lines to be sorted
#define BUFSIZE 5000

char* lineptr[MAXLINES];

int readlines(char* lineptr[], char* buf, int maxlines);
void writelines(char* lineptr[], int nlines, int order);
void sort(void* v[], int left, int right, int (*comp)(void*, void*));
int numcmp(char* s1, char* s2);
int regcmp(char* r1, char* r2);

int numeric, order, reg, dir;

/* sort input lines */
int main(int argc, char* argv[])
{
    int nlines; // number of input lines read
    int c, wk;
    char buf[BUFSIZE];
    int (*pFunc)(int*);
    numeric = 0;
    order = 0;
    reg = 0;
    dir = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c)
            {
            case 'd': // directory order
                dir = 1;
                break;
            case 'n': // numerically sort
                numeric = 1;
                break;
            case 'f': // sort upper & lower case together
                reg = 1;
                break;
            case 'r': // sorting in reverse
                order = 1;
                break;
            default:
                printf("wrong key\n");
                wk = -1;
                argc = 1;
                break;
            }
    if (argc)
        printf("ERROR\n");
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
            sort((void**)lineptr, 0, nlines - 1, (int (*)(void*, void*)) * pFunc);
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
void sort(void* v[], int left, int right, int (*comp)(void*, void*))
{
    int i, last;
    void swap(void* v[], int i, int j);

    if (left >= right) // do nothing if array contains
        return;        // fewer than two elements
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    sort(v, left, last - 1, comp);
    sort(v, last + 1, right, comp);
}

#include <stdlib.h>

/* numcmp: compare s1 and s2 numericalli */
int numcmp(char* s1, char* s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void* v[], int i, int j)
{
    void* temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#define MAXLEN 1000 // max lenght of any input line

int getlin(char*, int);

/* readlines: read input lines */
int readlines(char* lineptr[], char* buf, int maxlines)
{
    int len, nlines;

    char line[MAXLEN];

    char* p = buf;
    char* bufstop = buf + BUFSIZE;

    nlines = 0;
    while ((len = getlin(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || p + len > bufstop)
            return -1;
        else
        {
            line[len - 1] = '\0'; // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char* lineptr[], int nlines, int order)
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

int getlin(char* l, int lim)
{
    int c;
    char* tmp = l;

    for (; --lim > 0 && (c = getchar()) != EOF && c != '\n'; l++)
        *l = c;
    if (c == '\n')
        *l++ = c;
    *l = '\0';
    return l - tmp;
}

int regcmp(char* r1, char* r2)
{
    if (reg == 1 && dir == 0)
    {
        for (; tolower(*r1) == tolower(*r2); r1++, r2++)
            if (*r1 == '\0')
                return 0;
        return tolower(*r1) - tolower(*r2);
    }
    else if (reg == 0 && dir == 1)
    {
        while (*r1 == *r2)
        {
            while (!isalnum(*r1) && *r1 != '\0' && *r2 != ' ')
                r1++;
            while (!isalnum(*r2) && *r1 != '\0' && *r2 != ' ')
                r2++;
        }
        if (*r1 == *r2 && *r1 == '\0')
            return 0;
        else
            return *r1 - *r2;
    }
    else
    {
        while (*r1 == *r2)
        {
            while (!isalnum(tolower(*r1)) && *r1 != '\0' && *r2 != ' ')
                r1++;
            while (!isalnum(tolower(*r2)) && *r1 != '\0' && *r2 != ' ')
                r2++;
        }
        if (tolower(*r1) == tolower(*r2) && *r1 == '\0')
            return 0;
        else
            return tolower(*r1) - tolower(*r2);
    }
}