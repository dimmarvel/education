#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LEN 100

int strrindex(char s[], char t[]);

int main()
{
    int n, w;
    char s[] = {'q', 'w', 'e', 'a', 's', 'd', 'q', 'w', 'a', 's', 'd', 'a', '\0'};
    char t[] = {'a', 's', 'd', '\0'};

    printf("%d", strrindex(s, t));
    printf("\n");
    return 0;
}

int strrindex(char s[], char t[])
{
    int i = 0;
    int k = 0; //итерация по s для проверки есть ли слово t
    int entry = -1;

    while (s[i] != '\0')
    {
        if (s[i] == t[0])
        {
            int tWordIns = 1;
            int r = 0; //итерация по t
            k = i;

            do
            {
                if (s[k] != t[r])
                {
                    tWordIns = 0;
                    break;
                }

            } while (t[++r] != '\0' && s[++k] != '\0');

            if (tWordIns && s[k] != '\0')
            {
                entry = i;
            }
        }
        i++;
    }
    return entry;
}