// iterev.cpp
// демонстрация обратного итератора
#include <iostream>
#include <list>
using namespace std;
int main()
{
	int arr[] = { 2, 4, 6, 8, 10 };    // массив типа int
	list<int> theList;
	for (int i = 0; i < 5; i++)
		theList.push_back(arr[i]);
	list<int>::reverse_iterator revit;
	revit = theList.rbegin();
	while (revit != theList.rend())
		cout << *revit++ << endl;
	cout << endl;
	system("pause");
	return 0;
}