// демонстрирует статические локальные переменные
#include <iostream>
using namespace std;

float getavg(float);    // прототип функции

int main()
{
	setlocale(LC_ALL,"Rus");
	float data = 1, avg;
	while (data != 0)
	{
		cout << "Введите число: ";
		cin >> data;
		avg = getavg(data);
		cout << "Среднее значение: " << avg << endl;
	}

	system("pause");
}

// находит среднее арифметическое всех введенных значений
float getavg(float newdata)
{
	static float total = 0;    // инициализация статических
	static int count = 0;      // переменных при первом вызове
	count++;                   // увеличение счетчика
	total += newdata;          // добавление нового значения к сумме
	return total / count;      // возврат нового среднего значения
}


