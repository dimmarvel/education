#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");

    char operaciya, division = '/', pluse = '+', minus = '-';
    double otvet, perem1, perem2;
    bool y = true;

    while (y)
    {

        cout << "Введите первый операнд, операцию и второй операнд" << endl;
        cin >> perem1 >> operaciya >> perem2;

        switch (operaciya)
        {
        case '+':
            otvet = perem1 + perem2;
            cout << "Ответ: " << otvet << endl;
            break;
        case '-':
            otvet = perem1 - perem2;
            cout << "Ответ: " << otvet << endl;
            break;
        case '/':
            otvet = perem1 / perem2;
            cout << "Ответ: " << otvet << endl;
            break;
        default:
            cout << "Неверно попробуйте еще" << endl;
        }

        cout << "Хотите выполнить ещё одну операцию(у/n)?" << endl;

        char yn;
        cin >> yn;

        if (yn == 'n')
        {
            y = false;
            cout << "End work programm.";
        }
    }
    cout << endl;
    system("Pause");
}