#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"
#include "queue.h"
#include "priority_queue.h"
#include "stack.h"

struct Person {
	char name[10];
	int age;
};

static int comparePerson(const datap a, const datap b) {
	struct Person *p1, *p2;

	p1 = (struct Person*)a;
	p2 = (struct Person*)b;

	if (strcmp(p2->name, p1->name) != 0)
		return strcmp(p2->name, p1->name); // 이름이 사전순으로 앞일수록 우선순위가 큼
	else
		return p2->age - p1->age; // 나이가 적을수록 우선순위가 큼
}

int main() {
	Deque deque;
	initDeque(&deque);

	pushFrontDeque(&deque, (datap)(intptr_t)1);
	printf("popBackDeque: %d\n", (int)(intptr_t)popBackDeque(&deque));

	destroyDeque(&deque);


	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if (queue == NULL) exit(EXIT_FAILURE);
	initQueue(queue);

	for (uintptr_t i = 1; i <= 4; i++)
		enqueue(queue, (datap)i);

	while (*queue->cnt > 0)
		printf("dequeue: %llu\n", (uintptr_t)dequeue(queue));

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
		struct Person* temp = depqueue(&pqueue);
		printf("%s %d\n", temp->name, temp->age);
	}

	destroyPriorityQueue(&pqueue);


	Stack stack;
	initStack(&stack);

	pushStack(&stack, comparePerson);
	printf(
		"comparePriority({ \"John\", 30 }, { \"John\", 20 }) = %d\n",
		((comparePriorityFunc)popStack(&stack))(&array[0], &array[1])
	);

	destroyStack(&stack);

	return 0;
}
