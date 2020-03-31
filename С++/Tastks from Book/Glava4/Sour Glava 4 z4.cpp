#include<iostream>


using namespace std;

struct employ {
	int numberemploy;
	float price;
}; 

void Employfunction() {
	employ empl1;
	employ empl2;
	employ empl3;
	setlocale(LC_ALL, "Rus");

	cout << "Input number and price data of 3 empl 1" << endl;
	cin >> empl1.numberemploy >> empl1.price;
	cout << "Input number and price data of 3 empl 2" << endl;
	cin >> empl2.numberemploy >> empl2.price;
	cout << "Input number and price data of 3 empl 3" << endl;
	cin >> empl3.numberemploy >> empl3.price;

	cout << "        Data of employ:" << endl;

	cout << "First empl" << endl;
	cout << "Number " << empl1.numberemploy << endl;
	cout << "Price " << empl1.price << endl;
	cout << endl;
	cout << "Second empl" << endl;
	cout << "Number " << empl2.numberemploy << endl;
	cout << "Price " << empl2.price << endl;
	cout << endl;
	cout << "Third empl" << endl;
	cout << "Number " << empl3.numberemploy << endl;
	cout << "Price " << empl3.price << endl;


		cout << endl;
	system("Pause");
}