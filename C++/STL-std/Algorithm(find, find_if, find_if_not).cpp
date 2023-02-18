#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Person
{
public:
    Person(string name, double score)
    {
        this->name = name;
        this->score = score;
    }
    bool operator()(const Person& p) { return p.score > 100; }
    string name;
    double score;
};

int main()
{

    setlocale(LC_ALL, "Rus");
    vector<int> v = {1, 2, 4, 6, 7, 23, 32, 235, 12, 5};

    auto res = find(v.begin(), v.end(), 1);

    auto res2 = find_if(v.begin(), v.end(), [](int a) { return a % 2 != 0; });

    auto res3 = find_if_not(v.begin(), v.end(), [](int a) { return a % 2 != 0; }); // just inversion

    vector<Person> pers = {Person("Grisha", 10), Person("Mosha", 20), Person("Gosha", 42), Person("Catua", 12),
                           Person("Kriss", 52),  Person("Dima", 40),  Person("Fucker", 24)};
    for (auto elem : pers)
    {
        cout << "Name: \t" << elem.name << "\t score \t" << elem.score << endl;
    }
    cout << "--------------------------------" << endl;

    auto it = find_if(v.begin(), v.end(), [](Person const& a) { return (a.name == "Dima"); });

    if (it == pers.end())
        cout << "Is Not Here" << endl;
    else
        cout << "Is here" << endl;

    system("Pause");
}