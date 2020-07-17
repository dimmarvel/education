#include <iostream>
using namespace std;

void choise_sort1()
{
	int n;
	cin >> n;
	int*arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100 + 1;
		cout << i << ") " << arr[i] << endl;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i]) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i << ") " << arr[i] << endl;
	}
}

void choise_sort2()
{
	int n;
	cin >> n;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 50 + 1;
		cout << i << ") " << arr[i] << endl;
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i]) {
				int temp = arr[j];

				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "#" << i << "-> " << arr[i] << endl;
	}
}
int main() {
	choise_sort2();
	system("pause");
}