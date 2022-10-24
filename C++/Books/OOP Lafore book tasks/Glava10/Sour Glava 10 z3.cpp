// ptrtostr.cpp
// ������ ���������� �� ������
#include <iostream>
#include <cstring>
using namespace std;
const int DAYS = 7;
void bsort(const char*, int);

int main()
{
	setlocale(LC_ALL,"Rus");
	// ������ ���������� �� ������
	const char* arrptrs[DAYS] = { "�����������", "�����������", "�������", "�����", "�������", "�������", "�������" };
	cout << "\n���������������:\n";
	for (int j = 0; j < DAYS; j++) { // ������� ��� ������
		cout << arrptrs[j] << endl;
	}
	bsort(arrptrs[0], DAYS);
	cout << "\n�������������:\n" << endl;

	for (int j = 0; j < DAYS; j++)
	{
		cout << *(arrptrs + j) << endl;
	}
	system("pause");
	return 0;
}

void bsort(const char* pp, int n)
{
	void order(const char*, const char*);
	int j, k;
	for (j = 0; j < n - 1; j++)
	{
		for (k = 0; k < n; k++)
		{
			order(pp + j, pp + k);
		}
	}
}

void order(const char*pp1, const char*pp2)
{
	if (strcmp(pp1, pp2) > 0)
	{
		const char *tempptr = pp1;
		pp1 = pp2;
		pp2 = tempptr;
	}
}