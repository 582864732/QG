#include"myInterserface.h"
#include<iostream>
#include<iomanip>
using std::cout;
using std::endl;

MyIntersurface::MyIntersurface(){}

MyIntersurface::~MyIntersurface(){}

void MyIntersurface::drawMain()
{
	setPos(0, 0);
	for (int i = 0; i < 60; i++) cout << '-';
	cout << endl;
	cout << "输入 0 退出程序" << endl;
	cout << "1.生成并保存数组" << endl;
	cout << "2.读取并排序数组" << endl;
	cout << "3.对长度为 n 的不同数组进行 k 次排序并记录时间" << endl;
	cout << "4.对一个大数组排序并记录时间" << endl;
	cout << "5.颜色排序" << endl;
	for (int i = 0; i < 60; i++) cout << '-';
	cout << endl;
}

void MyIntersurface::loading(float rate)
{
	//cout << std::setw(6) << rate<<"%";
	printf("%6.2f", rate);
	cout << '%';
}

void MyIntersurface::loading(int rate)
{
	cout << std::setw(3) << rate << "%";
}