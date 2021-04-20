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
//�õ����ε��õ�ʱ���
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
	cout << "���ڶԳ���Ϊ" << length << "�Ĳ�ͬ�������" << k << "������" << endl;
	string sort_name[6] = { "��������","�鲢����","��������","��������","������������","���ŷǵݹ��" };
	double t[6] = {0};
	int y;
	int x;
	getPos(x, y);
	string str1 = "���ڽ���";
	string str2 = "����ɶȣ�";
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
				cout << "�������" << endl;
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
		cout << sort_name[i] << " ��ʱ " << t[i]<<" ms"<<endl;
	}
	setCursorVisible(1);
}

void caseOne()
{
	cout << "�������鳤��: " << endl;
	string str;
	getline(cin, str);
	int length = atoi(str.c_str());
	cout << "�����ļ�����: "<<endl;
	getline(cin, str);
	int* nums = new int[length];
	randomCreate(nums, length, 0, 10000);
	if (!saveFile(nums, length, str))
	{
		cout << "�޷����ļ�";
		return;
	}
	cout << "�ɹ������ļ�"<<endl;
	delete[] nums;
	stop("�����������������");
}

void caseTwo()
{
	cout << "�����ļ�����:" << endl;
	string str;
	getline(cin, str);
	ifstream file(str);
	if (!file.is_open())
	{
		cout << "�޷����ļ�";
		return;
	}
	int length = getArrayLength(file);
	int* nums = new int[length];
	for (int i = 0; i < length; i++)
	{
		file >> nums[i];
	}
	quickSort(nums, length);
	cout << "�ɹ�����" << endl;
	cout << "�Ƿ񱣴棬������ֱ�������ļ���" << endl;
	getline(cin, str);
	if (saveFile(nums, length, str)) cout << "�ɹ������ļ�";
	delete[] nums;
	stop("�����������������");
}

void caseThree()
{
	string str;
	int length;
	int k;
	cout << "���������鳤�ȣ�" << endl;
	getline(cin, str);
	length = atoi(str.c_str());
	cout << "���������������" << endl;
	getline(cin, str);
	k = atoi(str.c_str());
	system("cls");
	allSort(length, k);
	stop("�����������������");
}

void caseFour()
{
	system("cls");
	cout << "�Գ���Ϊ1000����������" << endl;
	allSort(1000, 1);
	cout << endl << "�Գ���Ϊ10000����������" << endl;
	allSort(10000, 1);
	cout << endl << "�Գ���Ϊ20000����������" << endl;
	allSort(20000, 1);
	stop("��������������˵�");
}

void caseFive()
{
	system("cls");
	cout << "�������ɳ���Ϊ100�����飨ֻ����0��1��2��" << endl;
	Sleep(1000);
	int nums[100];
	randomCreate(nums, 100, 0, 2);
	cout << "ԭ����Ϊ��" << endl;
	printInt(nums, 100);
	Sleep(1000);
	cout << "���������Ϊ" << endl;
	rainbowSort(nums,100);
	printInt(nums, 100);
	stop("��������������˵�");
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