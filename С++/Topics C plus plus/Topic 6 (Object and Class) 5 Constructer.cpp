// counter.cpp
// счетчик в качестве объекта
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////
class Counter
{
private:
	unsigned int count;         // значение счетчика    
public:
	Counter() : count(0) {
	cout << "Constructor work";
	} // конструктор

	void inc_count()            // инкрементирование счетчика
	{
		count++;
	}
	int get_count()             // получение значения счетчика
	{
		return count;
	}
};
//////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL,"Rus");
	Counter c1, c2;               // определение с инициализацией
	cout << "\nc1=" << c1.get_count(); // вывод
	cout << "\nc2=" << c2.get_count();
	c1.inc_count();               // инкрементирование c1
	c2.inc_count();               // инкрементирование c2
	c2.inc_count();               // инкрементирование c2
	cout << "\nc1=" << c1.get_count(); // вывод
	cout << "\nc2=" << c2.get_count();
	cout << endl;
	system("pause");
}


