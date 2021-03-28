#include"interface.h"
#include"constant.h"
#include<Windows.h>
using namespace std;
#define SURHEIGHT 10


intersurface::intersurface(){}
intersurface::~intersurface(){}

void intersurface::show()
{
	pos.X = WIDTH/3;
	pos.Y = 0;
	for (; pos.Y < SURHEIGHT; pos.Y++)
	{
		SetConsoleCursorPosition(houtput, pos);
		switch (pos.Y)
		{
		case 0:cout << "请选择以下操作（输入q退出）"; break;
		case 1:cout << "1.输入链表"; break;
		case 2:cout << "2.自动生成链表"; break;
		case 3:cout << "3.链接两个链表"; break;
		case 4:cout << "4.查找元素."; break;
		case 5:cout << "5.插入元素"; break;
		case 6:cout << "6.删除元素"; break;
		case 7:cout << "7.判断链表是否成环"; break;
		case 8:cout << "8.链表反转"; break;
		case 9:cout << "9.寻找中间节点"; break;
		}
	}
}

void intersurface::rules(int num)
{
	system("cls");
	pos.X = WIDTH / 3 - 15;
	pos.Y = 4;
	SetConsoleCursorPosition(houtput, pos);
	switch (num)
	{
	case 1:cout << "输入若干数，以空格隔开，链表从左到右，读取到非数字元素时结束"; break;
	case 2:cout << "输入一个数，表示生成多少个结点（只会读取一个数，后续都会被忽略）"; break;
	case 3:cout << "输入两个数，以空格隔开，第一个链表将被改变，不会生成新链表,若输入一个数则将该链表环接"; break;
	case 4:cout << "输入两个数，以空格隔开，第一个时链表的符号，第二个是查找的数，只会查找第一个相同的数"; break;
	case 5:cout << "输入三个数，以空格隔开，第一个是链表，第二个是索引，第三个是元素"; break;
	case 6:cout << "输入两个数，以空格隔开，第一个是链表，第二个是删除的索引"; break;
	case 7:
	case 8:
	case 9:cout << "请输入一个数（只会读取一个数，后续都会被忽略）";
	}
}

void intersurface::show_lists(linked_list *lists[],int len)
{
	pos.X = WIDTH / 4;
	pos.Y = SURHEIGHT+1;
	//int step = 1;
	for (int n = 0; n < len; n++)
	{
		pos.X = WIDTH / 4;
		SetConsoleCursorPosition(houtput, pos);
		cout << n+1 << " : ";
		pos.X = WIDTH / 4 + 5;
		int *nums = new int[lists[n]->len()];
		int length = lists[n]->len();
		//cout << lists[n]->len();
		lists[n]->return_all_nums(nums);
		for (int i = 0; i < length; i++)
		{
			cout << nums[i];
			if (i != length - 1) cout << "->";
			if ((i + 1) % 10 == 0)
			{
				pos.Y++;
				SetConsoleCursorPosition(houtput, pos);
			}
		}
		pos.Y += 2;
	}
}

void intersurface::input()
{
	pos.X = WIDTH / 3;
	pos.Y = 5;
	SetConsoleCursorPosition(houtput, pos);
	cout << "请输入： ";
}