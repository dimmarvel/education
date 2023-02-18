#include <iostream>
using namespace std;

class fraction
{
private:
    int a, b;
    char h;

public:
    fraction() : a(0), b(0), h(' ') {}
    void get()
    {
        cout << "Введите дробь: ";
        cin >> a >> h >> b;
    }

    void showinfo(fraction obj1, float& a1, float& a2)
    {
        a1 = obj1.a * a;
        a2 = obj1.b * b;
        cout << "Сложение = " << a1 << "/" << a2 << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    float a1, a2;
    fraction drobl;
    fraction drobl1;
    drobl.get();
    drobl1.get();
    drobl1.showinfo(drobl, a1, a2);

    cout << endl;
    system("Pause");
}