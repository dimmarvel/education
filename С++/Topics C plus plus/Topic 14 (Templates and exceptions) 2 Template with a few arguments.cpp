// tempfind.cpp
// Ўаблон функции поиска в массиве
#include <iostream>
using namespace std;
//---------------------------------------------------------
// функци€ возвращает индекс или Ц1 при отсутствии //совпадени€
template<class atype, class btype>
int find(atype *arr, atype value, btype size) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value) {
			return i;
		}
	}
	return -1;
}
//---------------------------------------------------------
char chrArr[] = { 1, 3, 5, 9, 11, 13 }; //массив
char ch = 5;                            //искомое значение
int intArr[] = { 1, 3, 5, 9, 11, 13 };
int in = 6;
long lonArr[] = { 1L, 3L, 5L, 9L, 11L, 13L };
long lo = 11L;
double dubArr[] = { 1.0, 3.0, 5.0, 9.0, 11.0, 13.0 };
double db = 4.0;

int main()
{
	cout << "\n 5 в chrArray: индекс=" << find(chrArr, ch, 6);
	cout << "\n 6 в intArray: индекс=" << find(intArr, in, 6);
	cout << "\n11 в lonArray: индекс=" << find(lonArr, lo, 6);
	cout << "\n 4 в dubArray: индекс=" << find(dubArr, db, 6);
	cout << endl;
	return 0;
}