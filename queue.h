#ifndef QUEUE_H
#define QUEUE_H

#include "types.h"

/*
	Queue 구조체:

	이 구조체는 큐를 나타냅니다. 큐는 선입선출(FIFO) 방식으로 동작하는 데이터 구조입니다.
	큐는 데이터를 넣고(enqueue) 꺼내는(dequeue) 작업을 수행합니다.

	이 구조체에서 큐는 Deque를 래핑해서 구현되었습니다.
	Deque에 직접 접근하는 것을 방지하고 Deque을 헤더 파일에서 노출하지 않기 위해 void*를 사용합니다.

	구조체 멤버:
	- deque: Deque 구조체의 포인터입니다. 초기화할 때 동적으로 할당됩니다.
	- size: deque->cnt를 가리키는 포인터입니다. 큐에 남은 원소의 개수를 확인하는 용도로 사용됩니다.
*/
typedef struct Queue {
	void* deque;		// Deque 구조체 포인터
	const int* cnt;		// 큐에 저장된 원소의 개수를 가리키는 포인터
} Queue;

/* 큐에 데이터를 삽입하는 함수 */
void enqueue(Queue* queue, datap data);

/* 큐에서 데이터를 추출하는 함수 */
datap dequeue(Queue* queue);

/* 큐를 초기화하는 함수 */
void initQueue(Queue* queue);

/* 큐를 해제하는 함수 */
void destroyQueue(Queue* queue);

#endif
