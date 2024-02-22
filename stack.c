#include <stdlib.h>
#include "stack.h"

#define MIN_STACK_SIZE 8

/* ������ ũ�⸦ �����ϴ� �Լ� */
static void resize(Stack *stack, size_t size) {
	datap *temp_arr;

	if (size <= INT_MAX)
		stack->size = size;
	else
		stack->size = INT_MAX;
	temp_arr = realloc(stack->arr, sizeof(datap) * stack->size);
	if (temp_arr == NULL)
		exit(EXIT_FAILURE);
	else
		stack->arr = temp_arr;
}

/* ���ÿ� �����͸� �����ϴ� �Լ� */
void pushStack(Stack *stack, datap data) {
	stack->top++;

	if (stack->top >= stack->size)
		resize(stack, stack->size * 2);

	stack->arr[stack->top] = data;
}

/* ���ÿ��� �����͸� �����ϴ� �Լ� */
datap popStack(Stack *stack) {
	datap ret;

	if (stack->top < 0)
		return NULL;

	ret = stack->arr[stack->top--];

	if (stack->size > MIN_STACK_SIZE && stack->top < stack->size / 4)
		resize(stack, stack->size / 2);

	return ret;
}

/* ������ �ʱ�ȭ�ϴ� �Լ� */
void initStack(Stack *stack) {
	stack->size = MIN_STACK_SIZE;
	stack->arr = (datap *)malloc(sizeof(datap) * stack->size);
	if (stack->arr == NULL)
		exit(EXIT_FAILURE);
	stack->top = -1;
}

/* ������ �����ϴ� �Լ� */
void destroyStack(Stack *stack) {
	free(stack->arr);
	stack->size = 0;
	stack->top = -1;
}
