#ifndef ERIC_NUM_HASH_H
#define ERIC_NUM_HASH_H

// homework : ���������У�ѡ����ʵ�hash�����ʹ����ͻ�ķ�������д���򹹽�����Ϊ50��hash���ұ���ʵ��hash��ѯ��
// 13, 27, 61, 25, 33, 39, 41, 83, 45, 77, 35, 19, 66, 49, 56, 22, 50, 71, 88, 28

#define HASH_ARRAY_LENGTH 50

typedef struct node {
	int value;
	struct node* next;
} Node;
typedef Node* PHead;
typedef Node* PNode;

// Queue functions
PHead initQueue();
void append(PHead head, int value);
bool isNumExistInQueue(PHead head, int value);
void freeQueue(PHead head);

int getHashIndex(int target);
PHead* initHashArray();
void insert2HashArray(PHead* hashArray, int target);
bool isNumExist(PHead* hashArray, int target);
void freeHashArray(PHead* hashArray);

#endif