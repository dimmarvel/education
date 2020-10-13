#include <iostream>
#include <string>

using namespace std;
struct day_name
	{
		string name;
		int day;
	}day_name_arr[12] =
		{
			{"January", 	31},
			{"February",	28},
			{"March", 		30},
			{"April",		31},
			{"May",			30},
			{"June", 		31},
			{"July",		30},
			{"August", 		31},
			{"September", 	30},
			{"October", 	31},
			{"November",	30},
			{"December", 	31},
		};
void printtable(int d[], string m[])
{
	for(int i = 0; i < 12; i++)
	{
		cout << m[i] << " "
			 << d[i] << endl;
	}
}

int main() {
	int days_in_month[12] = {30,28,30,31,30,31,30,31,30,31,30,31};
	string name_of_month[12] =
			{
				"January",
				"February",
				"March",
				"April",
				"May",
				"June",
				"July",
				"August",
				"September",
				"October",
				"November",
				"December"
			};
	cout << "Array:" << endl;

	printtable(days_in_month, name_of_month);
	cout << "----Struct:" << endl;
	for(int i = 0; i < 12; i++)
	{
		cout << day_name_arr[i].name << " - "
				<< day_name_arr[i].day << endl;
	}
	return 0;
}
