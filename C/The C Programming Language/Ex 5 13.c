#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 // max lines
#define BUFSIZE 5000
#define reserve 10

char* lineptr[MAXLINES]; // pointers to text lines

int readlines(char* lineptr[], char* buf, int nlines);
void writelines(char* lineptr[], int n, int nlines);

/* prints the last n lines */
int main(int argc, char** argv)
{
    int nlines, n; // number of input lines read && last lines
    char buf[BUFSIZE];

    if (argc > 2)
    {
        printf("ERROR: invalid parametrs\n");
        return 1;
    }
    if (argc == 2 && atoi(*++argv) < 0)
        n = -(atoi(*argv));
    else
    {
        printf("wrong parameters, to use default\n");
        n = reserve;
    }
    if ((nlines = readlines(lineptr, buf, MAXLINES)) >= 0)
    {
        printf("\n");
        writelines(lineptr, n, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
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
void writelines(char* lineptr[], int n, int nlines)
{
    int i;

    if (n > nlines)
    {
        n = nlines;
        printf("not enough lines\n");
    }
    for (i = nlines - n; n > 0; n--)
        printf("%s\n", lineptr[i++]);
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