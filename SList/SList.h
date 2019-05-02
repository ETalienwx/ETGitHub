#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int SLTDateType;//数据类型命名重定义

typedef struct SListNode//定义一个表示链表各个节点的结构体
{
	SLTDateType _date;//节点里的数据
	struct SListNode* _next;//节点里指向下一个节点的指针
}SListNode;

typedef struct SList//定义一个链表结构体，包含指向头节点和尾节点的指针
{
	struct SListNode* _head;//头节点
	struct SListNode* _tail;//尾节点
}SList;

void SListInit(SList* plist);//初始化该单链表
void SListDestory(SList* plist);//销毁该单链表

void SListPushBack(SList* plist,SLTDateType x);//单链表的尾插
void SListPopBack(SList* plist);//单链表的尾删
void SListPushFront(SList* plist,SLTDateType x);//单链表的头插
void SListPopFront(SList* plist);//单链表的头删

SListNode* SListFind(SList* plist, SLTDateType x);//查找x，返回指向该节点的指针，类型为SListNode*
//在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDateType x);//在pos位置的后面插入x
void SListEraseAfter(SListNode* pos);//删除pos位置后面的数据
void SListRemove(SList* plist, SLTDateType x);//删除x
void SListPrint(SList* plist);//打印单链表

void TestSList();//测试函数

