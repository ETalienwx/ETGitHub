//1.ʹ��main�����Ĳ�����ʵ��һ��������������������Խ���������������һ�������� - a��ѡ��ִ�мӷ����� - s��ѡ��ִ�м������� - m��ѡ��ִ�г˷����� - d��ѡ��ִ�г�����������������Ϊ��������
//���磺�����в������룺test.exe - a 1 2
//ִ��1 + 2���3
//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main(int argc,char* argv[],char* envp[])
//{
//	int ret = 0;
//	if (argc != 4)
//	{
//		printf("��������argc=%d\n", argc);
//		return 0;
//	}
//	switch (*(argv[1] + 1))
//	{
//	case 'a':
//		ret = Add(atoi(argv[2]), atoi(argv[3]));
//		break;
//	case 's':
//		ret = Sub(atoi(argv[2]), atoi(argv[3]));
//		break;
//	case 'm':
//		ret = Mul(atoi(argv[2]), atoi(argv[3]));
//		break;
//	case 'd':
//		ret = Div(atoi(argv[2]), atoi(argv[3]));
//		break;
//	}
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}


//2.дð����������������ַ�����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bubble_str(char *arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (strcmp(arr[j], arr[j + 1])>0)
			{
				char* tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	char* arr[] = { "bbbb", "xxxx", "aaaa", "cccc" };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++)
	{
		printf("%s\n", arr[i]);
	}
	bubble_str(arr,sz);
	printf("\n");
	for (i = 0; i < sz; i++)
	{
		printf("%s\n", arr[i]);
	}
	system("pause");
	return 0;
}
