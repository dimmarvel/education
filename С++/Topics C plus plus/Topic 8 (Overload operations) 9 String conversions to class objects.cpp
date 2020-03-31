// strconv.cpp
// перевод обычных строк в класс String
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string.h>          // для функций str*
///////////////////////////////////////////////////////////
class String
{
private:
	enum { SZ = 80 };       // размер массива
	char str[SZ];         // массив для хранения строки
public:
	// конструктор без параметров
	String()
	{
		str[0] = '\x0';
	}
	// конструктор с одним параметром
	String(const char s[])
	{
		strcpy(str, s);
	} // сохраняем строку в массиве
// показ строки
	void display() const
	{
		cout << str;
	}
	// перевод строки к обычному типу
	operator char* ()
	{
		return str;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL,"Rus");
	String s1;                 // используем конструктор без параметров

	char xstr[] = "Ура, товарищи! "; // создаем обычную строку

	s1 = xstr;                 // неявно используем конструктор с одним параметром

	s1.display();            // показываем строку

	String s2 = "Мы победим!"; // снова используем конструктор с параметром
	s2.display();
	cout << static_cast<char*>(s2); // используем оператор перевода типа
	cout << endl;
	system("pause");
	return 0;
}


