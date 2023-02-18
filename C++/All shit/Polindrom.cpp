#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * Напишите функцию, которая

называется PalindromFilter
возвращает vector<string>
принимает vector<string> words и int minLength и возвращает все строки из вектора words,
которые являются палиндромами и имеют длину не меньше minLength
Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.
 * */
string mreverse(string str)
{
    string temp;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        temp += str.at(i);
    }
    return temp;
}

vector<string> PalindromFilter(vector<string>& words, int minLength)
{
    vector<string> vec;
    for (auto it : words)
    {
        string str = mreverse(it);
        if (it == str && it.size() >= minLength)
        {
            vec.push_back(it);
        }
    }
    return vec;
}

int main()
{

    vector<string> vec = {"abacaba", "aca"};
    vector<string> vec2 = PalindromFilter(vec, 5);

    for (auto it : vec2)
    {
        cout << it << " ";
    }
    return 0;
}
