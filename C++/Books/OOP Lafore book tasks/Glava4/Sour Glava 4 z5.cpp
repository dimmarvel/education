#include <iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

void Datefunction()
{

    setlocale(LC_ALL, "Rus");
    Date info;

    cin >> info.day >> info.month >> info.year;
    cout << info.day << "/" << info.month << "/" << info.year;

    cout << endl;
}