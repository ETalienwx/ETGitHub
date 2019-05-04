#include "List.h"

void ListInit(List* plist)//��ʼ��
{
	assert(plist);
	plist->_head = BuyListNode(0);
	plist->_head->_next = plist->_head;
	plist->_head->_prev = plist->_head;
}

void ListDestory(List* plist)//����
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(plist->_head);
	plist->_head = NULL;
}

ListNode* BuyListNode(LTDateType x)//����һ���ڵ�
{
	ListNode* newnode = malloc(sizeof(ListNode));
	assert(newnode);
	newnode->_date = x;
	newnode->_next = NULL;
	newnode->_prev = NULL;
	return newnode;
}

void ListPushBack(List* plist, LTDateType x)//β��
{
	assert(plist);
	//ListNode* head = plist->_head;
	//ListNode* tail = plist->_head->_prev;
	//ListNode* newnode = BuyListNode(x);
	//tail->_next = newnode;
	//newnode->_prev = tail;
	//newnode->_next = head;
	//head->_prev = newnode; 

	//Ҳ����д�����´���
	//(��Ϊ��ѭ���ṹ������ͷ��ǰ�����β)
	ListInsert(plist->_head, x);
}

void ListPopBack(List* plist)//βɾ
{
	assert(plist);
	//ListNode* head = plist->_head;
	//ListNode* tail = head->_prev;
	//ListNode* prev = tail->_prev;
	//head->_prev = prev;
	//prev->_next = head;
	//free(tail);
	//tail = NULL;

	//Ҳ����д�����´���
	ListErase(plist->_head->_prev);
}

void ListPushFront(List* plist, LTDateType x)//ͷ��
{
	assert(plist);
	//ListNode* newnode = BuyListNode(x);
	//ListNode* head = plist->_head;
	//ListNode* next = head->_next;
	//head->_next = newnode;
	//newnode->_prev = head;
	//newnode->_next = next;
	//next->_prev = newnode;

	//Ҳ����д�����´���
	ListInsert(plist->_head->_next, x);
}

void ListPopFront(List* plist)//ͷɾ
{
	assert(plist);
	//ListNode* head = plist->_head;
	//ListNode* next = head->_next;
	//ListNode* nextnext = next->_next;

	//if (head == next)
	//	return;
	//head->_next = nextnext;
	//nextnext->_prev = head;
	//free(next);
	//next = NULL;

	//Ҳ����д�����´���
	ListErase(plist->_head->_next);
}

void ListPrint(List* plist)//��ӡ
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		printf("<- %d -> ", cur->_date);
		cur = cur->_next;
	}
	printf("\n");
}

void ListInsert(ListNode* pos, LTDateType x)//posλ��ǰ�����
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}

void ListErase(ListNode* pos)//ɾ��pos����ڵ�
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}

ListNode* ListFind(List* plist, LTDateType x)//����һ���ڵ�
{
	assert(plist);
	ListNode* cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		if (cur->_date == x)
		{
			return cur;
		}
		else
		{
			cur = cur->_next;
		}
	}
	return NULL;
}

void TestList()//���Ժ���
{
	List lt;
	ListInit(&lt);

	ListPushBack(&lt, 1);
	ListPushBack(&lt, 2);
	ListPushBack(&lt, 3);
	ListPushBack(&lt, 4);
	ListPrint(&lt);

	ListPopBack(&lt);
	ListPopBack(&lt);
	ListPrint(&lt);

	ListPushFront(&lt, 30);
	ListPushFront(&lt, 40);
	ListPrint(&lt);

	ListPopFront(&lt);
	ListPopFront(&lt);
	ListPrint(&lt);

	ListNode* pos = ListFind(&lt,2);
	ListInsert(pos, 100);
	ListPrint(&lt);

	ListErase(pos);
	ListPrint(&lt);

	ListDestory(&lt);
}