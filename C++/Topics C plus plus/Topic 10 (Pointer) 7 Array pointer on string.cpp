// ptrtostr.cpp
// массив указателей на строки
#include <iostream>
using namespace std;
const int DAYS = 7;

int main()
{
	setlocale(LC_ALL, "Rus");
	const char* arrptrs[DAYS] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
	for (int j = 0; j < DAYS; j++) // покажем все строки
		cout << arrptrs[j] << endl;
	system("pause");
	return 0;
}


