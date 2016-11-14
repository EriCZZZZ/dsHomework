#ifndef M10TASK1_H
#define M10TASK1_H

typedef struct node {
	int value;
	struct node* next;
} Node;
typedef Node* PNode;

PNode init(int* source, int length);
PNode push(PNode root, int value);
PNode pop(PNode root, int index);
#endif
