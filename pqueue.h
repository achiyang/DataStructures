#ifndef PQUEUE_H
#define	PQUEUE_H

#include "dstypes.h"

/*
	PriorityQueue 구조체:

	이 구조체는 우선순위 큐를 나타냅니다.
	우선순위 큐는 들어간 순서와 상관 없이 우선순위가 높은 데이터가 먼저 나오는 데이터 구조입니다.
	우선순위 큐는 데이터를 넣고(enpqueue) 꺼내는(depqueue) 작업을 수행합니다.

	이 구조체에서 우선순위 큐는 힙을 통해 구현되었습니다.
	힙은 배열과 index연산을 통해 구현되었습니다.

	구조체 멤버:
	- arr:	우선순위 큐에 저장될 데이터를 담는 배열을 가리키는 포인터입니다.
			배열은 동적으로 할당되어 크기가 동적으로 조정됩니다.
	- size: 배열의 크기를 나타냅니다. 현재 우선순위 큐에 저장될 수 있는 최대 원소의 개수를 나타냅니다.
	- cnt: 현재 우선순위 큐에 저장된 원소의 개수를 나타냅니다.
	- comparePriority: 우선순위를 비교하기 위한 함수의 포인터입니다.
*/
typedef struct PriorityQueue {
	datap *arr;		// 데이터를 저장하는 배열
	int size;		// 우선순위 큐의 크기
	int cnt;		// 우선순위 큐에 저장된 원소의 개수
	compareDatapFunc compare;	// 우선순위 비교를 위한 함수 포인터
} PriorityQueue;

/* 우선순위 큐에 데이터를 삽입하는 함수 */
void enpqueue(PriorityQueue *pqueue, datap data);

/* 우선순위 큐에서 데이터를 추출하는 함수 */
datap depqueue(PriorityQueue *pqueue);

/* 우선순위 큐를 초기화하는 함수 */
void initPriorityQueue(PriorityQueue *pqueue, compareDatapFunc compare);

/* 우선순위 큐를 해제하는 함수 */
void destroyPriorityQueue(PriorityQueue *pqueue);

#endif // PQUEUE_H
