#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXLINE 1000 // ������������ ������ �������� ������

int strleng(char l[]);
void copy(char to[], char from[]);

/*������ ����� ������� ������*/
main()
{

    int len = 0;        //����� ������� ������
    char line[MAXLINE]; //������� ������
    int c;

    while ((c = getchar()) != EOF)
    {
        line[len] = c;
        if (line[len] == '\t')
            for (int i = 0; i < 4; i++)
                line[len++] = ' ';
        else
            len++;
    }
    line[len + 1] = '\0';
    printf("%s", line);
    system("pause");
}

/*getlin ������ ������ � s, ���������� �����*/
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