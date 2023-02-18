#include <math.h>
#include <stdio.h>

#define LEN 100

void itoa(int n, char s[]);

int main()
{
    int n;
    char s[] = "123";
    printf("%s", s);
    itoa(3, s);
    printf("%s", s);
    system("pause");
    return 0;
}

void itoa(int n, char s[])
{
    static int i;
    int sign = n;
    i = 0;

    if (n / 10)
    {
        itoa(n / 10, s);
    }
    else
    {
        if (sign < 0)
        {
            s[i++] = '-';
        }
    }

    s[i++] = abs(n % 10) + '0';
    s[i] = '\0';
}