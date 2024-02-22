#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "dstypes.h"

/*
	연결 리스트의 노드

	포인터 변수를 NULL로 초기화해서 사용
	사용이 끝난 경우 freeList()를 호출
*/
typedef struct ListNode {
	datap data;
	struct ListNode *next;
} ListNode;

/* forEachList에서 사용되는 콜백 함수 정의 */
typedef void (*ListCallback)(datap data, size_t index, datap args[]);

/* 연결 리스트 정렬 */
void sortList(ListNode **headRef, compareDatapFunc compare);

/*
	연결 리스트의 원하는 위치에 요소를 삽입

	pos가 리스트의 길이보다 큰 경우 끝에 요소를 삽입
*/
void insertList(ListNode **headRef, datap data, size_t pos);

/* 연결 리스트의 끝에 요소를 추가 */
void appendList(ListNode **headRef, datap data);

/* 연결 리스트의 앞에 요소를 추가 */
void prependList(ListNode **headRef, datap data);

/*
	연결 리스트를 순회하면서 콜백 함수를 실행

	데이터와 인덱스, 변수들을 콜백 함수에 전달
*/
void forEachList(ListNode *head, ListCallback callback, datap args[]);

/* 연결 리스트를 해제하고 초기화하는 함수 */
void freeList(ListNode **headRef);

#endif // LINKEDLIST_H
