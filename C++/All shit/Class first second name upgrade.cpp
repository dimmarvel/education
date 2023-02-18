#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct FullName
{
    string Name;
    string Soname;
};
class Person
{
public:
    void ChangeFirstName(int year, const string& first_name)
    {
        if (YearNameSoname.count(year) == 0)
            YearNameSoname[year].Soname = "";
        YearNameSoname[year].Name = first_name;
    }
    void ChangeLastName(int year, const string& last_name)
    {
        if (YearNameSoname.count(year) == 0)
            YearNameSoname[year].Name = "";
        YearNameSoname[year].Soname = last_name;
    }
    string GetFullName(int year)
    {
        if (YearNameSoname.size() == 0)
        {
            return "Incognito";
        }
        else
        {
            for (const auto& i : YearNameSoname)
            {
                if (year < i.first)
                    return "Incognito";
                break;
            }
        }
        //иначе
        string nm = "";
        string sn = "";
        for (const auto& i : YearNameSoname)
        {

            if (i.first <= year && i.second.Soname != "")
                sn = i.second.Soname;
            if (i.first <= year && i.second.Name != "")
                nm = i.second.Name;
        }
        if (nm == "")
            return sn + " with unknown first name";
        else if (sn == "")
            return nm + " with unknown last name";
        else
            return nm + " " + sn;
    }
    string GetFullNameWithHistory(int year)
    {
        if (YearNameSoname.size() == 0)
        {
            return "Incognito";
        }
        else
        {
            for (const auto& i : YearNameSoname)
            {
                if (year < i.first)
                    return "Incognito";
                break;
            }
        }

        string nm = "";
        string sn = "";
        vector<string> secondnames;
        vector<string> firstnames;
        for (const auto& i : YearNameSoname)
        {

            if (i.first <= year && i.second.Soname != "")
            {
                if (i.second.Soname != sn && sn != "")
                {
                    secondnames.push_back(sn);
                }
                sn = i.second.Soname;
            }
            if (i.first <= year && i.second.Name != "")
            {
                if (i.second.Name != nm && nm != "")
                {
                    firstnames.push_back(nm);
                }
                nm = i.second.Name;
            }
        }
        string secnames_string = "", firstnames_string = "";
        if (secondnames.size() > 0)
        {
            secnames_string += " (" + secondnames[secondnames.size() - 1];
            if (secondnames.size() > 1)
            {
                for (int i = secondnames.size() - 1; i > 0; --i)
                {
                    secnames_string += ", " + secondnames[i - 1];
                }
            }
            secnames_string += ")";
        }
        if (firstnames.size() > 0)
        {
            firstnames_string += " (" + firstnames[firstnames.size() - 1];
            if (firstnames.size() > 1)
            {
                for (int i = firstnames.size() - 1; i > 0; --i)
                {
                    firstnames_string += ", " + firstnames[i - 1];
                }
            }
            firstnames_string += ")";
        }

        if (nm == "")
            return sn + secnames_string + " with unknown first name";
        else if (sn == "")
            return nm + firstnames_string + " with unknown last name";
        else
            return nm + firstnames_string + " " + sn + secnames_string;
    }

private:
    map<int, FullName> YearNameSoname;
};

int main()
{
    Person person;

    person.ChangeFirstName(1900, "Eugene");
    person.ChangeLastName(1900, "Sokolov");
    person.ChangeLastName(1910, "Sokolov");
    person.ChangeFirstName(1920, "Evgeny");
    person.ChangeLastName(1930, "Sokolov");
    cout << person.GetFullNameWithHistory(1940) << endl;

    return 0;
}