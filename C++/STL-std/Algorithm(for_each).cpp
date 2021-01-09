#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


int main() {

	setlocale(LC_ALL, "Rus");
	int arr[] = { 1, 2, 3, 6, 10, 7};

	for_each(begin(arr), end(arr), [](int a) {cout << a << endl; });
	for (auto a : arr) {
		cout << a << endl;
	}

	system("Pause");
}