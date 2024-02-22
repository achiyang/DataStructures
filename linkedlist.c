#include <stdlib.h>
#include <stdio.h>
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

static ListNode *mergeList(ListNode *front, ListNode *back, compareDatapFunc compare) {
	ListNode temp;
	ListNode *curr = &temp;

	while (front != NULL && back != NULL) {
		if (compare(front->data, back->data) <= 0) {
			curr->next = front;
			curr = curr->next;
			front = front->next;
		}
		else {
			curr->next = back;
			curr = curr->next;
			back = back->next;
		}
	}

	if (front == NULL) {
		curr->next = back;
	}
	else {
		curr->next = front;
	}

	return temp.next;
}

static void splitList(ListNode *source, ListNode **frontRef, ListNode **backRef) {
	if (source == NULL || source->next == NULL) {
		*frontRef = source;
		*backRef = NULL;
	}
	else {
		ListNode *slow = source;
		ListNode *fast = source->next;

		while (fast != NULL) {
			fast = fast->next;
			if (fast != NULL) {
				fast = fast->next;
				slow = slow->next;
			}
		}

		*frontRef = source;
		*backRef = slow->next;
		slow->next = NULL;
	}
}

void sortList(ListNode **headRef, compareDatapFunc compare) {
	if (*headRef == NULL || (*headRef)->next == NULL) {
		return;
	}

	ListNode *front, *back;

	splitList(*headRef, &front, &back);

	sortList(&front, compare);
	sortList(&back, compare);

	*headRef = mergeList(front, back, compare);
}

void insertList(ListNode **headRef, datap data, int pos) {
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
	ListNode *new_node = createNode(data);
	new_node->next = *headRef;
	*headRef = new_node;
}

void forEachList(ListNode *head, ListCallback callback, void *args) {
	int pos = 0;

	while (head != NULL) {
		callback(head->data, args);
		head = head->next;
	}
}

int getListLength(ListNode *head) {
	int length = 0;

	while (head != NULL) {
		++length;
		head = head->next;
	}

	return length;
}

int findPosList(ListNode *head, datap data, compareDatapFunc compare) {
	int pos = 0;

	while (head != NULL) {
		if (compare(data, head->data) == 0) {
			return pos;
		}
		++pos;
		head = head->next;
	}
	return -1;
}

void deleteListNodePos(ListNode **headRef, int pos) {
	if (*headRef == NULL) {
		return;
	}

	ListNode *node = *headRef;

	if (pos == 0) {
		*headRef = node->next;
		free(node);
		return;
	}

	for (int i = 0; node->next != NULL && ++i < pos;) {
		node = node->next;
	}

	if (node->next == NULL) {
		return;
	}

	ListNode *temp = node->next;
	node->next = temp->next;
	free(temp);
}

void deleteListNodeData(ListNode **headRef, datap data, compareDatapFunc compare) {
	ListNode *curr = *headRef;
	if (curr == NULL) {
		return;
	}

	ListNode *prev = NULL;

	while (curr != NULL) {
		if (compare(curr, data) == 0) {
			if (curr == *headRef) {
				*headRef = curr->next;
				free(curr);
				return;
			}
			else {
				prev->next = curr->next;
				free(curr);
				return;
			}
		}
		prev = curr;
		curr = curr->next;
	}
}

ListNode *getListNodePos(ListNode *head, int pos) {
	for (int i = 0; head != NULL && i < pos; i++) {
		head = head->next;
	}
	return head;
}

ListNode *getListNodeData(ListNode *head, datap data, compareDatapFunc compare) {
	while (head != NULL) {
		if (compare(data, head->data) == 0) {
			return head;
		}
		head = head->next;
	}
	return NULL;
}

void reverseList(ListNode **headRef) {
	ListNode *curr = *headRef;
	if (curr == NULL) {
		return;
	}

	ListNode *prev = NULL;
	ListNode *next;

	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	*headRef = prev;
}

void freeList(ListNode **headRef) {
	ListNode *curr = *headRef;
	ListNode *temp;
	while (curr != NULL) {
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*headRef = NULL;
}
