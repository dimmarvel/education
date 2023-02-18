#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int atoi(string s)
{
    int res = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        res *= 10;
        res += s[i] - '0';
    }
    return res;
}

string itoa(int n)
{
    string res = "";
    while (n > 0)
    {
        res += '0' + n % 10;
        n /= 10;
    }
    reverse(res.begin(), res.end());

    return res;
}
