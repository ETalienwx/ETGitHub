//�������ͼ��
//#include<stdio.h>
//int main()
//{
//	int line;
//	scanf_s("%d", &line);
//	int i;
//	for (i = 0; i < line - 1; i++)//��ӡline��
//	{
//		int j = 0;
//		for (j = 0; j < line - 1 - i;j++)//��ӡ�ո�
//		{
//			printf(" ");
//		}
//		for (j = 0;j < 2 * i + 1; j++)//��ӡ*
//		{
//			printf("*");
//		}
//			printf("\n");
//		}
//	for (i = 0; i < line-1; i++)
//	{
//		int j;
//		for (j = 0; j < i + 1;j++)
//		{
//			printf(" ");
//		}
//		for (j = 1; j <= 2 * (line-1-i) - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	getchar();
//	return 0;
//}

//���0��999֮������С�ˮ�ɻ����������
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0;i<= 999; i++)
//	{
//		//ȷ��i�Ǽ�λ��
//		int n = 1;
//		int sum = 0;
//		int tmp = i;
//		while (tmp / 10)
//		{
//			n++;
//			tmp = tmp / 10;
//		}
//		//����ÿһλ���
//		tmp = i;
//		while (tmp)
//		{
//			sum = sum + pow(tmp % 10, n);
//			tmp = tmp / 10;
//		}
//		//�ж�
//		if (sum==i)
//			printf("%d ", i);
//	}
//	getchar();
//	return 0;
//}

//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ������
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	int num = 0;
//	int count = 0;
//	int sum = 0;
//	int tmp = 0;
//	scanf("%d%d", &num, &count);
//	int i = 0;
//	for (i = 0; i < count; i++)
//	{
//		tmp = tmp * 10 + num;
//		sum += tmp;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}

//��дһ���������ӱ�׼�����ȡCԴ���룬����֤���еĻ����Ŷ���ȷ�ĳɶԳ��֡�
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int ch;
//	int count = 0;//����һ��������count
//	while ((ch = getchar()) != EOF)//ѭ�����룬EOF����
//	{
//		if (ch == '{')
//		{
//			count++;
//		}
//		//������{ʱ��������+1
//		if (ch == '}' && count == 0)
//		{
//			printf("��ƥ��\n");
//			return 0;
//		}
//		//������}��������Ϊ0�ˣ������ƥ�䣬��Ϊ}��{ǰ��
//		if (ch == '}' && count != 0)
//		{
//			count--;
//		}
//		//������}�Ҽ�������Ϊ0ʱ��������-1
//	}
//	if (count == 0)
//	{
//		printf("ƥ��!\n");
//	}
//	else
//	{
//		printf("��ƥ��!\n");
//	}//�жϼ�����count
//	system("pause");
//	return 0;
//}