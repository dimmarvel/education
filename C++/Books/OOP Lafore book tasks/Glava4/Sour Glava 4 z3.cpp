#include <iostream>
using namespace std;
struct Distance
{
    int feet;
    float inches;
};
struct volume
{
    Distance length;
    Distance width;
    Distance height;
};

int main()
{
    float l, w, h;
    setlocale(LC_ALL, "Rus");
    volume room1 = {{16, 3.5}, {12, 6.25}, {8, 1.75}};
    l = room1.length.feet + room1.length.inches / 12;
    w = room1.width.feet + room1.width.inches / 12;
    h = room1.height.feet + room1.height.inches / 12;
    cout << "l = " << l << "\n";
    cout << "w = " << w << "\n";
    cout << "h = " << h << "\n";
    cout << "V = " << l * w * h;

    cout << endl;
    system("Pause");
}