#include <functional>
#include <iostream>
#include <vector>
using namespace std;
//-------------------------
void chet(int a)
{
    if ((a % 2) == 0)
        cout << a << endl;
}

void NEchet(int a)
{
    if ((a % 2) != 0)
        cout << a << endl;
}

void cOUT(vector<int> arr, function<void(int)> fun)
{
    for (int i = 0; i < arr.size(); i++)
    {
        fun(arr[i]);
    }
}

void cOUT(vector<int>& arr, vector<function<void(int)>>& fun)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < fun.size(); j++)
        {
            fun[j](arr[i]);
        }
    }
}

//-------------------------
void foo() { cout << "Im is foo!" << endl; }

void bar() { cout << "Im is bar!" << endl; }

//-------------------------
int sum(int a, int b) { return a + b; }

//-------------------------
int main()
{

    setlocale(LC_ALL, "Rus");
    //-------------------------
    function<void()> f; //создаем переменную типа function
    // которая принимает функцию с типом возвр. значения void и принимающей 0 аргуменртов

    f = foo;

    f();

    f = bar;

    f();

    //-------------------------

    function<int(int, int)> f2;
    f2 = sum;
    int res = f2(4, 1);
    cout << "res - " << res << endl;

    //-------------------------

    vector<int> arr = {10, 11, 12, 13, 14, 15, 16, 17, 18};
    function<void(int)> f3;
    f3 = NEchet;
    cOUT(arr, f3);
    cout << endl;
    f3 = chet;
    cOUT(arr, f3);

    //-------------------------
    function<void(int)> f4;
    vector<function<void(int)>> vecF = {NEchet, chet, chet};
    cout << endl;
    cout << endl;
    cOUT(arr, vecF);

    system("Pause");
}