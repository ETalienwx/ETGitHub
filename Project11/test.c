#define _CRT_SECURE_NO_DEPRECATE


//��ϤԤ�����ʶ��
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int a = 0;
//	int b = 12;
//	//__LINE__��ӡ�ļ���ǰ���к�
//	//__DATE__��ӡ�ļ������������
//	//__TIME__��ӡ�ļ��������ʱ��
//	printf("%d %s %s", __LINE__, __DATE__, __TIME__);
//	system("pause");
//	return 0;
//}
//#���԰Ѻ������ɶ�Ӧ���ַ���

//##���ڰ������ߵķ��źϳ�һ������


//4.�˽��ͺ���������
//https://blog.csdn.net/etalien_/article/details/81145907
//5.дһ������Խ�һ�����ֵ�����λ��ż��λ������

#include <stdio.h>
#include <stdlib.h>
#define SWAP(X) ((((X)&0x55555555)<<1)+(((X)&0xaaaaaaaa)>>1))
              //��ȡ����λ�����ƶ�1λ   //��ȡż��λ�����ƶ�1λ
int main()
{
	int n = 11;
	int ret = SWAP(n);
	printf("ret = %d\n", ret);
	system("pause");
	return 0;
}


//6.ʹ�ú�ʵ������������ϴ�ֵ��
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX(a,b) ((a)>(b))?(a):(b)
//int main()
//{
//	int a = 10;
//	int b = 20;
//	printf("%d\n",MAX(a, b));
//	system("pause");
//	return 0;
//}