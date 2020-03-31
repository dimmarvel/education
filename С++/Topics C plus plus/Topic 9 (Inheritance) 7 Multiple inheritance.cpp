
#include <iostream>
using namespace std;
const int LEN = 80;       // максимальная длина имени
///////////////////////////////////////////////////////////
class student             // сведения об образовании
{
private:
	char school[LEN];   // название учебного заведения
	char degree[LEN];   // уровень образования
public:
	void getedu()
	{
		cout << "\n  Введите название учебного заведения: ";
		cin >> school;
		cout << "\n  Введите степень высшего образования\n";
		cout << " (неполное высшее, бакалавр, магистр, кандидат наук): ";
		cin >> degree;
	}
	void putedu() const
	{
		cout << "  Учебное заведение: " << school;
		cout << "\n  Степень: " << degree;
	}
};
///////////////////////////////////////////////////////////
class employee            // некий сотрудник
{
private:
	char name[LEN];     // имя сотрудника
	unsigned long number; // номер сотрудника
public:
	void getdata()
	{
		cout << "\n  Введите фамилию: "; cin >> name;
		cout << "  Введите номер: ";     cin >> number;
	}
	void putdata() const
	{
		cout << "\n  Фамилия: " << name;
		cout << "\n  Номер: " << number;
	}
};
///////////////////////////////////////////////////////////
class manager : private employee, private student // менеджер
{
private:
	char title[LEN];    // должность сотрудника
	double dues;          // сумма взносов в гольф-клуб
public:
	void getdata()
	{
		employee::getdata();
		cout << "\n  Введите должность: "; cin >> title;
		cout << "  Введите сумму взносов в гольф-клуб: "; cin >> dues;
		student::getedu();
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n  Должность: " << title;
		cout << "  Сумма взносов в гольф-клуб: " << dues;
		student::putedu();
	}
};
///////////////////////////////////////////////////////////
class scientist : private employee, private student // ученый
{
private:
	int pubs;             // количество публикаций
public:
	void getdata()
	{
		employee::getdata();
		cout << "  Введите количество публикаций: "; cin >> pubs;
		student::getedu();
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n  Количество публикаций: " << pubs;
		student::putedu();
	}
};
///////////////////////////////////////////////////////////
class laborer : public employee // рабочий
{
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "Rus");
	manager m1;
	scientist s1, s2;
	laborer l1;

	// введем информацию о нескольких сотрудниках
	cout << endl;
	cout << "\nВвод информации о первом менеджере";
	m1.getdata();

	cout << "\nВвод информации о первом ученом";
	s1.getdata();

	cout << "\nВвод информации о втором ученом";
	s2.getdata();

	cout << "\nВвод информации о первом рабочем";
	l1.getdata();

	// выведем полученную информацию на экран
	cout << "\nИнформация о первом менеджере";
	m1.putdata();

	cout << "\nИнформация о первом ученом";
	s1.putdata();

	cout << "\nИнформация о втором ученом";
	s2.putdata();

	cout << "\nИнформация о первом рабочем";
	l1.putdata();
	system("pause");
	cout << endl;
	return 0;
}


