//函数栈帧剖析代码

#include <stdio.h>
#include <stdlib.h>
int Add(int x, int y)
{
	int c = 0;
	c = x + y;
	return c;
}
int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = Add(a, b);
	printf("%d\n", c);
	system("pause");
	return 0;
}


//实现一个函数可以求任意个参数的平均值

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
		sum += va_arg(arg, int);
	}
	va_end(arg);
	return sum / n;
}
int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 10;
	int average1 = average(3, a, b, c);
	int average2 = average(4, a, b, c, d);
	printf("average1 = %d\n", average1);
	printf("average2 = %d\n", average2);
	system("pause");
	return 0;
}