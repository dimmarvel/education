/*
    4.	В цикле запрашивайте у пользователя данные, состоящие из имени, отчест-
ва, фамилии и номера работника (типа unsigned long). Затем осуществите
форматированный вывод в объект ofstream с помощью оператора вставки
(<<). Не забывайте, что строки данных должны оканчиваться пробелами
или другими разделителями. Когда пользователь сообщит об окончании
ввода, закройте объект ofstream, откройте объект ifstream, прочитайте и вы-
ведите на экран все данные из файла, после чего завершите программу.

*/
#include <fstream>
#include <iostream>
using namespace std;
class persons
{
private:
    char name[50];
    char fam[50];
    char otch[50];
    unsigned long number;

public:
    persons() : name(""), fam(""), otch(""), number(1) {}

    friend istream& operator>>(istream& s, persons& p);
    friend ostream& operator<<(ostream& s, persons& p);
};
istream& operator>>(istream& s, persons& p)
{
    cout << "Input:" << endl;
    cout << "Name: ";
    s >> p.name;
    cout << "Fam: ";
    s >> p.fam;
    cout << "Otch: ";
    s >> p.otch;
    cout << "Number pers: ";
    s >> p.number;
    return s;
}
ostream& operator<<(ostream& s, persons& p)
{
    s << "Имя: " << p.name << endl;
    s << "Фамилия: " << p.fam << endl;
    s << "Отчество: " << p.otch << endl;
    s << "Номер: " << p.number << endl;
    return s;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    persons obj, obj2;
    cin >> obj;
    cin >> obj2;
    cout << obj;
    cout << obj2;
    system("pause");
    return 0;
}
