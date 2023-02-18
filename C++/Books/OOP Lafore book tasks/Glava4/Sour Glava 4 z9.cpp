#include <iostream>
using namespace std;

struct time
{
    int hours;
    int min;
    int sec;
};

int main()
{
    setlocale(LC_ALL, "Rus");
    time t1;
    cout << "Input hours\min\sec " << endl;
    cin >> t1.hours >> t1.min >> t1.sec;

    long total = t1.hours * 3600 + t1.min * 60 + t1.sec;
    cout << "Total SEC = " << total;

    cout << endl;
    system("Pause");
}