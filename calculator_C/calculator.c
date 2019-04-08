#define _CRT_SECURE_NO_DEPRECATE 1
//实现一个计算器
//#include <stdio.h>
//#include <stdlib.h>
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int x, y;
//	int input = 1;
//	int ret = 0;
//	while (input)
//	{
//		printf("*************************\n");
//		printf("****  1.add   2.sub  ****\n");
//		printf("****  3.mul   4.div  ****\n");
//		printf("*************************\n");
//		printf("请选择：");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("请输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = add(x, y);
//			break;
//		case 2:
//			printf("请输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = sub(x, y);
//			break;
//		case 3:
//			printf("请输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = mul(x, y);
//			break;
//		case 4:
//			printf("请输入操作数：");
//			scanf("%d %d", &x, &y);
//			ret = div(x, y);
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//		printf("%d\n", ret);
//	}
//	system("pause");
//	return 0;
//}

//使用函数指针实现简易计算器
#include <stdio.h>
#include <stdlib.h>
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}
int main()
{
	int x, y;
	int input = 1;
	int ret = 0;
	int(*p[5])(int x, int y) = { 0, add, sub, mul, div };//转移表
	while (input)
	{
		printf("*************************\n");
		printf("****  1.add   2.sub  ****\n");
		printf("****  3.mul   4.div  ****\n");
		printf("*************************\n");
		printf("请选择：");
		scanf("%d", &input);
		if (input<4 && input>1)
		{
			printf("请输入操作数：");
			scanf("%d %d", &x, &y);
			ret = (*p[input])(x, y);
		}
		else
			printf("输入有误\n");
		printf("ret = %d", ret);
	}
	system("pause");
	return 0;
}