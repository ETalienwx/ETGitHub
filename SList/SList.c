#include "SList.h"

void SListInit(SList* plist)//��ʼ���õ�����
{
	assert(plist);
	plist->_head = plist->_tail = NULL;
}

void SListDestory(SList* plist)//���ٸõ�����
{
	assert(plist);
	SListNode* cur = plist->_head;
	while (cur != NULL)
	{
		//��next��¼��һ���ڵ��λ��
		//����free��cur֮����Ҳ���cur����һ���ڵ���
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	//��Ҫ��ͷ�ڵ��β�ڵ�����ָ���ÿ�
	plist->_head = plist->_tail = NULL;
}

SListNode* BuyListNode(SLTDateType x)//����һ���½ڵ�
{
	SListNode* node = malloc(sizeof(SListNode));
	assert(node);//����Ƿ񿪱ٳɹ�
	node->_date = x;
	node->_next = NULL;
	return node;
}

void SListPushBack(SList* plist, SLTDateType x)//�������β��
{
	assert(plist);
	//1.һ���ڵ㶼û��
	if (plist->_tail == NULL)
	{
		plist->_head = plist->_tail = BuyListNode(x);
	}
	//2.һ�����Ͻڵ�
	else
	{
		SListNode* newnode = BuyListNode(x);//����һ���½ڵ�
		plist->_tail->_next = newnode;//��tail��nextָ���½ڵ�
		plist->_tail = newnode;//��tailҲָ�����һ���½ڵ�
	}
}

void SListPopBack(SList* plist)//�������βɾ
{
	assert(plist);
	SListNode* prev = plist->_head;
	//һ���ڵ�
	if (prev->_next == NULL)
	{
		free(prev);
		plist->_head = plist->_tail = NULL;
	}
	//����ڵ�
	else
	{
		while (prev->_next != plist->_tail)//Ѱ��β�ڵ��ǰһ��
		{
			prev = prev->_next;
		}
		free(plist->_tail);
		prev->_next = NULL;
		plist->_tail = prev;
	}
}

void SListPushFront(SList* plist, SLTDateType x)//�������ͷ��
{
	assert(plist);
	SListNode* newnode = BuyListNode(x);
	newnode->_next = plist->_head;
	plist->_head = newnode;
}

void SListPopFront(SList* plist)//�������ͷɾ
{
	assert(plist);
	SListNode* next = plist->_head->_next;
	free(plist->_head);
	plist->_head = next;
}

SListNode* SListFind(SList* plist, SLTDateType x)//����x������ָ��ýڵ��ָ�룬����ΪSListNode*
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

void SListInsertAfter(SListNode* pos, SLTDateType x)//��posλ�õĺ������x
{
	assert(pos);
	SListNode* next = pos->_next;
	SListNode* newnode = BuyListNode(x);
	pos->_next = newnode;
	newnode->_next = next;
}

//����һ��λ�ã���ɾ�����λ�ú����ֵ
void SListEraseAfter(SListNode* pos)//ɾ��posλ�ú��������
{
	assert(pos);
	SListNode* next;
	//pos����û��ֵ
	if (pos->_next == NULL)
		return;
	//pos������ֵ
	next = pos->_next->_next;
	free(pos->_next);
	pos->_next = NULL;
	pos->_next = next;
}
//����һ��x��ɾ�����x
void SListRemove(SList* plist, SLTDateType x)//ɾ��x
{
	assert(plist);
	//Ҫɾ����x�����ǵ�һ��
	//���Ը���ͷɾ
	if (plist->_head->_date == x)
	{
		SListPopFront(plist);
		return;
	}
	//Ҫɾ���Ĳ��ǵ�һ��
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

void SListPrint(SList* plist)//��ӡ������
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

void TestSList()//���Ժ���
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


