#define _CRT_SECURE_NO_DEPRECATE


//熟悉预处理标识符
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int a = 0;
//	int b = 12;
//	//__LINE__打印文件当前的行号
//	//__DATE__打印文件被编译的日期
//	//__TIME__打印文件被编译的时间
//	printf("%d %s %s", __LINE__, __DATE__, __TIME__);
//	system("pause");
//	return 0;
//}
//#可以把宏参数变成对应的字符串

//##用于把它两边的符号合成一个符号


//4.了解宏和函数的区别。
//https://blog.csdn.net/etalien_/article/details/81145907
//5.写一个宏可以将一个数字的奇数位和偶数位交换。

#include <stdio.h>
#include <stdlib.h>
#define SWAP(X) ((((X)&0x55555555)<<1)+(((X)&0xaaaaaaaa)>>1))
              //提取奇数位向左移动1位   //提取偶数位向右移动1位
int main()
{
	int n = 11;
	int ret = SWAP(n);
	printf("ret = %d\n", ret);
	system("pause");
	return 0;
}


//6.使用宏实现两个数中求较大值。
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