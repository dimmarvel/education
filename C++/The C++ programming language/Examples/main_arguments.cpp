#include<iostream>

using namespace std;
int main(int argc, char* arhv[])
{
	switch(argc)
	{
	case 1:
		break;
	case 2:
		cin = *new istream(argv[1], strlen(argv[1]));
		break;
	default:
		error("so much params");
		return 1;
	}
	return 1;
}
