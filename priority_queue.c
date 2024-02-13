#include <stdlib.h>
#include "priority_queue.h"

#define MIN_HEAP_SIZE 7

/* �� �����͸� ��ȯ�ϴ� �Լ� */
static void swap(datap* a, datap* b) {
	datap temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/* �켱���� ť�� �迭 ũ�⸦ �����ϴ� �Լ� */
static void resize(PriorityQueue* pqueue, int size) {
	datap* temp_arr;

	pqueue->size = size;

	/* index�� 1���� ���Ǳ� ������ �迭�� ���� ũ��� size + 1 */
	temp_arr = realloc(pqueue->arr, sizeof(datap) * (pqueue->size + 1));
	if (temp_arr == NULL)
		exit(EXIT_FAILURE);
	else
		pqueue->arr = temp_arr;
}

/* ���� �籸���� �켱������ �����ϴ� �Լ� */
static void heapify(PriorityQueue* pqueue) {
	int index;
	int left, right, temp;

	index = 1;
	while (1) {
		left = index * 2;
		right = index * 2 + 1;
		temp = index;

		if (left <= pqueue->cnt &&
			pqueue->comparePriority(pqueue->arr[left], pqueue->arr[temp]) > 0) {
			temp = left;
		}
		if (right <= pqueue->cnt &&
			pqueue->comparePriority(pqueue->arr[right], pqueue->arr[temp]) > 0) {
			temp = right;
		}

		if (temp != index) {
			swap(&pqueue->arr[temp], &pqueue->arr[index]);
			index = temp;
		}
		else {
			break;
		}
	}
}
 /* �켱���� ť�� �����͸� �����ϴ� �Լ� */
void enpqueue(PriorityQueue* pqueue, datap data) {
	int index;

	/* �������� ���� �迭�� ũ�⺸�� ũ�ų� ���� ��� ũ�⸦ ���� */
	if (pqueue->cnt >= pqueue->size)
		resize(pqueue, pqueue->size * 2 + 1);

	/* �迭�� �������� ������ ���� */
	index = ++pqueue->cnt;
	pqueue->arr[index] = data;

	/* �켱������ �����ϱ� ���� �迭�� ���� */
	while (index > 1 &&
		pqueue->comparePriority(pqueue->arr[index], pqueue->arr[index / 2]) > 0) {
		swap(&pqueue->arr[index], &pqueue->arr[index / 2]);
		index /= 2;
	}
}

/* �켱���� ť���� �����͸� �����ϴ� �Լ� */
datap depqueue(PriorityQueue* pqueue) {
	datap ret;

	if (pqueue->cnt <= 0)
		return NULL;

	ret = pqueue->arr[1];
	pqueue->arr[1] = pqueue->arr[pqueue->cnt--];
	heapify(pqueue);

	if (pqueue->size > MIN_HEAP_SIZE && pqueue->cnt < pqueue->size / 4) {
		resize(pqueue, pqueue->size / 2);
	}

	return ret;
}

/* �켱���� ť�� �ʱ�ȭ�ϴ� �Լ� */
void initPriorityQueue(PriorityQueue* pqueue, comparePriorityFunc comparePriority) {
	pqueue->size = MIN_HEAP_SIZE;
	pqueue->arr = (datap*)malloc(sizeof(datap) * (pqueue->size + 1));
	if (pqueue->arr == NULL)
		exit(EXIT_FAILURE);
	pqueue->cnt = 0;
	pqueue->comparePriority = comparePriority;
}

/* �켱���� ť�� �����ϴ� �Լ� */
void destroyPriorityQueue(PriorityQueue* pqueue) {
	free(pqueue->arr);
	pqueue->arr = NULL;
	pqueue->size = 0;
	pqueue->cnt = 0;
}
