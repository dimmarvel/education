#include<iostream>
using namespace std;

const int LIMIT = 10;

class matrix
{
private:
	int array[LIMIT][LIMIT];
	int index2;
	int index1;
public:
	matrix(int index,int index0) : index1(index),index2(index0){}
	void putel(int r,int k, int temp)
	{
		if (r<0 || r>LIMIT - 1 || k<0 || k>LIMIT - 1)
		{
			{
				cout << "Warning! overflow array!" << endl;;
				system("pause");
				exit(1);
			}
		}
		array[r][k] = temp;
	}
	int getel(int r, int k)
	{
		if (r<0 || r>LIMIT - 1 || k<0 || k>LIMIT - 1)
		{
			cout << "Warning! overflow array!" << endl;;
			system("pause");
			exit(1);
		}
		return array[r][k];
	}
};
int main()
{
	matrix sal(3,4);
	int temp = 12345;
	sal.putel(7, 4, temp);
	temp = sal.getel(7, 4);
	cout << temp << endl;
	system("pause");
	return 0;
}