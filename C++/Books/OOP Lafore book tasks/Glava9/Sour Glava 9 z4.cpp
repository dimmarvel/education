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

	void getdata()
	{
		cout << "\nInput Name: "; cin >> Name;
		cout << "Input Price: ";  cin >> Price;
	}

	void showdata()const
	{
		cout << "\nName: " << Name;
		cout << "\nPrice: " << Price;
	}

};
class Sales
{
private:
	enum {MONTH = 3};
	float PricePerMonth[MONTH];
public:

	void getdata()
	{
		
		for (int i = 0; i < MONTH; i++)
		{
		cout << "Month: " << i+1 << endl;
		cout << "Input PricePerMonth: ";
		cin >> PricePerMonth[i];
		}
	}
	void showdata()const
	{
		for (int i = 0; i < MONTH; i++)
		{
			cout << "Month: " << i + 1 << endl;
			cout << "PricePerMonth: " << PricePerMonth[i] << endl;
		}
	}

};

class book : public Publication, public Sales
{
private:
	int Pages;
public:
	book() : Pages(0) {}
	book(int p) : Pages(p) {}

	void getdata()
	{	
		Publication::getdata();	
		Sales::getdata();
		cout << "Input pages: ";  cin >> Pages;	
	}

	void showdata()const
	{
		Publication::showdata();	
		Sales::showdata();
		cout << "Pages: " << Pages << endl;		
	}

};
class type : public Publication, public Sales
{
private:
	float time;
public:
	type() : time(0) {}
	type(float z) : time(z) {}

	void getdata()
	{
		Publication::getdata();
		Sales::getdata();
		cout << "Input time: "; cin >> time;
	}

	void showdata()const
	{
		Publication::showdata();
		Sales::showdata();
		cout << "Time: " << time << endl;
	}

};

class disk : public Publication, public Sales
{
private:
	enum howdisk {CD, DVD};
public:
	char ch;
	howdisk disk;
	void getdata()
	{
		Publication::getdata();
		cout << "Input C (CD) or D (DVD): ";
		cin >> ch;
		if (ch == 'C') {
			disk = CD;
		}else disk = DVD;
		Sales::getdata();
	}
	void showdata() const 
	{
		Publication::showdata();
		if (disk == CD) {
			cout << endl << "Disk =" << "CD" << endl;
		}else cout << endl << "Disk =" << "DVD" << endl;
		Sales::showdata();
	}
};
int main()
{
	setlocale(LC_ALL, "Rus");
	type t;
	book b;
	disk d;
	t.getdata();
	b.getdata();
	d.getdata();
	t.showdata();
	b.showdata();
	d.showdata();

	cout << endl;
	system("pause");
	return 0;
}


