#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
int main() {
	map<string, set<string>> words;
	int size; cin >> size;
	for (int i = 0; i < size; i++) {
		string command;
		cin >> command;
		if (command == "ADD") {
			string word1, word2;
			cin >> word1 >> word2;
			words[word1].insert(word2);
			words[word2].insert(word1);
		}
		else if (command == "COUNT") {
			string word;
			cin >> word;
			cout << words[word].size() << endl;
		}
		else if (command == "CHECK") {
			string word1, word2;
			cin >> word1 >> word2;
			const auto& it1 = words[word1].find(word2);
			const auto& it2 = words[word2].find(word1);
			if (it1 != words[word1].end() || it2 != words[word2].end())
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}