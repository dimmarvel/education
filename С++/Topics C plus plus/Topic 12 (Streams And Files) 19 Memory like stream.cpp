// ostrstr.cpp
// Запись форматированных данных в память
#include <strstream>
#include <iostream>
#include <iomanip>        // для функции setiosflags()
using namespace std;
const int SIZE = 80;      // размер буфера

int main()
{
	setlocale(LC_ALL, "Rus");
	char ch = 'x';          // тестовые данные
	int j = 77;
	double d = 67890.12345;
	char str1[] = "Kafka";
	char str2[] = "Freud";

	char membuff[SIZE];
	ostrstream omem(membuff, SIZE);
	omem << "ch=" << ch << endl     // вставить форматированны данные
		<< "j=" << j << endl         // в объект
		<< setiosflags(ios::fixed)   // формат с десятичной запятой (фиксированной)
		<< setprecision(2)           // оставлять два знака после запятой
		<< "d=" << d << endl
		<< "str1=" << str1 << endl
		<< "str2=" << str2 << endl
		<< ends;         // закончить буфер символом '\0'
	cout << membuff;     // вывод содержимого буфера
	system("pause");
	return 0;
}