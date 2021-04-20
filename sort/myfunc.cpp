#include"myfunc.h"
#include<iostream>
using std::cout;
using std::endl;

void printInt(int* nums, int length, char split, char ending)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << nums[i];
		if (i != length) std::cout << split;
	}
	std::cout << ending;
}

int randomNum(int lower, int upper)
{
	return rand() % (upper - lower + 1) + lower;
}

void randomCreate(int* nums, int length, int min, int max)
{
	for (int i = 0; i < length; i++)
	{
		nums[i] = rand() % (max - min + 1) + min;
	}
}

void setPos(int x, int y)
{
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(houtput, pos);
}

void getPos(int& x, int& y)
{
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bi;
	GetConsoleScreenBufferInfo(houtput,&bi);
	x = bi.dwCursorPosition.X;
	y = bi.dwCursorPosition.Y;
}

void setCursorVisible(int visible)
{	
	if (visible != 0 && visible != 1) return;
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ci;
	GetConsoleCursorInfo(houtput, &ci);
	ci.bVisible = visible;
	SetConsoleCursorInfo(houtput, &ci);
}
