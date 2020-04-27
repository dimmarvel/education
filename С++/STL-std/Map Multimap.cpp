#include<iostream>
#include<map>
#include<string>
using namespace std;

int main() {

	setlocale(LC_ALL, "Rus");
	
	pair<int, string> p(1, "telephone");

	cout << "1 - " << p.first << "2 - " << p.second << endl;


	//----------------------------------------------------------

	map<int, string> mmap;

	mmap.emplace(3, "monithor"); //create obj in runtime

	mmap.insert(make_pair(1, "telephone"));
	mmap.insert(pair<int, string>(2, "notepad")); //copy obj or move

	mmap.emplace(22, "keyboard"); //create obj in runtime

	auto it = mmap.find(22);
	
	cout << it->second << " " << it->first << endl;

	cout << mmap[1] << endl;

	//-----------------------------------------------------------

	multimap<string, int> mmap2;

	mmap2.emplace("monithor",2); //create obj in runtime

	mmap2.insert(make_pair("telephone",4));
	mmap2.insert(pair<string, int>("notepad",3)); //copy obj or move

	mmap2.emplace("keyboard",6); //create obj in runtime

	auto it2 = mmap2.find("telephone");

	cout << it2->second << " " << it2->first << endl;

	//cout << mmap2[1] << endl; //ERROR
	system("Pause");
}