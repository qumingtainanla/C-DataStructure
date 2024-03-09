#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include "slist.h"
//新建结点
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
//打印
void SListPrint(SListNode* plist) {
	SListNode* cur = plist;
	while (cur) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//尾插
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
//头插
void SListPushFront(SListNode** pplist, SLTDataType x) {
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}
//尾删
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
//头删
void SListPopFront(SListNode** pplist) {
	assert(*pplist);
	SListNode* tmp = *pplist;
	*pplist = (*pplist)->next;
	free(tmp);
}
//查找
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
//在pos之后插入x
void SListInsertAfter(SListNode* pos, SLTDataType x) {
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
//删除pos之后的位置
void SListEraseAfter(SListNode* pos) {
	assert(pos&&pos->next);
	SListNode* tmp = pos->next;
	pos->next = pos->next->next;
	free(tmp);
	tmp = NULL;
}
//在pos之前插入x
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
//删除pos位置
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
//删除链表
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