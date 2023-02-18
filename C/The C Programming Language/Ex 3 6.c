#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LEN 100

void itoa(int n, char s[], int w);
void reverse(char s[]);
int abs(int x);

int main()
{
    int n, w;
    char s[LEN];

    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Enter the field width: ");
    scanf("%d", &w);
    itoa(n, s, w);
    printf("%s", s);
    printf("\n");
    return 0;
}

/*itoa*/
void itoa(int n, char s[], int w)
{
    int i, sign;

    sign = n; //сохраняем знак
    i = 0;
    do //генерируем цифры в обратном порядке
    {
        s[i] = abs(n % 10) + '0'; //следующая цифра
        i++;
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    while ((i + 1) <= w) //дополняем пробелами
        s[i++] = '|';    //для наглядности вместо пробелов '|'
    s[i] = '\0';
    reverse(s);
}

/*reverse*/
void reverse(char s[])
{
    int i, j;
    char c;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/*abs*/
int abs(int x) { return ((x) < 0 ? -(x) : (x)); }
