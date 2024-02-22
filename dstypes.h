#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

/*
	datap 자료형:

	- 자료구조에서 데이터를 나타내는 데 사용됩니다.
	- void* 형식을 기반으로 하여, 어떤 유형의 데이터든 가리킬 수 있습니다.
	- uintptr_t 나 intptr_t 등의 정수형 타입으로 캐스팅하여 정수값을 나타낼 수 있습니다.
*/
typedef void *datap;

/*
	데이터를 비교하는 함수

	앞이 더 작은 경우 0보다 작은 값을 반환
	반대의 경우 0보다 큰 값을 반환
	같은 경우 0을 반환
*/
typedef int (*compareDatapFunc)(datap, datap);

#endif // TYPES_H
