#include <iostream>
#include <string.h>

using namespace std;

size_t mstrlen(const char* s)
{
    size_t i = 0;
    while (s[i++] != '\0')
        ;
    return i;
}

char* mstrcpy(char* s1, const char* s2)
{
    if (strlen(s1) <= strlen(s2))
    {
        while (*s1 != '\0')
        {
            *s1 = *s2;
            s1++;
            s2++;
        }
        return s1;
    }
    else
    {
        return NULL;
    }
}

int mstrcmp(const char* s1, const char* s2)
{
    if (strlen(s1) == strlen(s2))
    {
        for (size_t i = 0; i <= strlen(s1); i++)
        {
            if (*s1 != *s2)
                return 0;
            s1++;
            s2++;
        }
        return 1;
    }
    else
        return 0;
}

int main()
{
    char a[6] = "qweas";
    char b[6] = "qweas";
    char c[6] = "qweac";
    cout << "a: " << mstrlen(a) << " b:" << mstrlen(b) << endl;
    cout << "strcmp " << mstrcmp(a, b) << endl;
    cout << "mstrcpy " << a << "(a) in " << c << "(c) c = " << strcpy(c, a) << endl;
    return 0;
}
