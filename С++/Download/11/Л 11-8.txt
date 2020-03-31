// virtbase.cpp
// Виртуальные базовые классы
class Parent
    {
    protected:
      int basedata;
    };
class Child1 : virtual public Parent // наследует копию
                                     // класса Parent
    { };
class Child2 : virtual public Parent // наследует копию
                                     // класса Parent
    { };
class Grandchild : public Child1, public Child2
    {
    public:
      int getdata()
        { return basedata; }         // OK: только одна копия
                                     //класса Parent
    };


