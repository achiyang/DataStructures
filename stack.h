#ifndef STACK_H
#define STACK_H

#include "dstypes.h"

/*
	Stack 구조체:

	이 구조체는 스택을 나타냅니다. 스택은 후입선출(LIFO) 방식으로 동작하는 데이터 구조입니다.
	스택은 데이터를 쌓고(push) 꺼내는(pop) 작업에 사용됩니다.

	구조체 멤버:
	- arr:	스택에 저장될 데이터를 담는 배열을 가리키는 포인터입니다.
			배열은 동적으로 할당되어 크기가 동적으로 조정됩니다.
	- size:	arr의 크기를 나타냅니다. 현재 스택에 저장될 수 있는 최대 원소의 개수를 나타냅니다.
	- top:	현재 스택의 맨 위에 위치한 원소의 인덱스를 나타냅니다.
			스택이 비어있을 때는 -1로 초기화됩니다.
*/
typedef struct Stack {
	datap *arr;	// 데이터 배열
	int size;	// 스택의 크기
	int top;	// 스택의 가장 위 원소의 인덱스
} Stack;

/* 스택에 데이터를 삽입하는 함수 */
void pushStack(Stack *stack, datap data);

/* 스택에서 데이터를 추출하는 함수 */
datap popStack(Stack *stack);

/* 스택을 초기화하는 함수 */
void initStack(Stack *stack);

/* 스택을 해제하는 함수 */
void destroyStack(Stack *stack);

#endif
