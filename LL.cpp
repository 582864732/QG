#include<iostream>
#include"linkedList.h"
using namespace std;

linked_list::linked_list()
{
	head = new node;
	length = 1;
	head->next = NULL;
	annular = false;
	position = head;
}

linked_list::~linked_list()
{
	node* t = head;
	while (head->next != NULL)
	{
		delete t;
		head++;
		t = head;
	}
}

int linked_list::len() { return length; }

void linked_list::to_the_pos(int pos)
{
	position = head;
	for (int n = 1; n < pos; n++) position = position->next;
}

bool linked_list::insert(int data, int pos = -1)
{
	if (pos == -1)
	{
		if (annular) return false;
		node* t = new node;
		t->data = data;
		return true;
	}
	if (pos > length) return false;
	else
	{
		to_the_pos(pos);
		node* t = new node;
		node* d = position->next;
		t->next = d;
		position->next = t;
		return_to_last();
		return true;
	}
}

int linked_list::search(int d, int n)
{
	if (n <= 0) return -1;
	position = head;
	for (int i = 0; i < length; i++)
	{
		if (position->data == d)
		{
			if (n == 0) return i;
			n--;
		}
		position = position->next;
	}
	return -1;
}

linked_list::node* linked_list::search(int pos)
{
	if (pos > length) return NULL;
	to_the_pos(pos);
	return position;
}

bool linked_list::delete_data(int pos)
{
	if (pos <= 1) return false;
	if (pos > length) return false;
	to_the_pos(pos - 1);
	node* t = position->next;
	position->next = t->next;
	delete t;
	return true;
}

bool linked_list::delete_data(int d, int n){return delete_data(search(d, n) - 1);}

bool linked_list::return_to_last()
{
	if (annular) return false;
	while (position->next != NULL) position = position->next;
	return true;
}

linked_list::node* linked_list::reverse(node*pos)
{
	if (annular) return NULL;
	node* p;
	node* t = pos;
	if (pos->next != NULL) p = reverse(pos->next);
	else
	{
		head = pos;
		return pos;
	}
	p->next = t;
	t->next = NULL;
	return t;
}

bool linked_list::isannular()
{
	node* q = head;
	node* s = head;
	while (q->next->next != NULL)
	{
		if (q->next == s || q->next->next == s) return true;
		q = q->next->next;
		s = s->next;
	}
	return false;
}

bool linked_list::montage(linked_list* l,int pos1,int pos2)
{
	node* n2 = search(pos2);
	node* n1 = l->search(pos1);
	if (n1 && n2)
	{
		n2->next = n1;
	}
	if (this != l) length = l->len();
	else return false;
}

linked_list::node* linked_list::find_midnode()
{
	if (annular) return NULL;
	node* q = head;
	node* s = head;
	while (q->next != NULL || q != NULL)
	{
		q = q->next->next;
		s = s->next;
	}
	return s;
}
