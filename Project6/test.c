//дһ���������ز����������� 1 �ĸ���
//����һ
//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <stdlib.h>
//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	while (value)
//	{
//		if (value % 2 == 1)
//		{
//			count++;
//		}
//		value = value / 2;
//	}
//	return count;
//}
//int main()
//{
//	unsigned int num = 0;
//	int ret = 0;
//	scanf("%d", &num);
//	ret = count_one_bits(num);
//	printf("count=%d\n", ret);
//	system("pause");
//	return 0;
//}
//������
//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <stdlib.h>
//int count_one_bits(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & n - 1;
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int num = 0;
//	int ret = 0;
//	scanf("%d", &num);
//	ret = count_one_bits(num);
//	printf("count=%d\n", ret);
//	system("pause");
//	return 0;
//}


//��ȡһ�������������������е�ż��λ������λ���ֱ�������������С�

//����һ
//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <stdlib.h> 
//int main()
//{
//	int date = 0;
//	printf("���������֣�");
//	scanf("%d", &date);
//	int a[32];
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		a[i] = date % 2;
//		date /= 2;
//	}
//	printf("ż����");
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d", a[i]);
//	}
//	printf("\n");
//	printf("������");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d", a[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//������
//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	//00000000 00000000 00000000 00001010
//	//����λ������0/2/4....λ����λ��1��30��
//	//ż��λ������1/3/5....λ����λ��1��31��
//	int n = 0;
//	printf("���������֣�");
//	scanf("%d", &n);
//	int i = 0;
//	printf("����λΪ��");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", (n >> i)&1);
//	}
//	printf("\n");
//	printf("ż��λΪ��");
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d ", (n >> i)&1);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//���һ��������ÿһλ��

//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <stdlib.h>
//void sss(a)
//{
//	if (a <= 9)
//	{
//		printf("%d ", a);
//	}
//	else
//	{
//		sss(a / 10);
//		printf("%d ", a%10);
//	}
//}
//int main()
//{
//	int a = 0;
//	printf("������һ����\n");
//	scanf("%d", &a);
//	sss(a);
//	system("pause");
//	return 0;
//}

//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <stdlib.h>
//
//int print(int n)
//{
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d ", n % 10);
//}
//int main()
//{
//	int n = 1234;
//	print(n);
//	system("pause");
//	return 0;
//}

//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ

int count(int a, int b)
{
	int m = a ^ b; // ��������λ��򣬶�Ӧ��ͬ��λ������1 
	int num = 0;
	while (m>0)
	{
		m =m & (m - 1);//��λ�뷽������һ�������б���λΪ1�ĸ���
		num++;
	}
	return num;
}
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int m = 0;
	int n = 0;
	int ret = 0;
	printf("������������\n");
	scanf("%d %d", &m, &n);
	ret = count(m,n);
	printf("��%d������λ��ͬ\n",ret);
	system("pause");
	return 0;
}

//д�����ܽ�C���Բ��������������ӷ����ң�������Ⱥ�