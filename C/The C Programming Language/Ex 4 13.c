#include <math.h>
#include <stdio.h>
#include <string.h>

#define LEN 100

void reverse(char s[]);

int main()
{
    int n;
    char s[] = "123";
    printf("%s", s);
    reverse(s);
    printf("%s", s);
    system("pause");
    return 0;
}

void reverse(char s[])
{
    char temp;
    static int i = 0;
    int j = strlen(s) - (i + 1);

    if (i < j)
    {
        temp = s[i];
        s[i++] = s[j];
        s[j] = temp;
        reverse(s);
    }
}