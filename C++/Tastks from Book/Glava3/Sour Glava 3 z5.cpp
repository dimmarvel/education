#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	for (int i = 1; i < 21; i++)
	{
		cout<< setw(i) << setfill('X') << "X"<< endl;
	}

	cout << endl;
	system("Pause");
}