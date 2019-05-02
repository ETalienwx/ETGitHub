#include "SList.h"

void SListInit(SList* plist)//初始化该单链表
{
	assert(plist);
	plist->_head = plist->_tail = NULL;
}

void SListDestory(SList* plist)//销毁该单链表
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		//让next记录下一个节点的位置
		//否则free掉cur之后便找不到cur的下一个节点了
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	//需要把头节点和尾节点两个指针置空
	plist->_head = plist->_tail = NULL;
}

SListNode* BuyListNode(SLTDateType x)//开辟一个新节点
{
	SListNode* node = malloc(sizeof(SListNode));
	assert(node);//检测是否开辟成功
	node->_date = x;
	node->_next = NULL;
	return node;
}

void SListPushBack(SList* plist, SLTDateType x)//单链表的尾插
{
	assert(plist);
	//1.一个节点都没有
	if (plist->_tail == NULL)
	{
		plist->_head = plist->_tail = BuyListNode(x);
	}
	//2.一个以上节点
	else
	{
		SListNode* newnode = BuyListNode(x);//开辟一个新节点
		plist->_tail->_next = newnode;//让tail的next指向新节点
		plist->_tail = newnode;//让tail也指向最后一个新节点
	}
}

void SListPopBack(SList* plist)//单链表的尾删
{
	assert(plist);
	SListNode* prev = plist->_head;
	//一个节点
	if (prev->_next == NULL)
	{
		free(prev);
		plist->_head = plist->_tail = NULL;
	}
	//多个节点
	else
	{
		while (prev->_next != plist->_tail)//寻找尾节点的前一个
		{
			prev = prev->_next;
		}
		free(plist->_tail);
		prev->_next = NULL;
		plist->_tail = prev;
	}
}

void SListPushFront(SList* plist, SLTDateType x)//单链表的头插
{
	assert(plist);
	SListNode* newnode = BuyListNode(x);
	newnode->_next = plist->_head;
	plist->_head = newnode;
}

void SListPopFront(SList* plist)//单链表的头删
{
	assert(plist);
	SListNode* next = plist->_head->_next;
	free(plist->_head);
	plist->_head = next;
}

SListNode* SListFind(SList* plist, SLTDateType x)//查找x，返回指向该节点的指针，类型为SListNode*
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_date == x)
			return cur;
		else
			cur = cur->_next;
	}
	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDateType x)//在pos位置的后面插入x
{
	assert(pos);
	SListNode* next = pos->_next;
	SListNode* newnode = BuyListNode(x);
	pos->_next = newnode;
	newnode->_next = next;
}

//给我一个位置，我删除这个位置后面的值
void SListEraseAfter(SListNode* pos)//删除pos位置后面的数据
{
	assert(pos);
	SListNode* next;
	//pos后面没有值
	if (pos->_next == NULL)
		return;
	//pos后面有值
	next = pos->_next->_next;
	free(pos->_next);
	pos->_next = NULL;
	pos->_next = next;
}
//给我一个x，删除这个x
void SListRemove(SList* plist, SLTDateType x)//删除x
{
	assert(plist);
	//要删除的x正好是第一个
	//可以复用头删
	if (plist->_head->_date == x)
	{
		SListPopFront(plist);
		return;
	}
	//要删除的不是第一个
	SListNode* prev = plist->_head;
	SListNode* cur = plist->_head;
	while (cur)
	{
		if (cur->_date == x)
		{
			prev->_next = cur->_next;
			free(cur);
			cur = NULL;
			break;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}

void SListPrint(SList* plist)//打印单链表
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		printf("%d -> ", cur->_date);
		cur = cur->_next;
	}
	printf("NULL\n");
}

void TestSList()//测试函数
{
	SList sl;
	SListInit(&sl);

	SListPushBack(&sl, 1);
	SListPushBack(&sl, 2);
	SListPushBack(&sl, 3);
	SListPushBack(&sl, 4);
	SListPushBack(&sl, 5);
	SListPrint(&sl);
	SListPopBack(&sl);
	SListPrint(&sl);

	SListPushFront(&sl, 100);
	SListPushFront(&sl, 100);
	SListPrint(&sl);
	SListPopFront(&sl);
	SListPrint(&sl);

	SListNode* pos1 = SListFind(&sl,3);
	SListInsertAfter(pos1, 20);
	SListPrint(&sl);
	SListEraseAfter(pos1);
	SListPrint(&sl);

	SListNode* pos2 = SListFind(&sl, 4);
	SListInsertAfter(pos2, 5);
	SListPrint(&sl);
	SListEraseAfter(pos2);
	SListPrint(&sl);

	SListRemove(&sl, 4);
	SListPrint(&sl);

	SListDestory(&sl);
}


