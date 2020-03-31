#include<iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace std;
class bMoney
{
private:
	string strMon;
	long double number;

public:
	bMoney() : number(0)
	{}
	void mstold()
	{
		cout << "Enter the amount in decimal point. End with a dollar sign" << endl;
		getline(cin, strMon, '$');

		int wlen = strMon.length();
		int n = 0;
		string num;

		for (int j = 0; j < wlen; j++)
			if (strMon[j] != ',' && strMon[j] != '$')
				num.push_back(strMon[j]); ;
		number = stold(num);
	}
	bMoney operator+(bMoney mon2)
	{
		bMoney temp;
		temp.number = number + mon2.number;
		return temp;
	}
	bMoney operator-(bMoney mon2)
	{
		bMoney temp;
		temp.number = number - mon2.number;
		return temp;
	}
	bMoney operator*(long double mon2)
	{
		bMoney temp;
		temp.number = number * mon2;
		return temp;
	}
	bMoney operator/(long double mon2)
	{
		bMoney temp;
		temp.number = number / mon2;
		return temp;
	}
	long double operator/(bMoney mon2)
	{			
		return number / mon2.number;
	}
	void display()const
	{
		cout << setiosflags(ios::fixed)
			<< setiosflags(ios::showpoint)
			<< setprecision(2)
			<< "\n" << number << '$' << endl;
	}
};

int main()
{
	bMoney money1, money2, moneysum;
	char ans;
	long double temp;
	do
	{
		money1.mstold();
		money2.mstold();

		cout << "\n + = "; 
		moneysum = money1 + money2;
		moneysum.display();

		cout << "\n - = "; 
		moneysum = money1 - money2;
		moneysum.display();

		cout << "\n * = "; 
		moneysum = money1 * 2;
		moneysum.display();

		cout << "\n bMoney / = "; 
		moneysum = money1 / 2;
		moneysum.display();

		cout << "\n / long dbl = "; 
		temp = money1 / money2;
		cout << "\n" << temp << "$";

		cout << "\nrepeat?" << endl;
		cin.get();
	} while (cin.get() != 'n');
	system("pause");
	return 0;
}