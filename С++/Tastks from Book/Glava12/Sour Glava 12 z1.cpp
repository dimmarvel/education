/*
	Рассмотрите класс Distance из программы ENGLCON, глава 6 «Объекты и
	классы». Используя цикл, аналогичный приводимому в программе DISKFUN
	в этой главе, получите несколько значений от пользователя и запишите
	их в файл. Добавьте их к уже записанным там данным (при их наличии).
	При окончании пользователем ввода прочитайте файл и выведите на экран все значения.
*/
#include<iostream>
#include<fstream>
using namespace std;
class Distance           
{
private:
	int feet;
	float inches;
public:                  
	Distance() : feet(0), inches(0.0) {}
	Distance(int ft, float in) : feet(ft), inches(in){}
	void getdist()         
	{
		cout << "\nВведите число футов: "; cin >> feet;
		cout << "Введите число дюймов: "; cin >> inches;
	}
	void showdist()          // вывод длины на экран
	{
		cout << feet << "\'-" << inches << '\"';
	}
	void add_dist(Distance, Distance);            // прототип
};

void Distance::add_dist(Distance dd1, Distance dd2)
{
	inches = dd1.inches + dd2.inches;      // сложение дюймов
	feet = 0;                              // с возможным заемом
	if (inches >= 12.0)                     // если число дюймов больше 12.0,
	{                                      // то уменьшаем число дюймов
		inches -= 12.0;                      // на 12.0 и увеличиваем
		feet++;                              // число футов на 1
	}
	feet += dd1.feet + dd2.feet;           // сложение футов
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Distance dist1;
	fstream obj("DISTANCEDATA.DAT", ios::in | ios::app | ios::binary | ios::out);
	char ch = 'n';
	do {
		cout << "\nInput data: ";
		dist1.getdist();
		obj.write(reinterpret_cast<char*>(&dist1), sizeof(dist1));
		cout << "Continue?(y|n)" << endl;
		cin >> ch;
	} while (ch != 'n');
	obj.seekg(0);

	obj.read(reinterpret_cast<char*>(&dist1), sizeof(dist1));
	while (obj) {
		cout << "Dist: ";
		dist1.showdist();
		obj.read(reinterpret_cast<char*>(&dist1), sizeof(dist1));
		cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
