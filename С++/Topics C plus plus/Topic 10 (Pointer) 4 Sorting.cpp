// passarr.cpp
// передача массива по указателю
#include <iostream>
using namespace std;
const int MAX = 5;            // количество элементов в массиве
void sort(int*, int*);
void sortPuzir(int*,int);
void coutArr(int* arr, int size);
int main()
{
	const int siz = 7;
	int n1[siz] = {12,24,51,21,2,4,1};
	
	for (int i = 0; i < siz; i++)
	{
		cout << "n -" <<i <<"- = "<< n1[i] << endl;
	}
	sortPuzir(n1,siz);
	cout << endl;
	coutArr(n1,siz);
	cout << endl;
	system("pause");
	return 0;
}
void coutArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "n -" << i << "- = " << arr[i] << endl;
	}
}
void sortPuzir(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			sort(arr+i,arr+j);
		}
	}
}

void sort(int* srt, int* srt2)
{
	if(*srt > *srt2){
		int temp = *srt;
		*srt = *srt2;
		*srt2 = temp;
	}
}
