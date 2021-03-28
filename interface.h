#ifndef  INTERFACE_H_
#define INTERFACE_H_
#include"linkedList.h"
#include<vector>

class intersurface
{
public:
	intersurface();
	~intersurface();
	void show_lists(linked_list *list[],int len);
	void show();
	void input();
	void rules(int num);
};

#endif // ! INTERFACE

