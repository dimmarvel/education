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

    auto res = remove(v.begin(), v.end(), 12);

    v.erase(res, v.end());

    vector<Person> pers = {Person("Grisha", 10), Person("Mosha", 20), Person("Gosha", 42), Person("Catua", 12),
                           Person("Kriss", 52),  Person("Dima", 40),  Person("Dima", 41),  Person("Fucker", 24)};

    pers.erase(remove_if(pers.begin(), pers.end(), [](const Person& p) { return p.score < 40; }), pers.end());

    for (auto elem : pers)
    {
        cout << "Name\t" << elem.name << "\tscore:\t" << elem.score << endl;
    }
    cout << "----------------------------------------" << endl;

    string text = "Here you see some text";
    cout << text << endl;

    text.erase(remove(text.begin(), text.end(), 't'), text.end());

    cout << text << endl;

    system("Pause");
}