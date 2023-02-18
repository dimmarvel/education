#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    double C;
    double res;
    cout << "Введите температуру по Цельсию: ";
    cin >> C;
    res = C * (9 / 5) + 32;
    cout << "По фаренгейту: " << res;

    system("pause");
}