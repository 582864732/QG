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
	cout << "���� 0 �˳�����" << endl;
	cout << "1.���ɲ���������" << endl;
	cout << "2.��ȡ����������" << endl;
	cout << "3.�Գ���Ϊ n �Ĳ�ͬ������� k �����򲢼�¼ʱ��" << endl;
	cout << "4.��һ�����������򲢼�¼ʱ��" << endl;
	cout << "5.��ɫ����" << endl;
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