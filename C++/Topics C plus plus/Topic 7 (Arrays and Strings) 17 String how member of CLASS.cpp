// использование строк в классе
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
///////////////////////////////////////////////////////////
class part
{
private:
	char partname[30]; // название
	int partnumber;       // номер
	double cost;          // цена
public:
	void setpart(const char* pname, int pn, double c)
	{
		strncpy(partname, pname, 30);
		partnumber = pn;
		cost = c;
	}
	void showpart()
	{
		cout << "\nНазвание = " << partname;
		cout << ", номер = " << partnumber;
		cout << ", цена = $" << cost;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL,"Rus");
	part part1, part2;

	part1.setpart("муфта", 4473, 217.55);
	part2.setpart("вороток", 9924, 419.25);
	cout << "\nПервая деталь: "; part1.showpart();
	cout << "\nВторая деталь: "; part2.showpart();
	cout << endl;
	system("pause");
	return 0;
}


