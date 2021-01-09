#include<iostream>
//Работа функции с структурой
using namespace std;

struct Distance {
	int feet;
	float inches;
};

void engldisp(Distance);// В скобках имя структуры

int main() {
	setlocale(LC_ALL, "Rus");

	Distance d1,d2;

	cout << "Input number feet: "; cin >> d1.feet;
	cout << "Input number inches: "; cin >> d1.inches;
	
	cout << "Input number feet: "; cin >> d2.feet;
	cout << "Input number inches: "; cin >> d2.inches;

	cout  <<"\nd1 = ";
	engldisp(d1); // в скобках имя СТРУКТУРНОЙ переменной
	cout  <<"\nd2 = ";
	engldisp(d2);

	cout << endl;
	system("pause");
}

void engldisp(Distance dd) {
	cout << dd.feet << "\'-" << dd.inches << "\"";
}