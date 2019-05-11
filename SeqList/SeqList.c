#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->_capacity == psl->_size)
	{
		if (psl->_capacity == 0)
		{
			psl->_capacity = 2;
		}
		SLDateType* tmp = realloc(psl->_a, psl->_capacity * 2 * sizeof(SLDateType));//增二倍
		assert(tmp);
		psl->_a = tmp;
		psl->_capacity *= 2;
	}
}

void SeqListPrint(SeqList* psl)
{
	assert(psl);
	size_t i = 0;
	for (i = 0; i < (psl->_size); i++)
	{
		printf("%d ", psl->_a[i]);
	}
	printf("\n");
}

void SeqListInit(SeqList* psl, size_t capacity)//初始化
{
	assert(psl);
	if (capacity == 0)
	{
		psl->_capacity = 0;
		psl->_size = 0;
		psl->_a = NULL;
	}
	else
	{
		psl->_a = (SLDateType*)malloc(sizeof(SLDateType)*capacity);
		assert(psl->_a);
		psl->_capacity = capacity;
		psl->_size = 0;
	}
}

void SeqListDestory(SeqList* psl)//销毁
{
	assert(psl);
	free(psl->_a);
	psl->_a = NULL;
	psl->_capacity = 0;
	psl->_size = 0;
}

void SeqListPushBack(SeqList* psl, SLDateType x)//尾插
{
	assert(psl);

	CheckCapacity(psl);

	psl->_a[psl->_size] = x;
	psl->_size++;
	
	//SeqListInsert(psl, psl->_size, x);
}

void SeqListPopBack(SeqList* psl)//尾删
{
	assert(psl);
	if (psl->_size > 0)
	{
		psl->_size--;
	}

	//SeqListErase(psl, psl->_size);
}

void SeqListPushFront(SeqList* psl, SLDateType x)//头插
{
	assert(psl);

	CheckCapacity(psl);

	int end = psl->_size;
	while (end >= 0)
	{
		psl->_a[end + 1] = psl->_a[end];
		end--;
	}
	psl->_a[0] = x;
	psl->_size++;

	//SeqListInsert(psl, 0, x);
}

void SeqListPopFront(SeqList* psl)//头删
{
	assert(psl);
	if ((psl->_size) > 0)
	{
		int start = 0;
		while (start < (int)(psl->_size-1))
		{
			psl->_a[start] = psl->_a[start + 1];
			start++;
		}
		psl->_size--;
	}

	//SeqListErase(psl, 0);
}

void SeqListInsert(SeqList* psl, size_t pos, SLDateType x)//任意位置的插入,在pos位置上的插入
{
	assert(psl && pos <= (psl->_size));//pos=size可以理解为尾插
	int end = psl->_size - 1;

	CheckCapacity(psl);

	while (end >= (int)pos)
	{
		psl->_a[end + 1] = psl->_a[end];
		end--;
	}
	psl->_a[pos] = x;
	psl->_size++;
}

void SeqListErase(SeqList* psl, size_t pos)//删除pos这个位置的数据
{
	assert(psl && pos <= (psl->_size));
	int start = pos;
	while (start < (int)(psl->_size - 1))
	{
		psl->_a[start] = psl->_a[start + 1];
		start++;
	}
	psl->_size--;
}

int SeqListFind(SeqList* psl, SLDateType x)//查找一个数据
{
	assert(psl);
	size_t i = 0;
	for (i = 0; i < (psl->_size); i++)
	{
		if (psl->_a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListRemove(SeqList* psl, SLDateType x)//删除x这个数据
{
	assert(psl);
	int pos = SeqListFind(psl, x);
	if (pos != -1)
	{
		SeqListErase(psl, pos);
	}
}

void SeqListModify(SeqList* psl, size_t pos, SLDateType x)//修改pos位置的值，修改为x
{
	assert(psl && pos<(psl->_size));
	psl->_a[pos] = x;
}

void SeqListBubbleSort(SeqList* psl)//冒泡排序
{
	assert(psl);
	size_t i = 0;
	size_t j = 0;
	int flag = 0;
	for (i = 0; i < psl->_size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < psl->_size - 1 - i; j++)
		{
			if (psl->_a[j] > psl->_a[j + 1])
			{
				SLDateType tmp = psl->_a[j];
				psl->_a[j] = psl->_a[j + 1];
				psl->_a[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag = 0)
		{
			break;
		}
	}
}

void Swap(SLDateType* x, SLDateType* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void SeqListSelectSort(SeqList* psl)//选择排序
{
	assert(psl);
	int begin = 0;
	int end = psl->_size - 1;
	while (begin < end)
	{
		int min = begin;
		int max = begin;
		for (int i = begin; i < end; i++)
		{
			if (psl->_a[i] < psl->_a[min])
			{
				min = i;
			}
			if (psl->_a[i] > psl->_a[max])
			{
				max = i;
			}
		}

		Swap(&psl->_a[begin], &psl->_a[min]);
		if (begin == max)
		{
			max = min;
		}
		Swap(&psl->_a[end], &psl->_a[max]);

		begin++;
		end--;
	}
}

int SeqListBinarySearch(SeqList* psl,SLDateType x) //二分查找
{
	assert(psl);
	size_t left = 0;
	size_t right = psl->_size - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (psl->_a[mid] == x)
		{
			return mid;
		}
		if (psl->_a[mid] > x)
		{
			right = mid - 1;
		}
		if (psl->_a[mid] < x)
		{
			left = mid + 1;
		}
	}
	return -1;
}

void SeqListRemoveAll(SeqList* psl, SLDateType x)//删除所有的x
{
	assert(psl);
	size_t i = 0;
	while (i < psl->_size-1)
	{
		int cur = SeqListFind(psl, x);
		if (cur != -1)
		{
			SeqListRemove(psl, x);
		}
		i++;
	}

}

void TestSeqList()
{
	SeqList sl;
	SeqListInit(&sl, 5);
	SeqListPushBack(&sl, 1);//尾插1
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 7);
	SeqListPopBack(&sl);//尾删
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 50);//头插50
	SeqListPushFront(&sl, 50);
	SeqListPopFront(&sl);//头删
	SeqListPrint(&sl);

	SeqListInsert(&sl, 4, 100);//在下标为4的数据前添加数据100
	SeqListPrint(&sl);

	SeqListErase(&sl, 6);//删除下标为6的数据
	SeqListPrint(&sl);

	SeqListRemove(&sl, 2);//删除2
	SeqListPrint(&sl);

	SeqListModify(&sl, 3, 2);
	SeqListPrint(&sl);

	//SeqListBubbleSort(&sl);//冒泡排序
	SeqListSelectSort(&sl);//选择排序
	SeqListPrint(&sl);

	int sub = SeqListBinarySearch(&sl, 2);//二分查找数据2
	if (sub != -1)
	{
		printf("找到了，下标为：%d\n", sub);
	}

	SeqListRemoveAll(&sl, 3);//删除所有3
	SeqListPrint(&sl);

	SeqListDestory(&sl);//销毁该顺序表
}