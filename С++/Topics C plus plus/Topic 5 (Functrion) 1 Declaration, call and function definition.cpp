#include<iostream>
//Объявление, вызов, определение функции
using namespace std;
void repchar(char, int); // Declaration (prototype function)

int main() {
	setlocale(LC_ALL, "Rus");
	
	repchar('-', 43);	// call function
	cout << "Type data Diapazone" << endl;
	repchar('=', 23);	// call function
	cout <<"SOME TEXT SOME TEXT" << endl
	<< "SOME TEXT SOME TEXT" << endl;
	repchar('-',40);	// call function

	cout << endl;
	system("pause");
}

void repchar(char ch, int n) {
	for (int j = 0; j < n; j++) {
		cout << ch;							//definition function
	}
	cout << endl;
}