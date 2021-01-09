#include<iostream>
//инициализация
using namespace std;

struct part { //объявление структуры
	int modelnumber; //номер модели
	int partnumber; //номер детали
	float cost; //стоимость
};

int main() {
    // способ инициализации переменной ***
	part part1 = {6224,373,217.55F};
	part part2;

	cout << "Model = " << part1.modelnumber << endl;
	cout << "Cost = $" << part1.cost << endl;
	cout << "Numberpart = " << part1.partnumber << endl;


	//можно присваивать те же значения другой переменной того же типа(part)
	part2 = part1;
	cout << "Model = " << part2.modelnumber << endl;
	cout << "Cost = $" << part2.cost << endl;
	cout << "Numberpart = " << part2.partnumber << endl;
	system("pause");
}