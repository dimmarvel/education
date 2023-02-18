#include <deque> //двусторонн€€ очередь
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    setlocale(LC_ALL, "Rus");

    deque<int> dq = {1, 6, 2};
    // in memory looks like [1][2][3] -> [4][5][6] ->[7][8][9]
    //всЄ остальное как в векторе\листе

    system("Pause");
}
