//输出菱形图案
//#include<stdio.h>
//int main()
//{
//	int line;
//	scanf_s("%d", &line);
//	int i;
//	for (i = 0; i < line - 1; i++)//打印line行
//	{
//		int j = 0;
//		for (j = 0; j < line - 1 - i;j++)//打印空格
//		{
//			printf(" ");
//		}
//		for (j = 0;j < 2 * i + 1; j++)//打印*
//		{
//			printf("*");
//		}
//			printf("\n");
//		}
//	for (i = 0; i < line-1; i++)
//	{
//		int j;
//		for (j = 0; j < i + 1;j++)
//		{
//			printf(" ");
//		}
//		for (j = 1; j <= 2 * (line-1-i) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	getchar();
//	return 0;
//}

//求出0～999之间的所有“水仙花数”并输出
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0;i<= 999; i++)
//	{
//		//确定i是几位数
//		int n = 1;
//		int sum = 0;
//		int tmp = i;
//		while (tmp / 10)
//		{
//			n++;
//			tmp = tmp / 10;
//		}
//		//拆下每一位求和
//		tmp = i;
//		while (tmp)
//		{
//			sum = sum + pow(tmp % 10, n);
//			tmp = tmp / 10;
//		}
//		//判断
//		if (sum==i)
//			printf("%d ", i);
//	}
//	getchar();
//	return 0;
//}

//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int num = 0;
//	int count = 0;
//	int sum = 0;
//	int tmp = 0;
//	scanf("%d%d", &num, &count);
//	int i = 0;
//	for (i = 0; i < count; i++)
//	{
//		tmp = tmp * 10 + num;
//		sum += tmp;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}

//编写一个程序，它从标准输入读取C源代码，并验证所有的花括号都正确的成对出现。
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int ch;
//	int count = 0;//定义一个计数器count
//	while ((ch = getchar()) != EOF)//循环输入，EOF结束
//	{
//		if (ch == '{')
//		{
//			count++;
//		}
//		//当遇到{时，计数器+1
//		if (ch == '}' && count == 0)
//		{
//			printf("不匹配\n");
//			return 0;
//		}
//		//当遇到}但计数器为0了，输出不匹配，即为}在{前边
//		if (ch == '}' && count != 0)
//		{
//			count--;
//		}
//		//当遇到}且计数器不为0时，计数器-1
//	}
//	if (count == 0)
//	{
//		printf("匹配!\n");
//	}
//	else
//	{
//		printf("不匹配!\n");
//	}//判断计数器count
//	system("pause");
//	return 0;
//}