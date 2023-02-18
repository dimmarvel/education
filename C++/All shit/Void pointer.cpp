#include <iomanip>
#include <iostream>

using namespace std;
typedef bool (*howsort2)(int, int);

bool bolshe(int a, int b) { return a > b; }

bool menshe(int a, int b) { return a < b; }

void sort(int* arr, int size, bool (*howsort)(int, int) = bolshe)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (howsort(arr[j], arr[j + 1]))
                swap(arr[j], arr[j + 1]);
        }
    }
}

void sort2(int* arr, int size, howsort2 pointerOnFunc = bolshe)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (pointerOnFunc(arr[j], arr[j + 1]))
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    int arr[8] = {1, 2, 5, 17, 8, 7, 20, 5};
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    sort(arr, 8, menshe);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    system("pause");
}