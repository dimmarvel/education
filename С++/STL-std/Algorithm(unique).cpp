#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {

	setlocale(LC_ALL, "Rus"); 
	vector<int> arr = { 1, 2, 3, 5, 9,9,2,3 };
	vector<int> arr2;

	unique_copy(begin(arr), end(arr), back_inserter(arr2));
	for_each(begin(arr2), end(arr2), [](int a) {cout << a << endl; });
		cout << endl;
	arr.erase(unique(begin(arr), end(arr)), end(arr));
	for_each(begin(arr), unique(begin(arr), end(arr)), [](int a) {cout << a << endl; });


	system("Pause");
}