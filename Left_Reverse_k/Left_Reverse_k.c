//实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

//暴力移位
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void left_move(char arr[], int k)
{
	int len = strlen(arr);
	int i = 0;
	while (k--)
	{
		char tmp = arr[0];//保存第一个字符
		for (i = 0; i < len - 1; i++)//将后面的字符往前移动
		{
			*(arr + i) = *(arr + 1 + i);
		}
		*(arr + len - 1) = tmp;//把保存的字符放在最后
	}

}
int main()
{
	char arr[] = "abcdef";
	int k = 2;
	left_move(arr, k);
	printf("%s\n", arr);
	system("pause");
	return 0;
}

//三步翻转法
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
void reverse(char *left, char* right)
{
	assert(left&&right);
	while (left < right)
	{
		int tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move(char arr[], int k)
{
	int len = strlen(arr);
	reverse(arr, arr + k - 1);//逆序前部分
	reverse(arr + k, arr + len - 1);//逆序后部分
	reverse(arr, arr + len - 1);//逆序整个字符串
}
int main()
{
	char arr[] = "ABCDEF";
	int k = 2;
	left_move(arr, k);
	printf("%s\n", arr);
	system("pause");
	return 0;
}