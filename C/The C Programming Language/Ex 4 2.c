#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <stdio.h>
#define MAXLINE 100
double atof(char s[])
{
    double val, power, degree;
    int i, sign, sign2;
    int counter;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.')
        i++;

    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    if (s[i] == 'e' || s[i] == 'E')
        i++;
    else
        return sign * val / power;

    sign2 = (s[i++] == '-') ? -1 : 1;
    counter = 0;

    for (degree = 1.0; counter < s[i] - '0'; counter++)
        degree *= 10;

    if (sign2 > 0)
        return degree * sign * val / power;
    else
        return (sign * val / power) / degree;
}
int mygetline(char s[], int lim)
{
    int c, i;
    i = 0;

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

int main(void)
{
    double sum, atof(char[]);
    char line[MAXLINE];
    int mygetline(char line[], int max);

    sum = 0;
    while (mygetline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}