#include<stdio.h>
int main()
////�������������Լ��(շת�����)(��С������==x*y/���Լ��)
//{
//	int x = 16;
//	int y = 24;
//	int z = 0;
//	while (z = x%y)//��z��=0��Ϊ�棬����while�ڲ�����z=0��Ϊ�٣�ѭ��ֹͣ
//	{
//		x = y;
//		y = z;
//	}
//	printf("%d ", y);
//	getchar();
//	return 0;
//}


//�Ż����������մӴ�С��˳�����(���ظ��Ĵ���ʹ�ú���,ʹ��ָ��)
//void Swap (int *x, int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//int main()
//{
//	int a = 25;
//	int b = 56;
//	int c = 98;
//	int tmp = 0;
//	if (a < b)
//	{
//		Swap(&a, &b);
//	}
//	if (a < c)
//	{
//		Swap(&a, &c);
//	}
//	if (b < c)
//	{
//		Swap(&b, &c);
//	}
//	printf("%d %d %d ", a, b, c);
//	getchar();
//	return 0;
//}
//ʹ���������մӴ�С��˳�����
//{
//	int a = 25;
//	int b = 56;
//	int c = 98;
//	int tmp = 0;
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("%d %d %d ", a, b, c);
//	getchar();
//	return 0;
//}
//��10�������е����ֵ
{
	int arr[] = { -1, 2, -3, 8, -9, 56, -7, -4, 15, 86};
	int max = arr[0];
	int i = 0;
	int sz = sizeof (arr) / sizeof (arr[0]);
	for (i = 1; i < sz; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}
	printf("max = %d\n", max);
	getchar();
	return 0;
}
//��������ʱ����������������������
//{
//	int a = 10;//01010
//	int b = 20;//10100//��λ�����ͬ���Ϊ0����ͬ���Ϊ1	
//	printf("a=%d  b=%d  \n", a, b);
//	a = a^b;//11110
//	b = a^b;//01010
//	a = a^b;//10100
//	printf("a=%d  b=%d  \n", a, b);
//	getchar();
//	return 0;
//}
//{
//	//�����������α�����ֵ��������ֵ�����ݽ��н���
//	int a = 10;
//	int b = 20;
//	int c;
//	printf("a=%d  b=%d  \n", a, b);
//	c = a;
//	a = b;
//	b = c;
//	printf("a=%d  b=%d  \n", a, b);
//	getchar();
//	return 0;
//}