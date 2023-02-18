#include <iostream>
using namespace std;

class employ
{
private:
    int numberemploy;
    float price;

public:
    employ() : numberemploy(0), price(0) {}
    employ(int numempl, float prce) : numberemploy(numempl), price(prce) {}
    void getData()
    {
        cin >> numberemploy;
        cin >> price;
    }
    void show() const
    {
        cout << "Empl" << endl;
        cout << "Number " << numberemploy << endl;
        cout << "Price " << price << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    employ empl1;
    employ empl2;
    employ empl3;

    cout << "Input number and price data of 3 empl 1" << endl;
    empl1.getData();
    cout << "Input number and price data of 3 empl 2" << endl;
    empl2.getData();
    cout << "Input number and price data of 3 empl 3" << endl;
    empl3.getData();

    cout << "        Data of employ:" << endl;
    empl1.show();
    empl2.show();
    empl3.show();

    cout << endl;
    system("Pause");
}