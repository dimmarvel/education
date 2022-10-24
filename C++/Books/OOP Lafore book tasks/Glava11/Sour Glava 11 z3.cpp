// frengl.cpp
// ������������� ������������� �������� +
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Distance                //����� ���������� ����������
{
private:
	int feet;
	float inches;
public:
	Distance()                //����������� ��� ����������
	{
		feet = 0; inches = 0.0;
	}
	Distance(float fltfeet) //����������� (1 ���.)
	{    //��������� float � Distance
		feet = static_cast<int>(fltfeet);    //feet � ����� �����
		inches = 12 * (fltfeet - feet); //����� - �����
	}
	Distance(int ft, float in)    //����������� (2 ���.)
	{
		feet = ft; inches = in;
	}
	void showdist()              //������� �����
	{
		cout << feet << "\'-" << inches << '\"';
	}
	friend Distance operator + (Distance, Distance); //�������������
	friend Distance operator * (Distance, Distance); //�������������
};
//---------------------------------------------------------

Distance operator + (Distance d1, Distance d2) // d1 + d2
{
	int f = d1.feet + d2.feet;       //+ ����
	float i = d1.inches + d2.inches; //+ �����
	if (i >= 12.0)                    //���� ������ 12 ������,
	{
		i -= 12.0; f++;
	}           //��������� �� 12 ������,
				   //��������� 1 ���
	return Distance(f, i);            //����� ����� � ������
}
Distance operator * (Distance d1, Distance d2) // d1 * d2
{
	float fltfeet1 = d1.feet + d1.inches/12;//�������������� � float
	float fltfeet2 = d2.feet + d2.inches/12;
	float multfeet = fltfeet1 * fltfeet2;	//����� ���������
	return Distance(multfeet);            //������� ��������� ��������
}
//---------------------------------------------------------
int main()
{
	Distance d1(3,6);         //����������� ���������
	Distance d2(2,1.25);        //float-feet � Distance
	Distance d3;
	cout << "\nd1 = "; d1.showdist();
	cout << "\nd2 = "; d2.showdist();

	d3 = d1 * 10.0;            //distance + float: OK
	cout << "\nd3 = "; d3.showdist();
	d3 = 10.0 * d1;            //float + Distance: OK
	cout << "\nd3` = "; d3.showdist();
	cout << endl;
	system("pause");
	return 0;
}


