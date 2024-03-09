#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include "list.h"

//��ʼ��
ListNode* InitList() {
	ListNode* pHead = ListCreate(1);
	pHead->next = pHead;
	pHead->prev = pHead;
}
//�����½��
ListNode* ListCreate(LTDataType x) {
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if(newnode == NULL){
		perror("malloc");
		return -1;
	}
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
//��������
void ListDestory(ListNode* pHead) {
	assert(pHead);
	ListNode* cur = pHead->next;
	while(cur!=pHead){
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(pHead);
}
//��ӡ����
void ListPrint(ListNode* pHead) {
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead) {
		printf("%d <=> ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//β��
void ListPushBack(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* tail = pHead->prev;
	ListNode* newnode = ListCreate(x);
	newnode->next = pHead;
	pHead->prev = newnode;
	newnode->prev = tail;
	tail->next = newnode;
}
//βɾ
void ListPopBack(ListNode* pHead) {
	assert(pHead);
	assert(pHead->next != pHead);
	ListNode* tail = pHead->prev;
	tail->prev->next = pHead;
	pHead->prev = tail->prev;
	free(tail);
}
//ͷ��
void ListPushFront(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* newnode = ListCreate(x);
	ListNode* next = pHead->next;
	pHead->next = newnode;
	newnode->prev = pHead;
	next->prev = newnode;
	newnode->next = next;
}
//ͷɾ
void ListPopFront(ListNode* pHead) {
	assert(pHead);
	assert(pHead->next != pHead);
	ListNode* next = pHead->next;
	ListNode* next2 = next->next;
	pHead->next = next2;
	next2->prev = pHead;
	free(next);
}
//����
ListNode* ListFind(ListNode* pHead, LTDataType x) {
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead) {
		if (cur->data == x)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}
//ָ��λ�ò���
void ListInsert(ListNode* pos, LTDataType x) {
	assert(pos);
	ListNode* newnode = ListCreate(x);
	ListNode* posprev = pos->prev;
	posprev->next = newnode;
	newnode->prev = posprev;
	newnode->next = pos;
	pos->prev = newnode;
}
//ָ��λ��ɾ��
void ListErase(ListNode* pos) {
	assert(pos);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}