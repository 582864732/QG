#include<iostream>
#include"linkedList.h"
using namespace std;

linked_list::linked_list()
{
	head = new node;
	length = 0;
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
	for (int n = 0; n < pos; n++) position = position->next;
}

bool linked_list::insert(int data, int pos)
{
	if (pos == -1)
	{
		if (annular) return false;
		node* t = new node;
		t->data = data;
		return_to_last();
		position->next = t;
		t->next = NULL;
		length++;
		return true;
	}
	if (pos > length) return false;
	else
	{
		to_the_pos(pos);
		node* t = new node;
		t->data = data;
		node* d = position->next;
		t->next = d;
		length++;
		position->next = t;
		return true;
	}
}

int linked_list::search(int d, int n)
{
	if (n <= 0) return -1;
	position = head->next;
	for (int i = 0; i < length; i++)
	{
		if (position->data == d)
		{
			if (n == 1) return i;
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
	if (length <= 1) return false;
	if (pos < 1) return false;
	if (pos > length) return false;
	to_the_pos(pos - 1);
	node* t = position->next;
	position->next = t->next;
	delete t;
	length--;
	return true;
}

bool linked_list::delete_data(int d, int n){return delete_data(search(d, n) - 1);}

bool linked_list::return_to_last()
{
	if (annular) return false;
	position = head;
	while (position->next != NULL) position = position->next;
	return true;
}

int linked_list::print_pos() { return position->data; }

linked_list::node* linked_list::reverse(node*pos)
{
	if (annular) return NULL;
	if (pos == NULL) pos = head->next;
	node* p;
	node* t = pos;
	if (pos->next != NULL) p = reverse(pos->next);
	else
	{
		node* t = head;
		node* n = new node;
		n->next = pos;
		head = n;
		delete t;
		return pos;
	}
	p->next = t;
	t->next = NULL;
	return t;
}

bool linked_list::isannular()
{
	node* q = head->next;
	node* s = head;
	while (true)
	{
		if (q == NULL) return false;
		if (q->next == NULL)return false;
		if (q->next == s || q == s) return true;
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
	if (this != l) length += l->len();
	else {
		annular = isannular();
		return false;
	}
	annular = isannular();
	return true;
}

linked_list::node* linked_list::find_midnode()
{
	if (annular) return NULL;
	if (length == 0)return NULL;
	cout << 1;
	node* q = head->next;
	node* s = head->next;
	while (q != NULL)
	{
		if (q->next == NULL) break;
		q = q->next->next;
		s = s->next;
	}
	return s;
}

void linked_list::return_all_nums(int *nums)
{
	position = head->next;
	for (int n = 0; n < length; n++)
	{
		*(nums + n) = position->data;
		if (position->next == NULL)break;
		position = position->next;
	}
}