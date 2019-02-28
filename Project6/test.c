//写一个函数返回参数二进制中 1 的个数
//方法一
//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <stdlib.h>
//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	while (value)
//	{
//		if (value % 2 == 1)
//		{
//			count++;
//		}
//		value = value / 2;
//	}
//	return count;
//}
//int main()
//{
//	unsigned int num = 0;
//	int ret = 0;
//	scanf("%d", &num);
//	ret = count_one_bits(num);
//	printf("count=%d\n", ret);
//	system("pause");
//	return 0;
//}
//方法二
//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <stdlib.h>
//int count_one_bits(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & n - 1;
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int num = 0;
//	int ret = 0;
//	scanf("%d", &num);
//	ret = count_one_bits(num);
//	printf("count=%d\n", ret);
//	system("pause");
//	return 0;
//}


//获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。

//方法一
//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <stdlib.h> 
//int main()
//{
//	int date = 0;
//	printf("请输入数字：");
//	scanf("%d", &date);
//	int a[32];
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		a[i] = date % 2;
//		date /= 2;
//	}
//	printf("偶数：");
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d", a[i]);
//	}
//	printf("\n");
//	printf("奇数：");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//方法二
//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	//00000000 00000000 00000000 00001010
//	//奇数位：右移0/2/4....位，按位与1（30）
//	//偶数位：右移1/3/5....位，按位与1（31）
//	int n = 0;
//	printf("请输入数字：");
//	scanf("%d", &n);
//	int i = 0;
//	printf("奇数位为：");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (n >> i)&1);
//	}
//	printf("\n");
//	printf("偶数位为：");
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d ", (n >> i)&1);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//输出一个整数的每一位。

//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <stdlib.h>
//void sss(a)
//{
//	if (a <= 9)
//	{
//		printf("%d ", a);
//	}
//	else
//	{
//		sss(a / 10);
//		printf("%d ", a%10);
//	}
//}
//int main()
//{
//	int a = 0;
//	printf("请输入一个数\n");
//	scanf("%d", &a);
//	sss(a);
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <stdlib.h>
//
//int print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	int n = 1234;
//	print(n);
//	system("pause");
//	return 0;
//}

//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同

int count(int a, int b)
{
	int m = a ^ b; // 两个数按位异或，对应不同的位将会置1 
	int num = 0;
	while (m>0)
	{
		m =m & (m - 1);//按位与方法计算一个整数中比特位为1的个数
		num++;
	}
	return num;
}
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int m = 0;
	int n = 0;
	int ret = 0;
	printf("请输入两个数\n");
	scanf("%d %d", &m, &n);
	ret = count(m,n);
	printf("有%d个比特位相同\n",ret);
	system("pause");
	return 0;
}

//写博客总结C语言操作符，博客链接发给我，并分享到群里。