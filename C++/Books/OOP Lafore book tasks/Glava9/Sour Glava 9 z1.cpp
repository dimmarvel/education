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

    void showdata()
    {
        cout << "\nName: " << Name;
        cout << "\nPrice: " << Price;
    }
};
class book : public Publication
{
private:
    int Pages;

public:
    book() : Pages(0) {}
    book(int p) : Pages(p) {}

    void getdata()
    {
        Publication::getdata();
        cout << "¬ведите pages: ";
        cin >> Pages;
    }

    void showdata()
    {
        Publication::showdata();
        cout << "\nPages: " << Pages;
    }
};
class type : public Publication
{
private:
    float time;

public:
    type() : time(0) {}
    type(float z) : time(z) {}

    void getdata()
    {
        Publication::getdata();
        cout << "¬ведите time: ";
        cin >> time;
    }

    void showdata()
    {
        Publication::showdata();
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
    b.showdata();

    cout << endl;
    system("pause");
    return 0;
}
