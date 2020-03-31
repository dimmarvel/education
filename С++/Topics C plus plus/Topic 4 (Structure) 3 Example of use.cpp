#include<iostream>

//английска€ система мер, реализованна€ с помощью структуры(Struct)

using namespace std;

struct Distance {        //объ€вление структуры
	int feet;
	float inches;
};
int main() {
	setlocale(LC_ALL, "Rus");

	Distance d1, d3;
	Distance d2 = { 11, 6.25 };

	cout << "\n¬ведите число футов: ";
	cin >> d1.feet;
	cout << "¬ведите число дюймов: ";
	cin >> d1.inches;

	//сложение длин д1 и д2 и присвоение результата д3
	d3.inches = d1.inches + d2.inches;  //сложение дюймов
	d3.feet = 0;						//с возможным заемом

	if (d3.inches >= 12.0) {			//если сумма больше 12
		d3.inches -= 12.0;				//то уменьшаем число дюймов на 12
		d3.feet++;						//и + 1 фут

	}
	d3.feet += d1.feet + d2.feet;		//сложение футов

	cout << d1.feet << "\ '-" << d1.inches << "\" + ";
	cout << d2.feet << "\ '-" << d2.inches << "\" = ";
	cout << d3.feet << "\ '-" << d3.inches << "\"\n ";


	system("pause");
}