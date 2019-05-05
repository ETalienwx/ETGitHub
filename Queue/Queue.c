#include "Queue.h"

void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
}

void QueueDestory(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}

QueueNode* BuyQueueNode(QUDateType x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->_date = x;
	newnode->_next = NULL;
	return newnode;
}
void QueuePush(Queue* q, QUDateType x)
{
	assert(q);
	if (q->_front == NULL)
	{
		q->_front = q->_rear = BuyQueueNode(x);
	}
	else
	{
		q->_rear->_next = BuyQueueNode(x);
		q->_rear = q->_rear->_next;
	}
}

void QueuePop(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	if (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		q->_front = next;

		if (q->_front == NULL)
		{
			q->_rear = NULL;
		}
	}
}

int QueueSize(Queue* q)
{
	assert(q);
	QueueNode* cur = q->_front;
	int size = 0;
	while (cur)
	{
		cur = cur->_next;
		size++;
	}
	return size;
}
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL ? 0 : 1;
}
QUDateType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_date;
}
QUDateType QueueBack(Queue* q)
{
	assert(q);
	return q->_rear->_date;
}
void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}

}

