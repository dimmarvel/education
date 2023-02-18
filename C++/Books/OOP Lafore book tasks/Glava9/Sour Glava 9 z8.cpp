#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;
class String
{
protected:
    enum
    {
        SZ = 80
    };
    char str[SZ];

public:
    String() { str[0] == '\0'; }
    String(char s[]) { strcpy(str, s); }

    void display() const { cout << str; }
    operator char*() { return str; }
};
class Pstring : public String
{
public:
    Pstring(const char s[]);
    Pstring() : String() {}
};
Pstring::Pstring(const char s[])
{
    if (strlen(s) > SZ - 1)
    {
        int i = 0;
        for (; i < SZ - 1; i++)
        {
            str[i] = s[i];
        }
        str[i] = '\0';
    }
}

class Pstring2 : public Pstring
{
private:
    char mass[SZ];

public:
    Pstring2() : Pstring()
    {
        for (int i = 0; i < strlen(str); i++)
        {
            mass[i] = str[i];
        }
    }
    void left(const char s[], int n) // s из какой строки, n скока символов
    {
        if (n < SZ - 1)
        {
            int i = 0;
            for (; i <= n; i++)
            {
                mass[strlen(mass) + 1] = s[i];
            }
            mass[i] = '\0';
        }
    }
};
int main()
{
    // setlocale(LC_ALL, "En");
    Pstring s1 = "This so much-much longer string wich maby, no, sure -- more then size locked SZ. qwqwqwqw";
    Pstring2 s2 = "This string";
    s1.display();
    s2.String::display();
    cout << endl;
    system("pause");
    return 0;
}
