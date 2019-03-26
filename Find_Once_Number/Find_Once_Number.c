//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//找出这两个数字，编程实现。

#include <stdio.h>
#include <stdlib.h>
int oxr(int arr[], int sz)
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < sz; i++)
	{
		sum = sum^arr[i];
	}
	return sum;
}
int find_one(int sum)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 31; i++)
	{
		if (((sum >> i) & 1) == 1)
			return i;
	}

}
void group_oxr(int arr[], int ret, int sz)
{
	int a = 0;
	int b = 0;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> ret) & 1) == 0)
		{
			a ^= arr[i];
		}
		if (((arr[i] >> ret) & 1) != 0)
		{
			b ^= arr[i];
		}
	}
	printf("a = %d, b = %d\n", a, b);
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 1, 2, 3, 6 };

	int a = 0;
	int b = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int sum = oxr(arr, sz);
	int ret = find_one(sum);
	group_oxr(arr, ret, sz);
	system("pause");
	return 0;
}

//////#include <stdio.h>
//////#include <stdlib.h>
//////int find_one(int n)
//////{
//////	int i = 0;
//////	for (i = 0; i < 32; i++)
//////	{
//////		if (((n >> i) & 1) == 1)
//////			return i;
//////	}
//////}
//////void find_diff_num(int arr[],int sz, int *pa, int *pb)
//////{
//////	int ret = 0;
//////	int i = 0;
//////	for (i = 0; i < sz; i++)
//////	{
//////		ret ^= arr[i];
//////	}
//////	int pow = find_one(ret);
//////	if ((arr[i] >> pow) != 0)
//////	{
//////		*pa ^= arr[i];
//////	}
//////	else
//////		*pb ^= arr[i];
//////	
//////}
//////int main()
//////{
//////	int arr[] = { 1, 2, 3, 4, 1, 2, 3, 6 };
//////	int a = 0;
//////	int b = 0;
//////	int sz = sizeof(arr) / sizeof(arr[0]);
//////	find_diff_num(arr,sz, &a, &b);
//////	printf("a = %d, b = %d\n", a, b);
//////	system("pause");
//////	return 0;
//////}