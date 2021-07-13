#include <iostream>

using namespace std;

int i, j, key=0, temp=0;

void InsertSort(int *mas, int n) //сортировка вставками
{
    for (i=0; i<n-1; i++)
    {
        key=i+1;
        temp=mas[key];
        for (j=i+1; j>0; j--)
        {
            if (temp<mas[j-1])
            {
                mas[j]=mas[j-1];
                key=j-1;
            }
        }
        mas[key]=temp;
    }
    cout<<endl<<"Результирующий массив: ";
    for (i=0; i<n; i++) //вывод массива
        cout<<mas[i]<<" ";
}

//главная функция
int main ()
{
    int n;

    cout << "Количество элементов в массиве > ";
    cin>>n;
    int *mas=new int[n];
    for (i=0; i<n; i++) //ввод массива
    { cout<<i+1<<" элемент > "; cin>>mas[i]; }
    InsertSort(mas, n); //вызов функции
    delete[] mas;
    system("pause>>void");
}