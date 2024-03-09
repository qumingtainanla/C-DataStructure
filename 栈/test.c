#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
test(){
    Stack s;
    StackInit(&s);
    StackPush(&s, 1);
    StackPush(&s, 2);
    StackPush(&s, 3);
    printf("%d ", StackTop(&s));
    StackPop(&s);
    printf("%d ", StackTop(&s));
    StackPop(&s);
    
    StackPush(&s, 4);
    StackPush(&s, 5);
    while (!StackEmpty(&s))
    {
    	printf("%d ", StackTop(&s));
        StackPop(&s);
    }
    printf("\n");
    
    return 0;
}
int main() {
    test();
	return 0;
}