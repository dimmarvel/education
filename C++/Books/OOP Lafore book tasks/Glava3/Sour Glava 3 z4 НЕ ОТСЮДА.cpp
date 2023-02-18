#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    double SUM, g;
    const double gallon = 7.481;
    cout << "1 галлон = 7,481" << endl;
    cout << "¬ведите число галлонов:";
    cin >> g;
    SUM = g / gallon;
    cout << "ќбъъем в кубических футах = " << SUM;

    cout << endl;
    system("Pause");
}