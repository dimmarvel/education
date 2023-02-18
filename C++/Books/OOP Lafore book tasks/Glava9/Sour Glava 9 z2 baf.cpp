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
private:
    int Pages;

public:
    Pstring() : String() {}
    Pstring(char s[]);
};

Pstring::Pstring(char s[])
{
    if (strlen(s) > SZ - 1)
    {
        for (int i = 0; i < SZ - 1; i++)
        {
            str[i] == s[i];
            str[i] == '\0';
        }
    }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    Pstring s1 = "This so much-much longer string wich maby, no, sure -- more then size locked SZ. qwqwqwqw";
    s1.display();

    cout << endl;
    system("pause");
    return 0;
}
