#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
// 初始化栈 
void StackInit(Stack* ps) {
	assert(ps);
	ps->a = NULL;
	ps->top = -1;
	ps->capacity = 0;
}
// 入栈 
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
// 出栈 
void StackPop(Stack* ps) {
	assert(ps);
	assert(ps->top >= 0);
	ps->top--;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps) {
	assert(ps);
	assert(ps->top >= 0);
	return ps->a[ps->top];
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps) {
	assert(ps);
	return (ps->top) + 1;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
bool StackEmpty(Stack* ps) {
	assert(ps);
	return ps->top == -1;//true
}
// 销毁栈 
void StackDestroy(Stack* ps) {
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}