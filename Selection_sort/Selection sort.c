#include <stdio.h>
#include <stdlib.h>
void Swap(int* p1, int* p2)//值交换函数
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void print(int* array, int size)//打印函数
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
void SelectSort(int* a, int size)//选择排序
{
	int begin = 0, end = size - 1;
	int min = 0, max = 0;
	while (begin < end)
	{
		min = max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}

		Swap(&a[begin], &a[min]);
		if (begin == max)
		{
			min = max;
		}
		Swap(&a[end], &a[max]);

		print(a, size);
		begin++;
		end--;
	}
}
int main()
{
	int arr[10] = { 21, 32, 5, 5, 76, 34, 89, 12, 65, 34 };
	SelectSort(arr, 10);
	system("pause");
	return 0;
}