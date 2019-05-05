#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

typedef int QUDateType;

typedef struct QueueNode
{
	QUDateType* _date;
	struct Queue* _next;
}QueueNode;

typedef struct Queue
{
	QueueNode* _front;
	QueueNode* _rear;
}Queue;

void QueueInit(Queue* q);
void QueueDestory(Queue* q);
void QueuePush(Queue* q, QUDateType x);
void QueuePop(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
QUDateType QueueFront(Queue* q);
QUDateType QueueBack(Queue* q);
void TestQueue();
