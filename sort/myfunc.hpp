#ifndef MYFUNC_H_
#define MYFUNC_H_
#include<Windows.h>
#include<stdlib.h>
#include<iostream>

//template<typename T>
//void swap(T& a, T& b)
//{
//	T c = a;
//	a = b;
//	b = c;
//}

void printInt(int* nums, int length,char split = ' ',char ending = '\n')
{
	for (int i = 0; i < length; i++)
	{
		std::cout << nums[i];
		if (i != length) std::cout << split;
	}
	std::cout << ending;
}

int randomNum(int lower,int upper)
{
	return rand() % (upper - lower + 1) + lower;
}

void randomCreate(int* nums, int length,int min,int max)
{
	for (int i = 0; i < length; i++)
	{
		nums[i] = rand() % (max - min + 1) + min;
	}
}

void SetPos(int x, int y)
{
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(houtput, pos);
}


#endif // !MYFUNC_H_
