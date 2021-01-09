// countpp2.cpp
// операция ++, возвращающий значение
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Counter
{
private:
	unsigned int count;
public:
	Counter():count(0){}
	void get_count() {
	cout << count << endl;
	}
	Counter operator++() {	 //INT в параметре если хотим постфиксную форму
		++count;
		Counter temp;
		temp.count = count;
		return temp;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	Counter c1, c2;                        // определяем переменные

	c1.get_count(); // выводим на экран
	c2.get_count();

	++c1;                                  // увеличиваем c1
	c2 = ++c1;                             // c1=2, c2=2

	c1.get_count(); // снова показываем значения
	c2.get_count();
	system("pause");
	return 0;
}


