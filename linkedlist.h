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
typedef void (*ListCallback)(datap data, void *params);


/* 연결 리스트 정렬 */
void sortList(ListNode **headRef, compareDatapFunc compare);


/*
	연결 리스트의 특정 위치에 데이터를 삽입

	위치가 리스트의 길이보다 큰 경우 끝에 데이터를 추가
*/
void insertList(ListNode **headRef, datap data, int pos);

/* 연결 리스트의 끝에 데이터를 추가 */
void appendList(ListNode **headRef, datap data);

/* 연결 리스트의 앞에 데이터를 추가 */
void prependList(ListNode **headRef, datap data);


/*
	연결 리스트를 순회하면서 콜백 함수를 실행

	매개변수는 포인터, 배열, 포인터 배열 등으로 전달할 수 있음
*/
void forEachList(ListNode *head, ListCallback callback, void *params);


/* 연결 리스트의 길이를 반환 */
int getListLength(ListNode *head);


/*
	연결 리스트에서 데이터와 일치하는 첫 번째 노드의 위치를 반환

	일치하는 데이터가 없을 경우 -1을 반환
*/
int findPosList(ListNode *head, datap data, compareDatapFunc compare);


/*
	동적 할당된 데이터가 연결 리스트의 노드에만 존재하는 경우,
	노드를 삭제하기 전 데이터를 해제한 뒤 노드를 위치로 삭제해야함
*/

/* 연결 리스트에서 특정 위치의 노드를 삭제 */
void deleteListNodePos(ListNode **headRef, int pos);

/* 연결 리스트에서 특정 데이터와 일치하는 첫 번째 노드를 삭제 */
void deleteListNodeData(ListNode **headRef, datap data, compareDatapFunc compare);


/* 연결 리스트에서 특정 위치의 노드를 반환 */
ListNode *getListNodePos(ListNode *head, int pos);

/* 연결 리스트에서 특정 데이터와 일치하는 첫 번째 노드를 반환 */
ListNode *getListNodeData(ListNode *head, datap data, compareDatapFunc compare);


/* 연결 리스트의 순서를 역순으로 바꿈 */
void reverseList(ListNode **headRef);


/* 연결 리스트를 해제하고 초기화 */
void freeList(ListNode **headRef);

#endif // LINKEDLIST_H
