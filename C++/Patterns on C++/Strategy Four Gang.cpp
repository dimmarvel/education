#include <iostream>
#include <string>
using namespace std;
// FIRST IMPL -----------------------------------------------------------------
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
// FIRST IMPL -----------------------------------------------------------------

// SECOND IMPL -----------------------------------------------------------------
class compositor {
public:
    virtual int compose(int some_data) = 0;
protected:
    compositor() {}
};

class simple_compositor : public compositor
{
public:
    simple_compositor() {}
    virtual int compose(int some_data) { cout << "text_compositor" << endl; return some_data + 1; }
};

class text_compositor : public compositor
{
public:
    text_compositor() {}
    virtual int compose(int some_data) { cout << "text_compositor" << endl; return some_data + 2; }
};

class composition {
public:
    composition(compositor* cmp) : _compositor(cmp) {}
    int repair() { return _compositor->compose(1); }

private:
    compositor* _compositor;
};
// SECOND IMPL -----------------------------------------------------------------

int main()
{
    context<ZIP_compression> cntx1;
    context<ARJ_compression> cntx2;
    cntx1.operatiorn();
    cntx2.operatiorn();
    composition* quick = new composition(new simple_compositor);
    composition* slick = new composition(new text_compositor);
    cout << "data " << quick->repair() << endl;
    cout << "data " << slick->repair() << endl;
    return 0;
}