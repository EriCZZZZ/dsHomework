#include "m10task1.h"
#include <cstdlib>
#include <iostream>

PNode init(int* source, int length) {
	PNode root = (PNode)malloc(sizeof(Node));
	root->value = source[0];
	root->next = root;

	for (int i = 1; i < length; i++) {
		root = push(root, source[i]);
	}

	return root;
}

PNode push(PNode root, int value) {
	PNode newPNode = (PNode)malloc(sizeof(Node));
	newPNode->value = value;
	newPNode->next = root->next;
	root->next = newPNode;
	return root->next;
}

PNode pop(PNode root, int index) {
	if (root == NULL) {
		std::cout << "done" << std::endl;
		return NULL;
	}
	else if (root->next == root) {
		std::cout << root->value << std::endl;
		return NULL;
	}
	else {
		for (int i = 1; i < index - 1; i++) {
			root = root->next;
		}
		std::cout << root->next->value << std::endl;
		PNode temp = root->next;
		root->next = temp->next;
		free(temp);
		return root->next;
	}
}