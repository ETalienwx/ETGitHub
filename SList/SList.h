#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int SLTDateType;//�������������ض���

typedef struct SListNode//����һ����ʾ��������ڵ�Ľṹ��
{
	SLTDateType _date;//�ڵ��������
	struct SListNode* _next;//�ڵ���ָ����һ���ڵ��ָ��
}SListNode;

typedef struct SList//����һ������ṹ�壬����ָ��ͷ�ڵ��β�ڵ��ָ��
{
	struct SListNode* _head;//ͷ�ڵ�
	struct SListNode* _tail;//β�ڵ�
}SList;

void SListInit(SList* plist);//��ʼ���õ�����
void SListDestory(SList* plist);//���ٸõ�����

void SListPushBack(SList* plist,SLTDateType x);//�������β��
void SListPopBack(SList* plist);//�������βɾ
void SListPushFront(SList* plist,SLTDateType x);//�������ͷ��
void SListPopFront(SList* plist);//�������ͷɾ

SListNode* SListFind(SList* plist, SLTDateType x);//����x������ָ��ýڵ��ָ�룬����ΪSListNode*
//��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDateType x);//��posλ�õĺ������x
void SListEraseAfter(SListNode* pos);//ɾ��posλ�ú��������
void SListRemove(SList* plist, SLTDateType x);//ɾ��x
void SListPrint(SList* plist);//��ӡ������

void TestSList();//���Ժ���

