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
