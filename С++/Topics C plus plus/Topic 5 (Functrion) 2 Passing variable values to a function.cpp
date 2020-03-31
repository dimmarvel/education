#include<iostream>
//Передача переменной в параметр функции
using namespace std;
void repchar(char, int); // Declaration (prototype function)

int main() {
	setlocale(LC_ALL, "Rus");
	
	char somechar;
	int someint;

	cout << "Input simvol: ";
	cin >> somechar;
	cout << "Input some number: ";
	cin >> someint;

	repchar(somechar,someint);	// call function

	cout << endl;
	system("pause");
}

void repchar(char ch, int n) {
	for (int j = 0; j < n; j++) {
		cout << ch;							//definition function
	}
	cout << endl;
}