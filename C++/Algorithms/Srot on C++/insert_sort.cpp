#include <iostream>
using namespace std;

void insert_sort1()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 + 1;
        cout << i << ") " << arr[i] << endl;
    }

    for (int top = 1; top < n; top++)
    {
        int k = top;
        while (k > 0 && arr[k - 1] > arr[k])
        {
            int temp;
            temp = arr[k];
            arr[k] = arr[k - 1];
            arr[k - 1] = temp;
            k -= 1;
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << ") " << arr[i] << endl;
    }
}
void insert_sort2()
{
    int size;
    cin >> size;
    int* arr = new int[n];

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 150 + 100;
        cout << "#" << i << " - " << arr[i] << endl;
    }

    for (int top = 1; top < size; top++)
    {
        int k = top;

        while (k > 0 && arr[k - 1] > arr[k])
        {
            int temp;

            temp = arr[k];
            arr[k] = arr[k - 1];
            arr[k - 1] = temp;
            k -= 1;
        }
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "#" << i << " - " << arr[i] << endl;
    }
}

int main()
{
    insert_sort2();
    system("pause");
}