#include"myfunc.h"
#include"sort.hpp"
#include"myInterserface.h"
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<fstream>
#include<string>
#include<vector>
#include"myInterserface.h"
#include<conio.h>
using std::cout;
using std::endl;
using std::cin;
#define SIZE 10

//int nums[10] = {1,2,3,4,5,6,7,8,9,0};
//得到两次调用的时间差
double timeCounter(bool use_ms = false)
{
	static __int64 pre_time = 0;
	static __int64 count = 0;
	if(count==0) QueryPerformanceFrequency((LARGE_INTEGER*)&count);
	if (pre_time == 0) QueryPerformanceCounter((LARGE_INTEGER*)&pre_time);
	static double second_percount = 1.0 / count;
	__int64 curr_time;
	QueryPerformanceCounter((LARGE_INTEGER*)&curr_time);
	double dt = (curr_time - pre_time) * second_percount;
	pre_time = curr_time;
	if (use_ms) dt *= 1000;
	return dt;
}

int getArrayLength(ifstream &file)
{
	string str;
	getline(file, str);
	string l = "";
	for (int i = 13; i < str.length(); i++)
	{
		l += str[i];
	}
	return atoi(l.c_str());
}

bool saveFile(int* nums,int length,string filename)
{
	ofstream file(filename);
	if (!file.is_open()) return false;
	file << "array length " << length << endl;
	for (int i = 0; i < length; i++)
	{
		file << nums[i] ;
		if (i % 50 == 0) file << endl;
		else file << ' ';
	}
	file.close();
	return true;
}

MyIntersurface m_surface;

void stop(string str)
{
	cout << str << endl;
	_getch();
}

void allSort(int length,int k)
{
	if (length <= 0 && k <= 0) return;
	setCursorVisible(0);
	cout << "正在对长度为" << length << "的不同数组进行" << k << "次排序" << endl;
	string sort_name[6] = { "插入排序","归并排序","快速排序","计数排序","基数计数排序","快排非递归版" };
	double t[6] = {0};
	int y;
	int x;
	getPos(x, y);
	string str1 = "正在进行";
	string str2 = "，完成度：";
	for (int i = 0; i < 6; i++)
	{
		//i = 5;
		cout << str1 << sort_name[i] << str2;
		double total_time=0;
		for (int n = 1; n <= k; n++)
		{
			int* nums = new int[length];
			randomCreate(nums, length, 0, 10000);
			setPos(sort_name[i].length() + str1.length()+str2.length(), y);
			m_surface.loading((float)(n-1) / k * 100);
			timeCounter();
			switch (i)
			{
			case 0: insertSort(nums, length);
			case 1: mergeSort(nums, length);
			case 2: quickSort(nums, length);
			case 3: countSort(nums, length);
			case 4: radixCountSort(nums, length);
			case 5:quickSort2(nums, length);
			}
			total_time+= timeCounter(1);
			if (!isSorted(nums, length))
			{
				cout << "排序出错" << endl;
				return;
			}
			delete[] nums;
		}
		t[i] = total_time;
		setPos(sort_name[i].length() + str1.length() + str2.length(), y);
		m_surface.loading((float)100);
		y++;
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << sort_name[i] << " 用时 " << t[i]<<" ms"<<endl;
	}
	setCursorVisible(1);
}

void caseOne()
{
	cout << "输入数组长度: " << endl;
	string str;
	getline(cin, str);
	int length = atoi(str.c_str());
	cout << "输入文件名称: "<<endl;
	getline(cin, str);
	int* nums = new int[length];
	randomCreate(nums, length, 0, 10000);
	if (!saveFile(nums, length, str))
	{
		cout << "无法打开文件";
		return;
	}
	cout << "成功保存文件"<<endl;
	delete[] nums;
	stop("按任意键返回主界面");
}

void caseTwo()
{
	cout << "输入文件名称:" << endl;
	string str;
	getline(cin, str);
	ifstream file(str);
	if (!file.is_open())
	{
		cout << "无法打开文件";
		return;
	}
	int length = getArrayLength(file);
	int* nums = new int[length];
	for (int i = 0; i < length; i++)
	{
		file >> nums[i];
	}
	quickSort(nums, length);
	cout << "成功排序" << endl;
	cout << "是否保存，若保存直接输入文件名" << endl;
	getline(cin, str);
	if (saveFile(nums, length, str)) cout << "成功保存文件";
	delete[] nums;
	stop("按任意键返回主界面");
}

void caseThree()
{
	string str;
	int length;
	int k;
	cout << "请输入数组长度：" << endl;
	getline(cin, str);
	length = atoi(str.c_str());
	cout << "请输入排序次数：" << endl;
	getline(cin, str);
	k = atoi(str.c_str());
	system("cls");
	allSort(length, k);
	stop("按任意键返回主界面");
}

void caseFour()
{
	system("cls");
	cout << "对长度为1000的数组排序" << endl;
	allSort(1000, 1);
	cout << endl << "对长度为10000的数组排序" << endl;
	allSort(10000, 1);
	cout << endl << "对长度为20000的数组排序" << endl;
	allSort(20000, 1);
	stop("按任意键返回主菜单");
}

void caseFive()
{
	system("cls");
	cout << "正在生成长度为100的数组（只包含0，1，2）" << endl;
	Sleep(1000);
	int nums[100];
	randomCreate(nums, 100, 0, 2);
	cout << "原数组为：" << endl;
	printInt(nums, 100);
	Sleep(1000);
	cout << "排序后数组为" << endl;
	rainbowSort(nums,100);
	printInt(nums, 100);
	stop("按任意键返回主菜单");
}

int main()
{
	srand(time(0));
	while (true)
	{
		system("cls");
		m_surface.drawMain();
		char c;
		c = _getch();
		switch (c)
		{
		case '\0':
		case '0':return 0;
		case '1':caseOne(); break;
		case '2':caseTwo(); break;
		case '3':caseThree(); break;
		case '4':caseFour(); break;
		case '5':caseFive(); break;
		}
	}
	return 0;
}