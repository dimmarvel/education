// retstrc.cpp
// демонстрирует возвращение функцией структурной переменной 
#include <iostream>
using namespace std;


struct Distance                   // длина в английской системе
{
	int feet;
	float inches;
};

Distance addengl(Distance, Distance); // прототипы
void engldisp(Distance);

int main()
{
	setlocale(LC_ALL, "Rus");
	Distance d1, d2, d3;            // три структурные переменные
	// ввод значени€ d1
	cout << "\n¬ведите число футов: "; cin >> d1.feet;
	cout << "¬ведите число дюймов: "; cin >> d1.inches;
	// ввод значени€ d2
	cout << "\n¬ведите число футов: "; cin >> d2.feet;
	cout << "¬ведите число дюймов: "; cin >> d2.inches;
	d3 = addengl(d1,d2);
	cout << endl;
	engldisp(d1); cout << " + ";
	engldisp(d2); cout << " = ";
	engldisp(d3); cout << endl;
	system("pause");

}

// складывает два значени€ типа Distance и возвращает сумму
Distance addengl(Distance dd1, Distance dd2)
{
	Distance dd3;                 // переменна€ дл€ хранени€ будущей суммы
	dd3.inches = dd1.inches + dd2.inches; // сложение дюймов
	dd3.feet = 0;                 // с заемом;
	if (dd3.inches >= 12.0)        // если число дюймов больше 12.0,
	{                             // то уменьшаем число дюймов 
		dd3.inches -= 12.0;         // на 12.0 и увеличиваем
		dd3.feet++;                 // число футов на 1
	}
	dd3.feet += dd1.feet + dd2.feet; // сложение футов
	return dd3;                   // возврат значени€
}


// отображает пол€ структурной переменной Distance
void engldisp(Distance dd)
{
	cout << dd.feet << "\'-" << dd.inches << "\"";
}

