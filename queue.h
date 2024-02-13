#ifndef QUEUE_H
#define QUEUE_H

#include "types.h"

/*
	Queue ����ü:

	�� ����ü�� ť�� ��Ÿ���ϴ�. ť�� ���Լ���(FIFO) ������� �����ϴ� ������ �����Դϴ�.
	ť�� �����͸� �ְ�(enqueue) ������(dequeue) �۾��� �����մϴ�.

	�� ����ü���� ť�� Deque�� �����ؼ� �����Ǿ����ϴ�.
	Deque�� ���� �����ϴ� ���� �����ϰ� Deque�� ��� ���Ͽ��� �������� �ʱ� ���� void*�� ����մϴ�.

	����ü ���:
	- deque: Deque ����ü�� �������Դϴ�. �ʱ�ȭ�� �� �������� �Ҵ�˴ϴ�.
	- size: deque->cnt�� ����Ű�� �������Դϴ�. ť�� ���� ������ ������ Ȯ���ϴ� �뵵�� ���˴ϴ�.
*/
typedef struct Queue {
	void* deque;		// Deque ����ü ������
	const int* cnt;		// ť�� ����� ������ ������ ����Ű�� ������
} Queue;

/* ť�� �����͸� �����ϴ� �Լ� */
void enqueue(Queue* queue, datap data);

/* ť���� �����͸� �����ϴ� �Լ� */
datap dequeue(Queue* queue);

/* ť�� �ʱ�ȭ�ϴ� �Լ� */
void initQueue(Queue* queue);

/* ť�� �����ϴ� �Լ� */
void destroyQueue(Queue* queue);

#endif
