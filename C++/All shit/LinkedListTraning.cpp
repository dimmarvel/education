/*
      Односвязный список
*/

#include <iostream>
#include <string>

struct node
{
    std::string data;
    node* next;
};

class linkedlist
{
    node* head;
    int count;

public:
    linkedlist(std::string data);

public:
    void add(std::string data);
    void del(std::string data);
    void show_all();
    node* get(std::string data);
};

linkedlist::linkedlist(std::string data)
{
    head = new node();
    head->data = data;
    head->next = NULL;
    count++;
}

void linkedlist::add(std::string data)
{
    node* p = head;

    while (p->next)
        p = p->next;

    p->next = new node();
    p = p->next;
    p->data = data;
    count++;
}

void linkedlist::del(std::string data)
{
    // TODO: del
}

void linkedlist::show_all()
{
    std::cout << "All objects: " << count << std::endl;

    int i = 0;
    node* p = head;

    do
    {
        std::cout << i++ << ". Data (" << p->data << "), Address (" << p << "), Next address (" << p->next << ")"
                  << std::endl;
    } while (p = p->next);
}

node* linkedlist::get(std::string data)
{
    node* p = head;
    int number = 0;

    do
    {

        if (p->data == data)
            return p;
    } while (p = p->next);

    return NULL;
}

int main()
{
    linkedlist list("str1");
    list.add("str2");
    list.add("str3");
    list.add("str4");
    list.show_all();
    node* p = new node();
    p = list.get("str3");
    std::cout << "Get - Data (" << p->data << "), Address (" << p << "), Next address (" << p->next << ")" << std::endl;

    system("pause");
    return 0;
}