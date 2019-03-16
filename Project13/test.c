//调整数组使奇数全部都位于偶数前面。
//题目：输入一个整数数组，实现一个函数，来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分。


#include <stdio.h>
#include <stdlib.h>
void swap(int arr[], int sz)
{
	int *left = arr;
	int *right = arr+sz-1;
	while (left < right)//持续循环查找下一组数
	{
		while ((left<right) && (*left) % 2 != 0)//从左边开始找一个偶数
		{
			left++;
		}
		while ((left<right) && (*right) % 2 == 0)//从右边开始找一个奇数
		{
			right--;
		}
		if (left < right)//基于上面两个循环找出来的两个数，若left<right，则交换两个数
		{
			int tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
}
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	swap(arr, sz);
	print(arr, sz);
	system("pause");
	return 0;
}

