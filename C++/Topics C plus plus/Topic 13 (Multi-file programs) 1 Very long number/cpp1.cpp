#include "H1.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	unsigned long numb, j;
	verylong fact = 1;       //инициализировать verylong

	cout << "\n\n¬ведите число: ";
	cin >> numb;           //ввод числа типа long int

	for (j = numb; j > 0; j--)  //факториал Ч это numb *
		fact = fact * j;     //  numb-1 * numb-2 *
	cout << "‘акториал= "; //  numb-3 и т. д.
	fact.putvl();          //вывести значение факториала
	cout << endl;
	system("pause");
	return 0;
}

