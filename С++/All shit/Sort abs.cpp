#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

// ���������� �����\������

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