#include <iostream>
#include <memory>

using namespace std;

class obj
{
public:
    virtual void request() const = 0;
};

class real_object : public obj
{
public:
    virtual void request() const override { cout << "real_object request" << endl; }
};

class proxy : public obj
{
public:
    proxy(shared_ptr<real_object> robj) : _robj(robj) {}

    bool check_access() const
    {
        cout << "proxy check some access" << endl;
        return true;
    }

    void log_access() const { cout << "proxy login time request" << endl; }

    virtual void request() const override
    {
        if (check_access())
        {
            _robj->request();
            log_access();
        }
    }

private:
    shared_ptr<real_object> _robj;
};

int main()
{
    shared_ptr<real_object> real_obj = make_shared<real_object>();
    real_obj->request();
    unique_ptr<proxy> prxy = make_unique<proxy>(real_obj);
    prxy->request();
    return 0;
}
