//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回 值value的二进制位模式从左到右翻转后的值。
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832


//#include <stdio.h>
//#include <stdlib.h>
//
////方法1
//unsigned int reverse_bit(unsigned int n)
//{
//	int i = 0;
//	unsigned int num = 0;
//	for (i = 0; i < 32; i++)
//	{
//		num += ((n >> i) & 1) << (32 - 1 - i);
//		//向右移动i位按位与1即可拿到第i位
//		//第i位向左移动32-1-i位即可来到翻转之后的位置		
//	}
//	return num;
//}
////方法2
//#include <math.h>
//unsigned int reverse_bit(unsigned int n)
//{
//	int i = 0;
//	unsigned int num = 0;
//	for (i = 0; i < 32; i++)
//	{
//		num += ((n >> i) & 1) * pow(2,31-i);	
//	}
//	return num;
//}
////方法3
//unsigned int reverse_bit(unsigned int n)
//{
//	int i = 0;
//	unsigned int num = 0;
//	for (i = 0; i < 32; i++)
//	{
//		num <<=1;//等价num=num<<1
//		num |= ((n >> i) & 1);//等价num=num|((n >> i) & 1)
//	}
//	return num;
//}
//int main()
//{
//	int num = 25;
//	unsigned int ret = reverse_bit(num);
//	printf("翻转之后的值 ret = %u\n",ret);
//	//注意：需要用%u来打印，因为1有可能来到最高位上
//	system("pause");
//	return 0;
//}



//2.不使用（a + b） / 2这种方式，求两个数的平均值。

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int a = 10;
//	int b = -20;
//	int average = a + ((b - a) >> 1);
//	printf("%d\n", average);
//	average = (a&b) + ((a^b) >> 1);
//	//(a&b)a，b中相同的二进制位和的一半
//	//(a^b)a，b中不同的二进制位保留除2
//	printf("%d\n", average);
//	system("pause");
//	return 0;
//}



//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）


//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 1, 2, 3 };
//	int ret = 0;//ret必须初始化为0，否则会对异或的结果产生影响
//	//因为只有0和a异或的结果为a
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//升级版本：一组数据中只有两个数字出现了一次。其他所有数字都是成对出现的。
//请找出这两个数字。

//#include <stdio.h>
//#include <stdlib.h>
//int yihuo(int arr[], int sz)
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < sz; i++)
//	{
//		sum = sum^arr[i];
//	}
//	return sum;
//}
//int find_one(int sum)
//{
//	int i = 0;
//	int count = 0;
//	for (i = 0; i < 31; i++)
//	{
//		if (((sum >> i) & 1) == 1)
//			return i;
//	}
//	
//}
//void fenzuyuhuo(int arr[], int ret, int sz)
//{
//	int a = 0;
//	int b = 0;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> ret) & 1) == 0)
//		{
//			a ^= arr[i];
//		}
//		if (((arr[i] >> ret) & 1) != 0)
//		{
//			b ^= arr[i];
//		}
//	}
//	printf("a = %d, b = %d\n", a, b);
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 1, 2, 3, 6};
//
//	int a = 0;
//	int b = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int sum = yihuo(arr, sz);
//	int ret = find_one(sum);
//	fenzuyuhuo(arr, ret, sz);
//	printf("%d", ret);
//	system("pause");
//	return 0;
//}

//升级版本：一组数据中只有三个数字出现了一次。其他所有数字都是成对出现的。
//请找出这三个数字中的任意一个。


//4.
//有一个字符数组的内容为:"student a am i", 请你将数组的内容改为"i am a student".
//			要求：
//			不能使用库函数。只能开辟有限个空间（空间个数和字符串的长度无关）。

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
void swap(char *left, char *right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left<right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void reverse(char *arr)
{
	//整体逆置
	int len = strlen(arr);
	swap(arr, arr + len - 1);
	//每个单词的逆置
	while (*arr != '\0')//若arr不等于\0说明还没有到最后一个单词
	{
		char *start = arr;//单词的起始位置
		char *end = start;//单词的结束位置
		while ((*end != ' ') && (*end != '\0'))
	  //连接符必须为&&，如果写为 ||，当end等于空格时第一个条件为假，此时逻辑或需要继续运算，而空格不等于\0为真，所以表达式为真，所以会执行end++，此时会跳过空格。若为&&连接符，有一个为假，结果为假，当end等于空格时第一个条件为假，所以整个表达式结果为假，所以会停止循环，end则指向空格位置的地址。
		{
			end++;//end指向空格位置的地址
		}
		swap(start, end - 1);
		//单词的起始位置为start，结束位置为空格前一个字符（end-1）
		if (*end != '\0')
			arr = end + 1;
		//当结束一个单词的逆置后，下一个单词的开始为空格后一个字符（end+1）
		else
			arr = end;

	}
}
int main()
{
	char arr[] = "student a am i";
	reverse(arr);//完成整个过程的逆序,只传递这个数组过去，不用传数组的大小
	printf("%s\n", arr);
	system("pause");
	return 0;
}

