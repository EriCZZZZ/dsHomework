#include "EricNumHash.h"
#include <cstdlib>

PHead initQueue() {
	PHead head = (PHead)malloc(sizeof(Node));
	head->next = nullptr;
	return head;
}
void append(PHead head, int value) {
	PNode node = (PNode)malloc(sizeof(Node));
	node->next = nullptr;
	node->value = value;

	while (head->next != nullptr) {
		head = head->next;
	}
	head->next = node;
}
bool isNumExistInQueue(PHead head, int value) {
	bool isExist = false;
	while (head->next != nullptr) {
		head = head->next;
		if (head->value == value) {
			isExist = true;
			return isExist;
		}
	}
	return isExist;
}
void freeQueue(PHead head) {
	while (head->next != nullptr) {
		PHead temp = head->next;
		free(head);
		head = temp;
	}
	free(head);
}
int getHashIndex(int target) {
	return target % HASH_ARRAY_LENGTH;
}
PHead* initHashArray() {
	int i = 0;
	PHead* hashArray = (PHead*) malloc(sizeof(PHead) * HASH_ARRAY_LENGTH);
	while (i < HASH_ARRAY_LENGTH) {
		hashArray[i++] = initQueue();
	}
	return hashArray;
}
void insert2HashArray(PHead* hashArray, int target) {
	append(hashArray[getHashIndex(target)], target);
}

bool isNumExist(PHead* head, int target) {
	int i = 0;
	bool flag = false;
	while (i < HASH_ARRAY_LENGTH) {
		if (isNumExistInQueue(head[i++], target)) {
			flag = true;
			return flag;
		}
	}
	return flag;
}

void freeHashArray(PHead* hashArray) {
	int i = 0;
	while (i < HASH_ARRAY_LENGTH) {
		freeQueue(hashArray[i++]);
	}
}