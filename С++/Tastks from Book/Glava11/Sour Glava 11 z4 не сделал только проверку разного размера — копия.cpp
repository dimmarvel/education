// clarray.cpp
// создает класс-массив
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Array                  //моделирует обычный массив C++ 
{
private:
	int* ptr;                //указатель на содержимое Array
	int size;                //размер Array
public:
	Array(int s){size = s;ptr = new int[s];}
	Array(Array& arr2) {
	cout << "\nCopy constructor HERE" << endl;
		delete[] ptr;
		size = arr2.size;
		ptr = new int[size];
			for (int i = 0; i < size; i++)
			{
				ptr[i] = arr2[i];
			}
	}
	Array(Array& arr2, int size1) {
	cout << "Copy constructor HERE" << endl;
	size = size1;
		if (arr2.size == size)
		{
			for (int i = 0; i < size; i++)
			{
				arr2[i] = ptr[i];
			}
		}
		else {
			cout << "Size error";
		}
	}
	~Array() { delete[] ptr; }  //деструктор
	int& operator [] (int j) {return *(ptr + j);} //перегружаемая операциясписка индексов
	int& operator = (Array* arr2) {
		cout << "Operator = constructor HERE" << endl;
		if (arr2->size == size)
		{
			for (int i = 0; i < size; i++)
			{
				arr2[i] = ptr[i];
			}
		}
		else {
			cout << "Size error";
		}
	}
};
///////////////////////////////////////////////////////////
int main()
{
	const int ASIZE = 10;           //размер массива
	Array arr(ASIZE);               //создать массив

	for (int j = 0; j < ASIZE; j++) //заполнить его j^2
		arr[j] = j * j;

	for (int j = 0; j < ASIZE; j++) //вывести его содержимое
		cout << arr[j] << ' ';
	Array arr2(arr);

	for (int j = 0; j < ASIZE; j++) //вывести его содержимое
		cout << arr2[j] << ' ';
	Array arr3(ASIZE);
	arr3 = arr2;

	cout << "\n";
	for (int j = 0; j < ASIZE; j++) //вывести его содержимое
		cout << arr3[j] << ' ';

	system("pause");
	cout << endl;
	return 0;
}