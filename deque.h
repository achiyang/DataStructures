#ifndef DEQUE_H
#define DEQUE_H

#include "types.h"

/*
	Deque ����ü:

	�� ����ü�� ���� ��Ÿ���ϴ�. ���� �հ� �ڿ��� ������ ���԰� ������ ������ �� �ִ� ������ �����Դϴ�.
	���� �հ� �ڿ� �����Ӱ� �����͸� �ְ�(push) ������(pop) �۾��� �����մϴ�.

	����ü ���:
	- arr:	���� ����� �����͸� ��� �迭�� ����Ű�� �������Դϴ�.
			�迭�� �������� �Ҵ�Ǿ� ũ�Ⱑ �������� �����˴ϴ�.
	- size: �迭�� ũ�⸦ ��Ÿ���ϴ�. ���� ���� ����� �� �ִ� �ִ� ������ ������ ��Ÿ���ϴ�.
	- cnt: ���� ���� ����� ������ ������ ��Ÿ���ϴ�.
	- front: ���� �� ������ �ε����� ��Ÿ���ϴ�.
	- back: ���� �� ������ �ε����� ��Ÿ���ϴ�.
*/
typedef struct Deque {
	datap* arr;	// �����͸� �����ϴ� �迭
	int size;	// ���� ũ��
	int cnt;	// ���� ����� ������ ����
	int front;	// ���� �� ������ �ε���
	int back;	// ���� �� ������ �ε���
} Deque;

/* ���� �ڿ� �����͸� �߰��ϴ� �Լ� */
void pushBackDeque(Deque* deque, datap data);

/* ���� �տ� �����͸� �߰��ϴ� �Լ� */
void pushFrontDeque(Deque* deque, datap data);

/* ���� �ڿ��� �����͸� �����ϴ� �Լ� */
datap popBackDeque(Deque* deque);

/* ���� �տ��� �����͸� �����ϴ� �Լ� */
datap popFrontDeque(Deque* deque);

/* ���� �ʱ�ȭ�ϴ� �Լ� */
void initDeque(Deque* deque);

/* ���� �����ϴ� �Լ� */
void destroyDeque(Deque* deque);

#endif
