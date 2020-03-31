// parse.cpp
// программа разбора арифметических выражений
#include <iostream>
#include <cstring>
using namespace std;
const int LEN = 80;
const int MAX = 20;
class stack {
private:
	char s[MAX];
	int counter;
public:
	stack()
	{
		counter = 0;
	}
	void push(char var)
	{
		s[++counter] = var;
	}
	int pop()
	{
		return s[--counter];
	}
	int getcounter()
	{
		return counter;
	}

};

class express
{
private:
	stack s;
	char* pStr;
	int len;
public:
	express(char* str)
	{
		pStr = str;
		len = strlen(str);
	}
	void parse();
	int solve();
};
void express::parse()
{
	char ch;
	char lastval;
	char lasttop;
	for (int i = 0; i < len; i++)
	{
		ch = pStr[i];
		if (ch >= '0' && ch <= '9')
		{
			s.push(ch - '0');
		}
		else
			if (s.getcounter() == 1)
			{
				s.push(ch);
			}
			else 
			{
				lastval = s.pop();
				lasttop = s.pop();
				if ((ch == '*' || ch == '/') && (lasttop == '+' || lasttop == '-'))
				{
					s.push(lasttop);
					s.push(lastval);
				}
				else
				{
					switch (lasttop)
					{
						case '+': s.push(s.pop() + lastval); break;
						case '-': s.push(s.pop() - lastval); break;
						case '*': s.push(s.pop() * lastval); break;
						case '/': s.push(s.pop() / lastval); break;
					}
				}
				s.push(ch);
			}
	}
}
int express::solve()
{
	char lastval;
	while (s.getcounter() > 1)
	{
		lastval = s.pop();
		switch (s.pop())
		{
			case '+': s.push(s.pop() + lastval); break;
			case '-': s.push(s.pop() - lastval); break;
			case '*': s.push(s.pop() * lastval); break;
			case '/': s.push(s.pop() / lastval); break;
		}
	}
	return int(s.pop());
}
int main()
{
	setlocale(LC_ALL, "Rus");
	char ans;            // 'д' или 'н'
	char string[LEN]; // строка для разбора

	do
	{
		cout << "\nВыражение";
		cin >> string;
		express* eptr = new express(string);
		eptr->parse();
		cout << "\nResult: " << eptr->solve() << endl;
		delete eptr;
		cout << "\nOne more? say(y\n)"; cin >> ans;
	}while(ans == 'y');
	system("pause");
	return 0;
}


