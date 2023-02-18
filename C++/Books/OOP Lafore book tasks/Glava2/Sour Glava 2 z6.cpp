#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    double Doll = 1.487, Frank = 0.172, GermanyMark = 0.584, Yena = 0.00955;
    double funt;
    cout << "Введите количество фунтов: ";
    cin >> funt;
    cout << "Цена за 1 фунт." << endl;
    cout << "В Долларах: " << funt * Doll << "$" << endl;
    cout << "В Франках: " << funt * Frank << "$" << endl;
    cout << "В Немецких марок: " << funt * GermanyMark << "$" << endl;
    cout << "В Японский йенах: " << funt * Yena << "$" << endl;
    system("pause");
}