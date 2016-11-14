#include "m10task2.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>

Root initMid(int* src, int indexStart, int indexEnd) {
	int length = indexEnd - indexStart;
	if (length < 0) {
		return nullptr;
	}
	if (length == 0) {
		Root root = (Root)malloc(sizeof(Leaf));
		root->value = src[indexStart];
		root->lc = nullptr;
		root->rc = nullptr;

		return root;
	}

	Root root = (Root)malloc(sizeof(Leaf));
	root->lc = initMid(src, indexStart, indexStart + length / 2 - 1);
	root->value = src[indexStart + length / 2];
	root->rc = initMid(src, indexStart + length / 2 + 1, indexEnd);

	return root;
}

Root initPre(int* src, int indexStart, int indexEnd) {
	int length = indexEnd - indexStart;
	if (length >= 0) {
		if (length == 0) {
			Root root = (Root)malloc(sizeof(Leaf));
			root->value = src[indexStart];
			root->lc = nullptr;
			root->rc = nullptr;

			return root;
		}
		Root root = (Root)malloc(sizeof(Leaf));
		root->value = src[indexStart];
		root->lc = initPre(src, indexStart + 1, indexStart + length / 2);
		root->rc = initPre(src, indexStart + length / 2 + 1, indexEnd);
		return root;
	}
	return nullptr;
}

void levelTra(Root tree) {
	PNode old = task2_initQueue();
	PNode _new = task2_initQueue();
	push(old, tree);

	while (old->next != nullptr) {
		PNode temp = old;
		while (temp->next != nullptr) {
			temp = temp->next;
			if (temp->value->lc != nullptr) {
				push(_new, temp->value->lc);
			}
			if (temp->value->rc != nullptr) {
				push(_new, temp->value->rc);
			}
			printf("%d ", temp->value->value);
		}
		printf("\n");
		_delete(old);
		old = _new;
		_new = task2_initQueue();
	}
}

PNode task2_initQueue(void) {
	PNode root = (PNode)malloc(sizeof(Node));
	root->value = nullptr;
	root->next = nullptr;
	return root;
}

void push(PNode root, PLeaf value) {
	while (root->next != nullptr) {
		root = root->next;
	}
	PNode newNode = (PNode)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = nullptr;
	root->next = newNode;
}

void _delete(PNode root) {
	while (root->next != nullptr) {
		PNode temp = root;
		root = root->next;
		free(temp);
	}
	free(root);
}