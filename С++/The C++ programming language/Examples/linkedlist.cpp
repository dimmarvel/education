#include<iostream>
using namespace std;

template <typename T>
class List
{
private:
	struct Node;
public:
	class Iterator
	{
		//...
	};
public:
	List();
	~List();
	void append(const T&t);
	void remove();
	T head() const;
	Iterator begin() const;
	Iterator end() const;
	size_t size() const;
private:
	struct Node
	{
		Node() : m_next(NULL){}
		Node(const T& t) : m_t(t), m_next(NULL){}
		T m_t;
		Node* m_next;
	};
	Node* m_head;
};

template<typename T>
List<T>::List() : m_head(NULL){}

template<typename T>
void List<T>::append(const T& t)
{
	Node* node = new Node(t);
	node->m_next = m_head; //новый привязываем к старому головному элементу
	m_head = node; //новый узел = голова
}

template<typename T>
void List<T>::remove()
{
	if(m_head)
	{
		Node newHead = m_head->m_next; //сохраняем указатель на второй узел, который станет головой
		delete m_head; // чистим память выделенную для удаляемого головного элемента
		m_head = newHead; // назначаем новую голову
	}
}

template<typename T>
List<T>::~List(){
	while(m_head)
	{
		remove();
	}
}


