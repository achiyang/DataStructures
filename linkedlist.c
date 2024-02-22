#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

static ListNode *createNode(datap data) {
	ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

void sortList(ListNode **headRef, compareDatapFunc compare) {
	ListNode *a, *b;
}

void insertList(ListNode **headRef, datap data, size_t pos) {
	ListNode *new_node = createNode(data);

	if (*headRef == NULL || pos == 0) {
		new_node->next = *headRef;
		*headRef = new_node;
	}
	else {
		ListNode *curr = *headRef;
		while (--pos && curr->next != NULL) {
			curr = curr->next;
		}
		new_node->next = curr->next;
		curr->next = new_node;
	}
}

void appendList(ListNode **headRef, datap data) {
	ListNode *new_node = createNode(data);

	if (*headRef == NULL) {
		*headRef = new_node;
	}
	else {
		ListNode *curr = *headRef;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = new_node;
	}
}

void prependList(ListNode **headRef, datap data) {
	*headRef = createNode(data)->next = *headRef;
}
