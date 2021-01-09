// strequal.cpp
// перегрузка операции ==
#include <iostream>
using namespace std;
#include <string.h> // дл€ функции strcmp
///////////////////////////////////////////////////////////
class String            // наш класс дл€ строк
{
private:
	enum { SZ = 80 } ;  // максимальный размер строки
	char str[SZ];    // массив дл€ строки
public:
	// конструктор без параметров
	String()
	{
		strcpy(str, "");
	}
	// конструктор с одним параметром
	String(const char s[])
	{
		strcpy(str, s);
	}
	// показ строки
	void display() const
	{
		cout << str;
	}
	// получение строки
	void getstr()
	{
		cin.get(str, SZ);
	}
	// оператор сравнени€
	bool operator== (String ss) const
	{
		return (strcmp(str, ss.str) == 0) ? true : false; 
		//strcmp - возвращает 0 если строки равны, отрицательное число если перва€ строка меньше второй
		//положительное число если перва€ строка больше второй
	}
};
///////////////////////////////////////////////////////////
int main()
{
	String s1 = "да";
	String s2 = "нет";
	String s3;

	cout << "\n¬ведите 'да' или 'нет': ";
	s3.getstr();        // получаем строку от пользовател€

	if (s3 == s1)       // сравниваем со строкой 'да'
		cout << "¬ы ввели 'да'\n";
	else
		if (s3 == s2)       // сравниваем со строкой 'нет'
			cout << "¬ы ввели 'нет'\n";
		else
			cout << "—ледуйте инструкци€м!\n";

	return 0;
}

