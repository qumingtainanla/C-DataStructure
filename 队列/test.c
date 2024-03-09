#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include "queue.h"
void test_queue() {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);
	printf("%d ", QueueFront(&q));
	QueuePop(&q);

	QueuePush(&q, 4);
	QueuePush(&q, 5);
	putchar('\n');
	int size = QueueSize(&q);
	printf("%d", size);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	
	QueueDestroy(&q);
}
int main() {
	test_queue();
	return 0;
}