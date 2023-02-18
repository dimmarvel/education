#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct last_first
{
    string first_name;
    string last_name;
};

class Person
{
public:
    void ChangeFirstName(int year, const string& first_name)
    {
        // добавить факт изменения имени на first_name в год year
        if (data.count(year) == 0)
            data[year].last_name = "";
        data[year].first_name = first_name;
    }

    void ChangeLastName(int year, const string& last_name)
    {
        if (data.count(year) == 0)
            data[year].first_name = "";
        data[year].last_name = last_name;
    }

    string GetFullName(int year)
    {
        // получить имя и фамилию по состоянию на конец года year
        const auto& it = data.find(year);
        if (data.empty())
        {
            return "Incognito";
        }
        else
        {
            for (const auto& i : data)
            {
                if (year < i.first)
                    return "Incognito";
                break;
            }
        }

        string nm = "";
        string sn = "";

        for (const auto& i : data)
        {

            if (i.first <= year && i.second.last_name != "")
                sn = i.second.last_name;

            if (i.first <= year && i.second.first_name != "")
                nm = i.second.first_name;
        }
        if (nm == "")
            return sn + " with unknown first name";
        else if (sn == "")
            return nm + " with unknown last name";
        else
            return nm + " " + sn;
    }

private:
    // приватные поля
    map<int, last_first> data;
};

int main()
{
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990})
    {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970})
    {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970})
    {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}