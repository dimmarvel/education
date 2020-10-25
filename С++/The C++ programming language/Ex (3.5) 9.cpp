#include<iostream>
#include<string.h>

using namespace std;

char* cat(char* p1, char* p2)
{
	int sum_size = strlen(p1) + strlen(p2);
	char* result = new char(sum_size);
	int resi = 0;
	for(int i = 0; i < strlen(p1); i++)
	{
		result[resi++] = p1[i];
	}
	for(int i = 0; i < strlen(p2); i++)
	{
		result[resi++] = p2[i];
	}
	return result;
}
int main()
{
	char str1[4] = "qwe";
	char str2[4] = "asd";
	char* p = cat(str1,str2);
	cout << p;
	return 0;
}

