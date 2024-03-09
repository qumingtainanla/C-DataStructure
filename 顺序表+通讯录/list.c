#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
void SLInit(SL* ps) {
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SLDestroy(SL* ps) {
	if (ps->a)
		free(ps->a);
		ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SLPrint(SL* ps) {
	for (int i = 0; i < ps->size; i++)
		printf("%d ", ps->a[i]);
	printf("\n");
}
void SLCheckCapacity(SL* ps) {
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL) {
			perror("realloc fail!\n");
			return 1;
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}
//头部插入删除 / 尾部插入删除
void SLPushBack(SL* ps, SLDataType x) {
	assert(ps);
	SLCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SLPopBack(SL* ps) {
	assert(ps);
	ps->size--;
}
void SLPushFront(SL* ps, SLDataType x) {
	assert(ps);
	SLCheckCapacity(ps);
	for (size_t i = ps->size; i > 0; i--)
		ps->a[i] = ps->a[i - 1];
	ps->a[0] = x;
	ps->size++;
}
void SLPopFront(SL* ps) {
	assert(ps);
	for (size_t i = 0; i < ps->size; i++)
		ps->a[i] = ps->a[i + 1];
	ps->size--;
}
//指定位置之前插入/删除数据
void SLInsert(SL* ps, int pos, SLDataType x) {
	assert(ps);
	SLCheckCapacity(ps);
	if (pos < 0 || pos > ps->size) {
		printf("无效位置\n");
		return;
	}
	int i = ps->size;
	for (; i > pos; i--) { 
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}
void SLErase(SL* ps, int pos)
{
	assert(ps);
	if (pos < 0 || pos > ps->size) {
		printf("无效位置\n");
		return;
	}
	int i = pos;
	for (; i <= ps->size; i++)
		ps->a[i - 1] = ps->a[i];
	ps->size--;
}

int SLFind(SL* ps, SLDataType* x) {
	assert(ps);
	int i = 0;
	for (i; i < ps->size; i++) {
		if (ps->a[i].name == x)
			return i;
	}
	return 0;
}