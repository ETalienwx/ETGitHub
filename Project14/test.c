//判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.

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
int is_left_move(char *arr1, char *arr2)
{
	int len = strlen(arr1);
	while (len--)
	{
		left_move(arr1, 1);
		if (strcmp(arr1, arr2) == 0)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	char arr1[] = "AABCD";
	char arr2[] = "BCDAA";
	int ret = is_left_move(arr1, arr2);
	if (ret == 1)
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
	return 0;
}
