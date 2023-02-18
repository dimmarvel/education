#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

// справочник стран\столиц

int main()
{
    vector<int> v;
    int size = 0;
    cin >> size;
    v.reserve(size + 1);

    for (int i = 0; i < size; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(begin(v), end(v), [](int a, int b) { return abs(a) < abs(b); });
    for (const auto& it : v)
    {
        cout << it << " ";
    }
}