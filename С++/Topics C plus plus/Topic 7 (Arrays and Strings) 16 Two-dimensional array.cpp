// straray.cpp
// массив строк
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL,"Rus");
	const int DAYS = 7; // количество строк в массиве
	const int MAX = 12; // максимальная длина каждой из них

	// массив строк
	char star[DAYS][MAX] =
	{
	  "Понедельник", "Вторник", "Среда", "Четверг",
	  "Пятница", "Суббота", "Воскресенье"
	};

	// вывод всех строк на экран
	for (int j = 0; j < DAYS; j++)
		cout << star[j] << endl;
	system("pause");
	return 0;
}
