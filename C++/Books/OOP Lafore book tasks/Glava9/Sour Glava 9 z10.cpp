#include <iostream>
using namespace std;
const int LEN = 200; // максимальная длина имени
///////////////////////////////////////////////////////////
class student // сведения об образовании
{
private:
    char school[LEN]; // название учебного заведения
    char degree[LEN]; // уровень образования
public:
    void getedu()
    {
        cout << "  Введите название учебного заведения: ";
        cin >> school;
        cout << "  Введите степень высшего образования\n";
        cout << "  (неполное высшее, бакалавр, магистр, кандидат наук): ";
        cin >> degree;
    }
    void putedu() const
    {
        cout << "\n  Учебное заведение: " << school;
        cout << "\n  Степень: " << degree;
    }
};
///////////////////////////////////////////////////////////
class employee // некий сотрудник
{
private:
    char name[LEN];       // имя сотрудника
    unsigned long number; // номер сотрудника
public:
    void getdata()
    {
        cout << "\n  Введите фамилию: ";
        cin >> name;
        cout << "  Введите номер: ";
        cin >> number;
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
    char title[LEN]; // должность сотрудника
    double dues;     // сумма взносов в гольф-клуб
public:
    void getdata()
    {
        employee::getdata();
        cout << "  Введите должность: ";
        cin >> title;
        cout << "  Введите сумму взносов в гольф-клуб: ";
        cin >> dues;
        student::getedu();
    }
    void putdata() const
    {
        employee::putdata();
        cout << "\n  Должность: " << title;
        cout << "\n  Сумма взносов в гольф-клуб: " << dues;
        student::putedu();
    }
};
class executer : public manager // управляющий
{
private:
    int AkciyCompany;
    int YearPrem;

public:
    void getdata()
    {
        manager::getdata();
        cout << "  Размер годовой премии: ";
        cin >> YearPrem;
        cout << "  Размер акций компании: ";
        cin >> AkciyCompany;
    }
    void putdata() const
    {
        manager::putdata();
        cout << "  \nРазмер годовой премии: " << YearPrem << endl;
        cout << "  Размер акций компании: " << AkciyCompany;
    }
};
///////////////////////////////////////////////////////////
class scientist : private employee, private student // ученый
{
private:
    int pubs; // количество публикаций
public:
    void getdata()
    {
        employee::getdata();
        cout << "  Введите количество публикаций: ";
        cin >> pubs;
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
    executer e1;
    // введем информацию о нескольких сотрудниках
    cout << endl;

    cout << "\nВвод информации о первом управляющем";
    e1.getdata();

    cout << "\nИнформация о первомуправляющем";
    e1.putdata();

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

    cout << endl;
    return 0;
}
