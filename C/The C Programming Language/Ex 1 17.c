#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXLINE 1000 // ������������ ������ �������� ������

int getlin(char line[], int MAX);
void copy(char to[], char from[]);

/*������ ����� ������� ������*/
main()
{

    int len;               //����� ������� ������
    int max;               //����� ������������ �� ������������� �����
    char line[MAXLINE];    //������� ������
    char longest[MAXLINE]; //����� ������� ������
    int c;

    max = 0;
    while ((len = getlin(line, MAXLINE)) > 0)
    {
        if (line[len - 1] != '\n')
            while ((c = getchar()) != EOF && c != '\n')
                len++;
        if (len > 80)
        {
            printf("%s\nLen - %d\n", line, len);
        }
    }
    system("pause");
}

/*getlin ������ ������ � s, ���������� �����*/
int getlin(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        i++;
}