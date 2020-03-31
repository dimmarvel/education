#include <iostream>
using namespace std;
struct link {
	int data;
	link* next;
};
class linked {
	private:
	link* first;
	public:
	linked()
	{
		first = NULL;	
	}
	~linked()
	{
		link* current = first;
		while (current != NULL) {

			link* temp = current;
			current = current->next;
			delete temp;		
		}
	}
	void additem(int data)
	{
		link* newlink = new link;
		newlink->data = data;
		newlink->next = first;
		first = newlink;
	}
	void display()
	{
		link* current = first;
		while (current)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
};

int main() {
	linked it;
	it.additem(25);
	it.additem(35);
	it.additem(4);
	it.additem(1);
	it.display();
	int sex;
	cin >> sex;
}