#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//- добавление события : Add Дата Событие
//- удаление события : Del Дата Событие
//- удаление всех событий за конкретную дату : Del Дата
//- поиск событий за конкретную дату : Find Дата
//- печать всех событий за все даты : Print

// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
private:
	int year;
	int month;
	int day;
public:
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	void Input(ifstream& ifstr);
	void Out() const;
};

void Date::Input(ifstream& ifstr)
{
	if (ifstr)
	{
		getline(ifstr, year, '-');
		getline(ifstr, month, '-');
		getline(ifstr, day, '-');
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
	if (lhs.GetYear() != rhs.GetYear())
	{
		return lhs.GetYear() < rhs.GetYear();
	}
	else if (lhs.GetMonth() != rhs.GetMonth())
	{
		return lhs.GetMonth() < rhs.GetMonth();
	}
	else if (lhs.GetDay() != rhs.GetDay())
	{
		return lhs.GetDay() < rhs.GetDay();
	}
}

class Database {
	map<Date, vector<string>> data;
public:
	void AddEvent(const Date& date, const string& event);
	bool DeleteEvent(const Date& date, const string& event);
	int  DeleteDate(const Date& date);

	void Find(const Date& date) const;

	void Print() const;
	
};

void Database::AddEvent(const Date& date, const string& event)
{
	data[date].push_back(event);
}

bool Database::DeleteEvent(const Date& date, const string& event)
{

}

int  Database::DeleteDate(const Date& date)
{

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
	}
}

int main() {
	Database db;

	string command;
	try {
		while (getline(cin, command)) {
			if (command == "Add")
			{
				string ev, date_str;
				Date date;
				cin >> date_str;
				ifstream ifstr(date_str);

				date.Input(ifstr);
				cin >> ev;

				db.AddEvent(date, ev);
			}
			else if (command == "Del")
			{

			}
			else if (command == "Find")
			{

			}
			else if (command == "Print")
			{

			}
		}
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}