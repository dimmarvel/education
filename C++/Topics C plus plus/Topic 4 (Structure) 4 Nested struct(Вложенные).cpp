#include<iostream>
//ВЛОЖЕННЫЕ СТРУКТУРЫ
using namespace std;

struct Distance { //длины в английской системе

	int feet; //
	float inches; //
};
struct Room { //размеры прямоуг. комнаты

	Distance lenght; //длина определенная структурой DISTANCE!!!
	Distance width; //ширина определенная структурой DISTANCE!!!
};

int main() {
	setlocale(LC_ALL, "Rus");
	Room dining;
	dining.lenght.feet = 13;
	dining.lenght.inches = 6.5f;
	dining.width.feet = 10;
	dining.width.inches = 0.0f;
	//преобразование длины и ширины в вещественный формат
	float l = dining.lenght.feet + dining.lenght.inches / 12;
	float w = dining.width.feet + dining.width.feet / 12;


	cout << "l = " << l << "\n";
	cout << "w = " << w << "\n";

	//вычисление площади комнаты и вывод
	cout << "S = " << l * w << " футов квадратных\n";

	system("pause");
}