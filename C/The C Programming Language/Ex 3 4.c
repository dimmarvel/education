#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LEN 100

void itoa(int n, char s[]);
void reverse(char s[]);
int abs(int x);

int main()
{
    int n;
    char s[LEN];

    printf("Enter the number: ");
    scanf("%d", &n);
    itoa(n, s);
    printf("%s", s);
    printf("\n");
    return 0;
}

void itoa(int n, char s[])
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
    s[i] = '\0';
    reverse(s);
}

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

int abs(int x) { return ((x) < 0 ? -(x) : (x)); }