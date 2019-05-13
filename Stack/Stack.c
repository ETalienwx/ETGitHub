#include "Stack.h"

void StackInit(Stack* ps, int n)//初始化栈
{
	assert(ps);
	ps->_a =(STDateType*) malloc(sizeof(STDateType)*n);
	ps->_capacity = n;
	ps->_top = 0;
}
void StackPush(Stack* ps, STDateType x)//入数据
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
void StackPop(Stack* ps)//出数据
{
	assert(ps);
	if (ps->_top > 0)
	{
		ps->_top--;
	}
}
STDateType* StackTop(Stack* ps)//取栈顶的数据
{
	assert(ps);
	return ps->_a[ps->_top-1];
}

int StackSize(Stack* ps)//返回栈中数据个数
{
	assert(ps);
	return ps->_top;
}
int StackEmpty(Stack* ps)//判断是否为空
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
