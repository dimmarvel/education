#include <iostream>
#include <string.h>

using namespace std;

char* cat(char* p1, char* p2)
{
    int sum_size = strlen(p1) + strlen(p2);
    char* result = new char(sum_size);
    int resi = 0;
    for (int i = 0; i < strlen(p1); i++)
    {
        result[resi++] = p1[i];
    }
    for (int i = 0; i < strlen(p2); i++)
    {
        result[resi++] = p2[i];
    }
    return result;
}

void rev(char* p)
{
    char* str = new char(strlen(p));
    for (int i = strlen(p) - 1, j = 0; i >= 0; i--, j++)
    {
        str[j] = p[i];
    }
    strcpy(p, str);
}
int main()
{
    char str1[4] = "qwe";
    char str2[4] = "asd";
    char* p = cat(str1, str2);
    cout << p;
    rev(p);
    cout << "\nrev = " << p;
    return 0;
}
