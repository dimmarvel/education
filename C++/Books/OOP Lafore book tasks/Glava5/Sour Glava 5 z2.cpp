//������� �������� ����� � �������
#include <iostream>
using namespace std;
double power(double n, int p = 2);//p has default value 2

int main()
{
	setlocale(LC_ALL,"Rus");
	double number, answer;
	int pow;
	char yeserno;
	cout << "\n������� �����:";//get number
	cin >> number;
	cout << "������ ������� ������� (y/n)?\n";
	cin >> yeserno;

	if (yeserno == 'y')//������������ ����� �� ������� 									//�����?
	{
	cout << "������� �������:";
	cin >> pow;
	answer = power(number, pow);//�������� ����� � �������
	}else {
		answer = power(number);//������� �����
	}

	cout << "����� " << answer << endl;
	
	system("pause");
}
//���������� ����� n, ����������� � ������� p
double power(double n, int p)
{
	double result = 1.0;//������ � 1
	for (int j = 0; j < p; j++)//�������� �� n
		result *= n;//p ���
	return result;
}


