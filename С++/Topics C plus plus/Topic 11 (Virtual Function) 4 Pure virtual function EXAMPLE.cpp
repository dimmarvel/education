// vitrpers.cpp
// виртуальные функции и класс person
#include <iostream>
using namespace std;
///////////////////////////////////////////////
class person                    //класс person
{
protected:
	char name[40];
public:
	void getName()
	{
		cout << "  Введите имя: "; cin >> name;
	}
	void putName()
	{
		cout << "  Имя: " << name << endl;
	}
	virtual void getData() = 0;      //чистые
	virtual bool isOutstanding() = 0; //виртуальные
									 //функции
};
////////////////////////////////////////////////
class student : public person   //класс student
{
private:
	float gpa;                //средний балл
public:
	void getData()            //запросить данные об ученике у
	{                       //пользователя
		person::getName();
		cout << "  Средний балл ученика:  "; cin >> gpa;
	}
	bool isOutstanding()
	{
		return (gpa > 3.5) ? true : false;
	}
};
////////////////////////////////////////////////
class professor : public person //класс professor
{
private:
	int numPubs;              //число публикаций
public:
	void getData()            //запросить данные о педагоге у
	{                       //пользователя
		person::getName();
		cout << "  Число публикаций:  "; cin >> numPubs;
	}
	bool isOutstanding()
	{
		return (numPubs > 100) ? true : false;
	}
};
////////////////////////////////////////////////
int main()
{
setlocale(LC_ALL,"Rus");
	person* persPtr[100];  //массив указателей на person
	int n = 0;            //число людей, внесенных в список char choice;
	char choice;
	do {
		cout << " Учащийся (s) или педагог (p): ";
		cin >> choice;

		if (choice == 's')               //Занести нового ученика 
			persPtr[n] = new student;   // в массив
		else                          //Занести нового
			persPtr[n] = new professor; //педагога в массив

		persPtr[n++]->getData();       //Запрос данных о персоне
		cout << " Ввести еще персону (y/n)? "; //создать еще
											   //персону
		cin >> choice;
	} while (choice == 'y');       //цикл, пока ответ 'y'

	for (int i = 0;i < n; i++)
	{
		persPtr[i]->putName();        //Вывести все имена,
		if (persPtr[i]->isOutstanding())        //сообщать о 
			cout << "  Это выдающийся человек!\n"; //выдающихся
	}
	system("pause");
	return 0;

