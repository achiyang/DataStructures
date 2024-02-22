#include <stdlib.h>
#include "stack.h"

#define MIN_STACK_SIZE 8

/* 스택의 크기를 조절하는 함수 */
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

/* 스택에 데이터를 삽입하는 함수 */
void pushStack(Stack *stack, datap data) {
	stack->top++;

	if (stack->top >= stack->size)
		resize(stack, stack->size * 2);

	stack->arr[stack->top] = data;
}

/* 스택에서 데이터를 추출하는 함수 */
datap popStack(Stack *stack) {
	datap ret;

	if (stack->top < 0)
		return NULL;

	ret = stack->arr[stack->top--];

	if (stack->size > MIN_STACK_SIZE && stack->top < stack->size / 4)
		resize(stack, stack->size / 2);

	return ret;
}

/* 스택을 초기화하는 함수 */
void initStack(Stack *stack) {
	stack->size = MIN_STACK_SIZE;
	stack->arr = (datap *)malloc(sizeof(datap) * stack->size);
	if (stack->arr == NULL)
		exit(EXIT_FAILURE);
	stack->top = -1;
}

/* 스택을 해제하는 함수 */
void destroyStack(Stack *stack) {
	free(stack->arr);
	stack->size = 0;
	stack->top = -1;
}
