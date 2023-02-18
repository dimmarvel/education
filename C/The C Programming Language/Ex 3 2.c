#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void escape(char s[], char t[])
{
    int i = 0;
    int j = 0;

    while ((s[j] = t[i]) != '\0')
    {
        switch (s[j])
        {
        case '\n':
            s[j++] = '\\';
            s[j] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j] = 't';
            break;
        }
        i++;
        j++;
    }
}

void escape_reverse(char s[], char t[])
{
    int i = 0;
    int j = 0;

    while (s[j] != '\0')
    {
        if (t[i] == '\\')
        {
            switch (t[i + 1])
            {
            case 'n':
                s[j] = '\n';
                break;
            case 't':
                s[j] = '\t';
                break;
            }
        }
        else
        {
            s[j] = t[i];
        }
        i++;
        j++;
    }
}

main()
{
    char s[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'w', 'w', 's', 'd', '\0'};
    char t[] = {'a', 's', '\t', 'f', '\n', 'h', 'j', '\0'};

    printf("escape default\n");
    printf("str1 = %s\n", s);
    printf("str2 = %s\n", t);

    escape(s, t);

    printf("str1 = %s\n", s);
    printf("str2 = %s\n\n", t);

    char s1[] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'w', 'w', 's', 'd', '\0'};
    char t1[] = {'a', 's', '\\', 't', '\\', 'n', 'j', '\0'};

    printf("escape reversed\n");
    printf("str1 = %s\n", s1);
    printf("str2 = %s\n", t1);

    escape_reverse(s1, t1);

    printf("str1 = %s\n", s1);
    printf("str2 = %s\n", t1);
    system("pause");
    return 0;
}