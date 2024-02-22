#include <stdlib.h>
#include <string.h>
#include "deque.h"

#define MIN_DEQUE_SIZE 8

/* 덱의 크기를 조정하는 함수 */
static void resize(Deque *deque, size_t size) {
	datap *new_arr;
	int new_size;

	if (size <= INT_MAX)
		new_size = size;
	else
		new_size = INT_MAX;

	new_arr = (datap *)malloc(sizeof(datap) * new_size);
	if (new_arr == NULL)
		exit(EXIT_FAILURE);

	if (deque->front <= deque->back) {
		memcpy(new_arr, deque->arr + deque->front, sizeof(datap) * deque->cnt);
	}
	else {
		memcpy(new_arr, deque->arr + deque->front, sizeof(datap) * (deque->size - deque->front));
		memcpy(new_arr + (deque->size - deque->front), deque->arr, sizeof(datap) * (deque->back + 1));
	}

	free(deque->arr);
	deque->arr = new_arr;
	deque->size = new_size;
	deque->front = 0;
	deque->back = deque->cnt - 1;
}

/* 덱의 뒤에 데이터를 추가하는 함수 */
void pushBackDeque(Deque *deque, datap data) {
	if (deque->cnt >= deque->size)
		resize(deque, (size_t)deque->size * 2);

	if (++deque->back >= deque->size)
		deque->back = 0;
	deque->arr[deque->back] = data;

	deque->cnt++;
}

/* 덱의 앞에 데이터를 추가하는 함수 */
void pushFrontDeque(Deque *deque, datap data) {
	if (deque->cnt >= deque->size)
		resize(deque, (size_t)deque->size * 2);

	if (--deque->front < 0)
		deque->front = deque->size - 1;
	deque->arr[deque->front] = data;

	deque->cnt++;
}

/* 덱의 뒤에서 데이터를 추출하는 함수 */
datap popBackDeque(Deque *deque) {
	datap ret;

	if (deque->cnt <= 0)
		return NULL;

	ret = deque->arr[deque->back--];
	if (deque->back < 0)
		deque->back = deque->size - 1;
	deque->cnt--;

	if (deque->size > MIN_DEQUE_SIZE && deque->cnt < deque->size / 4)
		resize(deque, deque->size / 2);

	return ret;
}

/* 덱의 앞에서 데이터를 추출하는 함수 */
datap popFrontDeque(Deque *deque) {
	datap ret;

	if (deque->cnt <= 0)
		return NULL;

	ret = deque->arr[deque->front++];
	if (deque->front >= deque->size)
		deque->front = 0;
	deque->cnt--;

	if (deque->size > MIN_DEQUE_SIZE && deque->cnt < deque->size / 4)
		resize(deque, deque->size / 2);

	return ret;
}

/* 덱을 초기화하는 함수 */
void initDeque(Deque *deque) {
	deque->size = MIN_DEQUE_SIZE;
	deque->arr = malloc(sizeof(datap) * deque->size);
	if (deque->arr == NULL)
		exit(EXIT_FAILURE);
	deque->cnt = 0;
	deque->front = 1;
	deque->back = 0;
}

/* 덱을 해제하는 함수 */
void destroyDeque(Deque *deque) {
	free(deque->arr);
	deque->arr = NULL;
	deque->size = 0;
	deque->cnt = 0;
}
