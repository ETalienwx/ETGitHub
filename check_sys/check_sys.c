//��С���ֽ���Ľ����Լ��ж�
//#include <stdio.h>
//#include <stdlib.h>
//int check_sys()
//{
//	int i = 1;
//	union
//	{
//		int i;
//		char c;
//	}un;
//	un.i = 1;
//	return un.c;
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//		printf("С��");
//	else
//		printf("���");
//	system("pause");
//	return 0;
//}


#include <stdio.h>
#include <stdlib.h>
int check_sys()
{
	int i = 1;
	return (*(char *)&i);
}
int main()
{
	int ret = check_sys();
	if (ret == 1)
		printf("С��\n");
	else
		printf("���\n");
	system("pause");
	return 0;
}