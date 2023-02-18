#include <iostream>
using namespace std;
// Номер телефона 165стр
struct phone
{
    int countrycod;
    int numberstation;
    int numberhuman;
};

int main()
{
    phone ph1 = {212, 767, 8900};
    phone ph2;
    setlocale(LC_ALL, "Rus");
    cout << "Input cod of country, cod of station and number abonent.\n";
    cin >> ph2.countrycod >> ph2.numberhuman >> ph2.numberstation;
    cout << "My number: "
         << "(" << ph1.countrycod << ") " << ph1.numberhuman << "-" << ph1.numberstation << endl;
    cout << "Your number: "
         << "(" << ph2.countrycod << ") " << ph2.numberhuman << "-" << ph2.numberstation << endl;

    cout << endl;
    system("Pause");
}