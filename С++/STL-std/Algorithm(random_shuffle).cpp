#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<ctime>
using namespace std;

class IAction
{
public:
	virtual void Action() = 0;
};

class CatAction : public IAction 
{
	virtual void Action() override {
		cout << "Glaju kota" << endl;
	}
};

class TeaAction : public IAction
{
	virtual void Action() override {
		cout << "Eat tea" << endl;
	}
};

class DogAction : public IAction
{
	virtual void Action() override {
		cout << "Walking with dog" << endl;
	}
};

class SleepAction : public IAction
{
	virtual void Action() override {
		cout << "I sleep" << endl;
	}
};

int main() {

	setlocale(LC_ALL, "Rus");
	int arr[5] = {1,2,3,4,5};

	srand(time(NULL));

	random_shuffle(begin(arr), end(arr));

	for (auto i : arr) {
		cout << i << endl;
	}


	cout << "---------------------------------" << endl;

	vector<IAction*> act = 
	{
		&CatAction(),
		&DogAction(),
		&SleepAction(),
		&TeaAction(),
	};

	for (auto element : act) {
		element->Action();
	}
	cout << endl;
	random_shuffle(begin(act), end(act));
	for (auto element : act) {
		element->Action();
	}

	system("Pause");
}