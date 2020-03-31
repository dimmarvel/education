// показ графика продаж
#include <iostream>
#include <iomanip>
using namespace std;

const int DISTRICTS = 4;
const int MONTHS = 3;
int main()
{
	setlocale(LC_ALL, "Rus");
	int d, m;
	double sales[DISTRICTS][MONTHS];

	cout << endl;
	for (d = 0; d < DISTRICTS; d++)
	{
		for (m = 0; m < MONTHS; m++)
		{
			cout << "Введите объем продаж для отдела " << d + 1;
			cout << ", за месяц " << m + 1 << ": ";
			cin >> sales[d][m];
		}
	}

	cout << "\n\n";
	cout << "                        Месяц\n";
	cout << "                1         2         3";
	
	for (d = 0; d < DISTRICTS; d++)
	{
		cout << "\nОтдел " << d + 1;
		for (m = 0; m < MONTHS; m++)// подробно о том что делает каждый флаг СТР 269
			cout << setiosflags(ios::fixed) //фикс формата записи - 3.25е2
			<< setiosflags(ios::showpoint)// определяет точку, будет не 120 а 120.00
			<< setprecision(2) // знаков после запятой, поэтому сверху 2 знака
			<< setw(10)
			<< sales[d][m]; //само число
	}
	
	cout << endl;
	system("pause");
	return 0;
}

