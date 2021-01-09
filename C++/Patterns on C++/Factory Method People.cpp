#include <iostream>
#include <vector>

using namespace std;

class People
{
public:
	static People* make_people(int choice);
	virtual void info() = 0;
};


int main()
{
	vector<People*> people;
	for (int i = 0; i < 3; i++)
	{
		people.push_back(People::make_people(i));
		people[i]->info();
	}

	system("pause");
}

class Dayn : public People
{
public:
	void info()
	{
		cout << "Im DAYN" << endl;
	}
};

class Genius : public People
{
public:
	void info()
	{
		cout << "Im GENIUS" << endl;
	}
};

class Medium : public People
{
public:
	void info()
	{
		cout << "Im Medium" << endl;
	}
};

People* People::make_people(int choice)
{
	if (choice == 1)
	{
		return new Dayn();
	}
	else if(choice == 2)
	{
		return new Genius();
	}
	else
	{
		return new Medium();
	}
}