#ifndef RBTREE_H
#define RBTREE_H

#include "dstypes.h"

typedef struct RBNode {
	datap data;
	char color;
	struct RBNode *parent;
	struct RBNode *left;
	struct RBNode *right;
} RBNode;

typedef struct RBTree {
	RBNode *root;
	compareDatapFunc compare;
} RBTree;

void initRBTree(RBTree *tree, compareDatapFunc compare);

void insertRBTree(RBTree *tree, datap data);

void destroyRBTree(RBTree *tree);

#endif // RBTREE_H
