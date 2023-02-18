#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * �������� �������, �������

���������� PalindromFilter
���������� vector<string>
��������� vector<string> words � int minLength � ���������� ��� ������ �� ������� words,
������� �������� ������������ � ����� ����� �� ������ minLength
������� ������ �������� �� ����� 100 �����, ����� ������ ������ �� ������ 100 ��������.
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
