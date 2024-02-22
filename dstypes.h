#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

/*
	datap �ڷ���:

	- �ڷᱸ������ �����͸� ��Ÿ���� �� ���˴ϴ�.
	- void* ������ ������� �Ͽ�, � ������ �����͵� ����ų �� �ֽ��ϴ�.
	- uintptr_t �� intptr_t ���� ������ Ÿ������ ĳ�����Ͽ� �������� ��Ÿ�� �� �ֽ��ϴ�.
*/
typedef void *datap;

typedef int (*compareDatapFunc)(datap, datap);

#endif // TYPES_H
