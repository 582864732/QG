#ifndef DULINKEDLIST_H_
#define DULINKEDLIST_H_

class duLinkedList
{
	struct node
	{
		int data;
		node* prior;
		node* next;
	};
	node* head;
	int length;
public:
	duLinkedList();
	~duLinkedList();
	//insert after pos
	bool insert(int pos,int data);
	//add to the end
	bool insert(int data);
	bool delete_data(int pos);
	void traverse_list(void (*visit)(int e));
};

#endif