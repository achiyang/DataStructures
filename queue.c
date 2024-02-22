#include <stdlib.h>
#include "deque.h"
#include "queue.h"

/* 큐에 데이터를 삽입하는 함수 */
void enqueue(Queue *queue, datap data) {
	pushBackDeque(queue->deque, data);
}

/* 큐에서 데이터를 추출하는 함수 */
datap dequeue(Queue *queue) {
	return popFrontDeque(queue->deque);
}

/* 큐를 초기화하는 함수 */
void initQueue(Queue *queue) {
	queue->deque = malloc(sizeof(Deque));
	if (queue->deque == NULL)
		exit(EXIT_FAILURE);
	initDeque(queue->deque);
	queue->cnt = &((Deque *)(queue->deque))->cnt;
}

/* 큐를 해제하는 함수 */
void destroyQueue(Queue *queue) {
	destroyDeque(queue->deque);
	free(queue->deque);
	queue->deque = NULL;
	queue->cnt = NULL;
}
