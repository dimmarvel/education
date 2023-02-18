#include <iostream>
using namespace std;
void bubble_sort1(int* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void buble_sort2(int* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void coutArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "n -" << i << "- = " << arr[i] << endl;
    }
}

void swap(int* srt, int* srt2)
{
    int temp = *srt;
    *srt = *srt2;
    *srt2 = temp;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int siz;
    cin >> siz;
    int* arr = new int[siz];

    for (int i = 0; i < siz; i++)
    {
        arr[i] = rand() % 100 + 1;
        cout << "n -" << i << "- = " << arr[i] << endl;
    }
    buble_sort2(arr, siz);
    cout << endl;
    coutArr(arr, siz);
    cout << endl;
    system("pause");
    return 0;
}