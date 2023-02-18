// arrover3.cpp
// демонстраци€ создани€ безопасного массива, провер€ющего
// свои индексы при использовании
// используетс€ перегрузка операции [ ]

#include <iostream>
using namespace std;
#include <process.h>    // дл€ функции exit
const int LIMIT = 1000; // размер массива

class safearray
{
protected:
    int arr[LIMIT];

public:
    // обратите внимание, что функци€ возвращает ссылку!
    int& operator[](int n)
    {
        if (n < 0 || n >= LIMIT)
        {
            cout << "\nќшибочный индекс!";
            exit(1);
        }
        return arr[n];
    }
};

class safehilo : public safearray
{
private:
    int up, down, down2, differ = 0;

public:
    safehilo() : safearray() {}
    safehilo(int up, int low) : up(up), down(low) {}
    void getarr()
    {
        differ = up - 100;
        down2 = down;
        for (int i = down - differ; i < up - differ; i++)
            arr[i] = (down2++) * 10;
    }
    void showarray()
    {
        for (int i = down - differ; i < up - differ; i++)
        {
            int temp = arr[i]; // используем функцию справа от знака =
            cout << "Element " << down++ << " equal " << temp << endl;
        }
    }
};
int main()
{
    safehilo s1(100, 5);
    s1.getarr();
    s1.showarray();

    cout << endl;
    system("pause");
    return 0;
}
