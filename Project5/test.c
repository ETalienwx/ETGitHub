////����n�Ľ׳�
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int i = 0;
//	int ret = 1;
//	for (i = 1; i <= 5; i++)
//	{
//		ret = ret*i;
//	}
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}


////����1��+2��+31+....+n��

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int num = 0;
//	int ret = 1;
//	for (n = 1; n <= 3; n++)
//	{
//		ret = ret*n;
//		num = num + ret;
//	}
//	printf("%d\n", num);
//	system("pause");
//	return 0;
//}


//��ɲ�������Ϸ

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void menu()
//{
//	printf("***************************\n");
//	printf("*********  1.play  ********\n");
//	printf("*********  0.exit  ********\n");
//	printf("***************************\n");
//
//}
//void game()
//{
//	//�������һ������
//	int ret = 0;
//	int n = 0;
//	ret = rand()%101;
//	//������
//	while (1)
//	{
//		printf("������֣�\n");
//		scanf_s("%d",&n);
//		if (n == ret)
//		{
//			printf("��ϲ��¶���\n");
//			break;
//		}
//		else if (n < ret)
//		{
//			printf("��С�ˣ�\n");
//		}
//		else
//		{
//			printf("�´��ˣ�\n");
//
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	//srand:��������������
//	//time������Ϊlong����������ǿתΪint�ͣ�unsigned int��������Ϊָ�루��ȷ�����Ƕ�ΪNULL��
//	//srand����������������ֻ����һ��
//	do{
//		menu();
//		printf("��ѡ��\n");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case 1:
//			printf("����Ϸ\n");
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}

//��д����ģ��������������ĳ���������������������룬������ȷ����ʾ����¼�ɹ���, ������󣬿����������룬����������Ρ����ξ�������ʾ�˳�����

//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//int main()
//{
//	//"123456"
//	char arr[10] = {0};
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("����������\n");
//		scanf("%s", arr);
//		if (strcmp(arr,"123456") == 0)
//		{
//			printf("��½�ɹ�\n");
//			break;
//		}
//		else
//		{
//			printf("�����������������\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("������������˳�����\n");
//	}
//	system("pause");
//	return 0;
//}


//��дһ�����򣬿���һֱ���ռ����ַ��������Сд�ַ��������Ӧ�Ĵ�д�ַ���������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ�����������ֲ������
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			putchar(ch - 32);
		}
		else if (ch >= 'A'&& ch <= 'Z')
		{
			putchar(ch + 32);
		}
		else if (ch >= '0'&& ch <= '9')
		{
			;
		}
		else
		{
			putchar(ch);
		}
	}
	system("pause");
	return 0;
}