// ptrtostr.cpp
// массив указателей на строки
#include <cstring>
#include <iostream>
using namespace std;
const int DAYS = 7;
void bsort(const char*, int);

int main()
{
    setlocale(LC_ALL, "Rus");
    // массив указателей на строки
    const char* arrptrs[DAYS] = {"Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"};
    cout << "\nНеупорядоченный:\n";
    for (int j = 0; j < DAYS; j++)
    { // покажем все строки
        cout << arrptrs[j] << endl;
    }
    bsort(arrptrs[0], DAYS);
    cout << "\nУпорядоченный:\n" << endl;

    for (int j = 0; j < DAYS; j++)
    {
        cout << *(arrptrs + j) << endl;
    }
    system("pause");
    return 0;
}

void bsort(const char* pp, int n)
{
    void order(const char*, const char*);
    int j, k;
    for (j = 0; j < n - 1; j++)
    {
        for (k = 0; k < n; k++)
        {
            order(pp + j, pp + k);
        }
    }
}

void order(const char* pp1, const char* pp2)
{
    if (strcmp(pp1, pp2) > 0)
    {
        const char* tempptr = pp1;
        pp1 = pp2;
        pp2 = tempptr;
    }
}