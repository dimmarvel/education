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

    vector<Person> pers = {Person("Grisha", 10), Person("Mosha", 20), Person("Gosha", 42), Person("Catua", 12),
                           Person("Kriss", 52),  Person("Dima", 40),  Person("Dima", 41),  Person("Fucker", 24)};
    for (auto elem : pers)
    {
        cout << "Name: \t" << elem.name << "\t score \t" << elem.score << endl;
    }
    cout << "--------------------------------" << endl;

    vector<Person> res;
    copy(pers.begin(), pers.end(), back_inserter(res));

    cout << "Size - " << res.size() << endl;

    for (auto elem : res)
    {
        cout << "Name: \t" << elem.name << "\t score \t" << elem.score << endl;
    }
    cout << "--------------------------------" << endl;

    vector<Person> res2;

    copy_if(pers.begin(), pers.end(), back_inserter(res2), [](const Person& p) { return p.score > 40; });

    for (auto elem : res2)
    {
        cout << "Name: \t" << elem.name << "\t score \t" << elem.score << endl;
    }

    system("Pause");
}