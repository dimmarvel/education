// persort.cpp
// сортировка объектов через массив указателей на них
#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int **arr = new int*[9];
	for (int i = 0; i < 9; i++)
	{
		arr[i] = new int[10];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			arr[i][j] = i + 1;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		cout << endl;
			for (int j = 0; j < 10; j++)
			{
				cout << arr[i][j] << "   ";
			}
	}

	for (int i = 0; i < 9; i++)
	{
		delete [] arr[i];
	}
	delete [] arr;
	system("pause");
	return 0;
}



