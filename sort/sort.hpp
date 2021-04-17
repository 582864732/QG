#ifndef SORT_H_
#define SORT_H_
#include<iostream>
using namespace std;

void swap(int* nums, int p, int q)
{
	int c = nums[p];
	nums[p] = nums[q];
	nums[q] = c;
}

bool isSorted(int* nums, int length)
{
	if (length <= 0) return false;
	int max = nums[0];
	for (int i = 0; i < length; i++)
	{
		if (nums[i] < max) return false;
		else max = nums[i];
	}
	return true;
}

bool isSorted(int* nums, int end, int first)
{
	int max = nums[first];
	for (int i = first;i<=end;i++)
	{
		if (nums[i] < max) return false;
		else max = nums[i];
	}
	return true;
}
//插入排序
void insertSort(int* nums, int length)
{
	for (int i = 1; i < length; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (nums[j] < nums[j - 1]) swap(nums, j, j - 1);
			else break;
		}
	}
}

//归并排序
void mergeSort(int *nums,int end,int start = 0)
{
	if (end != start)
	{
		mergeSort(nums, (end + start) / 2, start);
		mergeSort(nums, end, (end + start) / 2 + 1);
	}
	else return;

	int* nums1 = new int[(end + start) / 2 - start + 2];
	int* nums2 = new int[end - (end + start) / 2 + 3];
	int count = start;
	int i = 0, j = 0;
	for (int n = start; n <= (end + start) / 2; n++, i++) nums1[i] = nums[n];
	for (int n = (end + start) / 2 + 1; n <= end; n++, j++) nums2[j] = nums[n];
	nums1[i] = MAXINT;
	nums2[j] = MAXINT;
	i = 0;
	j = 0;

	while (count!=end+1)
	{
		if (nums1[i] > nums2[j])
		{
			nums[count] = nums2[j];
			j++;
		}
		else
		{
			nums[count] = nums1[i];
			i++;
		}
		count++;
	}
	delete[] nums1;
	delete[] nums2;
}

//快排递归版
void quickSort(int *nums,int end,int first = 0)
{
	if (end <= first)return;
	int r = randomNum(first, end);
	swap(nums[end], nums[r]);
	int i = first-1, j = first;
	for (; j != end; j++)
	{
		if(nums[j]<=nums[end])
		{
			i++;
			swap(nums[i], nums[j]);
		}
	}
	swap(nums[i + 1], nums[end]);
	if (isSorted(nums, end, first)) return;
	quickSort(nums, end,i+1);
	quickSort(nums, i, first);
}

//计数排序
void countSort(int* nums, int length)
{
	int min = nums[0];
	int max = nums[0];
	for (int i = 0; i < length; i++)
	{
		if (nums[i] < min) min = nums[i];
		else if (nums[i] > max) max = nums[i];
	}
	int* count_nums = new int[max - min + 1];
	for (int i = 0; i < max-min+1; i++) count_nums[i] = 0;
	for (int i = 0; i < length; i++)
	{
		count_nums[nums[i] - min] ++;
	}
	int n = 0;
	for (int i = 0; i < max - min + 1; i++)
	{
		for (int j = 0; j < count_nums[i]; j++)
		{
			nums[n] = i + min;
			n++;
		}
	}
	delete[] count_nums;
}

//基数计数排序
void radixCountSort(int* nums, int length)
{
	int n = 10;
	while (true)
	{
		int counts[10] = { 0 };
		int total = 0;
		for (int i = 0; i < length; i++)
		{
			counts[(nums[i] % n) / (n / 10)]++;
		}
		for (int i = 0; i < 10; i++)
		{
			total += counts[i];
			if (counts[i] != 0) counts[i] = total;
		}
		int *sort_nums = new int[length];
		for (int i = length-1; i>=0; i--)
		{
			int num = (nums[i] % n) / (n / 10);
			sort_nums[--counts[num]] = nums[i];
			//counts[num]--;
		}
		for (int i = 0; i < length; i++) nums[i] = sort_nums[i];
		delete[] sort_nums;
		n *= 10;
		if (isSorted(nums, length)) return;
	}
}

//快排非递归版
void quickSort2(int *nums,int length)
{
	int end = length - 1;
	int first = 0;
	while (true)
	{
		int i = first - 1, j = first;
		for (; j != end; j++)
		{
			if (nums[j] <= nums[end])
			{
				i++;
				swap(nums[i], nums[j]);
			}
		}
		swap(nums[i + 1], nums[end]);
	}
}

#endif // !SORT_H_
