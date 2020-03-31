// подсчет факториала числа с помощью рекурсии
#include <iostream>
using namespace std;

unsigned long factfunc(unsigned long); // прототип
int main()
{
	setlocale(LC_ALL,"Rus");
	int n = 5;                               // число, вводимое пользователем
	unsigned long fact;                  // факториал этого числа
	fact = factfunc(n);
	cout << "Факториал числа " << n << " равен " << fact << endl;
	system("pause");
}

// рекурсивно подсчитывает факториал числа
unsigned long factfunc(unsigned long n)
{

	if (n > 1) {
		return n *factfunc(n-1);
	}
	else {
		return 1;
	}

}


