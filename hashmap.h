#ifndef HASHMAP_H
#define HASHMAP_H

#include "dstypes.h"

typedef struct HashNode {
	char *key;
	datap value;
	struct HashNode *next;
} HashNode;

typedef struct HashMap {
	HashNode **buckets;
	int capacity;
	int size;
	float load_factor;
} HashMap;

void initHashMap(HashMap *map);

void destroyHashMap(HashMap *map);

void putHashMap(HashMap *map, const char *key, datap value);

datap getHashMap(HashMap *map, const char *key);

void removeHashMapKey(HashMap *map, const char *key);

void removeHashMapValue(HashMap *map, datap value, compareDatapFunc compare);

void printHashMap(HashMap *map, void(printFunc(datap)));

#endif // HASHMAP_H
