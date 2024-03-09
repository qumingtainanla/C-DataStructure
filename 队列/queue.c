#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"
// ��ʼ������ 
void QueueInit(Queue* q) {
	assert(q);
	q->_front = q->_rear = NULL;
}
// ��β����� 
void QueuePush(Queue* q, QDataType data) {
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->_data = data;
	newnode->_next = NULL;
	if (q->_rear == NULL)
		q->_rear = q->_front = newnode;
	else {
		q->_rear->_next = newnode;
		q->_rear = newnode;
	}
}
// ��ͷ������ 
void QueuePop(Queue* q) {
	assert(q);
	assert(q->_front);
	QNode* del = q->_front;
	q->_front = q->_front->_next;
	free(del);
	del = NULL;
	if (q->_front == NULL)
		q->_rear = NULL;
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q) {
	assert(q);
	assert(q->_front);
	return q->_front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q) {
	assert(q);
	if (q->_rear == NULL)
		return 0;
	else
		return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q) {
	assert(q);
	int count = 0;
	QNode* cur = q->_front;
	while (cur) {
		cur = cur->_next;
		count++;
	}
	return count;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q) {
	assert(q);
	return q->_front == NULL;
}
// ���ٶ��� 
void QueueDestroy(Queue* q) {
	assert(q);
	while (q->_rear)
		QueuePop(q);
}