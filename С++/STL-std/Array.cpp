#include<iostream>
#include<array>
using namespace std;

int main() {

	setlocale(LC_ALL, "Rus");

	array<int, 10> arr; //статик массив

	cout << arr.front() << endl;
	cout << arr.back() << endl;

	arr.fill(10);
	for (auto elem : arr) {
		cout << elem << endl;
	}

	system("Pause");
}