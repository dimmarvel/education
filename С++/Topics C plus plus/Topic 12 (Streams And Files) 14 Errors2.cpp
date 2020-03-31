// ferrors.cpp
// Проверка ошибок открытия файла
#include <fstream>           // для файловых функций
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	ifstream file;
	file.open("a:test.dat");

	if (!file)
		cout << "\nНевозможно открыть GROUP.DAT";
	else
		cout << "\nФайл открыт без ошибок.";
	cout << "\nfile = " << &file;
	cout << "\nКод ошибки = " << file.rdstate();
	cout << "\ngood() = " << file.good();
	cout << "\neof() = " << file.eof();
	cout << "\nfail() = " << file.fail();
	cout << "\nbad() = " << file.bad() << endl;
	file.close();
	system("pause");
	return 0;
}