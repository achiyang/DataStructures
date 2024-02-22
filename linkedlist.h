#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "dstypes.h"

typedef struct ListNode {
	datap data;
	struct ListNode *next;
} ListNode;

typedef void (*ListCallbackFunc)(datap *data, size_t index);

void sortList(ListNode **headRef, compareDatapFunc compare);

void insertList(ListNode **headRef, datap data, size_t pos);

void appendList(ListNode **headRef, datap data);

void prependList(ListNode **headRef, datap data);

void forEachList(ListNode *head, ListCallbackFunc callback);

void freeList(ListNode **headRef);

#endif // LINKEDLIST_H
