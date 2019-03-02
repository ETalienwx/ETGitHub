//#include <stdio.h>
//#include <stdlib.h>
//int Max(int a, int b)
//{
//	return a > b ? a : b;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int max = Max(a, b);
//	printf("%d ", max);
//	system("pause");
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//void swap(int *x, int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("a = %d , b = %d\n", a, b);
//	swap(&a, &b);
//	printf("a = %d , b = %d\n", a, b);
//	system("pause");
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//int sushu(int n)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(n); i++)
//	{
//		if ((n%i) == 0)
//			return 0;
//		
//	}
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (sushu(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	system("pause");
//	return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//int runnian(int i)
//{
//	return ((i % 4 == 0) && (i % 100 != 0) || (i % 400 == 0));
//}
//int main()
//{
//	int year = 0;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (runnian(year))
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
//	printf("count=%d ", count);
//	system("pause");
//	return 0;
//}
#include <stdio.h>
#include <stdlib.h>
int binary_search(int arr[], int k, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
	    if (arr[mid] < k)
		{
			left = mid + 1;
		}
		if (arr[mid]>k)
		{
			right = mid - 1;
		}
		if (arr[mid] == k)
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int k = 7;
	int ret=binary_search(arr, k, sz);
	if (ret==-1)
	{
		printf("没有找到\n");
	}
	else
		printf("找到了，下标为%d\n", ret);
	system("pause");
	return 0;
}
