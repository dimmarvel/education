#include <iostream>
using namespace std;
#include <process.h>      // ��� ������� exit
const int LIMIT = 100;

class safearray
{
private:
	int arr[LIMIT];
public:

	int& operator[](int n)// �������� ��������, ��� ������� ���������� ������!
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\n��������� ������!"; exit(1);
		}
		return arr[n];
	}
};

int main()
{
	safearray sa1;
	int up, down, down2, differ = 0;
	cout << "Enter upper limit araay" << endl; cin >> up;
	cout << "Enter lower limit araay" << endl; cin >> down;
	differ = up - 100;
	down2 = down;
	for (int i = down - differ; i < up - differ; i++)
		sa1[i] = (down2++) * 10;

	for (int i = down - differ; i < up - differ; i++)
	{
		int temp = sa1[i];  // ���������� ������� ������ �� ����� =
		cout << "Element " << down++ << " equal " << temp << endl;
	}
	system("pause");
	return 0;
}