#include <iostream>
#include <map>
#include <string>
/*
Заведем словарь, где ключом является символ, а значением - сколько
он встретился. Если символ встретился впервые - создаем элемент словаря с ключом,
совпадающем с этим символом и значением ноль. Прибавляем к элементу словаря с
ключом, совпадающем с этим символом, единицу
O(N+K) = O(N) - где N - количество букв, К - количество различных букв
*/
using namespace std;

int main()
{
    map<char, int> dct;
    string input;
    cin >> input;

    char ans = ' ';
    int anscnt = 0;

    for (int i = 0; i < input.size(); i++)
    {
        if (dct.find(input[i]) == dct.cend()) // if is not here
            dct[input[i]] = 0;

        dct[input[i]] += 1;
    }

    for (const auto& it : dct)
    {
        if (it.second > anscnt)
        {
            anscnt = it.second;
            ans = it.first;
        }
    }

    cout << ans;

    return 0;
}
