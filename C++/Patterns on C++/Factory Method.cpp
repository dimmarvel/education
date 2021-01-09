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
		cout << "Наземный(1) Морской(2) Воздушный(3) Машинный(4) Космический(5) Go(0): ";
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

class Car : public Transport
{
public:
	void info()
	{
		cout << "Машинный транспорт\n";
	}
};

class Cosmos : public Transport
{
public:
	void info()
	{
		cout << "Космический транспорт\n";
	}
};

Transport *Transport::make_transport(int choice)
{
	if (choice == 1)
		return new Land;
	else if (choice == 2)
		return new Sea;
	else if(choice == 3)
		return new Air;
	else if (choice == 4)
		return new Car;
	else if(choice == 5)
		return new Cosmos;
}