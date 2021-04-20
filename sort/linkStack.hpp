#ifndef LINKSTACK_H_
#define LINKSTACK_H_
#include<iostream>
using std::cout;
using std::endl;
template<typename Elemtype>
class linkStack
{
	struct node
	{
		Elemtype data;
		node* next;
	};
	node* top;
	int len;
public:
	linkStack()
	{
		top = new node;
		top->next = nullptr;
		len = 0;
	}
	~linkStack()
	{
		while (top->next != nullptr)
		{
			node* t = top;
			top = top->next;
			delete t;
		}
	}
	bool isEmpty() { return len == 0; }
	bool getTopStack(Elemtype &data)
	{
		if (len == 0) return false;
		data = top->data;
		return true;
	}
	void clear()
	{
		for (; len > 0; len--)
		{
			node* t = top;
			top = top->next;
			delete t;
		}
	}
	int length() { return len; }
	void push(Elemtype data)
	{
		node* t = new node;
		t->data = data;
		t->next = top;
		top = t;
		len++;
	}
	bool pop(Elemtype& data)
	{
		if (len == 0)return false;
		data = top->data;
		node* t = top;
		top = top->next;
		len--;
		delete t;
		return true;
	}
	bool pop()
	{
		Elemtype data;
		return pop(data);
	}
	void popAllStacks(Elemtype* datas)
	{
		for (; len > 0;) pop(datas[len - 1]);
	}
};

#endif