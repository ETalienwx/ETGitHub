//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
//�ݹ�
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
//�ǵݹ�
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
//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
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


//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ����磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
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

//4. ��дһ������reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
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

//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//�ݹ�
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
//�ǵݹ�
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
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
//�ݹ�
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
//�ǵݹ�
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


//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
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