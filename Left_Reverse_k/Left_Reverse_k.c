//ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

//������λ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void left_move(char arr[], int k)
{
	int len = strlen(arr);
	int i = 0;
	while (k--)
	{
		char tmp = arr[0];//�����һ���ַ�
		for (i = 0; i < len - 1; i++)//��������ַ���ǰ�ƶ�
		{
			*(arr + i) = *(arr + 1 + i);
		}
		*(arr + len - 1) = tmp;//�ѱ�����ַ��������
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

//������ת��
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
	reverse(arr, arr + k - 1);//����ǰ����
	reverse(arr + k, arr + len - 1);//����󲿷�
	reverse(arr, arr + len - 1);//���������ַ���
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