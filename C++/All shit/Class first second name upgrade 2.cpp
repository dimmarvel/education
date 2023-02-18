#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct FullName
{ //создадим структуру из имени и фамилии
    string Name;
    string Soname;
};
class Person
{
public:
    Person(const string& first_name, const string& last_name, int year)
    {
        YearNameSoname[year] = {first_name, last_name};
        birth_year = year;
        for (auto& i : YearNameSoname)
        {
            if (i.first < year)
                YearNameSoname.erase(i.first);
        }
    }
    void ChangeFirstName(int year, const string& first_name)
    {
        for (auto& i : YearNameSoname)
        {
            if (year > i.first)
            {
                if (YearNameSoname.count(year) == 0)
                    YearNameSoname[year].Soname = "";   //если такого года еще нет, то добавим пустую фамилию
                YearNameSoname[year].Name = first_name; //добавим указанное имя
            }
            break; //сразу выходим
        }
    }
    void ChangeLastName(int year, const string& last_name)
    {
        for (auto& i : YearNameSoname)
        {
            if (year > i.first)
            {
                if (YearNameSoname.count(year) == 0)
                    YearNameSoname[year].Name = "";      //если такого года еще нет, то добавим пустое имя
                YearNameSoname[year].Soname = last_name; //и добавим указанную фамилию
            }
            break; //сразу выходим
        }
    }
    string GetFullName(int year) const
    {
        if (birth_year != 0 && year < birth_year)
            return "No person";
        else if (YearNameSoname.size() == 0)
        {                       //если размер = 0
            return "Incognito"; //выводим Инкогнито
        }
        else
        {
            for (const auto& i : YearNameSoname)
            {
                if (year < i.first)
                    return "Incognito"; //если искомый год меньше первого года изменения, выводим Инкогнито
                break;                  //сразу выходим из цикла
            }
        }
        //иначе
        string nm = "";
        string sn = "";
        for (const auto& i : YearNameSoname)
        { //полистаем нашу структуру
          //и будем присваивать переменной sn значение фамилии, если она не пустая и пока искомый год больше текущего(в
          //структуре)
            if (i.first <= year && i.second.Soname != "")
                sn = i.second.Soname;
            if (i.first <= year && i.second.Name != "")
                nm = i.second.Name; //тоже самое с именем
        }
        if (nm == "")
            return sn + " with unknown first name"; //условие, если имя пустое(вывод фамилии и текста)
        else if (sn == "")
            return nm + " with unknown last name"; //условие, если фамилия пуста (вывод имени и текста)
        else
            return nm + " " + sn; //вывод имени и фамилии
    }
    string GetFullNameWithHistory(int year) const
    {
        if (birth_year != 0 && year < birth_year)
            return "No person";
        else if (YearNameSoname.size() == 0)
        {                       //если размер = 0
            return "Incognito"; //выводим Инкогнито
        }
        else
        {
            for (const auto& i : YearNameSoname)
            {
                if (year < i.first)
                    return "Incognito"; //если искомый год меньше первого года изменения, выводим Инкогнито
                break;                  //сразу выходим из цикла
            }
        }
        //иначе
        string nm = "";
        string sn = "";
        vector<string> secondnames; //вектор предыдущих фамилий
        vector<string> firstnames;  //вектор предыдущих имен
        for (const auto& i : YearNameSoname)
        { //полистаем нашу структуру
          //и будем присваивать переменной sn значение фамилии, если она не пустая и пока искомый год больше текущего(в
          //структуре)
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
        //инициализируем переменные в которые будем складывать фамилии и имена в обратном порядке
        string secnames_string = "", firstnames_string = "";
        if (secondnames.size() > 0)
        { //если вектор с фамилиями не пуст, то
            secnames_string +=
                " (" + secondnames[secondnames.size() - 1]; //добавим в строку пробел, скобку и предыдущую фамилию
            if (secondnames.size() > 1)
            {
                for (int i = secondnames.size() - 1; i > 0; --i)
                {                                                 //в обратном порядке
                    secnames_string += ", " + secondnames[i - 1]; // добавим в строку остальные фамилии
                }
            }
            secnames_string += ")"; //закроем строку скобкой
        }
        //аналогично с именами
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

private:                               //объявим в приватной секции
    map<int, FullName> YearNameSoname; //структуру с годом и полным именем
    int birth_year = 0;
};