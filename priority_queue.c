#include <stdlib.h>
#include "priority_queue.h"

#define MIN_HEAP_SIZE 7

/* 두 데이터를 교환하는 함수 */
static void swap(datap* a, datap* b) {
	datap temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/* 우선순위 큐의 배열 크기를 조정하는 함수 */
static void resize(PriorityQueue* pqueue, int size) {
	datap* temp_arr;

	pqueue->size = size;

	/* index가 1부터 사용되기 때문에 배열의 실제 크기는 size + 1 */
	temp_arr = realloc(pqueue->arr, sizeof(datap) * (pqueue->size + 1));
	if (temp_arr == NULL)
		exit(EXIT_FAILURE);
	else
		pqueue->arr = temp_arr;
}

/* 힙을 재구성해 우선순위를 유지하는 함수 */
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
 /* 우선순위 큐에 데이터를 삽입하는 함수 */
void enpqueue(PriorityQueue* pqueue, datap data) {
	int index;

	/* 데이터의 수가 배열의 크기보다 크거나 같은 경우 크기를 조정 */
	if (pqueue->cnt >= pqueue->size)
		resize(pqueue, pqueue->size * 2 + 1);

	/* 배열의 마지막에 데이터 삽입 */
	index = ++pqueue->cnt;
	pqueue->arr[index] = data;

	/* 우선순위를 유지하기 위해 배열을 조정 */
	while (index > 1 &&
		pqueue->comparePriority(pqueue->arr[index], pqueue->arr[index / 2]) > 0) {
		swap(&pqueue->arr[index], &pqueue->arr[index / 2]);
		index /= 2;
	}
}

/* 우선순위 큐에서 데이터를 추출하는 함수 */
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

/* 우선순위 큐를 초기화하는 함수 */
void initPriorityQueue(PriorityQueue* pqueue, comparePriorityFunc comparePriority) {
	pqueue->size = MIN_HEAP_SIZE;
	pqueue->arr = (datap*)malloc(sizeof(datap) * (pqueue->size + 1));
	if (pqueue->arr == NULL)
		exit(EXIT_FAILURE);
	pqueue->cnt = 0;
	pqueue->comparePriority = comparePriority;
}

/* 우선순위 큐를 해제하는 함수 */
void destroyPriorityQueue(PriorityQueue* pqueue) {
	free(pqueue->arr);
	pqueue->arr = NULL;
	pqueue->size = 0;
	pqueue->cnt = 0;
}
