//qsort参数
//void qsort(void *base,size_t num,size_t width,int(*cmp)(const void *e1,const void *e2))


//qsort的使用
//#include <stdio.h>
//#include <stdlib.h>
//struct Stu
//{
//	char name[20];
//	int age;
//};
//int cmp_int(const void *e1, const void *e2)
//{
//	return *(int *)e1 - *(int *)e2;
//}
//int cmp_stu_by_age(const void *e1, const void *e2)
//{
//	return ((struct Stu *)e1)->age - ((struct Stu *)e2)->age;
//}
//int cmp_stu_by_name(const void *e1, const void *e2)
//{
//	return strcmp(((struct Stu *)e1)->name , ((struct Stu *)e2)->name);
//}
//int main()
//{
//	//排序整形数组
//	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	//排序结构体
//	//struct Stu arr[] = { { "zhangsan", 20 }, { "lisi", 15 }, { "wangwu", 8 } };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	system("pause");
//	return 0;
//}

//模拟实现qsort（采用冒泡排序的方式）
#include <stdlib.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
struct Stu
{
	char name[20];
	int age;
};
int cmp_int(const void *e1, const void *e2)
{
	return *(int *)e1 - *(int *)e2;
}
int cmp_stu_by_age(const void *e1, const void *e2)
{
	return ((struct Stu *)e1)->age - ((struct Stu *)e2)->age;
}
int cmp_stu_by_name(const void *e1, const void *e2)
{
	return strcmp(((struct Stu *)e1)->name , ((struct Stu *)e2)->name);
}
void _swap(char* buf1, char* buf2, size_t width)
{
	unsigned int i = 0;
	assert(buf1 && buf2);
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void bubble_sort(void *base, int num, int width, int (*cmp)(const void *e1, const void *e2))
{
	assert(base && cmp);
	int i = 0;
	int j = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			//相邻元素的比较
			if (cmp((char*)base + j*width, (char*)base + (j + 1)*width)>0)
			{
				//交换
				_swap((char*)base + j*width, (char*)base + (j + 1)*width,width);
			}
		}
	}
}
int main()
{
	int i = 0;
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	//struct Stu arr[] = { { "zhangsan", 20 }, { "lisi", 15 }, { "wangwu", 8 } };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz , sizeof(arr[0]), cmp_stu_by_name);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}