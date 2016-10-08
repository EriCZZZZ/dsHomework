#include "EricBinarySearchTree.h"
#include <cstdlib>

eric::PBSTRoot eric::initBinSearchTree(int value) {
	eric::PBSTRoot rootP = (eric::PBSTRoot) malloc(sizeof(eric::BSTNode));
	rootP->value = value;
	rootP->leftChild = nullptr;
	rootP->rightChild = nullptr;
	return rootP;
}

eric::PBSTNode eric::initBinSearchTreeNode(int value) {
	eric::PBSTNode nodeP = (eric::PBSTNode) malloc(sizeof(eric::BSTNode));
	nodeP->value = value;
	nodeP->leftChild = nullptr;
	nodeP->rightChild = nullptr;
}

void eric::insertNode2BST(eric::PBSTRoot rootP, eric::PBSTNode newNodeP) {
	if (newNodeP->value > rootP->value) {
		if (rootP->rightChild != nullptr) {
			eric::insertNode2BST((eric::PBSTRoot) rootP->rightChild, newNodeP);
		}
		else {
			rootP->rightChild = newNodeP;
		}
	}
	else if (newNodeP->value < rootP->value) {
		if (rootP->leftChild != nullptr) {
			eric::insertNode2BST((eric::PBSTRoot) rootP->leftChild, newNodeP);
		}
		else {
			rootP->leftChild = newNodeP;
		}
	}
}

void eric::traversalPre(PBSTRoot rootP, void(*func) (PBSTNode)) {
	if (rootP->rightChild != nullptr) {
		eric::traversalPre(rootP->rightChild, func);
	}
	(*func)(rootP);
	if (rootP->leftChild != nullptr) {
		eric::traversalPre(rootP->leftChild, func);
	}
	return;
}

void eric::deleteNode(PBSTRoot rootP, int value) {
}