//1.递归和非递归分别实现求第n个斐波那契数。
//递归
#include <stdio.h>
#include <stdlib.h>
int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main()
{
	int n = 6;
	printf("%d \n",fib(n));
	system("pause");
	return 0;
}
//非递归
#include <stdio.h>
#include <stdlib.h>
int fib(int n)
{
	if (n <= 2)
		return 1;
	else
	{
		int a = 1;
		int b = 1;
		int c = 0;
		while (n>2)
		{
			c = a + b;
			a = b;
			b = c;
			n--;
		}
		return c;
	}
}
int main()
{
	int n = 6;
	printf("%d \n", fib(n));
	system("pause");
	return 0;
}
//2.编写一个函数实现n^k，使用递归实现
#include <stdio.h>
#include <stdlib.h>
int fun(int n, int k)
{
	int ret = 0;
	if (k == 0)
	{
		ret = 1;
	}
	else
	{
		ret = n*fun(n, k - 1);
	}
	return ret;
}
int main()
{
	int n = 2;
	int k = 3;
	printf("ret = %d\n",fun(n, k));
	system("pause");
	return 0;
}


//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
#include <stdio.h>
#include <stdlib.h>
int DigitSum(int n)
{
	if (n < 9)
		return n;
	else
		return n % 10 + DigitSum(n / 10);
}
int main()
{
	int num = 1729;
	printf("%d\n",DigitSum(num));
	system("pause");
	return 0;
}

//4. 编写一个函数reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int my_strlen(char *str)
{
	assert(str);
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
void reverse_string(char *str)
{
	assert(str);
	char tmp = 0;
	int len = my_strlen(str);
	if (len > 0)
	{
		tmp = str[0];
		str[0] = str[len - 1];
		str[len - 1] = '\0';
		reverse_string(str + 1);
		str[len - 1] = tmp;
	}
}
int main()
{
	char arr[] = "abcdefgh";
	reverse_string(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}

//5.递归和非递归分别实现strlen
//递归
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
size_t my_strlen(const char *str)
{
	assert(str != NULL);
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen(str + 1);

}
int main()
{
	char arr[] = "abcdef";
	int len = my_strlen(arr);
	printf("%d \n", len);
	system("pause");
	return 0;
}
//非递归
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
size_t my_strlen(const char *str)
{
	assert(str != NULL);
	unsigned int count = 0;
	while (*str != 0)
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char arr[] = "abcdef";
	int len = my_strlen(arr);
	printf("%d \n", len);
	system("pause");
	return 0;
}
//6.递归和非递归分别实现求n的阶乘
//递归
#include <stdio.h>
#include <stdlib.h>
int fac(int n)
{
	if (n <= 1)
		return 1;
	else
		return n*fac(n - 1);
}
int main()
{
	int n = 5;
	printf("%d ", fac(n));
	system("pause");
	return 0;
}
//非递归
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n = 5;
	int i = 0;
	int ret = 1;
	for (i = 1; i <= n; i++)
	{
		ret *= i;
	}
	printf("ret = %d \n", ret);
	system("pause");
	return 0;
}


//7.递归方式实现打印一个整数的每一位
#include <stdio.h>
#include <stdlib.h>
void print(int num)
{
	if (num > 9)
		print(num / 10);
	printf("%d ", num % 10);
}
int main()
{
	int num = 1234;
	print(num);
	system("pause");
	return 0;
}