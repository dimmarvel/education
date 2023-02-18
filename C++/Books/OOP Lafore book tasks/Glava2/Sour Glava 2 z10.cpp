#include <cmath> //Для функции ciel();
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    float F, SH, P;
    float newpens;
    // 1F = 20SH
    // 1SH = 12P
    cout << "Введите количество фунтов: ";
    cin >> F;
    cout << "Введите количество шиллингов: ";
    cin >> SH;
    cout << "Введите количество пенсов: ";
    cin >> P;
    newpens = (SH * 12 + P) / 2.4;
    //Функция ciel(переменная) используется для округления до целого числа
    cout << "Десятичных фунтов: "
         << "J" << F << "." << ceil(newpens) << endl;
    system("pause");
}