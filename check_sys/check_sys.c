//大小端字节序的介绍以及判断
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
//		printf("小端");
//	else
//		printf("大端");
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
		printf("小端\n");
	else
		printf("大端\n");
	system("pause");
	return 0;
}