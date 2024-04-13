#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

#define MIN_BUCKET_SIZE 32

void initHashMap(HashMap *map) {
	map->buckets = (HashNode **)calloc(MIN_BUCKET_SIZE, sizeof(HashNode *));
	if (map->buckets == NULL)
		exit(EXIT_FAILURE);

	map->capacity = MIN_BUCKET_SIZE;
	map->size = 0;
	map->load_factor = 0.8f;
}

static void freeHashNode(HashNode *node) {
	free(node->key);
	free(node);
}

static void freeBucket(HashNode **bucket) {
	HashNode *curr = *bucket;

	while (curr) {
		HashNode *temp = curr;
		curr = curr->next;
		freeHashNode(temp);
	}

	*bucket = NULL;
}

void destroyHashMap(HashMap *map) {
	for (int i = 0; i < map->size; ++i) {
		freeBucket(&map->buckets[i]);
	}
	free(map->buckets);
	map->buckets = NULL;
	map->capacity = 0;
	map->size = 0;
}

static unsigned long djb2(const unsigned char *str) {
	unsigned long hash = 5381;
	int c;

	while (c = *str++) {
		hash = ((hash << 5) + hash) + c;  /* hash * 33 + c */
	}

	return hash;
}

static HashNode *createHashNode(const char *key, datap value) {
	HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
	if (newNode == NULL)
		exit(EXIT_FAILURE);

	newNode->key = _strdup(key);
	newNode->value = value;
	newNode->next = NULL;

	return newNode;
}

static void putBucket(HashNode **bucket, HashNode *node) {
	if (*bucket == NULL) {
		*bucket = node;
	}
	else {
		HashNode *curr = *bucket;
		while (curr->next) {
			curr = curr->next;
		}
		curr->next = node;
	}
}

void putHashMap(HashMap *map, const char *key, datap value) {
	HashNode *curr = map->buckets[djb2(key) % map->capacity];
	while (curr) {
		if (strcmp(key, curr->key) == 0) {
			curr->value = value;
			return;
		}
		curr = curr->next;
	}

	if (map->capacity * map->load_factor < map->size + 1) {
		int newCapacity = map->capacity << 1;
		HashNode **newBuckets = (HashNode **)calloc(newCapacity, sizeof(HashNode *));
		if (newBuckets == NULL)
			exit(EXIT_FAILURE);

		for (int i = 0; i < map->capacity; ++i) {
			curr = map->buckets[i];
			while (curr) {
				HashNode *temp = curr->next;
				curr->next = NULL;
				putBucket(&newBuckets[djb2(curr->key) % newCapacity], curr);
				curr = temp;
			}
		}

		free(map->buckets);
		map->buckets = newBuckets;
		map->capacity = newCapacity;
	}

	putBucket(&map->buckets[djb2(key) % map->capacity], createHashNode(key, value));
	map->size++;
}

datap getHashMap(HashMap *map, const char *key) {
	HashNode *curr = map->buckets[djb2(key) % map->capacity];

	while (curr) {
		if (strcmp(key, curr->key) == 0) {
			return curr->value;
		}
		curr = curr->next;
	}

	return NULL;
}

void removeHashMapKey(HashMap *map, const char *key) {
	HashNode **bucket = &map->buckets[djb2(key) % map->capacity];
	HashNode *curr = *bucket;
	HashNode *prev = NULL;

	while (curr) {
		if (strcmp(key, curr->key) == 0) {
			if (prev) {
				prev->next = curr->next;
			}
			else {
				*bucket = curr->next;
			}
			freeHashNode(curr);
			return;
		}
		prev = curr;
		curr = curr->next;
	}
}

void removeHashMapValue(HashMap *map, datap value, compareDatapFunc compare) {
	for (int i = 0; i < map->capacity; ++i) {
		HashNode **bucket = &map->buckets[i];
		HashNode *curr = *bucket;
		HashNode *prev = NULL;

		while (curr) {
			if (compare(value, curr->value) == 0) {
				if (prev) {
					prev->next = curr->next;
				}
				else {
					*bucket = curr->next;
				}
				HashNode *temp = curr;
				curr = curr->next;
				freeHashNode(temp);
			}
			else {
				prev = curr;
				curr = curr->next;
			}
		}
	}
}

void printHashMap(HashMap *map, void(printFunc(datap))) {
	for (int i = 0; i < map->capacity; ++i) {
		HashNode *curr = map->buckets[i];

		while (curr) {
			printf("\"%s\": ", curr->key);
			printFunc(curr->value);
			printf("\n");
			curr = curr->next;
		}
	}
	printf("\n");
}
