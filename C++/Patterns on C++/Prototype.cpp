#include <iostream>
#include <memory>

using namespace std;

class ProductA
{
public:
    virtual void init(string field) { fieldA = field; }
    virtual unique_ptr<ProductA> clone() { return make_unique<ProductA>(); }
    void info() { std::cout << fieldA << std::endl; }

private:
    string fieldA = "productA";
};

class ProductB
{
public:
    virtual void init(string field) { fieldB = field; }
    virtual unique_ptr<ProductB> clone() { return make_unique<ProductB>(); }
    void info() { std::cout << fieldB << std::endl; }

private:
    string fieldB = "productB";
};

class ProductAbstractFactory
{
public:
    virtual unique_ptr<ProductA> make_productA(string field) = 0;
    virtual unique_ptr<ProductB> make_productB(string field) = 0;
};

class Prototype : public ProductAbstractFactory
{
public:
    Prototype() : prototypeA(make_unique<ProductA>()), prototypeB(make_unique<ProductB>()) {}

    virtual unique_ptr<ProductA> make_productA(string field = {}) override
    {
        if (!field.empty())
            prototypeA->init(field);
        return prototypeA->clone();
    }
    virtual unique_ptr<ProductB> make_productB(string field = {}) override
    {
        if (!field.empty())
            prototypeB->init(field);
        return prototypeB->clone();
    }

private:
    unique_ptr<ProductA> prototypeA;
    unique_ptr<ProductB> prototypeB;
};

void client()
{
    Prototype prototype;
    unique_ptr<ProductA> prA = prototype.make_productA("prdA");
    unique_ptr<ProductB> prB = prototype.make_productB();
    prA->info();
    prB->info();
}

int main()
{
    client();
    return 0;
}