#include <iostream>
using namespace std;
void arraySum(float* arr, float* arr2, float* sumarr, int size);
void arrayinpt(float* array, const int);
void displayarr(float* arr, const int size);
int main()
{
    const int size = 20;
    float* array = new float[size];
    float* array2 = new float[size];
    float* sumarray = new float[size];
    arrayinpt(array, size);
    displayarr(array, size);
    arrayinpt(array2, size);
    displayarr(array2, size);
    arraySum(array, array2, sumarray, size);
    displayarr(sumarray, size);
    system("pause");
}
void arraySum(float* arr, float* arr2, float* sumarr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        sumarr[i] = arr[i] + arr2[i];
    }
}
void arrayinpt(float* array, const int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = i;
    }
}
void displayarr(float* arr, const int size)
{
    cout << "array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i << ") - " << arr[i] << endl;
    }
}