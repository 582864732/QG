#ifndef MYFUNC_H_
#define MYFUNC_H_
#include<Windows.h>
#include<stdlib.h>
#include<iostream>
//打印整形数组
void printInt(int* nums, int length, char split = ' ', char ending = '\n');
//随记生成数
int randomNum(int lower, int upper);
//随机生成数组
void randomCreate(int* nums, int length, int min, int max);
//设置光标坐标
void setPos(int x, int y);
//获取光标坐标
void getPos(int& x, int& y);
//设置光标可见性
void setCursorVisible(int visible);

#endif // !MYFUNC_H_
