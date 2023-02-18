//функция возводит число в степень
#include <iostream>
using namespace std;
class date
{
private:
    int day;
    int month;
    int year;

public:
    date() : day(0), month(0), year(0) {}
    void getdate()
    {
        char h;
        cin >> month >> h >> day >> h >> year;
    }
    void showdate() const { cout << month << "/" << day << "/" << year; }
};
int main()
{
    setlocale(LC_ALL, "Rus");
    date date1;
    date1.getdate();
    date1.showdate();
    cout << endl;
    system("pause");
}
