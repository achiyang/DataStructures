#ifndef PRIORITY_QUEUE_H
#define	PRIORITY_QUEUE_H

#include "types.h"

/*
	comparePriorityFunc �Լ� ������:

	�� �Լ� �����ʹ� �������� �켱������ ���ϴ� �Լ��� ����Ű�� �������Դϴ�.
	�켱���� ť���� �������� �켱������ ���ϱ� ���� ���˴ϴ�.

	�Լ��� datap �� ���� �Է¹޾� ���� �켱������ ��ȯ�մϴ�.
	- ù ��° ����� �켱������ �� ��° ���� Ŭ ��� ����� ��ȯ�մϴ�.
	- �ݴ��� ��� ������ ��ȯ�մϴ�.
	- �켱������ ���� ��� 0�� ��ȯ�մϴ�.
*/
typedef int (*comparePriorityFunc)(const datap, const datap);

/*
	PriorityQueue ����ü:

	�� ����ü�� �켱���� ť�� ��Ÿ���ϴ�.
	�켱���� ť�� �� ������ ��� ���� �켱������ ���� �����Ͱ� ���� ������ ������ �����Դϴ�.
	�켱���� ť�� �����͸� �ְ�(enpqueue) ������(depqueue) �۾��� �����մϴ�.

	�� ����ü���� �켱���� ť�� ���� ���� �����Ǿ����ϴ�.
	���� �迭�� index������ ���� �����Ǿ����ϴ�.

	����ü ���:
	- arr:	�켱���� ť�� ����� �����͸� ��� �迭�� ����Ű�� �������Դϴ�.
			�迭�� �������� �Ҵ�Ǿ� ũ�Ⱑ �������� �����˴ϴ�.
	- size: �迭�� ũ�⸦ ��Ÿ���ϴ�. ���� �켱���� ť�� ����� �� �ִ� �ִ� ������ ������ ��Ÿ���ϴ�.
	- cnt: ���� �켱���� ť�� ����� ������ ������ ��Ÿ���ϴ�.
	- comparePriority: �켱������ ���ϱ� ���� �Լ��� �������Դϴ�.
*/
typedef struct PriorityQueue {
	datap* arr;		// �����͸� �����ϴ� �迭
	int size;		// �켱���� ť�� ũ��
	int cnt;		// �켱���� ť�� ����� ������ ����
	comparePriorityFunc comparePriority;	// �켱���� �񱳸� ���� �Լ� ������
} PriorityQueue;

/* �켱���� ť�� �����͸� �����ϴ� �Լ� */
void enpqueue(PriorityQueue* pqueue, datap data);

/* �켱���� ť���� �����͸� �����ϴ� �Լ� */
datap depqueue(PriorityQueue* pqueue);

/* �켱���� ť�� �ʱ�ȭ�ϴ� �Լ� */
void initPriorityQueue(PriorityQueue* pqueue, comparePriorityFunc comparePriority);

/* �켱���� ť�� �����ϴ� �Լ� */
void destroyPriorityQueue(PriorityQueue* pqueue);

#endif // PRIORITY_QUEUE_H
