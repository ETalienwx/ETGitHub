#include "Stack.h"

void StackInit(Stack* ps, int n)//��ʼ��ջ
{
	assert(ps);
	ps->_a =(STDateType*) malloc(sizeof(STDateType)*n);
	ps->_capacity = n;
	ps->_top = 0;
}
void StackPush(Stack* ps, STDateType x)//������
{
	assert(ps);
	if (ps->_capacity = ps->_top)
	{
		ps->_a = realloc(ps->_a, ps->_capacity * 2 * sizeof(STDateType));
		ps->_capacity = ps->_capacity * 2;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)//������
{
	assert(ps);
	if (ps->_top > 0)
	{
		ps->_top--;
	}
}
STDateType* StackTop(Stack* ps)//ȡջ��������
{
	assert(ps);
	return ps->_a[ps->_top-1];
}

int StackSize(Stack* ps)//����ջ�����ݸ���
{
	assert(ps);
	return ps->_top;
}
int StackEmpty(Stack* ps)//�ж��Ƿ�Ϊ��
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}

void TestStack()
{
	Stack sl;
	StackInit(&sl,3);
	StackPush(&sl, 1);
	StackPush(&sl, 2);
	StackPush(&sl, 3);
	StackPush(&sl, 4);
	StackPush(&sl, 5);

	while (StackEmpty(&sl))
	{
		printf("|   %d   |\n", StackTop(&sl));
		printf("-----------\n");
		StackPop(&sl);
	}
}
