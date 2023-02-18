#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*������ �����

������ ������ �������� ���� ����� ����� N �� 0 �� 10000 � ����� ���������.

����� ���� N �����, ������ �� ������� �������� ��� ������ ������ �� 1 �� 15 �������� � ��� � ������� ����������
��������, � ��� ����� ����� �� 0 �� 1000000000 � ����, ����� � ��� ��������.

��������� ������ �������� ���� ����� ����� M �� 0 �� 10000 � ����� ��������.

��������� M ����� �������� ������ ������ �� 1 �� 15 �������� � ������, � ����� ����� �� 0 �� 1000000000 � ����� ��������
(��������� ���������� � 1).*/

struct Student
{
    string firstname;
    string lastname;
    long int day;
    long int month;
    long int year;
    Student(string name, string secname, int new_day, int new_month, int new_year)
    {
        firstname = name;
        lastname = secname;
        day = new_day;
        month = new_month;
        year = new_year;
    }
    void PrintDate() { cout << day << "." << month << "." << year << endl; }
    void PrintName() { cout << firstname << " " << lastname << endl; }
};

void name(vector<Student> stud, int K)
{
    if (K - 1 < stud.size() && K - 1 >= 0)
    {
        stud[K - 1].PrintName();
    }
    else
    {
        cout << "bad request" << endl;
    }
}
void date(vector<Student> stud, int K)
{
    if (K - 1 < stud.size() && K - 1 >= 0)
    {
        stud[K - 1].PrintDate();
    }
    else
    {
        cout << "bad request" << endl;
    }
}

int main()
{
    vector<Student> stud;
    string firstname;
    string lastname;
    long int day;
    long int month;
    long int year;

    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> firstname >> lastname >> day >> month >> year;
        stud.push_back(Student(firstname, lastname, day, month, year));
    }

    string command;
    long int K;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> command >> K;
        if (command == "name")
        {
            name(stud, K);
        }
        else if (command == "date")
        {
            date(stud, K);
        }
        else
        {
            cout << "bad request" << endl;
        }
    }

    return 0;
}