#include<iostream>
using namespace std;
void swap(int&, int&);
int main() {
	setlocale(LC_ALL, "Rus");

	int one, two;

	cout << "Swaping first and second: " << endl;
	cin >> one >> two;
	swap(one, two);
	cout << one << " " << two;

	system("Pause");
}
void swap(int& one, int& two) {
	int temp = one;
	one = two;
	two = temp;
}

