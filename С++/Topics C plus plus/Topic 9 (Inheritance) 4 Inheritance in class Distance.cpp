// englen.cpp
// наследование в программе перевода английских мер длины
#include <iostream>
using namespace std;
enum posneg { pos, neg };
///////////////////////////////////////////////////////////
class Distance // класс дл€ английских мер длины
{
protected:   // заметьте, что private использовать нельз€
	int feet;
	float inches;
public:
	// конструктор без параметров
	Distance() : feet(0), inches(0.0)
	{ }
	// конструктор с двум€ параметрами
	Distance(int ft, float in) : feet(ft), inches(in)
	{ }
	// получение значений от пользовател€
	void getdist()
	{
		cout << "\n¬ведите футы: "; cin >> feet;
		cout << "¬ведите дюймы: "; cin >> inches;
	}
	// вывод значений на экран
	void showdist() const
	{
		cout << feet << "\'" << inches << '\"';
	}
};
///////////////////////////////////////////////////////////
class DistSing : public Distance // добавление знака к длине
{
private:
	posneg sing;                 // значение может быть pos или neg
public:
	// конструктор без параметров
	DistSing() : Distance()
	{
		sing = pos;
	}
	// конструктор с двум€ или трем€ параметрами
	DistSing(int ft, float in, posneg sg = pos) : Distance(ft, in)      // вызов конструктора базового класса
	{
		sing = sg;
	}           // начальна€ установка знака
	void getdist()           // ввод пользователем длины
	{
		Distance::getdist(); // вызов функции getdist из базового класса
		char ch;               // запрос знака
		cout << "¬ведите знак (+ или -): "; cin >> ch;
		sing = (ch == '+') ? pos : neg;
	}
	void showdist() const    // вывод рассто€ни€
	{
		// вывод всей информации, включа€ знак
		cout << ((sing == pos) ? "(+)" : "(-)");
		Distance::showdist();
	}
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL,"Rus");
	DistSing alpha;                   // используем конструктор по умолчанию
	alpha.getdist();                // получаем данные от пользовател€

	DistSing beta(11, 6.25);       // конструктор с двум€ аргументами

	DistSing gamma(100, 5.5, neg); // конструктор с трем€ аргументами

	// выводим данные дл€ всех переменных
	cout << "\nA = "; alpha.showdist();
	cout << "\nB = "; beta.showdist();
	cout << "\nC = "; gamma.showdist();
	cout << endl;
	system("pause");
	return 0;
}


