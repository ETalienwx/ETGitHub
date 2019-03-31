//1.使用main函数的参数，实现一个整数计算器，程序可以接受三个参数，第一个参数“ - a”选项执行加法，“ - s”选项执行减法，“ - m”选项执行乘法，“ - d”选项执行除法，后面两个参数为操作数。
//例如：命令行参数输入：test.exe - a 1 2
//执行1 + 2输出3
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main(int argc,char* argv[],char* envp[])
//{
//	int ret = 0;
//	if (argc != 4)
//	{
//		printf("参数有误：argc=%d\n", argc);
//		return 0;
//	}
//	switch (*(argv[1] + 1))
//	{
//	case 'a':
//		ret = Add(atoi(argv[2]), atoi(argv[3]));
//		break;
//	case 's':
//		ret = Sub(atoi(argv[2]), atoi(argv[3]));
//		break;
//	case 'm':
//		ret = Mul(atoi(argv[2]), atoi(argv[3]));
//		break;
//	case 'd':
//		ret = Div(atoi(argv[2]), atoi(argv[3]));
//		break;
//	}
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}


//2.写冒泡排序可以排序多个字符串。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bubble_str(char *arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (strcmp(arr[j], arr[j + 1])>0)
			{
				char* tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	char* arr[] = { "bbbb", "xxxx", "aaaa", "cccc" };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		printf("%s\n", arr[i]);
	}
	bubble_str(arr,sz);
	printf("\n");
	for (i = 0; i < sz; i++)
	{
		printf("%s\n", arr[i]);
	}
	system("pause");
	return 0;
}
