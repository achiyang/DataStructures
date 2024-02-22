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
typedef void (*ListCallback)(datap data, void *params);


/* ���� ����Ʈ ���� */
void sortList(ListNode **headRef, compareDatapFunc compare);


/*
	���� ����Ʈ�� Ư�� ��ġ�� �����͸� ����

	��ġ�� ����Ʈ�� ���̺��� ū ��� ���� �����͸� �߰�
*/
void insertList(ListNode **headRef, datap data, int pos);

/* ���� ����Ʈ�� ���� �����͸� �߰� */
void appendList(ListNode **headRef, datap data);

/* ���� ����Ʈ�� �տ� �����͸� �߰� */
void prependList(ListNode **headRef, datap data);


/*
	���� ����Ʈ�� ��ȸ�ϸ鼭 �ݹ� �Լ��� ����

	�Ű������� ������, �迭, ������ �迭 ������ ������ �� ����
*/
void forEachList(ListNode *head, ListCallback callback, void *params);


/* ���� ����Ʈ�� ���̸� ��ȯ */
int getListLength(ListNode *head);


/*
	���� ����Ʈ���� �����Ϳ� ��ġ�ϴ� ù ��° ����� ��ġ�� ��ȯ

	��ġ�ϴ� �����Ͱ� ���� ��� -1�� ��ȯ
*/
int findPosList(ListNode *head, datap data, compareDatapFunc compare);


/*
	���� �Ҵ�� �����Ͱ� ���� ����Ʈ�� ��忡�� �����ϴ� ���,
	��带 �����ϱ� �� �����͸� ������ �� ��带 ��ġ�� �����ؾ���
*/

/* ���� ����Ʈ���� Ư�� ��ġ�� ��带 ���� */
void deleteListNodePos(ListNode **headRef, int pos);

/* ���� ����Ʈ���� Ư�� �����Ϳ� ��ġ�ϴ� ù ��° ��带 ���� */
void deleteListNodeData(ListNode **headRef, datap data, compareDatapFunc compare);


/* ���� ����Ʈ���� Ư�� ��ġ�� ��带 ��ȯ */
ListNode *getListNodePos(ListNode *head, int pos);

/* ���� ����Ʈ���� Ư�� �����Ϳ� ��ġ�ϴ� ù ��° ��带 ��ȯ */
ListNode *getListNodeData(ListNode *head, datap data, compareDatapFunc compare);


/* ���� ����Ʈ�� ������ �������� �ٲ� */
void reverseList(ListNode **headRef);


/* ���� ����Ʈ�� �����ϰ� �ʱ�ȭ */
void freeList(ListNode **headRef);

#endif // LINKEDLIST_H
