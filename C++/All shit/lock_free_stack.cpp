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
        Node* old_head;
        do
        {
            old_head = head.load();
            if(!old_head) return false;
        } while (head.compare_exchange_weak(old_head, ));
        value = old_head->data;
        delete old_head;
        return true;
    }

    ~lf_stack()
    {
        T dummy;
        while(pop(dummy));
    }
};

int main() {
    return 0;
}