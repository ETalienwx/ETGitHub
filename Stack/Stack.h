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
void StackPush(Stack* ps, STDateType x);//������
void StackPop(Stack* ps);//������
STDateType* StackTop(Stack* ps);//ȡջ��������
int StackSize(Stack* ps);//����ջ�����ݸ���
//0Ϊ�գ�1Ϊ�ǿ�
int StackEmpty(Stack* ps);//�ж��Ƿ�Ϊ��
void TestStack();
