#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int STDateType;

typedef struct Stack
{
	STDateType* _a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps,int n);
void StackPush(Stack* ps, STDateType x);//入数据
void StackPop(Stack* ps);//出数据
STDateType* StackTop(Stack* ps);//取栈顶的数据
int StackSize(Stack* ps);//返回栈中数据个数
//0为空，1为非空
int StackEmpty(Stack* ps);//判断是否为空
void TestStack();
