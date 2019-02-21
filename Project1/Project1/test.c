#include<stdio.h>
int main()
{
	int year;
	for (year = 1000; year <= 2000; year++)
	{
		if (year % 4 == 0)
		{
			if (year%100!=0)
			{
				printf("%d ", year);
			}
		}
		if (year%400==0)
			printf("%d ", year);
	}
	getchar();
	return 0;
}
//打印乘法口诀表
//{
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//	getchar();
//	return 0;
//}
//打印100-200之间的素数
//{
//	int a, i;
//	for (a = 100; a <= 200; a++)
//	{
//		for (i = 2; i <= a - 1; i++)
//		{
//			if (a%i == 0)
//				break;
//		}
//		if (a==i)
//		printf("%d  ", a);
//	}
//	getchar();
//	return 0;
//}