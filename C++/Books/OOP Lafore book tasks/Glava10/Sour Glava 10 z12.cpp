#include <iostream>

using namespace std;

//Размер памяти
enum { MAX = 1000 };
//Модель памяти типа float
float fmemory[MAX];
//Модель памяти для указателей
int pmemory[MAX];
//Свободное место для float
int fmem_top = 0;
//Свободное место для указателя
int pmem_top = 0;

class Float
{
private:
	int addr;
public:
	Float(float a)
	{
		fmemory[fmem_top] = a;
		addr = fmem_top;
		fmem_top++;
	}

	int operator &()
	{
		return addr;
	}
};

class ptrFloat
{
private:
	int addr;

public:
	ptrFloat(int a)
	{
		pmemory[pmem_top] = a;
		addr = pmem_top;
		pmem_top++;
	}

	ptrFloat operator = (int a)
	{
		return ptrFloat(a);
	}

	float &operator *()
	{
		return fmemory[pmemory[addr]];
	}
};

void main()
{
	Float var1 = 1.234F;
	Float var2 = 5.678F;

	ptrFloat ptr1 = &var1;
	ptrFloat ptr2 = &var2;

	cout << " *ptr1 = " << *ptr1 << endl;
	cout << " *ptr2 = " << *ptr2 << endl;

	*ptr1 = 7.123F;
	*ptr2 = 8.456F;

	cout << " *ptr1 = " << *ptr1 << endl;
	cout << " *ptr2 = " << *ptr2 << endl;

	ptr2 = &var2;
	cout << " *ptr2 = " << *ptr2 << endl;
	system("pause");
	return 0;

}
