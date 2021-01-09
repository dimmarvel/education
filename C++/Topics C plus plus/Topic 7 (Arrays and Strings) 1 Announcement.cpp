// запоминание и вывод на экран информации, введенной пользователем
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL,"Rus");
	int age[4];
	for (int j = 0; j < 4; j++)
	{
		cout << "Введите возраст: ";
		cin >> age[j];
	}
	for (int j = 0; j < 4; j++)
		cout << "Вы ввели: " << age[j] << endl;

	system("pause");
}


