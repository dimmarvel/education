#include <array>
#include <iostream>
using namespace std;

int main()
{

    setlocale(LC_ALL, "Rus");

    array<int, 4> arr = {1, 2, 4, 6};    //������ ������
    array<int, 4> arr2 = {5, 2, 10, 20}; //������ ������

    cout << (arr == arr2) << endl;
    cout << (arr > arr2) << endl;
    cout << (arr < arr2) << endl;
    cout << (arr >= arr2) << endl;
    cout << (arr <= arr2) << endl;
    cout << (arr != arr2) << endl;

    system("Pause");
}