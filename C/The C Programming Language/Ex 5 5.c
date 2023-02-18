#include <stdio.h>

void strncpy(char*, char*, int);
void strncat(char*, char*, int);
short int strncmp(char* s, char* t, int n);

main()
{
    char str1[13] = "some";
    char str2[5] = "strw";
    strncpy(str1, str2, 1);
    printf("%s\n", str1);
    strncat(str1, str2, 1);
    printf("%s\n", str1);
    printf("%d\n", strncmp(str1, str2, 1));
    system("pause");
}

void strncat(char* s, char* t, int n)
{
    while (*++s != '\0')
        ;

    int counter = 0;
    while ((*s++ = *t++) != '\0' && counter++ < n)
        ;
}

void strncpy(char* s, char* t, int n)
{
    int counter = 0;
    while ((*s++ = *t++) != '\0' && counter++ < n)
        ;
}

short int strncmp(char* s, char* t, int n)
{
    while (*s++ == *t++)
    {
        if (*s == '\0')
        {
            return 0;
        }
    }
    return *s - *t;
}