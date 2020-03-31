#include<iostream>
//карточная игра на структуре 154стр.
using namespace std;

const int clubs = 0;   //трефа
const int diamonds = 1; //бубна
const int hearts = 2;  //чирва
const int spades = 3;  //пика

const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

struct card {
	int number; //достоинство
	int suit; //масть
};

int main() {
	setlocale(LC_ALL, "Rus");

	card temp, chosen, prize;
	int position;

	card card1 = {7, clubs};
	cout << "карта 1: 7 треф\n";
	card card2 = {jack, hearts};
	cout << "карта 2: валет чирва\n";
	card card3 = {ace, spades};
	cout << "карта 3: туз пик\n";

	prize = card3;
	cout << "Меняем местами карту 1 и карту 3...\n";
	temp = card3; card3 = card1; card1 = temp;
	cout << "Меняем местами карту 2 и карту 3...\n";
	temp = card3; card3 = card2; card2 = temp;
	cout << "Меняем местами карту 1 и карту 2...\n";
	temp = card2; card2 = card1; card1 = temp;

	cout << "На какой позиции (1, 2 или 3) теперь туз пик?\n";
	cin >> position;
	
	switch (position) {
		case 1: chosen = card1; break;
		case 2: chosen = card2; break;
		case 3: chosen = card3; break;
	}

	if (chosen.number == prize.number && chosen.suit == prize.suit) {
		cout <<"YOU WIN\n";
	}
	else {
		cout << "YOU LOST\n";
	}

	system("pause");
}