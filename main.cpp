#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<ctime>
#include"linkedList.h"
#include"interface.h"
#include"constant.h"
using namespace std;
intersurface surface;
linked_list** lists = new linked_list*;
int len = 0;

void error_output(string str);
int find_str(string &str,int num=-1);
void get_nums(string str, int* nums);
bool get_single_num(int &num)
{
	string str = "";
	getline(cin, str);
	num = atoi(str.c_str());
	if (num <= 0 || num > len)
	{
		error_output("不存在此链表");
		return false;
	}
	num--;
	return true;
}

bool check(string str)//check if is number
{
	int len = str.size();
	for (int n = 0; n < len; n++)
	{
		if (str[n] >= '0' && str[n] <= '9') continue;
		return false;
	}
	return true;
}

//output some text not only error
void error_output(string str)
{
	system("cls");
	pos.X = WIDTH / 3;
	pos.Y = 6;
	SetConsoleCursorPosition(houtput, pos);
	cout << str;
	_getch();
}

//get input and handle input error, its two chile function do the same
//find_str() and get_nums()
bool get_str(int* nums, int list_amount, int num_ammount)
{
	string str = "";
	getline(cin, str);
	int l = find_str(str,num_ammount);
	if (l < num_ammount)
	{
		error_output("输入错误");
		return false;
	}
	get_nums(str, nums);
	for (int i = 0; i < list_amount; i++)
	{
		if (nums[0] <= 0 || nums[0] > len)
		{
			error_output("不存在此链表");
			return false;
		}
		nums[0]--;
	}
	return true;
}

int find_str(string &str,int num)
{
	str.append(" ");
	int isnum = 0;
	int isneg = 0;
	int l = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
		{
			if (isneg == 1) isneg = 0;
			if (isnum == 1)
			{
				l++;
				isnum = 0;
				if (l == num)
				{
					str = str.substr(0, i + 1);
					break;
				}
			}
			continue;
		}
		if (str[i] == '-')
		{
			if (isneg == 1) 
			{
				str = str.substr(0, i + 1);
				break;
			}
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
			{
				isneg = 1;
				continue;
			}
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (isnum == 0) isnum = 1;
		}
		if (str[i] < '0' || str[i]>'9')
		{
			str = str.substr(0, i + 1);
			break;
		}
	}
	return l;
}

void get_nums(string str,int *nums)
{
	int isnum = 0;
	int count = 0;
	int pos = 0;
	int isneg = 0;
	for (int n = 0; n < str.length(); n++)
	{
		if (str[n] == ' ')
		{
			if (isneg == 1)isneg = 0;
			if (isnum == 1)
			{
				*(nums + count) = atoi(str.substr(pos, n).c_str());
				count++;
				pos = n;
				isnum = 0;
			}
			continue;
		}
		if (str[n] == '-')
		{
			if (isneg == 1)
			{
				str = str.substr(0, n + 1);
				break;
			}
			if (str[n + 1] >= '0' && str[n + 1] <= '9')
			{
				isneg = 1;
				continue;
			}
		}
		if (str[n] != ' ')
		{
			if (isnum == 0) isnum = 1;
		}
	}
}

void enter_list(linked_list *list)//input linked list
{
	int l;
	string str = "";
	getline(cin, str);
	l=find_str(str);
	int isnum = 0;
	if (l == 0) {
		error_output("没有生成链表");
		return;
	}
	int* nums = new int[l];
	int count=0;
	int pos = 0;
	isnum = 0;
	get_nums(str, nums);
	for (int i = 0; i < l; i++)
	{
		list->insert(*(nums+i));
	}
	lists[len] = list;
	len++;
}

void auto_list(linked_list* list)//auto create a linked list numbers in range 0 to 99
{
	string str = "";
	cin >> str;
	int nums = atoi(str.c_str());
	getline(cin, str);
	if (nums <= 0)
	{
		error_output("没有生成链表");
		return;
	}
	if (nums > 100)
	{
		error_output("最多生成100个数");
		return;
	}
	for (int i = 0; i < nums; i++) list->insert(rand()%100);
	lists[len] = list;
	len++;
}

void montage_list()//montage two lists
{
	string str = "";
	getline(cin, str);
	int l = find_str(str,2);
	if (l < 1)
	{
		error_output("输入错误");
		return;
	}
	int* nums=new int[2];
	get_nums(str, nums);
	if (l == 2)
	{
		if ((nums[0] > 0 && nums[0] <= len) || (nums[1] > 0 && nums[1] <= len));
		else {
			error_output("不存在此链表");
			return;
		}
		nums[0]--;
		nums[1]--;
		int len = lists[nums[0]]->len();
		lists[nums[0]]->montage(lists[nums[1]], 1,len);
	}
	else
	{
		if (nums[0] <= 0 || nums[0] > len)
		{
			error_output("不存在此链表");
			return;
		}
		nums[0]--;
		int len = lists[nums[0]]->len();
		lists[nums[0]]->montage(lists[nums[0]], 1,len);
	}
}

void find_value()
{
	int* nums = new int[2];
	if (!get_str(nums, 1, 2)) return;
	int p = lists[nums[0]]->search(nums[1], 1);
	if (p == -1)
	{
		error_output("找不到该元素");
		return;
	}
	else
	{
		string s = "元素在第"+to_string(p+1)+"个结点";
		error_output(s);
		return;
	}
}

void add_value()
{
	int* nums = new int[3];
	if (!get_str(nums, 1, 3))return;
	if (!lists[nums[0]]->insert(nums[2], nums[1]))
	{
		error_output("插入失败");
		return;
	}
}

void delete_value()
{
	int* nums = new int[2];
	if (!get_str(nums, 1, 2)) return;
	if (!lists[nums[0]]->delete_data(nums[1]))
	{
		error_output("删除失败");
		return;
	}
}

void is_annular()
{
	int num = 0;
	if (!get_single_num(num)) return;
	if (lists[num]->isannular()) error_output("成环");
	else error_output("单链");
}

void reverse_list()
{
	int num = 0;
	if (!get_single_num(num))return;
	if (lists[num]->reverse() == NULL)
	{
		error_output("循环链表不能反转");
	}
}

void find_midnode()
{
	int num = 0;
	if (!get_single_num(num)) return;
	if (lists[num]->find_midnode() == NULL)
	{
		error_output("循环链表不能寻找中间节点");
		return;
	}
	int midnode = lists[num]->find_midnode()->data;
	string str = "中间结点的元素是："+to_string(midnode);
	error_output(str);
}

int main()
{
	srand(time(0));
	while (true)
	{
		system("cls");
		surface.show();
		surface.show_lists(lists, len);
		char c;
		do {
			c = _getch();
			if (c == 'q') return 0;
		} while (c < '1' || c > '9');
		int num = atoi(&c);
		surface.rules(num);
		surface.input();
		int count = 0;
		linked_list* list = new linked_list;
		switch (num)
		{
		case 1: enter_list(list); break;
		case 2:  auto_list(list); break;
		case 3:montage_list(); delete list; break;
		case 4:find_value(); delete list; break;
		case 5:add_value(); delete list; break;
		case 6:delete_value(); delete list; break;
		case 7:is_annular(); delete list; break;
		case 8:reverse_list(); delete list; break;
		case 9:find_midnode(); delete list; break;
		}
	}
	return 0;
}