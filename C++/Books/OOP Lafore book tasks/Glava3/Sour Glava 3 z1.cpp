#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    unsigned long n;
    cout << "¬ведите число: ";
    cin >> n;
    for (int j = 1; j <= 200; j++)
    {
        cout << setw(5) << j * n << " | ";
        if (j % 10 == 0)
        {
            cout << endl;
        }
    }

    system("Pause");
}