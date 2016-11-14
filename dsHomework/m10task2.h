#ifndef M10TASK2_H
#define M10TASK2_H

typedef struct leaf {
	int value;
	struct leaf* lc;
	struct leaf* rc;
} Leaf;
typedef Leaf* PLeaf;
typedef Leaf* Root;

typedef struct node {
	PLeaf value;
	struct node* next;
} Node;
typedef Node* PNode;

Root initPre(int* src, int indexStart, int indexEnd);
Root initMid(int* src, int indexStart, int indexEnd);
void levelTra(Root tree);

PNode task2_initQueue(void);
void push(PNode root, PLeaf value);
void _delete(PNode root);
#endif