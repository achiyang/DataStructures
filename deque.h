#ifndef DEQUE_H
#define DEQUE_H

#include "types.h"

/*
	Deque 구조체:

	이 구조체는 덱을 나타냅니다. 덱은 앞과 뒤에서 데이터 삽입과 삭제를 수행할 수 있는 데이터 구조입니다.
	덱은 앞과 뒤에 자유롭게 데이터를 넣고(push) 꺼내는(pop) 작업을 수행합니다.

	구조체 멤버:
	- arr:	덱에 저장될 데이터를 담는 배열을 가리키는 포인터입니다.
			배열은 동적으로 할당되어 크기가 동적으로 조정됩니다.
	- size: 배열의 크기를 나타냅니다. 현재 덱에 저장될 수 있는 최대 원소의 개수를 나타냅니다.
	- cnt: 현재 덱에 저장된 원소의 개수를 나타냅니다.
	- front: 가장 앞 원소의 인덱스를 나타냅니다.
	- back: 가장 뒤 원소의 인덱스를 나타냅니다.
*/
typedef struct Deque {
	datap* arr;	// 데이터를 저장하는 배열
	int size;	// 덱의 크기
	int cnt;	// 덱에 저장된 원소의 개수
	int front;	// 가장 앞 원소의 인덱스
	int back;	// 가장 뒤 원소의 인덱스
} Deque;

/* 덱의 뒤에 데이터를 추가하는 함수 */
void pushBackDeque(Deque* deque, datap data);

/* 덱의 앞에 데이터를 추가하는 함수 */
void pushFrontDeque(Deque* deque, datap data);

/* 덱의 뒤에서 데이터를 추출하는 함수 */
datap popBackDeque(Deque* deque);

/* 덱의 앞에서 데이터를 추출하는 함수 */
datap popFrontDeque(Deque* deque);

/* 덱을 초기화하는 함수 */
void initDeque(Deque* deque);

/* 덱을 해제하는 함수 */
void destroyDeque(Deque* deque);

#endif
