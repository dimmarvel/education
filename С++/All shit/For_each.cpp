#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	int arr[] = { 2,5,7,8,42,1 };

	for(auto &element : arr)
	{
		element = -1;
		cout << element << endl;
	}

	list<int> lst= { 2,5,67,8,4,2,1 };

	for (const auto &element : lst) {
		cout << element << endl;
	}

	system("pause");
}