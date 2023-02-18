#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int any(char str1[], char str2[])
{
    for (int i = 0; i < strlen(str1); i++)
    {
        for (int j = 0; j < strlen(str2); j++)
        {
            if (str1[i] == str2[j])
                return i;
        }
    }
    return -1;
}

main()
{
    char str1[] = "qweasdzxc";
    char str2[] = "asdc";

    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("First symb from str2 in str1 in pos: %d\n", any(str1, str2));
    system("pause");
}