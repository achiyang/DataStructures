#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"
#include "queue.h"
#include "pqueue.h"
#include "stack.h"
#include "linkedlist.h"
#include "hashmap.h"

struct Person {
	char name[10];
	int age;
};

static int comparePerson(datap a, datap b) {
	struct Person *p1, *p2;

	p1 = (struct Person *)a;
	p2 = (struct Person *)b;

	if (strcmp(p2->name, p1->name) != 0)	// 이름이 다르다면
		return strcmp(p2->name, p1->name);		// 이름이 사전순으로 앞일수록 우선순위가 큼
	else									// 이름이 같다면
		return p2->age - p1->age;				// 나이가 적을수록 우선순위가 큼
}

static int comparePersonName(datap a, datap b) {
	struct Person *p1, *p2;

	p1 = (struct Person *)a;
	p2 = (struct Person *)b;

	return strcmp(p1->name, p2->name);
}

static void printPersonIndex(datap data, void *params) {
	struct Person *p = data;
	int *i = (int *)params;

	printf("%d : %s %d\n", (*i)++, p->name, p->age);
}

static void printPerson(datap data) {
	struct Person *p = data;

	printf("{ \"%s\", %d }", p->name, p->age);
}

static void sumList(datap data, void *params) {
	int num = (int)(uintptr_t)data;
	int *sum = ((int **)params)[0], *count = ((int **)params)[1];

	*sum += num;
	++(*count);
}

int main() {
	{
		Deque deque;
		initDeque(&deque);

		pushFrontDeque(&deque, (datap)(intptr_t)1);
		printf("popBackDeque: %lld\n", (intptr_t)popBackDeque(&deque));

		printf("\n");
		destroyDeque(&deque);
	}

	{
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
	}

	struct Person array[4] = {
		{"John", 30}, {"John", 20},
		{"Oliver", 35}, {"Harry", 25}
	};

	{
		PriorityQueue pqueue;
		initPriorityQueue(&pqueue, comparePerson);

		for (int i = 0; i < 4; i++)
			enpqueue(&pqueue, &array[i]);

		while (pqueue.cnt > 0) {
			struct Person *temp = depqueue(&pqueue);
			printf("%s %d\n", temp->name, temp->age);
		}

		printf("\n");
		destroyPriorityQueue(&pqueue);
	}

	{
		Stack stack;
		initStack(&stack);

		pushStack(&stack, comparePerson);
		printf(
			"comparePerson({ \"John\", 30 }, { \"John\", 20 }) = %d\n",
			((compareDatapFunc)popStack(&stack))(&array[0], &array[1])
		);

		printf("\n");
		destroyStack(&stack);
	}

	{
		ListNode *head = NULL;

		for (int i = 0; i < 4; i++) {
			appendList(&head, &array[i]);
		}

		int i = 0;
		forEachList(head, printPersonIndex, &i);
		printf("\n");

		i = 0;
		sortList(&head, comparePerson);
		forEachList(head, printPersonIndex, &i);
		printf("\n");

		freeList(&head);


		for (uintptr_t j = 0; j < 10; j++) {
			prependList(&head, (datap)j);
		}

		int count = 0, sum = 0;
		int* params[] = { &count, &sum };
		forEachList(head, sumList, params);
		printf("%d %d\n", count, sum);
		printf("\n");

		freeList(&head);
	}

	{
		HashMap hashmap;
		initHashMap(&hashmap);

		for (int i = 0; i < 4; i++) {
			char key[2] = { 0 };
			key[0] = 'a' + i;
			putHashMap(&hashmap, key, &array[i]);
		}
		printHashMap(&hashmap, printPerson);

		putHashMap(&hashmap, "c", &(struct Person){ "Kim", 40 });
		printHashMap(&hashmap, printPerson);

		removeHashMapKey(&hashmap, "d");
		printHashMap(&hashmap, printPerson);

		removeHashMapValue(&hashmap, &(struct Person){ "John", 0 }, comparePersonName);
		printHashMap(&hashmap, printPerson);
	}

	return 0;
}
