#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXLINE 1000 // максимальный размер вводимой строки

int getlin(char line[], int MAX);
void copy(char to[], char from[]);
void revers(char str[]);

/*печать самой длинной строки*/
main()
{
	
	int len; //длина текущей строки
	int max; //длина максимальной из просмотренных строк
	char line[MAXLINE]; //текущая строка
	char longest[MAXLINE]; //самая длинная строка
	int c;

	max = 0;
	while ((len = getlin(line, MAXLINE)) > 0)
	{
		if (line[len - 1] != '\n')
			while ((c = getchar()) != EOF && c != '\n')
				len++;
		
		revers(line);
	}
	system("pause");
}

/*getlin читает строку в s, возвращает длину*/
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

void revers(char str[]) {
	char temp[MAXLINE];
	int len = 0;
	while (str[len] != '\0') len++;

	for (int i = len; i >= 0; i--)
	{
		printf("%c", str[i]);
	}

}