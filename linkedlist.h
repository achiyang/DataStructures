#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "dstypes.h"

/*
	���� ����Ʈ�� ���

	������ ������ NULL�� �ʱ�ȭ�ؼ� ���
	����� ���� ��� freeList()�� ȣ��
*/
typedef struct ListNode {
	datap data;
	struct ListNode *next;
} ListNode;

/* forEachList���� ���Ǵ� �ݹ� �Լ� ���� */
typedef void (*ListCallback)(datap data, size_t index, datap args[]);

/* ���� ����Ʈ ���� */
void sortList(ListNode **headRef, compareDatapFunc compare);

/*
	���� ����Ʈ�� ���ϴ� ��ġ�� ��Ҹ� ����

	pos�� ����Ʈ�� ���̺��� ū ��� ���� ��Ҹ� ����
*/
void insertList(ListNode **headRef, datap data, size_t pos);

/* ���� ����Ʈ�� ���� ��Ҹ� �߰� */
void appendList(ListNode **headRef, datap data);

/* ���� ����Ʈ�� �տ� ��Ҹ� �߰� */
void prependList(ListNode **headRef, datap data);

/*
	���� ����Ʈ�� ��ȸ�ϸ鼭 �ݹ� �Լ��� ����

	�����Ϳ� �ε���, �������� �ݹ� �Լ��� ����
*/
void forEachList(ListNode *head, ListCallback callback, datap args[]);

/* ���� ����Ʈ�� �����ϰ� �ʱ�ȭ�ϴ� �Լ� */
void freeList(ListNode **headRef);

#endif // LINKEDLIST_H
