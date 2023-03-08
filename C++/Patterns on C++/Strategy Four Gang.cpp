#include <iostream>
#include <string>
using namespace std;

class ZIP_compression
{
public:
    void do_algorithm() { cout << "ZIP compression" << endl; }
};

class ARJ_compression 
{
public:
    void do_algorithm() { cout << "ARJ compression" << endl; }
};

template<class strategy>
class context
{
public:
    void operatiorn() { strat.do_algorithm(); }

private:
    strategy strat;
};

int main()
{
    context<ZIP_compression> cntx1;
    context<ARJ_compression> cntx2;
    cntx1.operatiorn();
    cntx2.operatiorn();
    return 0;
}