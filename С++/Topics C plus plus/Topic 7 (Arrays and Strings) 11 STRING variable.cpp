// stringin.cpp
// простая переменная строка
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL,"Rus");
	const int MAX = 80; // максимальный размер строки
	char str[MAX];   // сама строка

	cout << "Введите строку: ";          // ввод строки
	cin >> str;

	cout << "Вы ввели: " << str << endl; // показ результата
	system("pause");
	return 0;
}


