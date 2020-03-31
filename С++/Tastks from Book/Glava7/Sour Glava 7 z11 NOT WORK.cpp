#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
class Money
{
private:
	string strMon;
	string strMon1;
	long double summ;
public:
	void ldtoms()
	{
		stringstream conv;
		conv << summ;
		conv >> strMon;
	}
	void getmoney()
	{
		cout << "Enter the amount" << endl;
		cin >> summ;
		if (summ > 9999999999999990.00)
		{
			cout << "\nError. Try Again";
			system("pause");
			exit(1);
		}
	}
	void strings()
	{
		string doll("$");
		strMon1 = strMon;
		strMon1 = doll + strMon1;
		int x = strMon1.find('.');
		strMon1.erase(x, 1);
		reverse(strMon1.begin(), strMon1.end());
		strMon1.insert(5, " ");
		strMon1.insert(8, " ");
		strMon1.insert(11, " ");
		strMon1.insert(14, " ");
		strMon1.insert(17, " ");
		strMon1.insert(2, ".");
		reverse(strMon1.begin(), strMon1.end());
	}
	void display()const
	{
		cout << "\n" << strMon1 << endl;
	}
};

int main()
{
	Money money;
	money.getmoney();
	money.ldtoms();
	money.strings();
	money.display();
	system("pause");
	return 0;
}