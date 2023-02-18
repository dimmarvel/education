#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    float startvklad;
    float years;
    float prosent;
    cout << "¬ведите начальный вклад:";
    cin >> startvklad;
    cout << "¬ведите число лет:";
    cin >> years;
    cout << "¬ведите процентную ставку:";
    cin >> prosent;
    prosent = prosent / 100;

    for (int i = 0; i < years; i++)
    {
        startvklad = startvklad + (startvklad * prosent);
    }

    cout << "„ерез " << years << "лет вы получите  = " << startvklad;

    cout << endl;
    system("Pause");
}