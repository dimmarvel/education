// определение среднего дневного объема продаж
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL,"Rus");
	const int SIZE = 6;
	double sales[SIZE];

	cout << "Введите объем продаж на каждый из шести дней\n";
	for (int j = 0; j < SIZE; j++)
	{
		cin >> sales[j];
	}
	double total = 0;

	for (int j = 0; j < SIZE; j++)
	{
		total += sales[j];
	}

	double average = total / SIZE;
	
	cout << "Средний объем: " << average << endl;

	system("pause");
}


