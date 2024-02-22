#ifndef STACK_H
#define STACK_H

#include "dstypes.h"

/*
	Stack ����ü:

	�� ����ü�� ������ ��Ÿ���ϴ�. ������ ���Լ���(LIFO) ������� �����ϴ� ������ �����Դϴ�.
	������ �����͸� �װ�(push) ������(pop) �۾��� ���˴ϴ�.

	����ü ���:
	- arr:	���ÿ� ����� �����͸� ��� �迭�� ����Ű�� �������Դϴ�.
			�迭�� �������� �Ҵ�Ǿ� ũ�Ⱑ �������� �����˴ϴ�.
	- size:	arr�� ũ�⸦ ��Ÿ���ϴ�. ���� ���ÿ� ����� �� �ִ� �ִ� ������ ������ ��Ÿ���ϴ�.
	- top:	���� ������ �� ���� ��ġ�� ������ �ε����� ��Ÿ���ϴ�.
			������ ������� ���� -1�� �ʱ�ȭ�˴ϴ�.
*/
typedef struct Stack {
	datap *arr;	// ������ �迭
	int size;	// ������ ũ��
	int top;	// ������ ���� �� ������ �ε���
} Stack;

/* ���ÿ� �����͸� �����ϴ� �Լ� */
void pushStack(Stack *stack, datap data);

/* ���ÿ��� �����͸� �����ϴ� �Լ� */
datap popStack(Stack *stack);

/* ������ �ʱ�ȭ�ϴ� �Լ� */
void initStack(Stack *stack);

/* ������ �����ϴ� �Լ� */
void destroyStack(Stack *stack);

#endif
