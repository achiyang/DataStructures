#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"
#include "queue.h"
#include "pqueue.h"
#include "stack.h"
#include "linkedlist.h"

struct Person {
	char name[10];
	int age;
};

static int comparePerson(const datap a, const datap b) {
	struct Person *p1, *p2;

	p1 = (struct Person *)a;
	p2 = (struct Person *)b;

	if (strcmp(p2->name, p1->name) != 0)	// 이름이 다르다면
		return strcmp(p2->name, p1->name);		// 이름이 사전순으로 앞일수록 우선순위가 큼
	else									// 이름이 같다면
		return p2->age - p1->age;				// 나이가 적을수록 우선순위가 큼
}

static void callback(datap data, size_t index, datap args[]) {
	ListNode **head1Ref = (ListNode **)(args[0]);
	ListNode **head2Ref = (ListNode **)(args[1]);

	appendList(head1Ref, data);
	appendList(head2Ref, data);
}

static void printPerson(datap data, size_t index, datap args[]) {
	struct Person *p = data;
	printf("%s %d\n", p->name, p->age);
}

int main() {
	Deque deque;
	initDeque(&deque);

	pushFrontDeque(&deque, (datap)(intptr_t)1);
	printf("popBackDeque: %lld\n", (intptr_t)popBackDeque(&deque));

	printf("\n");
	destroyDeque(&deque);


	Queue *queue = (Queue *)malloc(sizeof(Queue));
	if (queue == NULL) exit(EXIT_FAILURE);
	initQueue(queue);

	for (uintptr_t i = 1; i <= 4; i++)
		enqueue(queue, (datap)i);

	while (*queue->cnt > 0)
		printf("dequeue: %llu\n", (uintptr_t)dequeue(queue));

	printf("\n");
	destroyQueue(queue);
	free(queue);


	PriorityQueue pqueue;
	initPriorityQueue(&pqueue, comparePerson);

	struct Person array[4] = {
		{"John", 30}, {"John", 20},
		{"Oliver", 35}, {"Harry", 25}
	};

	for (int i = 0; i < 4; i++)
		enpqueue(&pqueue, &array[i]);

	while (pqueue.cnt > 0) {
		struct Person *temp = depqueue(&pqueue);
		printf("%s %d\n", temp->name, temp->age);
	}

	printf("\n");
	destroyPriorityQueue(&pqueue);


	Stack stack;
	initStack(&stack);

	pushStack(&stack, comparePerson);
	printf(
		"comparePreson({ \"John\", 30 }, { \"John\", 20 }) = %d\n",
		((compareDatapFunc)popStack(&stack))(&array[0], &array[1])
	);

	printf("\n");
	destroyStack(&stack);


	ListNode *head_1 = NULL;

	for (int i = 0; i < 4; i++) {
		appendList(&head_1, &array[i]);
	}

	ListNode *head_2 = NULL;
	ListNode *head_3 = NULL;

	datap args[] = { &head_2, &head_3 };
	forEachList(head_1, callback, args);

	forEachList(head_2, printPerson, NULL);
	forEachList(head_3, printPerson, NULL);

	freeList(&head_1);
	freeList(&head_2);
	freeList(&head_3);

	return 0;
}
