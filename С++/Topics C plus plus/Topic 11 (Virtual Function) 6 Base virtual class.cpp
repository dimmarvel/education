// normbase.cpp
// неоднозначная ссылка на базовый класс

/*
class Parent
{
protected:
	 int basedata;
};
class Child1 : public Parent
{ };
class Child2 : public Parent
{ };
class Grandchild : public Child1, public Child2
{
public:
	int getdata()
	{
		return basedata;
	}   // ОШИБКА: неоднозначность
};
*/

// virtbase.cpp
// Виртуальные базовые классы
class Parent
{
protected:
	int basedata;
};
class Child1 : virtual public Parent // наследует копию
									 // класса Parent
{ };
class Child2 : virtual public Parent // наследует копию
									 // класса Parent
{ };
class Grandchild : public Child1, public Child2
{
public:
	int getdata()
	{
		return basedata;
	}         // OK: только одна копия
					  //класса Parent
};
