#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void expand1(char s1[], char s2[])
{
    char temp[100];
    int i = 0;
    int k = 0;
    while (s2[i] != '\0')
    {
        if (s2[i + 1] == '-')
        {
            for (int j = s2[i]; j <= s2[i + 2]; j++)
            {
                temp[k++] = j;
            }
            i += 2;
        }
        else
        {
            i++;
        }
    }
    temp[k] = '\0';
    strcpy(s1, temp);
}
main()
{
    char s[] = {'a', '-', 'y', 'a', '-', 'f', '\0'};
    char t[100];
    expand1(t, s);
    printf("%s", t);
    system("pause");
    return 0;
}