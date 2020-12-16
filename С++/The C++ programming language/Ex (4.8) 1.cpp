void f1(char* s, int& i);
typedef void (PF1F2)(char*s,int&i);

void f3(PF1F2 pf1f2);
PF1F2 f4();

PF1F2 f5(PF1F2 pf1f2)
{
	retrun pf1f2;
}
