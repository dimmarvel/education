#include "calc.h"
#include <ctype.h>
#include <stdio.h>

int getop(char s[])
{
    int i, c;

    static int ungetch = 0;

    if (ungetch == 0)
    {
        c = getch();
    }
    else
    {
        c = ungetch;
        ungetch = 0;
    }

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') // not a number
        return c;
    i = 0;
    if (c == '-')
    {
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c; // negative numbers
        else
        {
            if (c != EOF)
                ungetch = c;
            return '-';
        }
    }
    if (isdigit(c)) // collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') // collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch = c;
    return NUMBER;
}