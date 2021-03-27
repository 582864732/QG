#include<iostream>
#ifndef LINKLIST
#define LINKLIST

class linked_list
{
private:
	struct node
	{
		int data;
		node* next;
	};
	node* head;
	node* position;
	int length;
	bool annular;
	void to_the_pos(int pos);
public:
	linked_list();
	//linked_list(const linked_list& l);
	~linked_list();
	//insert a node into the linked list, insert at the end by default
	//however, it is necessary for a annular linked list to set the position
	bool insert(int data, int pos = -1);
	//delete the nth node with the same data 
	bool delete_data(int d, int n);
	//delete the node in the position of pos
	bool delete_data(int pos);
	//add node on the front of head
	bool push_front(int data);
	//find the nth data
	int search(int d, int n);
	//find the pos
	node* search(int pos);
	//reverse the linked list
	node* reverse(node*pos);
	//set the position to the last
	bool return_to_last();
	//montage two linked list in the position of pos1 and pos2
	//pos1 belongs to l and pos2 belongs to the main linked list,it will change the main linked list
	bool montage(linked_list* l,int pos1,int pos2);
	//return length of the linked list
	int len();
	//judge the linked list if annular
	bool isannular();
	//find the mid node, the linked list must be sole
	node* find_midnode();
};

#endif
