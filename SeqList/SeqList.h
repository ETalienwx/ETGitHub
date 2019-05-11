#pragma once

////静态顺序表
//#define N 10
//typedef int SLDateType;
//typedef struct SeqList
//{
//	int _a[N];//数组
//	size_t _size;//有多少个有效数据
//}SeqList;
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

//动态顺序表
#define N 10
typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* _a;   //数组
	size_t _size;     //有多少个有效数据
	size_t _capacity;  //容量
}SeqList;

void CheckCapacity(SeqList* psl);
void SeqListInit(SeqList* psl, size_t capacity);//初始化
void SeqListDestory(SeqList* psl);//销毁

void SeqListPushBack(SeqList* psl, SLDateType x);//尾插
void SeqListPopBack(SeqList* psl);//尾删
void SeqListPushFront(SeqList* psl, SLDateType x);//头插
void SeqListPopFront(SeqList* psl);//头删

void SeqListInsert(SeqList* psl, size_t pos, SLDateType x);//任意位置的插入,在pos位置上的插入
void SeqListErase(SeqList* psl, size_t pos);//删除pos这个位置的数据
void SeqListRemove(SeqList* psl, SLDateType x);//删除x这个数据
int SeqListFind(SeqList* psl, SLDateType x);//查找一个数据
void SeqListModify(SeqList* psl, size_t pos, SLDateType x);//修改pos位置的值，修改为x

void SeqListPrint(SeqList* psl);//打印该顺序表

void SeqListBubbleSort(SeqList* psl);//冒泡排序
void SeqListSelectSort(SeqList* psl);//选择排序
int SeqListBinarySearch(SeqList* psl,SLDateType x); //二分查找
void SeqListRemoveAll(SeqList* psl,SLDateType x);//删除所有的x

void TestSeqList();
