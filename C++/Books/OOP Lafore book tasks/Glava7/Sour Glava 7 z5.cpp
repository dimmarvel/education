#include <iostream>  
#include <cmath>
using namespace std;
class Fraction
{
private:
	int numerator, denominator;
public:
	Fraction() :numerator(0), denominator(0)
	{}
	void get_fr() //����� ��������� �����
	{
		char ch;
		cout << "enter fraction" << endl;
		cin >> numerator >> ch >> denominator;
	}
	void add_fr(Fraction f1, Fraction f2) //����� �������� ���� ������
	{
		numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
		denominator = f1.denominator * f2.denominator;
	}
	void mul_fr(Fraction f1, int n) //����� ������� ����� ������ �� ���������� �� ����� (��������� ����������� �� ��� �����)
	{
		denominator = f1.denominator * n;
	}

	void lowterms() //����� ���������� �����
	{
		long tnum, tden, temp, gcd;
		tnum = labs(numerator);            // ���������� ���������������
		tden = labs(denominator);            // �������� (����� cmath)
		if (tden == 0)              // �������� ����������� �� 0
		{
			cout << "������������ �����������!"; exit(1);
		}
		else if (tnum == 0)         // �������� ��������� �� 0
		{
			numerator = 0; denominator = 1; return;
		}
		// ���������� ����������� ������ ��������
		while (tnum != 0)
		{
			if (tnum < tden)          // ���� ��������� ������ �����������,
			{
				temp = tnum; tnum = tden; tden = temp;
			} //������ �� �������
			tnum = tnum - tden;        // ���������
		}
		gcd = tden;                  // ����� ��������� � ����������� ��
		numerator = numerator / gcd;             // ���������� ���������� ����� ��������
		denominator = denominator / gcd;
	}
	void disp_fr()const
	{
		cout << "\nthe average is " << numerator << "/" << denominator << endl;
	}
};
int main()
{
	Fraction fraction[100];
	Fraction frtemp, frsum;
	char ans;
	int n = 0;
	do //���� ������ � ������
	{
		fraction[n++].get_fr();
		cout << "continue typing? (y/n)" << endl; cin >> ans;
	} while (ans != 'n');
	for (int j = 0; j < n; j++) //�������� ������
	{
		frtemp.add_fr(fraction[j], fraction[j++]);
		j++;
		frsum.add_fr(frtemp, frsum);
	}
	frsum.mul_fr(frsum, n + 1); //������� �� �� ���-��

	frsum.disp_fr(); //����� �� �����
	system("pause");
	return 0;
}