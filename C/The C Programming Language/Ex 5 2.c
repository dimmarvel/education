#include <ctype.h>
#include <stdio.h>

int getfloat(float* pn)
{
    int c, sign, mark;
    float fract;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c); // it's not a number
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        mark = c; // remember a sign
        c = getch();
        if (!isdigit(c))
        {
            if (c != EOF)
                ungetch(c); // not a number - back on the input
            ungetch(mark);  // back sign of the symvol on the input
            return 0;
        }
    }
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0'); // collect integer part
    if (c == '.')
        c = getch();
    for (fract = 1.0; isdigit(c); c = getch())
    {
        *pn = 10.0 * *pn + (c - '0');
        fract *= 10.0;
    }

    *pn *= sign / fract;
    if (c != EOF)
        ungetch(c);
    return c;
}