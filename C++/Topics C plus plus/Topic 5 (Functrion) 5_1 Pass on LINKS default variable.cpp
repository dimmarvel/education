// применение ссылочного механизма передачи аргументов
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	void intfrac(float, float&, float&); //prototype
	float number, intpart, fracpart;
	do {
		cout << "\nВведите вещественное число:";
		cin >> number;                          // ввод числа пользователем
		intfrac(number, intpart, fracpart);		// нахождение целой и дробной части
		cout << "Целая часть равна " << intpart // вывод результатов
			<< ", дробная часть равна " << fracpart << endl;

	} while (number != 0.0); //если ввели - выходим

	system("pause");
}


// вычисляет целую и дробную часть вещественного числа
void intfrac(float n, float& intp, float& fracp)
{
	long temp = static_cast<long>(n);	//преобразование к типу лонг чтобы оставить только целое
	intp = static_cast<float>(temp);    //преобразуем обратно чтобы получить то же число
	fracp = n - intp;				    //вычитаем то же число и число без остатка(temp)
}


