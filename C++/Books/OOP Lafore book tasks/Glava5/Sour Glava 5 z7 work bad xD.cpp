#include<iostream>
using namespace std;


double power(double, int);
char power(char, double);
int power(int, float);
float power(float, char);
int main() {
	setlocale(LC_ALL, "Rus");

	int num;
	do {
		cout << "\n������� �����:";
		cout << "1 ������ ������� double(�����) int(��� �������)?\n";
		cout << "2 ������ ������� char int?\n";
		cout << "3 ������ ������� int int?\n";
		cout << "4 ������ ������� float int?\n";
		cin >> num;

		switch (num) {
		case 1:
			double num4, answer4;
			int pow4;
			cout << "������� double int?\n";
			cin >> num4 >> pow4;
			answer4 = power(num4, pow4);
			cout << "Answer: " << answer4;
			break;
		case 2:
			char num3, answer3;
			double pow3;
			cout << "������� char int?\n";
			cin >> num3 >> pow3;
			answer3 = power(num3, pow3);
			cout << "Answer: " << answer3;
			break;
		case 3:
			int num1, answer2;
			float pow2;
			cout << "������� int int?\n";
			cin >> num1 >> pow2;
			answer2 = power(num1, pow2);
			cout << "Answer: " << answer2;
			break;
		case 4:
			float nums, answer1;
			char pow1;
			cout << "������� float int?\n";
			cin >> nums >> pow1;
			answer1 = power(nums, pow1);
			cout << "Answer: " << answer1;
			break;
		}
	} while (num != 0);
	cout << endl;
	system("Pause");
}
double power(double n, int p)
{
	double result = 1.0; //������ � 1
	for (int j = 0; j < p; j++) //�������� �� n
		result *= n; //p ���
	return result;
}
char power(char n, double p)
{
	double result = 1.0; //������ � 1
	for (int j = 0; j < p; j++) //�������� �� n
		result *= n; //p ���
	return result;
}

int power(int n, float p)
{
	double result = 1.0; //������ � 1
	for (int j = 0; j < p; j++) //�������� �� n
		result *= n; //p ���
	return result;
}
float power(float n, char p)
{
	double result = 1.0; //������ � 1
	for (int j = 0; j < p; j++) //�������� �� n
		result *= n; //p ���
	return result;
}


