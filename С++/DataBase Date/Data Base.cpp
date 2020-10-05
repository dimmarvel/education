#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <iomanip>

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
	friend ostream& operator<<(ostream& ostr,const Date& date);
};

ostream& operator<<(ostream& ostr, const Date& date)
{
	return ostr << setfill('0')
		<< setw(4) << date.GetYear() << "-"
		<< setw(2) << date.GetMonth() << "-"
		<< setw(2) << date.GetDay();
}
int ConvertDateToDays(const Date& date)
{
	return date.GetDay() + date.GetMonth() * 31 + date.GetYear() * 365;
}

void Date::Input(istream& ifstr)
{
	string str_date;
	char def1, def2;

	ifstr >> str_date;
	stringstream temp(str_date);
	temp.clear();
	temp >> year >> def1 >> month >> def2 >> day;

	if (temp && temp.eof() && def1 == '-' && def2 == '-')
	{
		if (month < 1 || month > 12)
		{
			throw runtime_error("Month value is invalid: " + to_string(month));
		}
		if (day < 1 || day > 31)
		{
			throw runtime_error("Day value is invalid: " + to_string(day));
		}
	}
	else
	{
		throw runtime_error("Wrong date format: " + str_date);
	}
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
	return ConvertDateToDays(lhs) < ConvertDateToDays(rhs);
}

bool operator>(const Date& lhs, const Date& rhs)
{
	return ConvertDateToDays(lhs) > ConvertDateToDays(rhs);
}

bool operator==(const Date& lhs, const Date& rhs)
{
	return ConvertDateToDays(lhs) == ConvertDateToDays(rhs);
}

class Database {
	map<Date, set<string>> data;
public:
	void AddEvent(const Date& date, const string& event);
	bool DeleteEvent(const Date& date, const string& event);
	int  DeleteDate(const Date& date);

	void Find(const Date& date);

	void Print() const;
};


void Database::AddEvent(const Date& date, const string& event)
{
	if (event != "")
	{
		data[date].insert(event);
		//sort(data[date].begin(), data[date].end());
	}
	else // if event not added
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
	data.erase(date);
	return size;
}

void Database::Find(const Date& date)
{
	set<string> events = data[date];
	for (auto& it : events)
	{
		cout << it << endl;
	}
}

void Database::Print() const
{
	for (const auto& it : data)
	{
		for (const auto& vec : it.second)
		{
			cout << it.first << " " << vec << endl;;
		}
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
					cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
				}
			}
			else if (command == "Find")
			{
				Date date;
				date.Input(ss_line);
				db.Find(date);
			}
			else if (command == "Print")
			{
				db.Print();
			}
			else if (command != "")
			{
				throw runtime_error("Unknown command: " + command);
			}
		}
	}
	catch (runtime_error& ex)
	{
		cout << ex.what() << endl;
	}

	return 0;
}