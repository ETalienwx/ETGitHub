//���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//1 2 3
//4 5 6
//7 8 9
#include <stdio.h>
#include <stdlib.h>
int find(int arr[3][3], int *px, int *py, int k)
{
	int x = 0;
	int y = *py - 1;
	while (x < *px && y >= 0)
	{
		if (arr[x][y]<k)
			x++;//��ĳһ�е����Ҳ�Ԫ��С������Ҫ���ҵ�ֵ��������ȥ��һ��
		else if (arr[x][y]>k)
			y--;//��ĳһ�е����Ҳ�Ԫ�ش�������Ҫ���ҵ�ֵ��������ȥ��һ��
		else
		{
			//�����Ͳ���
			//�����ҵ���x��y�������ǵ��±�
			*px = x;//��x��ֵ����*px��*px���������x
			*py = y;//��y��ֵ����*py��*py���������y
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int k = 7;
	int x = 3;
	int y = 3;
	int ret = find(arr, &x, &y, k);
	if (ret == 1)
	{
		printf("�ҵ���:>%d %d\n",x,y);
	}
	else
	{
		printf("û���ҵ�\n");
	}
	system("pause");
	return 0;
}