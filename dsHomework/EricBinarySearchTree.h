#ifndef ERIC_BINARY_SEARCH_TREE
#define ERIC_BINARY_SEARCH_TREE
namespace eric {
	typedef struct bstNode {
		int value;
		struct bstNode* rightChild;
		struct bstNode* leftChild;
	} BSTNode;
	typedef BSTNode* PBSTNode;
	typedef BSTNode* PBSTRoot;

	PBSTRoot initBinSearchTree(int value);
	PBSTNode initBinSearchTreeNode(int value);
	void insertNode2BST(PBSTRoot rootP, PBSTNode newNodeP);
	void traversalPre(PBSTRoot rootP, void(*func) (PBSTNode));
	void deleteNode(PBSTRoot rootP, int value);
}
#endif
