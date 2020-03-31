#include<iostream>
//дни недели на структуре перечисления 157стр.
using namespace std;

//объявление перечисляемого типа
enum days_of_week {Sun, Mon, Tue, Wed, Thu, Fri, Sat};

int main() {
	setlocale(LC_ALL, "Rus");
	days_of_week day1, day2; //определение переменных хранящих дни недели
	day1 = Mon;
	day2 = Thu;
	int diff = day2 - day1;
	cout << "Разница в днях: " << diff << endl;
	if (day1 < day2) {
		cout << "day1 наступит раньше, чем day2\n";
	}
	

	system("pause");
}