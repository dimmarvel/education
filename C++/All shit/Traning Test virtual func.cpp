#include<iostream>
using namespace std;
typedef bool(*howsort)(int, int);
bool menshe(int a, int b) {
	return a < b;
}
bool bolshe(int a, int b) {
	return a > b;
}
void sort(int *arr, int size, howsort bm = bolshe) {
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (bm(arr[j],arr[j+1])) {
				swap(arr[j],arr[j+1]);
			}
		}
	}
}
int main() {
	int arr[10] = { 5,4, 2, 14, 19, 10,11,7,6,1 };
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	sort(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ' ';
	}
	system("pause");
}