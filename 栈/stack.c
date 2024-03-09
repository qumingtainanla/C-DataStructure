#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
// ��ʼ��ջ 
void StackInit(Stack* ps) {
	assert(ps);
	ps->a = NULL;
	ps->top = -1;
	ps->capacity = 0;
}
// ��ջ 
void StackPush(Stack* ps, STDataType data) {
	assert(ps);
	if (ps->capacity == ps->top+1) {
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, newcapacity);
		if (tmp == NULL)
		{
			perror("realloc");
			return;
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->top++;
	ps->a[ps->top] = data;
}
// ��ջ 
void StackPop(Stack* ps) {
	assert(ps);
	assert(ps->top >= 0);
	ps->top--;
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps) {
	assert(ps);
	assert(ps->top >= 0);
	return ps->a[ps->top];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps) {
	assert(ps);
	return (ps->top) + 1;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
bool StackEmpty(Stack* ps) {
	assert(ps);
	return ps->top == -1;//true
}
// ����ջ 
void StackDestroy(Stack* ps) {
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}