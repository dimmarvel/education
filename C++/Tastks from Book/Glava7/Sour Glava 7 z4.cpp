#include<iostream>
using namespace std;

void maxint(int arr[], int SIZE, int& max, int& index);
int main() {
	setlocale(LC_ALL, "Rus");
	int SomeNumb;
	const int size = 10;
	int NumbArr[size];
	int max = 0, index;
	cout << "Input 10 numb: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << " - ";
		cin >> NumbArr[i];
	}
	maxint(NumbArr, size, max, index);
	cout << "index = " << index << endl <<
		"Max = " << max;
	cout << endl;
	system("Pause");
}
void maxint(int arr[], int SIZE, int& max, int& index)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			index = i;
		}
	}
}