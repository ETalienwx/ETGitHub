//1.可变参数列表源码的剖析博客
//https://blog.csdn.net/etalien_/article/details/81229152

//2.使用可变参数，实现函数，求函数参数的平均值。
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
int average(int n, ...)
{
	int i = 0;
	int sum = 0;
	va_list arg;
	va_start(arg, n);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg,int);
	}
	return sum / n;
}
int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 10;
	int average1 = average(3, a, b, c);
	printf("average1=%d\n", average1);
	int average2 = average(4, a, b, c, d);
	printf("average2=%d\n", average2);
	system("pause");
	return 0;
}

//3.使用可变参数，实现函数，求函数参数的最大值。
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
int MAX(int n, ...)
{
	va_list arg;
	va_start(arg, n);
	int i = 0;
	int max = va_arg(arg, int);
	for (i = 1; i < n;i++)
	{
		int next = va_arg(arg, int);
		if (max < next)
		{
			max = next;
		}
	}
	va_end(arg);
	return max;
}
int main()
{
	int max1 = MAX(3, 1, 2, 5);
	int max2 = MAX(5, 9, 4, 5, 6, 41);
	printf("max1=%d\n", max1);
	printf("max2=%d\n", max2);
	system("pause");
	return 0;
}