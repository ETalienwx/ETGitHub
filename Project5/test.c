////计算n的阶乘
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= 5; i++)
//	{
//		ret = ret*i;
//	}
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}


////计算1！+2！+31+....+n！

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int num = 0;
//	int ret = 1;
//	for (n = 1; n <= 3; n++)
//	{
//		ret = ret*n;
//		num = num + ret;
//	}
//	printf("%d\n", num);
//	system("pause");
//	return 0;
//}


//完成猜数字游戏

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void menu()
//{
//	printf("***************************\n");
//	printf("*********  1.play  ********\n");
//	printf("*********  0.exit  ********\n");
//	printf("***************************\n");
//
//}
//void game()
//{
//	//随机生成一个数字
//	int ret = 0;
//	int n = 0;
//	ret = rand()%101;
//	//猜数字
//	while (1)
//	{
//		printf("请猜数字：\n");
//		scanf_s("%d",&n);
//		if (n == ret)
//		{
//			printf("恭喜你猜对了\n");
//			break;
//		}
//		else if (n < ret)
//		{
//			printf("猜小了：\n");
//		}
//		else
//		{
//			printf("猜大了：\n");
//
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	//srand:随机数的生成起点
//	//time：类型为long，所以我们强转为int型（unsigned int），参数为指针（不确定我们定为NULL）
//	//srand函数在整个代码中只调用一次
//	do{
//		menu();
//		printf("请选择：\n");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("玩游戏\n");
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}

//编写代码模拟三次密码输入的场景。最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。

//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main()
//{
//	//"123456"
//	char arr[10] = {0};
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码\n");
//		scanf("%s", arr);
//		if (strcmp(arr,"123456") == 0)
//		{
//			printf("登陆成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误，请重新输入\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次密码错误，退出程序\n");
//	}
//	system("pause");
//	return 0;
//}


//编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			putchar(ch - 32);
		}
		else if (ch >= 'A'&& ch <= 'Z')
		{
			putchar(ch + 32);
		}
		else if (ch >= '0'&& ch <= '9')
		{
			;
		}
		else
		{
			putchar(ch);
		}
	}
	system("pause");
	return 0;
}