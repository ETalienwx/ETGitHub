//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
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
	printf("������˷��ھ����������\n");
	scanf("%d", &line);
	koujue(line);
	system("pause");
	return 0;
}


//2.ʹ�ú���ʵ���������Ľ�����

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
	printf("������������\n");
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	swap(&a, &b);
	printf("a = %d b = %d", a, b);
	system("pause");
	return 0;
}


//3.ʵ��һ�������ж�year�ǲ������ꡣ

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
void runnian(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
	{
		printf("%d������\n",year);
	}
	if (year % 400 == 0)
	{
		printf("%d������\n", year);
	}
	else
	{
		printf("%d�ǲ�������\n", year);

	}
}
int main()
{
	int year = 0;
	printf("��������ݣ�\n");
	scanf("%d", &year);
	runnian(year);
	system("pause");
	return 0;
}

//���1000-2000��֮�������
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

//�ж�ĳһ���ǲ�������
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
		printf("%d������ ", year);
	}
	else
		("%d��������", year);
	system("pause");
	return 0;
}


//4.����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��

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


//5.ʵ��һ���������ж�һ�����ǲ���������
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
			printf("%d��������", a);
			break;
		}
		else
		{
			printf("%d������", a);
			break;
		}
	}
}
int main()
{
	int a = 0;
	printf("������һ����\n");
	scanf("%d", &a);
	sushu(a);
	system("pause");
	return 0;
}
