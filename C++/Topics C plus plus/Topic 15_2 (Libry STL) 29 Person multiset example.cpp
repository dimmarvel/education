// setpers.cpp
// Применение мультимножества для хранения объектов person
#pragma warning (disable:4786)     // для множеств (для
								   // компиляторов фирмы Microsoft)
#include <iostream>
#include <set>
#include <string>
using namespace std;

class person {
private:  
	string lastName;
	string firstName;
	int number;
public:
	person(string l, string f, int n) {
		lastName = l;
		firstName = f;
		number = n;
	}
	void display() const {
		cout << "Фамилия: " << lastName <<  "\tИмя: " << firstName << "\tНомер: " << number << endl;
	}
	friend bool operator< (const person& q1, const person& q2);
};
///////////////////////////////////////////////////////////
bool operator< (const person& q1, const person& q2) {
	if (q1.lastName == q2.lastName)
		return (q1.firstName < q2.firstName) ? true : false;
	return (q1.lastName < q2.lastName) ? true : false;

}
int main()
{                               // создание объектов person
	setlocale(LC_ALL, "Rus");
	person pers1("Deauville", "William", 8435150);
	person pers2("McDonald", "Stacey", 3327563);
	person pers3("Bartoski", "Peter", 6946473);
	person pers4("KuangThu", "Bruce", 4157300);
	person pers5("Wellington", "John", 9207404);
	person pers6("McDonald", "Amanda", 8435150);
	person pers7("Fredericks", "Roger", 7049982);
	person pers8("McDonald", "Stacey", 7764987);
	// мультимножество класса person
	multiset< person, less<person> > persSet;
	// итератор этого мультимножества
	multiset<person, less<person> >::iterator iter;

	persSet.insert(pers1);          // занести объекты person в мультимножество
	persSet.insert(pers2);
	persSet.insert(pers3);
	persSet.insert(pers4);
	persSet.insert(pers5);
	persSet.insert(pers6);
	persSet.insert(pers7);
	persSet.insert(pers8);

	cout << "\nЧисло записей: " << persSet.size() << endl;

	iter = persSet.begin();         //Вывод содержимого мультимножества
	while (iter != persSet.end())
		(*iter++).display();
	// получение имени и фамилии
	string searchLastName, searchFirstName;
	cout << "\n\nВведите фамилию искомого человека: ";
	cin >> searchLastName;
	cout << "Введите имя: ";
	cin >> searchFirstName;
	// создание объекта с заданными значениями атрибутов
	person searchPerson(searchLastName, searchFirstName, 0);
	// сосчитать количество людей с таким именем
	int cntPersons = persSet.count(searchPerson);
	cout << "Число людей с таким именем: " << cntPersons << endl;

	// вывести все записи, отвечающие запросу
	iter = persSet.lower_bound(searchPerson);
	while (iter != persSet.upper_bound(searchPerson))
		(*iter++).display();
	cout << endl;
	system("pause");
	return 0;
}    // end main()