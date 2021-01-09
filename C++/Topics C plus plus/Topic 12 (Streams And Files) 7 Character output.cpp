// ichar.cpp
// Посимвольный файловый ввод
#include <fstream>        //для файловых функций
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL,"Rus");
	char ch;                     // символ для считывания
	ifstream infile("TEST.TXT"); // входной файл
	while (infile)              // читать до EOF или ошибки (просто другой способ записи
	{
		infile.get(ch);            // считать символ
		cout << ch;                // и вывести его
	}
	cout << endl;
	return 0;
}


