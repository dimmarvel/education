#include <iostream>
#include <string>
using namespace std;
class Publication
{
private:
	string Name;
	float Price;
public:
	Publication() : Price(0), Name("N\A") {}
	Publication(string q, float p) : Price(p), Name(q) {}

	virtual void getdata()
	{
		cout << "\n¬ведите Name: "; cin >> Name;
		cout << "¬ведите Price: ";  cin >> Price;
	}

	virtual void showdata()
	{
		cout << "\nName: " << Name;
		cout << "\nPrice: " << Price;
	}

};
class book : public Publication
{
private:
	int Pages;
public:
	book() : Pages(0) {}
	book(int p) : Pages(p) {}

	void getdata()
	{
		Publication::getdata();
		cout << "¬ведите pages: ";  cin >> Pages;
	}

	void showdata()
	{
		Publication::showdata();
		cout << "\nPages: " << Pages;
	}

};
class type : public Publication
{
private:
	float time;
public:
	type() : time(0) {}
	type(float z) : time(z) {}

	void getdata()
	{
		Publication::getdata();
		cout << "¬ведите time: "; cin >> time;
	}

	void showdata()
	{
		Publication::showdata();
		cout << "\nTime: " << time;
	}

};

int main()
{
	setlocale(LC_ALL, "Rus");
	Publication*pubarr[100];
	int n = 0;
	char choice;
	do {
		cout << "\n Input data for book or plenki (b/t)";
		cin >> choice;
		if(choice =='b')
			pubarr[n] = new book;
		else
			pubarr[n] = new type;
		
		pubarr[n++]->getdata();
		cout <<"Continue?(y/n)";
		cin >> choice;
	}while(choice == 'y');
	for (int i = 0; i < n; i++)
	{
		pubarr[i]->showdata();
		cout << endl;
	}
	system("pause");
	return 0;
}


