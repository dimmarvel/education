#include <iostream>
#include <string>
#include <set>
/*
Переберем все символы, встречающиеся в строке, а затем переберем все позиции
и в случае совпадения прибавим к счетчику единицу. Найдем максимальное значение счетчика
O(N*K) где N - количество букв, К - количество различных букв
*/
using namespace std;

int main() {
    set<char> input;
    string temp;
    cin >> temp;

    for (int i = 0; i < temp.size(); ++i)
        input.insert(temp[i]);

    char ans = ' ';
    int anscnt = 0;

    for(const auto& it : input) {
        int nowcnt = 0;
        for (int j = 0; j < temp.size(); ++j) {
            if(it == temp[j])
                nowcnt++;
        }
        if(nowcnt > anscnt)
        {
            ans = it;
            anscnt = nowcnt;
        }
    }

    cout << ans;

    return 0;
}
