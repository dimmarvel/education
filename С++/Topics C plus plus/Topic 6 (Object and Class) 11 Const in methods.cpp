#include <iostream>
using namespace std;
class foo
{
private:
	int alpha;        						
public:
	void NotConst()                    // неконстантный метод
	{
		alpha = 99;
	}
	void getcount()const           // недопустимо тк константный метод
	{	
		alpha = 99;
	}
};

int main()
{
	setlocale(LC_ALL,"Rus");
	
	system("pause");
}


