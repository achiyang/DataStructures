#include <stdlib.h>
#include "deque.h"
#include "queue.h"

/* ť�� �����͸� �����ϴ� �Լ� */
void enqueue(Queue *queue, datap data) {
	pushBackDeque(queue->deque, data);
}

/* ť���� �����͸� �����ϴ� �Լ� */
datap dequeue(Queue *queue) {
	return popFrontDeque(queue->deque);
}

/* ť�� �ʱ�ȭ�ϴ� �Լ� */
void initQueue(Queue *queue) {
	queue->deque = malloc(sizeof(Deque));
	if (queue->deque == NULL)
		exit(EXIT_FAILURE);
	initDeque(queue->deque);
	queue->cnt = &((Deque *)(queue->deque))->cnt;
}

/* ť�� �����ϴ� �Լ� */
void destroyQueue(Queue *queue) {
	destroyDeque(queue->deque);
	free(queue->deque);
	queue->deque = NULL;
	queue->cnt = NULL;
}
