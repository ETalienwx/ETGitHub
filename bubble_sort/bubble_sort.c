//ð������

#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int arr[], int sz)
{
	int i = 0;
	int flag = 0;
	for (i = 0; i <= sz - 1; i++)//ȷ��ð�������������10��Ԫ����9�ˣ�
	{
		int j = 0;
		flag = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j]>arr[j + 1])//��ǰһ��Ԫ�ش��ں�һ��Ԫ���򽻻���Ԫ�ص�ֵ
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)//û��Ԫ�ؽ���ʱ����ֹͣð������
			break;
	}
}
void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{
	int arr[10] = { 10,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	bubble_sort(arr, sz);
	print(arr, sz);
	system("pause");
	return 0;
}