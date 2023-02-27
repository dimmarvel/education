#include <iostream>
#include <memory>

using namespace std;

class subsystem1
{
public:
    std::string operation1() const { return "subsystem1 Operation1\n"; }
    std::string operationN() const { return "subsystem1 OperationN\n"; }
};

class subsystem2
{
public:
    std::string operation1() const { return "subsystem2 operation1\n"; }
    std::string operationN() const { return "subsystem2 operationN\n"; }
};

class facade
{
public:
    facade(shared_ptr<subsystem1> subsys1 = nullptr, shared_ptr<subsystem2> subsys2 = nullptr)
    {
        this->_subsystem1 = subsys1 ?: make_shared<subsystem1>();
        this->_subsystem2 = subsys2 ?: make_shared<subsystem2>();
    }

    std::string Operation()
    {
        std::string result = "facade initializes subsystems:\n";
        result += this->_subsystem1->operation1();
        result += this->_subsystem2->operation1();
        result += "facade orders subsystems to perform the action:\n";
        result += this->_subsystem1->operationN();
        result += this->_subsystem2->operationN();
        return result;
    }

protected:
    shared_ptr<subsystem1> _subsystem1;
    shared_ptr<subsystem2> _subsystem2;
};

int main()
{
    shared_ptr<subsystem1> subsys1 = make_shared<subsystem1>();
    shared_ptr<subsystem2> subsys2 = make_shared<subsystem2>();
    shared_ptr<facade> fcd = make_shared<facade>(subsys1, subsys2);
    cout << fcd->Operation();

    return 0;
}