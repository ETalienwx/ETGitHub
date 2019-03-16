//��������ʹ����ȫ����λ��ż��ǰ�档
//��Ŀ������һ���������飬ʵ��һ�������������������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�


#include <stdio.h>
#include <stdlib.h>
void swap(int arr[], int sz)
{
	int *left = arr;
	int *right = arr+sz-1;
	while (left < right)//����ѭ��������һ����
	{
		while ((left<right) && (*left) % 2 != 0)//����߿�ʼ��һ��ż��
		{
			left++;
		}
		while ((left<right) && (*right) % 2 == 0)//���ұ߿�ʼ��һ������
		{
			right--;
		}
		if (left < right)//������������ѭ���ҳ���������������left<right���򽻻�������
		{
			int tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
}
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d  ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[] = { 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	swap(arr, sz);
	print(arr, sz);
	system("pause");
	return 0;
}

