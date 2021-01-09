// linesin.cpp
// ввод нескольких строк
#include <iostream>
using namespace std;
const int MAX = 2000; // максимальная длина строки
char str[MAX];     // сама строка
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL,"Rus");
	cout << "\nВведите строку:\n";
	cin.get(str, MAX, '$');
	cout << "Вы ввели:\n" << str << endl;
	system("pause");
	return 0;
}


