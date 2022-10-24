#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	int variant;
	float F, C;
	float res1, res2;
	cout << "Введите 1 если считаете из Цельсия в Фаренгейты." << endl;
	cout << "Введите 2 если считаете из Фаренгейта в Цельсии." << endl;
	cin >> variant;
	switch (variant) {
		case 1:
		    cout << "Введите температуру по Цельсию: ";
			cin >> C;
			res1 = C * (9 / 5) + 32;
			cout << "Значение по Фаренгейту: " << res1;
			break;
		case 2:
			cout << "Введите температуру по Фаренгейту: ";
			cin >> F;
			res2 = (F-32)*5/9;
			cout << "Значение по Цельсию: " << res2;
			break;
        default:
		cout << "Некорректно введено число.";
	}
	cout << endl;
	system("Pause");
}