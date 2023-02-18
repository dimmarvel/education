#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXLINE 1000 // максимальный размер вводимой строки

int strleng(char l[]);
void copy(char to[], char from[]);

/*печать самой длинной строки*/
main()
{

    int len = 0;        //длина текущей строки
    char line[MAXLINE]; //текущая строка
    int c;

    int cSpace = 0;
    while ((c = getchar()) != EOF)
    {
        line[len] = c;
        if (line[len] == ' ')
        {
            cSpace++;
            if (cSpace == 7)
            {
                len -= 6;
                line[len] = '\t';
                cSpace = 0;
            }
        }
        else if (line[len] != ' ' && cSpace > 0)
        {
            len -= cSpace;
            while (cSpace > 0)
            {
                line[len++] = ' ';
                cSpace--;
            }
        }
        len++;
    }
    line[len + 1] = '\0';
    printf("%s", line);
    system("pause");
}

/*getlin читает строку в s, возвращает длину*/
int strleng(char s[])
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}