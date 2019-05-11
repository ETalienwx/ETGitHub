#pragma once

////��̬˳���
//#define N 10
//typedef int SLDateType;
//typedef struct SeqList
//{
//	int _a[N];//����
//	size_t _size;//�ж��ٸ���Ч����
//}SeqList;
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

//��̬˳���
#define N 10
typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* _a;   //����
	size_t _size;     //�ж��ٸ���Ч����
	size_t _capacity;  //����
}SeqList;

void CheckCapacity(SeqList* psl);
void SeqListInit(SeqList* psl, size_t capacity);//��ʼ��
void SeqListDestory(SeqList* psl);//����

void SeqListPushBack(SeqList* psl, SLDateType x);//β��
void SeqListPopBack(SeqList* psl);//βɾ
void SeqListPushFront(SeqList* psl, SLDateType x);//ͷ��
void SeqListPopFront(SeqList* psl);//ͷɾ

void SeqListInsert(SeqList* psl, size_t pos, SLDateType x);//����λ�õĲ���,��posλ���ϵĲ���
void SeqListErase(SeqList* psl, size_t pos);//ɾ��pos���λ�õ�����
void SeqListRemove(SeqList* psl, SLDateType x);//ɾ��x�������
int SeqListFind(SeqList* psl, SLDateType x);//����һ������
void SeqListModify(SeqList* psl, size_t pos, SLDateType x);//�޸�posλ�õ�ֵ���޸�Ϊx

void SeqListPrint(SeqList* psl);//��ӡ��˳���

void SeqListBubbleSort(SeqList* psl);//ð������
void SeqListSelectSort(SeqList* psl);//ѡ������
int SeqListBinarySearch(SeqList* psl,SLDateType x); //���ֲ���
void SeqListRemoveAll(SeqList* psl,SLDateType x);//ɾ�����е�x

void TestSeqList();
