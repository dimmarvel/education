// показ количества дней с начала года и до введенной даты
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");

	int month, day, total_days;
	int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	cout << "\n¬ведите мес€ц (от 1 до 12): ";
	cin >> month;
	cout << "\n¬ведите день (от 1 до 31): ";
	cin >> day;

	total_days = day;

	for (int j = 0; j < month - 1; j++)
		total_days += days_per_month[j];

	cout << "ќбщее число дней с начала года: " << total_days << endl;

	system("pause");
}

