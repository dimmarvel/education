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

void Etypfunction()
{
    etyp TYPES;
    setlocale(LC_ALL, "Rus"); // 0      1          2         3         4           5
    cout << "Input first letter position (laborer, secretary, manager, accountant, executive, researcher) \n";
    TYPES = laborer;
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

    cout << endl;
    system("Pause");
}