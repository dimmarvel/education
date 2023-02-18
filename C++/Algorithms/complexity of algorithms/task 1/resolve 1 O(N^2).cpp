#include <iostream>
#include <string>
/*
Переберем все позиции и для каждой позиции в строке ещё раз
переберем все позиции и в случае совпадения прибавим к счетчику единицу.
Найдем максимальное значение счетчика.
*/
using namespace std;

int main()
{
    string temp;
    cin >> temp;

    char ch = ' ';
    int anscnt = 0;

    for (int i = 0; i < temp.size(); ++i)
    {
        int nowcnt = 0;
        for (int j = 0; j < temp.size(); ++j)
        {
            if (temp[i] == temp[j])
                nowcnt++;
        }
        if (nowcnt > anscnt)
        {
            ch = temp[i];
            anscnt = nowcnt;
        }
    }

    cout << ch;

    return 0;
}
