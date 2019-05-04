#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDateType;

typedef struct ListNode
{
	LTDateType _date;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

//双向带头循环链表
typedef struct List
{
	ListNode* _head;
}List;

void ListInit(List* plist);
void ListDestory(List* plist);

ListNode* BuyListNode(LTDateType x);
void ListPushBack(List* plist, LTDateType x);
void ListPopBack(List* plist);
void ListPushFront(List* plist, LTDateType x);
void ListPopFront(List* plist);

void ListInsert(ListNode* pos, LTDateType x);//在pos前面插入
void ListErase(ListNode* pos);
ListNode* ListFind(List* plist,LTDateType x);

void ListPrint(List* plist);
void TestList();

