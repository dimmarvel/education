#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main()
{
	map<string, string> words;
	int size;
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		string command;
		cin >> command;
		if (command == "ADD")
		{
			string word1, word2;
			cin >> word1 >> word2;
			words.insert({ word1,word2 });
		}
		else if (command == "COUNT")
		{
			string word;
			set<string> st;

			cin >> word;

			for (const auto& it : words)
			{
			
				if (it.first == word)
				{
					st.insert(it.second);
				}
				else if (it.second == word)
				{
					st.insert(it.first);
				}
			}

			cout << st.size() << endl;
		}
		else if (command == "CHECK")
		{
			string word1, word2;
			cin >> word1 >> word2;
			bool is_here = false;
			for (const auto& it : words)
			{
				if (it.first == word1 && it.second == word2)
				{
					cout << "YES" << endl;
					is_here = true;
					break;
				}
				else if (it.second == word1 && it.first == word2)
				{
					cout << "YES" << endl;
					is_here = true;
					break;
				}
			}

			if (!is_here)
			{
				cout << "NO" << endl;
			}
		}
	}
}