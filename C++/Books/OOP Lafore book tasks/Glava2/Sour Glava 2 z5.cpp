#include <CTYPE.H>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "Если вы ввели букву c нижнем регистром то ответ будет > 0 и наоборот." << endl;
    char a;
    int b = 1;
    while (b > 0)
    {
        cin >> a;
        cout << islower(a) << endl;
    }
    system("pause");
}