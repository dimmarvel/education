#include <iostream>
#include <string>
/**
 * Интерфейс Посредника предоставляет метод, используемый компонентами для
 * уведомления посредника о различных событиях. Посредник может реагировать на
 * эти события и передавать исполнение другим компонентам.
 */
class base_component;

class mediator
{
public:
    virtual void notify(base_component* sender, std::string event) const = 0;
};

/**
 * Базовый Компонент обеспечивает базовую функциональность хранения экземпляра
 * посредника внутри объектов компонентов.
 */
class base_component
{
protected:
    mediator* _mediator;

public:
    base_component(mediator* med = nullptr) : _mediator(med) {}
    void set_mediator(mediator* med) { _mediator = med; }
};

/**
 * Конкретные Компоненты реализуют различную функциональность. Они не зависят от
 * других компонентов. Они также не зависят от каких-либо конкретных классов
 * посредников.
 */
class component1 : public base_component
{
public:
    void do_a()
    {
        std::cout << "component 1 does A.\n";
        _mediator->notify(this, "A");
    }

    void do_b()
    {
        std::cout << "component 1 does B.\n";
        _mediator->notify(this, "B");
    }
};

class component2 : public base_component
{
public:
    void do_c()
    {
        std::cout << "component 2 does C.\n";
        _mediator->notify(this, "C");
    }

    void do_d()
    {
        std::cout << "component 2 does D.\n";
        _mediator->notify(this, "D");
    }
};

/**
 * Конкретные Посредники реализуют совместное поведение, координируя отдельные
 * компоненты.
 */
class concrete_mediator : public mediator
{
private:
    component1* _component1;
    component2* _component2;

public:
    concrete_mediator(component1* c1, component2* c2) : _component1(c1), _component2(c2)
    {
        _component1->set_mediator(this);
        _component2->set_mediator(this);
    }

    void notify(base_component* sender, std::string event) const override
    {
        if (event == "A")
        {
            std::cout << "mediator reacts on A and triggers following operations:\n";
            _component2->do_c();
        }
        
        if (event == "D")
        {
            std::cout << "mediator reacts on D and triggers following operations:\n";
            _component1->do_b();
            _component2->do_c();
        }
    }
};

int main()
{
    component1* c1 = new component1;
    component2* c2 = new component2;
    concrete_mediator* mediator = new concrete_mediator(c1, c2);
    std::cout << "client triggers operation A.\n";
    c1->do_a();
    std::cout << "\n";
    std::cout << "client triggers operation D.\n";
    c2->do_d();

    delete c1;
    delete c2;
    delete mediator;
    return 0;
}