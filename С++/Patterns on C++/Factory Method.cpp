#include<iostream>
#include<vector>
using namespace std;

class Transport
{
public:
	// Factory Method
	static Transport *make_transport(int choice);
	virtual void info() = 0;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	vector<Transport*> roles;
	int choice;

	while (true)
	{
		cout << "Наземный(1) Морской(2) Воздушный(3) Go(0): ";
		cin >> choice;
		if (choice == 0)
			break;
		roles.push_back(Transport::make_transport(choice));
	}
	for (int i = 0; i < roles.size(); i++)
		roles[i]->info();
	for (int i = 0; i < roles.size(); i++)
		delete roles[i];
	system("pause");
}

class Land : public Transport
{
public:
	void info()
	{
		cout << "Наземный транспорт.\n";
	}
};

class Sea : public Transport
{
public:
	void info()
	{
		cout << "Морской транспорт\n";
	}
};

class Air : public Transport
{
public:
	void info()
	{
		cout << "Воздушный транспорт\n";
	}
};

Transport *Transport::make_transport(int choice)
{
	if (choice == 1)
		return new Land;
	else if (choice == 2)
		return new Sea;
	else
		return new Air;
}