#include <iostream>
#include <memory>
#include <array>

using namespace std;

class concrete_component_a;
class concrete_component_b;

class visitor
{
public:
    virtual void visit_concrete_component_a(const concrete_component_a* element) const = 0;
    virtual void visit_concrete_component_b(const concrete_component_b* element) const = 0;
};

class component
{
public:
    virtual ~component() {}
    virtual void accept(visitor* vst) const = 0;
};

class concrete_component_a : public component
{
public:
    void accept(visitor* vst) const override { vst->visit_concrete_component_a(this); }
    std::string exclusive_method_of_concrete_component_a() const { return "A"; }
};

class concrete_component_b : public component
{
public:
    void accept(visitor* vst) const override { vst->visit_concrete_component_b(this); }
    std::string special_method_of_concrete_component_b() const { return "B"; }
};

class concrete_visitor1 : public visitor
{
public:
    void visit_concrete_component_a(const concrete_component_a* element) const override
    {
        std::cout << element->exclusive_method_of_concrete_component_a() << " + concrete_visitor1\n";
    }

    void visit_concrete_component_b(const concrete_component_b* element) const override
    {
        std::cout << element->special_method_of_concrete_component_b() << " + concrete_visitor1\n";
    }
};

class concrete_visitor2 : public visitor
{
public:
    void visit_concrete_component_a(const concrete_component_a* element) const override
    {
        std::cout << element->exclusive_method_of_concrete_component_a() << " + concrete_visitor2\n";
    }
    void visit_concrete_component_b(const concrete_component_b* element) const override
    {
        std::cout << element->special_method_of_concrete_component_b() << " + concrete_visitor2\n";
    }
};

void client_code(std::array<const component*, 2> components, visitor* vst)
{
    for (const component* comp : components)
        comp->accept(vst);
}

int main()
{
    std::array<const component*, 2> components = {new concrete_component_a, new concrete_component_b};
    std::cout << "The client code works with all visitors via the base visitor interface:\n";
    concrete_visitor1* vst1 = new concrete_visitor1;
    client_code(components, vst1);
    std::cout << "\n";
    std::cout << "It allows the same client code to work with different types of visitors:\n";
    concrete_visitor2* vst2 = new concrete_visitor2;
    client_code(components, vst2);

    for (const component* comp : components)
        delete comp;
    delete vst1;
    delete vst2;

    return 0;
}