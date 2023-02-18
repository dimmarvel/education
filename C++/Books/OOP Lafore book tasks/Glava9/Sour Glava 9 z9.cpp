#include <iostream>
#include <string>
using namespace std;
class Publication
{
private:
    string Name;
    float Price;

public:
    Publication() : Price(0), Name("N\A") {}
    Publication(string q, float p) : Price(p), Name(q) {}

    void getdata()
    {
        cout << "\n¬ведите Name: ";
        cin >> Name;
        cout << "¬ведите Price: ";
        cin >> Price;
    }

    void showdata() const
    {
        cout << "\nName: " << Name;
        cout << "\nPrice: " << Price << endl;
    }
};
class Publication2 : public Publication
{
protected:
    int day;
    int month;
    int year;

public:
    Publication2(string q, float p) : Publication(q, p) {}
    Publication2() : day(0), month(0), year(0) {}

    void getdate()
    {
        Publication::getdata();
        char h;
        cout << "Input month/day/year ";
        cin >> month >> h >> day >> h >> year;
    }
    void showdate() const
    {
        Publication::showdata();
        cout << "Date: " << month << "/" << day << "/" << year;
    }
};
class book : public Publication2
{
private:
    int Pages;

public:
    book() : Pages(0) {}
    book(int p) : Pages(p) {}

    void getdata()
    {
        Publication2::getdate();
        cout << "¬ведите pages: ";
        cin >> Pages;
    }

    void showdata()
    {
        Publication2::showdate();
        cout << "\nPages: " << Pages;
    }
};
class type : public Publication2
{
private:
    float time;

public:
    type() : time(0) {}
    type(float z) : time(z) {}

    void getdata()
    {
        Publication2::getdate();
        cout << "¬ведите time: ";
        cin >> time;
    }

    void showdata()
    {
        Publication2::showdate();
        cout << "\nTime: " << time;
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    type t;
    book b;
    t.getdata();
    b.getdata();
    t.showdata();
    cout << endl;
    b.showdata();
    cout << endl;

    cout << endl;
    system("pause");
    return 0;
}
