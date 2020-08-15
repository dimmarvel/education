#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

//- добавление события : Add Дата Событие
//- удаление события : Del Дата Событие
//- удаление всех событий за конкретную дату : Del Дата
//- поиск событий за конкретную дату : Find Дата
//- печать всех событий за все даты : Print


class Date {
private:
	int year;
	int month;
	int day;
public:
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	void Input(istream& ifstr);
	void Out() const;
};

void Date::Input(istream& ifstr)
{
	if (ifstr)
	{
		ifstr >> year;
		ifstr.ignore(1);
		ifstr >> month;
		ifstr.ignore(1);
		ifstr >> day;
	}
}

void Date::Out() const
{
	cout << year << "-" << month << "-" << day;
}

int Date::GetDay() const
{
	return day;
}

int Date::GetMonth() const
{
	return month;
}

int Date::GetYear() const
{
	return year;
}


bool operator<(const Date& lhs, const Date& rhs)
{
	int d1 = lhs.GetDay() + lhs.GetMonth() * 31 + lhs.GetYear() * 365;
	int d2 = rhs.GetDay() + rhs.GetMonth() * 31 + rhs.GetYear() * 365;
	
	return d1 < d2;
}

bool operator>(const Date& lhs, const Date& rhs)
{
	int d1 = lhs.GetDay() + lhs.GetMonth() * 31 + lhs.GetYear() * 365;
	int d2 = rhs.GetDay() + rhs.GetMonth() * 31 + rhs.GetYear() * 365;
	
	return d1 > d2;
}

bool operator==(const Date& lhs, const Date& rhs)
{
	int d1 = lhs.GetDay() + lhs.GetMonth() * 31 + lhs.GetYear() * 365;
	int d2 = rhs.GetDay() + rhs.GetMonth() * 31 + rhs.GetYear() * 365;
	
	return d1 == d2;
}

class Database {
	map<Date, vector<string>> data;
public:
	void AddEvent(const Date& date, const string& event);
	bool DeleteEvent(const Date& date, const string& event);
	int  DeleteDate(const Date& date);

	void Find(const Date& date) const;

	void Print() const;
	friend istream& operator>>(istream& stream, Database& db);
};

istream& operator>>(istream& stream, Database& db)
{
	Date date;
	date.Input(stream);
	if (stream)
	{
		string ev;
		stream >> ev;
		db.data[date].push_back(ev);
	}
	else
	{
		db.data[date];
	}
	return stream;
}

void Database::AddEvent(const Date& date, const string& event)
{
	if (event != "")
	{
		data[date].push_back(event);
	}
	else
	{
		data[date];
	}
}

bool Database::DeleteEvent(const Date& date, const string& event)
{
	auto it = find(data[date].begin(), data[date].end(), event);
	if (it != data[date].end())
	{
		data[date].erase(it);
		return true;
	}
	else 
	{
		return false;
	}


}

int Database::DeleteDate(const Date& date)
{
	int size = data[date].size();
	data[date].clear();
	return size;
}
void Database::Find(const Date& date) const
{

}
void Database::Print() const
{
	for (const auto& it : data)
	{
		it.first.Out();
		for (const auto& vec : it.second)
		{
			cout << " " << vec;
		}
		cout << endl;
	}
}

int main() {
	Database db;

	string line;
	try {
		while (getline(cin, line))
		{
			string command;
			stringstream ss_line(line);
			ss_line >> command;

			if (command == "Add")
			{
				Date date;
				string ev;
				date.Input(ss_line);
				ss_line >> ev;
				db.AddEvent(date, ev);
			}
			
			else if (command == "Del")
			{
				string ev, date_str;
				Date date;
				date.Input(ss_line);
				ss_line >> ev;
				if (ev != "")
				{
					/*Команда должна удалить добавленное ранее событие с указанным именем в указанную дату,
					если оно существует.Если событие найдено и удалено,
					программа должна вывести строку «Deleted successfully»(без кавычек).
					Если событие в указанную дату не найдено,
					программа должна вывести строку «Event not found»(без кавычек).*/
					if (db.DeleteEvent(date, ev))
					{
						cout << "Deleted successfully" << endl;
					}
					else
					{
						cout << "Event not found" << endl;
					}
				}
				else
				{
					/*Команда удаляет все ранее добавленные события за указанную дату.
					Программа всегда должна выводить строку вида «Deleted N events», 
					где N — это количество всех найденных и удалённых событий.N может быть равно нулю, 
					если в указанную дату не было ни одного события.*/
					cout << "Deleted "<< db.DeleteDate(date) << " events" << endl;
				}
			}
			else if (command == "Find")
			{

			}
			else if (command == "Print")
			{
				db.Print();
			}
		}
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}
