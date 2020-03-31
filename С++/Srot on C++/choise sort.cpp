#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int*arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100 + 1;
		cout << i << ") " << arr[i] << endl;
	}

	for (int i = 0; i < n-1; i++) {
		for (int j = i+1; j < n ;j++)
		{
			if (arr[j] < arr[i]) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
	}	}	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i << ") " << arr[i] << endl;
	}
	system("pause");
}