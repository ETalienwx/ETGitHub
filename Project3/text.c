
//编写程序数一下 1到 100 的所有整数中出现多少次数字9
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int a = 0;
//	int count = 0;
//	for (a = 1; a <= 100; a++)
//	{
//		int gw = a / 1 % 10;
//		int sw = a / 10 % 10;
//		if (gw == 9)
//		{
//			count++;
//		}
//		if (sw == 9)
//		{
//			count++;
//		}
//	}
//	printf("count=%d ", count);
//	system("pause");
//	return 0;
//}
//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int i=0;
//	double sum=0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum = sum + flag*(1.0/i);
//		flag = -flag;
//	}
//	printf("%lf ",sum);
//	system("pause");
//	return 0;
//}
//将数组A中的内容和数组B中的内容进行交换。（数组一样大） 
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[] = { 6, 7, 8, 9, 10 };
//	int i = 0;
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	for (i = 0; i < sz; i++)
//	{
//		int tmp = 0;
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}