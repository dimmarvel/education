#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// ���������� �����\������

string Lower(const string& str)
{
    string lower;
    for (const auto& it : str)
    {
        lower += tolower(it);
    }

    return lower;
}

int main()
{
    vector<string> v;
    int size = 0;
    cin >> size;
    v.reserve(size + 1);

    for (int i = 0; i < size; i++)
    {
        string num;
        cin >> num;
        v.push_back(num);
    }

    sort(begin(v), end(v), [](string a, string b) { return Lower(a) < Lower(b); });

    for (const auto& it : v)
    {
        cout << it << " ";
    }
}