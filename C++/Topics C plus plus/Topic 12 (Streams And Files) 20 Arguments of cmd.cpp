#include <fstream>
#include <iostream>
using namespace std;
#include <process.h>      // для exit()

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	if (argc != 2)
	{
		cerr << "\nФормат команды: otype имя_файла";

		system("pause");
		exit(-1);
	}
	char ch;                // символ для считывания
	ifstream infile;        // создать входной файл
	infile.open(argv[1]); // открыть файл
	if (!infile)           // проверить на наличие ошибок
	{
		cerr << "\nНевозможно открыть " << argv[1];

		system("pause");
		exit(-1);
	}
	while (infile) { // считать символ
		infile.get(ch);
		cout << ch;
	}
	system("pause");
	return 0;
}


