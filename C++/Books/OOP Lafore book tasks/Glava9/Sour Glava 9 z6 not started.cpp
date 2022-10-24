// arrover3.cpp
// ������������ �������� ����������� �������, ������������
// ���� ������� ��� �������������
// ������������ ���������� �������� [ ]

#include <iostream>
using namespace std;
#include <process.h>      // ��� ������� exit
const int LIMIT = 1000;    // ������ �������

class safearray
{
protected:
	int arr[LIMIT];
public:
	// �������� ��������, ��� ������� ���������� ������!
	int& operator[ ] (int n)
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\n��������� ������!"; exit(1);
		}
		return arr[n];
	}
};

class safehilo : public safearray {
private:
	int up, down, down2, differ = 0;
public:
	safehilo() : safearray() {}
	safehilo(int up, int low) : up(up), down(low) {}
	void getarr() {
		differ = up - 100;
		down2 = down;
		for (int i = down - differ; i < up - differ; i++)
			arr[i] = (down2++) * 10;
	}
	void showarray() {
		for (int i = down - differ; i < up - differ; i++)
		{
			int temp = arr[i];  // ���������� ������� ������ �� ����� =
			cout << "Element " << down++ << " equal " << temp << endl;
		}
	}
};
int main()
{
	safehilo s1(100,5);
	s1.getarr();
	s1.showarray();

	cout << endl;
	system("pause");
	return 0;
}



