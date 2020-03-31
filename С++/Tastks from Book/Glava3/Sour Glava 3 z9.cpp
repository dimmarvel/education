#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	float People, NumberMestFromTabel, otvet = 1, g; //g вспомогательна€ переменна€
	cout << "¬ведите число гостей:";
	cin >> People;
	cout << "„исло мест за столом:";
	cin >> NumberMestFromTabel;
	for (int i = 0; i < NumberMestFromTabel; i++) { //пример: введено число 15 и 5 что делает цикл: 15*14*13*12*11*10
		g = People;
		otvet *= g;
			//otvet = (People * (People - 1)) * otvet;
			cout << "iteraciua " << i+1 << setw(10) << "| otvet =" << otvet << setw(10) << "| People =" << People << setw(10) << "| g =" << g << setw(10) << endl;
		People--;
	}

	cout << endl;
	system("Pause");
}