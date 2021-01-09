// sstrchar.cpp
// доступ к символам в строке
#include <iostream>
#include <string>
using namespace std;
///////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL,"Rus");
	char charray[80];
	string word;

	cout << "Введите слово: ";
	cin >> word;
	int wlen = word.length();     // длина строки
	cout << "По одному символу: ";
	for (int j = 0; j < wlen; j++)
		cout << word.at(j);        // тут будет проверка на выход за пределы строки
		// cout << word [ j ];        // а тут проверки не будет

	word.copy(charray, wlen, 0); // копируем строку в массив
	charray[wlen] = 0;
	cout << "\nМассив содержит: " << charray << endl;
	system("pause");
	return 0;
}

