#include <iostream>
#include <vector>
using namespace std;
class abstract_class {

public:
    void template_method() const {
        this->base_operation_1();
        this->required_operations_1();
        this->base_operation_2();
        this->hook1();
        this->required_operations_2();
        this->base_operation_3();
        this->hook2();
    }

protected:
    void base_operation_1() const {
        std::cout << "abstract_class says: I am doing the bulk of the work\n";
    }
    void base_operation_2() const {
        std::cout << "abstract_class says: But I let subclasses override some operations\n";
    }
    void base_operation_3() const {
        std::cout << "abstract_class says: But I am doing the bulk of the work anyway\n";
    }
    virtual void required_operations_1() const = 0;
    virtual void required_operations_2() const = 0;
    virtual void hook1() const {}
    virtual void hook2() const {}
};
class concrete_class_1 : public abstract_class {
protected:
    void required_operations_1() const override {
        std::cout << "concrete_class_1 says: Implemented Operation1\n";
    }
    void required_operations_2() const override {
        std::cout << "concrete_class_1 says: Implemented Operation2\n";
    }
};

class concrete_class_2 : public abstract_class {
protected:
    void required_operations_1() const override {
        std::cout << "concrete_class_2 says: Implemented Operation1\n";
    }
    void required_operations_2() const override {
        std::cout << "concrete_class_2 says: Implemented Operation2\n";
    }
    void hook1() const override {
        std::cout << "concrete_class_2 says: Overridden hook1\n";
    }
};

void client_code(abstract_class *_class) {
    _class->template_method();
}

int main() {
    std::cout << "Same client code can work with different subclasses:\n";
    concrete_class_1 *concrete1 = new concrete_class_1;
    client_code(concrete1);
    std::cout << "\n";
    std::cout << "Same client code can work with different subclasses:\n";
    concrete_class_2 *concrete2 = new concrete_class_2;
    client_code(concrete2);
    delete concrete1;
    delete concrete2;
    return 0;
}
