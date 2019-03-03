//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
koujue(int n)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-2d ", i, j, i*j);
		}
		printf("\n");
	}
}
int main()
{
	int line = 0;
	printf("请输入乘法口诀表的行列数\n");
	scanf("%d", &line);
	koujue(line);
	system("pause");
	return 0;
}


//2.使用函数实现两个数的交换。

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	int a = 0;
	int b = 0;
	printf("请输入两个数\n");
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	swap(&a, &b);
	printf("a = %d b = %d", a, b);
	system("pause");
	return 0;
}


//3.实现一个函数判断year是不是润年。

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
void runnian(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		printf("%d是闰年\n",year);
	}
	if (year % 400 == 0)
	{
		printf("%d是闰年\n", year);
	}
	else
	{
		printf("%d是不是闰年\n", year);

	}
}
int main()
{
	int year = 0;
	printf("请输入年份：\n");
	scanf("%d", &year);
	runnian(year);
	system("pause");
	return 0;
}

//输出1000-2000年之间的闰年
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int runnian(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
}
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (runnian(year))
		{
			printf("%d ", year);
		}
	}
	system("pause");
	return 0;
}

//判断某一年是不是闰年
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int runnian(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0));
}
int main()
{
	int year = 1236;
	if (runnian(year))
	{
		printf("%d是闰年 ", year);
	}
	else
		("%d不是闰年", year);
	system("pause");
	return 0;
}


//4.创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
void init(int arr[],int sz)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
}
void empty(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		arr[i] = 0;
	}
}
void reverse(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		arr[i] = sz-1-i;
	}
}
int main()
{
	int i = 0;
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof (arr[0]);
	init(arr, sz);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	empty(arr, sz);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	reverse(arr, sz);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}



#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

void init(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = i;
	}
}
void empty(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}
void reverse(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = sz-i-1;
	}
}
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int i = 0;
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof (arr[0]);
	init(arr, sz);
	print(arr, sz);
	empty(arr, sz);
	print(arr, sz);
	reverse(arr, sz);
	print(arr, sz);
	system("pause");
	return 0;
}


//5.实现一个函数，判断一个数是不是素数。
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
void sushu(a)
{
	int i = 0;
	for (i = 2; i <= a - 1; i++)
	{
		if (a%i == 0)
		{
			printf("%d不是素数", a);
			break;
		}
		else
		{
			printf("%d是素数", a);
			break;
		}
	}
}
int main()
{
	int a = 0;
	printf("请输入一个数\n");
	scanf("%d", &a);
	sushu(a);
	system("pause");
	return 0;
}
