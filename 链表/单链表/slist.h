#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDataType x);
// �������ӡ
void SListPrint(SListNode* plist);
// ������β��
void SListPushBack(SListNode** pplist, SLTDataType x);
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDataType x);
// �������βɾ
void SListPopBack(SListNode** pplist);
// ������ͷɾ
void SListPopFront(SListNode** pplist);
// ���������
SListNode* SListFind(SListNode* plist, SLTDataType x);
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDataType x);
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);

// ��pos��ǰ�����
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDataType x);
// ɾ��posλ��
void SLTErase(SListNode** pphead, SListNode* pos);
void SLTDestroy(SListNode** pphead);