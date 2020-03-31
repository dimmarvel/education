// diskfun.cpp
// Чтение из файла и запись нескольких объектов
#include <fstream>      // для файловых потоков
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class person            // класс person
{
protected:
	char name[80];      // имя человека
	int age;            // его возраст
public:
	void getData()      // получить данные о человеке
	{
		cout << "\n  Введите имя: "; cin >> name;
		cout << "  Введите возраст: "; cin >> age;
	}
	void showData()     // вывод данных о человеке
	{
		cout << "\n  Имя: " << name;
		cout << "\n  Возраст: " << age;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "Rus");
	char ch;
	person pers;
	fstream file;
	file.open("GROUP.DAT", ios::in | ios::out | ios::app | ios::binary);
	char n = 'y';
	do {
		cout << "Input data:" << endl;
		pers.getData();

		file.write(reinterpret_cast<char*>(&pers), sizeof(pers));
		cout << "continye? y n" << endl;
		cin >> ch;
	} while (ch != 'n');
	file.seekg(0);
	file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
	while (!file.eof()) {
		pers.showData();
		file.read(reinterpret_cast<char*>(&pers), sizeof(pers));
	}
	cout << endl;
	system("pause");
	return 0;
}