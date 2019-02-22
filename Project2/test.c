#include<stdio.h>
int main()
////求两个数的最大公约数(辗转相除法)(最小公倍数==x*y/最大公约数)
//{
//	int x = 16;
//	int y = 24;
//	int z = 0;
//	while (z = x%y)//若z！=0则为真，进入while内部，若z=0则为假，循环停止
//	{
//		x = y;
//		y = z;
//	}
//	printf("%d ", y);
//	getchar();
//	return 0;
//}


//优化三个数按照从大到小的顺序输出(把重复的代码使用函数,使用指针)
//void Swap (int *x, int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//int main()
//{
//	int a = 25;
//	int b = 56;
//	int c = 98;
//	int tmp = 0;
//	if (a < b)
//	{
//		Swap(&a, &b);
//	}
//	if (a < c)
//	{
//		Swap(&a, &c);
//	}
//	if (b < c)
//	{
//		Swap(&b, &c);
//	}
//	printf("%d %d %d ", a, b, c);
//	getchar();
//	return 0;
//}
//使三个数按照从大到小的顺序输出
//{
//	int a = 25;
//	int b = 56;
//	int c = 98;
//	int tmp = 0;
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d ", a, b, c);
//	getchar();
//	return 0;
//}
//求10个整数中的最大值
{
	int arr[] = { -1, 2, -3, 8, -9, 56, -7, -4, 15, 86};
	int max = arr[0];
	int i = 0;
	int sz = sizeof (arr) / sizeof (arr[0]);
	for (i = 1; i < sz; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}
	printf("max = %d\n", max);
	getchar();
	return 0;
}
//不创建临时变量，交换两个数的内容
//{
//	int a = 10;//01010
//	int b = 20;//10100//按位异或，相同异或为0，不同异或为1	
//	printf("a=%d  b=%d  \n", a, b);
//	a = a^b;//11110
//	b = a^b;//01010
//	a = a^b;//10100
//	printf("a=%d  b=%d  \n", a, b);
//	getchar();
//	return 0;
//}
//{
//	//给定两个整形变量的值，将两个值的内容进行交换
//	int a = 10;
//	int b = 20;
//	int c;
//	printf("a=%d  b=%d  \n", a, b);
//	c = a;
//	a = b;
//	b = c;
//	printf("a=%d  b=%d  \n", a, b);
//	getchar();
//	return 0;
//}