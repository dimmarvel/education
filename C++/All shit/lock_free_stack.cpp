#include <memory>
#include <algorithm>
#include <iostream>
#include <atomic>

template <typename T>
class lf_stack
{
    struct node
    {
        T data;
        node* next;
        node(T data) : data(data), next(nullptr) {}
    };
    std::atomic<node*> head;

public:
    lf_stack() : head(nullptr) {}

    void push(T data)
    {
        node* new_node = new node(data);
        do
        {
            new_node->next = head.load();
        } while(!head.compare_exchange_weak(new_node->next, new_node));
    }

    bool pop(T& value)
    {
        if(!head) return false;
        node* old_head = head.load();
        while (!head.compare_exchange_weak(old_head, old_head->next)){
            if(!old_head) 
                return false;
        }
        value = old_head->data;
        return true;
    }

    ~lf_stack()
    {
        T dummy;
        while(pop(dummy));
    }
};

int main() {
    std::cout << "start" << std::endl;
    lf_stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    int val; 

    while(stack.pop(val)) {
        std::cout << val << std::endl;
    }
    
    return 0;
}