#ifndef ERIC_BINARY_SEARCH_TREE
#define ERIC_BINARY_SEARCH_TREE

#include <vector>

#define RIGHT_CHILD 0
#define LEFT_CHILD 1

namespace eric {
	typedef struct bstNode {
		int value;
		struct bstNode* parent;
		struct bstNode* rightChild;
		struct bstNode* leftChild;
	} BSTNode;
	typedef BSTNode* PBSTNode;
	typedef BSTNode* PBSTRoot;

	PBSTRoot initBinSearchTree(int value);
	PBSTNode initBinSearchTreeNode(int value);
	void push(PBSTRoot rootP, int value);
	int pop(PBSTRoot rootP, int value);

	void adjustBalance(PBSTNode newNode);
	int getNodeDepth(PBSTNode target);
	void turnRight(PBSTNode target2Down);
	void turnLeft(PBSTNode target2Down);
	void turnRightLeft(PBSTNode targetBalanceError);
	void turnLeftRight(PBSTNode targetBalanceError);
}
#endif
