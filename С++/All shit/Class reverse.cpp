#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


class  ReversibleString
{
	string str;
public:
	ReversibleString(){}
	ReversibleString(const string& stroke)
	{
		str = stroke;
	}
	void Reverse()
	{
		string temp;
		for (int i = str.size()-1; i >= 0; i--)
		{
			temp += str[i];
		}
		str = temp;
	}
	string ToString() const
	{
		return str;
	}
};

int main() {
	ReversibleString s("live");
	s.Reverse();
	cout << s.ToString() << endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	string tmp = s_ref.ToString();
	cout << tmp << endl;

	ReversibleString empty;
	cout << '"' << empty.ToString() << '"' << endl;

	return 0;
}