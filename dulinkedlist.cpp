#include<iostream>
#include"duLinkedList.h"

void visit(int e)
{
	std::cout << e<<' ';
}

duLinkedList::duLinkedList()
{
	length = 0;
	head = new node;
	head->next = NULL;
}
duLinkedList::~duLinkedList()
{
	while (true)
	{
		node* t = head;
		if (head->next == NULL)
		{
			delete head;
			break;
		}
		head = head->next;
		delete t;
	}
}

bool duLinkedList::insert(int data)
{
	node* p = head;
	while (p->next != NULL) p = p->next;
	node* t = new node;
	p->next = t;
	t->data = data;
	t->next = NULL;
	t->prior = p;
	length++;
	return true;
}

bool duLinkedList::insert(int pos, int data)
{
	if (pos <= 0 || pos > length) return false;
	node* p = head;
	for (int n = 0; n < pos; n++) p = p->next;
	node* t = new node;
	t->data = data;
	if (pos != length)
	{
		node* q = p->next;
		t->next = q;
		q->prior = t;
		p->next = t;
		t->prior = p;
	}
	else
	{
		t->next = NULL;
		t->prior = p;
		p->next = t;
	}
	length++;
	return true;
}

bool duLinkedList::delete_data(int pos)
{
	if (pos <= 0 || pos > length) return false;
	node* p = head;
	for (int n = 0; n < pos; n++)p = p->next;
	node* t = p;
	p->prior->next = p->next;
	delete t;
	length--;
	return true;
}

void duLinkedList::traverse_list(void(*visit)(int e))
{
	node* p = head;
	for (int n = 0; n < length; n++)
	{
		p = p->next;
		visit(p->data);
	}
}
