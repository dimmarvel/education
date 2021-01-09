#include<iostream>
//структура хранени€ инфы о детал€х
using namespace std;
struct part { //объ€вление структуры
	int modelnumber; //номер модели
	int partnumber; //номер детали
	float cost; //стоимость
};
int main() {

	part part1;

	part1.modelnumber = 6244;
	part1.cost = 373;
	part1.partnumber = 217.55F;
	cout << "Model = " << part1.modelnumber << endl;
	cout << "Cost = $" << part1.cost << endl;
	cout << "Numberpart = " << part1.partnumber << endl;
	
	system("pause");
}