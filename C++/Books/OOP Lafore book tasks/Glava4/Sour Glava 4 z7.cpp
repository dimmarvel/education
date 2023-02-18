#include <iostream>
using namespace std;

enum etype
{
    laborer,
    secretary,
    manager,
    accountant,
    executive,
    researcher
};

struct employ
{
    int numberemploy;
    float price;
    int day;
    int month;
    int year;
    etype TYPE;
};
employ empl1;
employ empl2;
employ empl3;
etype TYPES;

int main()
{
    //------------------------------------------------------Employfunction

    cout << "Input number and price data of 3 empl 1" << endl;
    cin >> empl1.numberemploy >> empl1.price;
    cout << "Input number and price data of 3 empl 2" << endl;
    cin >> empl2.numberemploy >> empl2.price;
    cout << "Input number and price data of 3 empl 3" << endl;
    cin >> empl3.numberemploy >> empl3.price;
    cout << endl;
    //------------------------------------------------------Datefunction
    cout << "DATE OF INPUT ON COMPANY" << endl;
    cout << "One: ";
    cin >> empl1.day >> empl1.month >> empl1.year;
    cout << "two: ";
    cin >> empl2.day >> empl2.month >> empl2.year;
    cout << "three: ";
    cin >> empl3.day >> empl3.month >> empl3.year;
    cout << endl;

    //------------------------------------------------------Typefunction
    cout << "1 Input first letter position (laborer, secretary, manager, accountant, executive, researcher) \n";
    char ltr;
    cin >> ltr;

    switch (ltr)
    {
    case 'l':
    {
        empl1.TYPE = laborer;
        break;
    }
    case 's':
    {
        empl1.TYPE = secretary;
        break;
    }
    case 'm':
    {
        empl1.TYPE = manager;
        break;
    }
    case 'a':
    {
        empl1.TYPE = accountant;
        break;
    }
    case 'e':
    {
        empl1.TYPE = executive;
        break;
    }
    case 'r':
    {
        empl1.TYPE = researcher;
        break;
    }
    }

    cout << "2 Input first letter position (laborer, secretary, manager, accountant, executive, researcher) \n";
    cin >> ltr;
    switch (ltr)
    {
    case 'l':
    {
        empl2.TYPE = laborer;
        break;
    }
    case 's':
    {
        empl2.TYPE = secretary;
        break;
    }
    case 'm':
    {
        empl2.TYPE = manager;
        break;
    }
    case 'a':
    {
        empl2.TYPE = accountant;
        break;
    }
    case 'e':
    {
        empl2.TYPE = executive;
        break;
    }
    case 'r':
    {
        empl2.TYPE = researcher;
        break;
    }
    }

    cout << "3 Input first letter position (laborer, secretary, manager, accountant, executive, researcher) \n";
    cin >> ltr;
    switch (ltr)
    {
    case 'l':
    {
        empl3.TYPE = laborer;
        break;
    }
    case 's':
    {
        empl3.TYPE = secretary;
        break;
    }
    case 'm':
    {
        empl3.TYPE = manager;
        break;
    }
    case 'a':
    {
        empl3.TYPE = accountant;
        break;
    }
    case 'e':
    {
        empl3.TYPE = executive;
        break;
    }
    case 'r':
    {
        empl3.TYPE = researcher;
        break;
    }
    }

    //------------------------------------------------------
    cout << endl;
    cout << endl;
    cout << "                       INFO:" << endl;
    cout << "¹ " << empl1.numberemploy << endl;
    cout << "Him price: " << empl1.price << endl;
    cout << "Him type: " << empl1.TYPE << endl;
    switch (empl1.TYPE)
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
    cout << "Him date:: " << empl1.day << "/" << empl1.month << "/" << empl1.year << endl;

    cout << "¹ " << empl2.numberemploy << endl;
    cout << "Him price: " << empl2.price << endl;
    switch (empl2.TYPE)
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
    cout << "Him date: " << empl2.day << "/" << empl2.month << "/" << empl2.year << endl;

    cout << "¹ " << empl3.numberemploy << endl;
    cout << "Him price: " << empl3.price << endl;
    switch (empl3.TYPE)
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
    cout << "Him date: " << empl3.day << "/" << empl3.month << "/" << empl3.year << endl;
    cout << endl;
    system("Pause");
}