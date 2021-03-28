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
		case 0:cout << "��ѡ�����²���������q�˳���"; break;
		case 1:cout << "1.��������"; break;
		case 2:cout << "2.�Զ���������"; break;
		case 3:cout << "3.������������"; break;
		case 4:cout << "4.����Ԫ��."; break;
		case 5:cout << "5.����Ԫ��"; break;
		case 6:cout << "6.ɾ��Ԫ��"; break;
		case 7:cout << "7.�ж������Ƿ�ɻ�"; break;
		case 8:cout << "8.����ת"; break;
		case 9:cout << "9.Ѱ���м�ڵ�"; break;
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
	case 1:cout << "�������������Կո��������������ң���ȡ��������Ԫ��ʱ����"; break;
	case 2:cout << "����һ��������ʾ���ɶ��ٸ���㣨ֻ���ȡһ�������������ᱻ���ԣ�"; break;
	case 3:cout << "�������������Կո��������һ���������ı䣬��������������,������һ�����򽫸�������"; break;
	case 4:cout << "�������������Կո��������һ��ʱ����ķ��ţ��ڶ����ǲ��ҵ�����ֻ����ҵ�һ����ͬ����"; break;
	case 5:cout << "�������������Կո��������һ���������ڶ�������������������Ԫ��"; break;
	case 6:cout << "�������������Կո��������һ���������ڶ�����ɾ��������"; break;
	case 7:
	case 8:
	case 9:cout << "������һ������ֻ���ȡһ�������������ᱻ���ԣ�";
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
	cout << "�����룺 ";
}