// seekg.cpp
// Поиск конкретного объекта в файле
#include <fstream>        // для файловых потоков
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class person              // класс person
{
protected:
	char name[80];        // имя человека
	int age;              // его возраст
public:
	void getData()        // получить данные о человеке
	{
		cout << "\n  Введите имя: "; cin >> name;
		cout << "  Введите возраст: "; cin >> age;
	}
	void showData(void)   // вывод данных о человеке
	{
		cout << "\n  Имя: " << name;
		cout << "\n  Возраст: " << age;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "Rus");
	person pers;                  // создать объект person 
	ifstream infile;              // создать входной файл
	infile.open("GROUP.DAT", ios::in | ios::binary); // открыть
	infile.seekg(0, ios::end);
	int endpos = infile.tellg();
	int n = endpos / sizeof(pers);
	cout << "Всего человек " << n << endl;
	cout << "Введите номер человека ";
	cin >> n;
	int posn = (n - 1) * sizeof(pers);
	infile.seekg(posn);
	infile.read(reinterpret_cast<char*>(&pers),sizeof(pers));
	pers.showData();
	cout << endl;
	system("pause");
	return 0;
}


