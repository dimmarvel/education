// newstr.cpp
// использование оператора new дл€ выделени€ пам€ти под строку
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
///////////////////////////////////////////////////////////
class String
{
private:
	char* str;          // указатель на строку
public:
	String(const char* s)  // конструктор с одним параметром
	{
		int length = strlen(s);     // вычисл€ем длину строки
		str = new char[length + 1]; // выдел€ем необходимую пам€ть
		strcpy(str, s);             // копируем строку
	}
	~String()         // деструктор
	{
		cout << "”дал€ем строку\n";
		delete[] str; // освобождаем пам€ть
	}
	void display()    // покажем строку на экране
	{
		cout << str << endl;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL,"Rus");
	String s1 = "“ише едешь Ц дальше будешь.";
	cout << "s1 = ";
	s1.display();
	system("pause");
	return 0;
}


