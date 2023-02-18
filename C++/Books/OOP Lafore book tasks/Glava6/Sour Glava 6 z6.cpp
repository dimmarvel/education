#include <iostream>
using namespace std;
enum etyp
{
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};
class employ
{
private:
    int numberemploy;
    float price;
    int day;
    int month;
    int year;
    etyp TYPES;

public:
    employ(int numempl, float prce) : numberemploy(numempl), price(prce) {}
    employ() : day(0), month(0), year(0), numberemploy(0), price(0), TYPES(laborer) {}
    void getinfo()
    {
        cout << "Input numberempoly: ";
        cin >> numberemploy;
        cout << "Input price: ";
        cin >> price;
        cout << "Input date: **/**/** ";
        char h;
        cin >> month >> h >> day >> h >> year;
        cout << "Input first letter position (laborer, secretary, manager, accountant, executive, researcher) \n";
        char ltr;
        cin >> ltr;
        switch (ltr)
        {
        case 'l':
        {
            TYPES = laborer;
            break;
        }
        case 's':
        {
            TYPES = secretary;
            break;
        }
        case 'm':
        {
            TYPES = manager;
            break;
        }
        case 'a':
        {
            TYPES = accountant;
            break;
        }
        case 'e':
        {
            TYPES = executive;
            break;
        }
        case 'r':
        {
            TYPES = researcher;
            break;
        }
        }
    }
    void showinfo() const
    {
        for (int i = 1; i > 30; i++)
        {
            if (i % 2 == 0)
            {
                cout << "*";
            }
            else
            {
                cout << "-";
            }
        }
        cout << "Number " << numberemploy << endl;
        cout << "Price " << price << endl;
        cout << month << "/" << day << "/" << year << endl;
        cout << "Etupe:\n";
        switch (TYPES)
        {
        case laborer:
        {
            cout << "Position: "
                 << "laborer" << endl;
            break;
        }
        case secretary:
        {
            cout << "Position: "
                 << "secretary" << endl;
            break;
        }
        case 2:
        {
            cout << "Position: "
                 << "manager" << endl;
            break;
        }
        case 3:
        {
            cout << "Position: "
                 << "accountant" << endl;
            break;
        }
        case 4:
        {
            cout << "Position: "
                 << "executive" << endl;
            break;
        }
        case 5:
        {
            cout << "Position: "
                 << "researcher" << endl;
            break;
        }
        }
    }
};
int main()
{
    setlocale(LC_ALL, "Rus");
    employ empl1;
    employ empl2;
    employ empl3;
    empl1.getinfo();
    empl2.getinfo();
    empl3.getinfo();
    cout << "        Data of employ:" << endl;
    empl1.showinfo();
    empl2.showinfo();
    empl3.showinfo();
    cout << endl;
    system("Pause");
}