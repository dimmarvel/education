#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    unsigned int numb = 1;
    unsigned long fact = 1;

    while (numb != 0)
    {

        cout << "¬ведите целое число" << endl;
        cin >> numb;

        for (int j = numb; j > 0; j--)
        {
            fact *= j;
        }

        if (numb != 0)
        {
            cout << "Fact = " << fact << endl;
        }
    }
    cout << "вы ввели 0 поки поки.";

    cout << endl;
    system("Pause");
}