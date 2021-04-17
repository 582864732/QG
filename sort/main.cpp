#include"myfunc.hpp"
#include"sort.hpp"
#include<iostream>
#include<stdlib.h>
#include<ctime>
using std::cout;
using std::endl;
#define SIZE 100

//int nums[10] = {1,2,3,4,5,6,7,8,9,0};

void m(int end, int first, int count = 0)
{
	static int len = end - first;
	cout << len<<endl;
	if (count == 2) return;
	else m(end, 2 * first, ++count);
}

int main()
{
	//quickSort(nums, 9);
	srand(time(0));
	int count = 0;
	for (int i = 0; i < 1000; i++)
	{
		int nums[SIZE];
		randomCreate(nums, SIZE, 0, 1000);
		radixCountSort(nums, SIZE);
		if (!isSorted(nums, SIZE))
		{
			printInt(nums, SIZE);
			cout << "sort error" << endl;
			return 0;
		}
	}
	cout << "it is Okay" << endl;
	return 0;
}