#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include "slist.h"
//�½����
SListNode* BuySListNode(SLTDataType x) {
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
//��ӡ
void SListPrint(SListNode* plist) {
	SListNode* cur = plist;
	while (cur) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//β��
void SListPushBack(SListNode** pplist, SLTDataType x) {
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	SListNode* tail = *pplist;
	if (*pplist == NULL)
		*pplist = newnode;
	else {
		while (tail->next) {
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
//ͷ��
void SListPushFront(SListNode** pplist, SLTDataType x) {
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}
//βɾ
void SListPopBack(SListNode** pplist) {
	assert(pplist);
	assert(*pplist);
	SListNode* tail = *pplist;
	if ((*pplist)->next == NULL) {
		free(*pplist);
		*pplist = NULL;
	}
	else {
		while (tail->next->next) {
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}
//ͷɾ
void SListPopFront(SListNode** pplist) {
	assert(*pplist);
	SListNode* tmp = *pplist;
	*pplist = (*pplist)->next;
	free(tmp);
}
//����
SListNode* SListFind(SListNode* plist, SLTDataType x) {
	assert(plist);
	SListNode* cur = plist;
	while (cur) {
		if (cur->data == x) 
			return cur;
		else 
			cur = cur->next;
	}
	return NULL;
}
//��pos֮�����x
void SListInsertAfter(SListNode* pos, SLTDataType x) {
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//ɾ��pos֮���λ��
void SListEraseAfter(SListNode* pos) {
	assert(pos&&pos->next);
	SListNode* tmp = pos->next;
	pos->next = pos->next->next;
	free(tmp);
	tmp = NULL;
}
//��pos֮ǰ����x
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDataType x) {
	assert(pphead);
	assert(pos);
	assert(*pphead);
	SListNode* newnode = BuySListNode(x);
	if (*pphead == pos) {
		SListPushFront(pphead, x);
	}
	SListNode* cur = *pphead;
	while (cur->next != pos)
	{
		cur = cur->next;
	}
	newnode->next = pos;
	cur->next = newnode;
}
//ɾ��posλ��
void SLTErase(SListNode** pphead, SListNode* pos) {
	assert(pphead && *pphead);
	if (*pphead == pos)
		SListPopFront(pphead);
	SListNode* prev = *pphead;
	while (prev->next != pos)
		prev = prev->next;
	prev->next = pos->next;
	free(pos);
	pos = NULL;
}
//ɾ������
void SLTDestroy(SListNode** pphead) {
	assert(pphead);
	SListNode* cur = *pphead;
	while (cur)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}