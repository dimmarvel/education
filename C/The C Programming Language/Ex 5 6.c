#include <math.h>
#include <stdio.h>

int getline(char s[], int lim);
int atoi(char s[]);
void reverse(char s[]);
char* strindex(char s[], char t[]);

main()
{
    char str[5] = "some";
    char str1[5] = "me";

    printf("atoi = %d\n", atoi(str1));
    printf("strindex = %s\n", strindex(str, str1));

    reverse(str);
    printf("Reverse = %s\n", str);

    printf("getline = %d\n", getline(str, 10));

    system("pause");
}

int getline(char s[], int lim)
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

int atoi(char s[])
{
    int n;
    n = 0;

    while (*s >= '0' && *s <= '9')
    {
        n = 10 * n + (*s - '0');
        s++;
    }

    return n;
}

void reverse(char s[])
{
    int c;
    char* start = s;
    char* end = s + strlen(s) - 1;

    while (start < end)
    {
        c = *start;
        *start = *end;
        *end = c;

        start++;
        end--;
    }
}

char* strindex(char s[], char t[])
{
    char* i;
    char* j;
    char* k;

    i = s;

    while (*i != '\0')
    {
        for (j = i, k = t; *k != '\0' && *j == *k; j++, k++)
            ;

        if (k > s && *k == '\0')
        {
            return i;
        }
        i++;
    }
    return 0;
}