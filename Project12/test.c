//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ��� ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832


//#include <stdio.h>
//#include <stdlib.h>
//
////����1
//unsigned int reverse_bit(unsigned int n)
//{
//	int i = 0;
//	unsigned int num = 0;
//	for (i = 0; i < 32; i++)
//	{
//		num += ((n >> i) & 1) << (32 - 1 - i);
//		//�����ƶ�iλ��λ��1�����õ���iλ
//		//��iλ�����ƶ�32-1-iλ����������ת֮���λ��		
//	}
//	return num;
//}
////����2
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
////����3
//unsigned int reverse_bit(unsigned int n)
//{
//	int i = 0;
//	unsigned int num = 0;
//	for (i = 0; i < 32; i++)
//	{
//		num <<=1;//�ȼ�num=num<<1
//		num |= ((n >> i) & 1);//�ȼ�num=num|((n >> i) & 1)
//	}
//	return num;
//}
//int main()
//{
//	int num = 25;
//	unsigned int ret = reverse_bit(num);
//	printf("��ת֮���ֵ ret = %u\n",ret);
//	//ע�⣺��Ҫ��%u����ӡ����Ϊ1�п����������λ��
//	system("pause");
//	return 0;
//}



//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int a = 10;
//	int b = -20;
//	int average = a + ((b - a) >> 1);
//	printf("%d\n", average);
//	average = (a&b) + ((a^b) >> 1);
//	//(a&b)a��b����ͬ�Ķ�����λ�͵�һ��
//	//(a^b)a��b�в�ͬ�Ķ�����λ������2
//	printf("%d\n", average);
//	system("pause");
//	return 0;
//}



//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩


//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 1, 2, 3 };
//	int ret = 0;//ret�����ʼ��Ϊ0�����������Ľ������Ӱ��
//	//��Ϊֻ��0��a���Ľ��Ϊa
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

//�����汾��һ��������ֻ���������ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ����������֡�

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

//�����汾��һ��������ֻ���������ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ������������е�����һ����


//4.
//��һ���ַ����������Ϊ:"student a am i", ���㽫��������ݸ�Ϊ"i am a student".
//			Ҫ��
//			����ʹ�ÿ⺯����ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

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
	//��������
	int len = strlen(arr);
	swap(arr, arr + len - 1);
	//ÿ�����ʵ�����
	while (*arr != '\0')//��arr������\0˵����û�е����һ������
	{
		char *start = arr;//���ʵ���ʼλ��
		char *end = start;//���ʵĽ���λ��
		while ((*end != ' ') && (*end != '\0'))
	  //���ӷ�����Ϊ&&�����дΪ ||����end���ڿո�ʱ��һ������Ϊ�٣���ʱ�߼�����Ҫ�������㣬���ո񲻵���\0Ϊ�棬���Ա��ʽΪ�棬���Ի�ִ��end++����ʱ�������ո���Ϊ&&���ӷ�����һ��Ϊ�٣����Ϊ�٣���end���ڿո�ʱ��һ������Ϊ�٣������������ʽ���Ϊ�٣����Ի�ֹͣѭ����end��ָ��ո�λ�õĵ�ַ��
		{
			end++;//endָ��ո�λ�õĵ�ַ
		}
		swap(start, end - 1);
		//���ʵ���ʼλ��Ϊstart������λ��Ϊ�ո�ǰһ���ַ���end-1��
		if (*end != '\0')
			arr = end + 1;
		//������һ�����ʵ����ú���һ�����ʵĿ�ʼΪ�ո��һ���ַ���end+1��
		else
			arr = end;

	}
}
int main()
{
	char arr[] = "student a am i";
	reverse(arr);//����������̵�����,ֻ������������ȥ�����ô�����Ĵ�С
	printf("%s\n", arr);
	system("pause");
	return 0;
}

