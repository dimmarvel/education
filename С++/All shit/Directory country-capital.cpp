#include<iostream>
#include<string>
#include<map>

using namespace std;

// справочник стран\столиц

int main()
{
	map<string, string> country_capital;
	int size;
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		string command;
		cin >> command;

		if (command == "CHANGE_CAPITAL")
		{
			string country, new_capital;
			cin >> country >> new_capital;

			if (country_capital.find(country) != country_capital.end())
			{
				if (country_capital[country] == "" || country_capital[country] == new_capital) //if have NO capital or new capital == old capital
				{
					cout << "Country " << country
						<< " hasn't changed its capital" << endl;
					
				}
				else //if HAVE capital but changed now
				{

					cout << "Country " << country
						<< " has changed its capital from " << country_capital[country]
						<< " to " << new_capital << endl;
					country_capital[country] = new_capital;
				}
			}
			else // if not exist
			{
				country_capital[country] = new_capital;
				cout << "Introduce new country " << country
					<< " with capital " << new_capital << endl;
			}

		}
		else if (command == "RENAME")
		{
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;

			auto key = country_capital.find(old_country_name);
			auto now_exist = country_capital.find(new_country_name);

			if (key != country_capital.end()) //if exist
			{

				if (key->first == new_country_name || now_exist != country_capital.end()) // if old key == new key
				{
					cout << "Incorrect rename, skip" << endl;
				}
				else if (key->second != "") // if extst and have capital
				{
					cout << "Country " << old_country_name
						<< " with capital " << key->second
						<< " has been renamed to " << new_country_name << endl;

					country_capital[new_country_name] = key->second;
					country_capital.erase(key);
				}

			}
			else // if NOT exist
			{
				cout << "Incorrect rename, skip" << endl;
			}

		}
		else if (command == "ABOUT")
		{
			string country;
			cin >> country;

			auto key = country_capital.find(country);

			if (key != country_capital.end()) //if exist
			{
				cout << "Country " << key->first << " has capital " << key->second << endl;
			}
			else // if NOT exist
			{
				cout << "Country " << country << " doesn't exist" << endl;
			}
		}
		else if (command == "DUMP")
		{
			if (!country_capital.empty())
			{
				for (const auto& it : country_capital)
				{
					cout << it.first << "/" << it.second << " ";
				}

				cout << endl;
			}
			else
			{
				cout << "There are no countries in the world" << endl;
			}
		}
	}
}