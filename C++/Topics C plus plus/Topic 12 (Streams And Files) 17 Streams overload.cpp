// englio.cpp
// Перегружаемые операции << и >> 
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Distance                      // класс английских расстояний
{
private:
	int feet;
	float inches;
public:
	Distance() :feet(0), inches(0.0) // конструктор (0 арг.)
	{  }
	// конструктор (2 аргумента)
	Distance(int ft, float in) : feet(ft), inches(in)
	{  }
	friend istream& operator >>(istream& s,Distance& d);
	friend ostream& operator <<(ostream& s,Distance& d);
};
istream& operator >>(istream& s, Distance& d) {
	cout << "\nВведите футы: "; s >> d.feet;
	cout << "\nВведите дюймы: "; s >> d.inches;
	return s;
}
ostream& operator <<(ostream& s, Distance& d) {
	s << d.feet << "\'-" << d.inches << '\"';
	return s;
}
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "Rus");
	Distance dist1, dist2;     //Определение переменных
	Distance dist3(11, 6.25);  // определение, инициализация dist3
	cout << "\nВведите два значения расстояний:";
	cin >> dist1 >> dist2;     // Получить значения от пользователя
							   // вывод расстояний
	cout << "\ndist1 = " << dist1 << "\ndist2 = " << dist2;
	cout << "\ndist3 = " << dist3 << endl;
	system("pause");
	return 0;
}