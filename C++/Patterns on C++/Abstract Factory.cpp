#include <memory>
#include <stdio.h>

using namespace std;

class AbstractA
{
public:
    virtual ~AbstractA() {};
    virtual void whoA() const = 0;
};

class AbstractB
{
public:
    virtual ~AbstractB() {};
    virtual void whoB() const = 0;
};

class ProductA1 : public AbstractA
{
public:
    virtual void whoA() const override { printf("product A1\n"); }
};

class ProductA2 : public AbstractA
{
public:
    virtual void whoA() const override { printf("product A2\n"); }
};

class ProductB1 : public AbstractB
{
public:
    virtual void whoB() const override { printf("product B1\n"); }
};

class ProductB2 : public AbstractB
{
public:
    virtual void whoB() const override { printf("product B2\n"); }
};

class AbstractProductFactory
{
public:
    virtual unique_ptr<AbstractA> create_productA() const = 0;
    virtual unique_ptr<AbstractB> create_productB() const = 0;
};

class ProductA1B1Factory : public AbstractProductFactory
{
public:
    virtual unique_ptr<AbstractA> create_productA() const override { return make_unique<ProductA1>(); }
    virtual unique_ptr<AbstractB> create_productB() const override { return make_unique<ProductB1>(); }
};

class ProductA2B2Factory : public AbstractProductFactory
{
public:
    virtual unique_ptr<AbstractA> create_productA() const override { return make_unique<ProductA2>(); }
    virtual unique_ptr<AbstractB> create_productB() const override { return make_unique<ProductB2>(); }
};

void create_products(const AbstractProductFactory& fact)
{
    const unique_ptr<AbstractA> productA = fact.create_productA();
    const unique_ptr<AbstractB> productB = fact.create_productB();

    productA->whoA();
    productB->whoB();
}

int main()
{
    unique_ptr<ProductA1B1Factory> factory1 = make_unique<ProductA1B1Factory>();
    unique_ptr<ProductA2B2Factory> factory2 = make_unique<ProductA2B2Factory>();
    create_products(*factory1);
    create_products(*factory2);
    return 0;
}