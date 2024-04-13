#include <stdlib.h>
#include "rbtree.h"

void initRBTree(RBTree *tree, compareDatapFunc compare) {
	tree->root = NULL;
	tree->compare = compare;
}

static void leftRotation(RBTree *tree, RBNode *node) {
	RBNode *child = node->right;

	node->right = child->left;
	if (child->left != NULL) {
		child->left->parent = node;
	}

	child->parent = node->parent;
	if (node->parent == NULL) {
		tree->root = child;
	}
	else if (node == node->parent->left) {
		node->parent->left = child;
	}
	else if (node == node->parent->right) {
		node->parent->right = child;
	}
	else {
		exit(EXIT_FAILURE);
	}

	child->left = node;
	node->parent = child;
}

static void rightRotation(RBTree *tree, RBNode *node) {
	RBNode *child = node->left;

	node->left = child->right;
	if (child->right != NULL) {
		child->right->parent = node;
	}

	child->parent = node->parent;
	if (node->parent == NULL) {
		tree->root = child;
	}
	else if (node == node->parent->left) {
		node->parent->left = child;
	}
	else if (node == node->parent->right) {
		node->parent->right = child;
	}
	else {
		exit(EXIT_FAILURE);
	}

	child->right = node;
	node->parent = child;
}

static void fixInsert(RBTree *tree, RBNode *node) {
	while (node->parent != NULL && node->parent->color == 'r') {
		if (node->parent == node->parent->parent->left) {
			RBNode *uncle = node->parent->parent->right;
			if (uncle != NULL && uncle->color == 'r') {
				node->parent->color = 'b';
				uncle->color = 'b';
				node->parent->parent->color = 'r';
				node = node->parent->parent;
			}
			else {
				if (node == node->parent->right) {
					node = node->parent;
					leftRotation(tree, node);
				}
				node->parent->color = 'b';
				node->parent->parent->color = 'r';
				rightRotation(tree, node->parent->parent);
			}
		}
		else {
			RBNode *uncle = node->parent->parent->left;
			if (uncle != NULL && uncle->color == 'r') {
				node->parent->color = 'b';
				uncle->color = 'b';
				node->parent->parent->color = 'r';
				node = node->parent->parent;
			}
			else {
				if (node == node->parent->left) {
					node = node->parent;
					rightRotation(tree, node);
				}
				node->parent->color = 'b';
				node->parent->parent->color = 'r';
				leftRotation(tree, node->parent->parent);
			}
		}
	}
	tree->root->color = 'b';
}

static RBNode *createRBNode(datap data) {
	RBNode *node = malloc(sizeof(RBNode));
	if (node == NULL)
		exit(EXIT_FAILURE);

	node->data = data;
	node->color = 'r';
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void insertRBTree(RBTree *tree, datap data) {
	RBNode *newNode = createRBNode(data);

	if (tree->compare == NULL)
		return;

	if (tree->root == NULL) {
		newNode->color = 'b';
		tree->root = newNode;
		return;
	}

	RBNode *parent = NULL;
	RBNode *current = tree->root;

	while (current != NULL) {
		parent = current;

		if (tree->compare(data, current->data) < 0)
			current = current->left;
		else
			current = current->right;
	}

	if (tree->compare(data, parent->data) < 0)
		parent->left = newNode;
	else
		parent->right = newNode;

	newNode->parent = parent;

	fixInsert(tree, newNode);
}

static void freeRBNode(RBNode *root) {
	if (root != NULL) {
		freeRBNode(root->left);
		freeRBNode(root->right);
		free(root);
	}
}

void destroyRBTree(RBTree *tree) {
	freeRBNode(tree->root);
	tree->root = NULL;
	tree->compare = NULL;
}
