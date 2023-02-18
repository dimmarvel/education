#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void squeeze(char str1[], char str2[])
{
    int k, i, j;

    for (k = 0; str2[k] != '\0'; k++)
    {
        for (i = j = 0; str1[i] != '\0'; i++)
            if (str1[i] != str2[k])
                str1[j++] = str1[i];
        str1[j] = '\0';
    }
}

main()
{
    char str1[] = "qweasdzxc";
    char str2[] = "asdc";
    squeeze(str1, str2);
    printf("%s\n", str1);
    printf("%s\n", str2);
    system("pause");
}