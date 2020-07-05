#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define LEN 100

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
	int n, b;
	char s[LEN];

	printf("Enter the number n: ");
	scanf("%d", &n);
	printf("base b: ");
	scanf("%d", &b);
	itob(n, s, b);
	printf("%s", s);
	printf("\n");
	return 0;
}

void itob(int n, char s[], int b)
{
	int i, sign, c;

	sign = n;
	if (sign < 0)
	{
		n = -n;
	}

	i = 0;
	do 
	{
		c = (n % b);
		s[i++] = (c > 9) ? c + 'A' - 10 : c + '0';// к примеру 11
		n /= b;                            // 11 - 'A'(65) + 10 = 'B'(66) изи
	} while (n >= 1);
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
