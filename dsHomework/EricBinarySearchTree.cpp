#include "EricBinarySearchTree.h"
#include <cstdlib>
#include <cmath>

eric::PBSTRoot eric::initBinSearchTree(int value) {
	eric::PBSTRoot rootP = (eric::PBSTRoot) malloc(sizeof(eric::BSTNode));
	rootP->value = value;
	rootP->parent = nullptr;
	rootP->leftChild = nullptr;
	rootP->rightChild = nullptr;
	return rootP;
}

eric::PBSTNode eric::initBinSearchTreeNode(int value) {
	eric::PBSTNode nodeP = (eric::PBSTNode) malloc(sizeof(eric::BSTNode));
	nodeP->value = value;
	nodeP->parent = nullptr;
	nodeP->leftChild = nullptr;
	nodeP->rightChild = nullptr;
	return nodeP;
}

void eric::push(PBSTRoot rootP, int value) {
	if (rootP != nullptr && rootP->value != value) {
		if (value > rootP->value) {
			if (rootP->rightChild == nullptr) {
				rootP->rightChild = initBinSearchTreeNode(value);
				rootP->rightChild->parent = rootP;
				eric::adjustBalance(rootP->rightChild);
			}
			else {
				eric::push(rootP->rightChild, value);
			}
		}
		else {
			if (rootP->leftChild == nullptr) {
				rootP->leftChild = initBinSearchTreeNode(value);
				rootP->leftChild->parent = rootP;
				eric::adjustBalance(rootP->leftChild);
			}
			else {
				eric::push(rootP->leftChild, value);
			}
		}
	}
}

int eric::pop(PBSTRoot rootP, int value) {
	if (rootP != nullptr) {
		if (rootP->value == value) {
			if (rootP->leftChild == nullptr && rootP->rightChild == nullptr) {
				free(rootP);
				return value;
			}
			else if (rootP->leftChild == nullptr || rootP->rightChild == nullptr) {
				PBSTNode temp = (rootP->leftChild == nullptr) ? rootP->rightChild : rootP->leftChild;
				rootP->value = temp->value;
				rootP->leftChild = temp->leftChild;
				rootP->rightChild = temp->rightChild;
				free(temp);
				return value;
			}
			else {
				// find pre node
				PBSTNode PpreNode = rootP->leftChild;
				PBSTNode PpreNodeFather = rootP;
				while (PpreNode->rightChild != nullptr) {
					PpreNodeFather = PpreNode;
					PpreNode = PpreNode->rightChild;
				}
				if (rootP == PpreNodeFather) {
					rootP->leftChild = PpreNode->leftChild;
				}
				else {
					PpreNodeFather->rightChild = PpreNode->leftChild;
				}
				// move up
				rootP->value = PpreNode->value;
				// remove pre node
				free(PpreNode);
				return value;
			}
		}
		else if (rootP->value > value) {
			return eric::pop(rootP->leftChild, value);
		}
		else if (rootP->value < value) {
			return eric::pop(rootP->rightChild, value);
		}
	}
	else {
		return -1;
	}
}

void eric::adjustBalance(PBSTNode newNode) {
	std::vector<int> rightLeftStack;
	if (newNode != nullptr) {
		while (1) {
			int rightHeight = eric::getNodeDepth(newNode->rightChild);
			int leftHeight = eric::getNodeDepth(newNode->leftChild);
			if (leftHeight - rightHeight > 1 || rightHeight - leftHeight > 1) {
				int node1 = rightLeftStack.at(rightLeftStack.size() - 1);
				rightLeftStack.erase(rightLeftStack.end() - 1);
				int node2 = rightLeftStack.at(rightLeftStack.size() - 1);
				rightLeftStack.erase(rightLeftStack.end() - 1);
				if (node1 == RIGHT_CHILD && node2 == RIGHT_CHILD) {
					eric::turnLeft(newNode);
				}
				else if (node1 == RIGHT_CHILD && node2 == LEFT_CHILD) {
					eric::turnRightLeft(newNode);
				}
				else if (node1 == LEFT_CHILD && node2 == LEFT_CHILD) {
					eric::turnRight(newNode);
				}
				else if (node1 == LEFT_CHILD && node2 == RIGHT_CHILD) {
					eric::turnLeftRight(newNode);
				}
				// return;
			}
			else {
				PBSTNode temp = newNode;
				if (newNode == nullptr || newNode->parent == nullptr) {
					return;
				}
				newNode = newNode->parent;

				if (newNode->leftChild == temp) {
					rightLeftStack.push_back(LEFT_CHILD);
				}
				else if (newNode->rightChild == temp) {
					rightLeftStack.push_back(RIGHT_CHILD);
				}
				else {
					return;
				}
			}
		}
	}
}
int eric::getNodeDepth(PBSTNode target) {
	if (target != nullptr) {
		return 1 + (eric::getNodeDepth(target->leftChild) > eric::getNodeDepth(target->rightChild) ? eric::getNodeDepth(target->leftChild) : eric::getNodeDepth(target->rightChild));
	}
	else {
		return 0;
	}
}

void eric::turnRight(PBSTNode target2Down) {
	if (target2Down != nullptr && target2Down->leftChild != nullptr) {
		PBSTNode tempTarget = eric::initBinSearchTreeNode(target2Down->value);
		tempTarget->rightChild = target2Down->rightChild;
		if (tempTarget->rightChild != nullptr) {
			tempTarget->rightChild->parent = tempTarget;
		}
		tempTarget->leftChild = target2Down->leftChild->rightChild;
		if (tempTarget->leftChild != nullptr) {
			tempTarget->leftChild->parent = tempTarget;
		}
		tempTarget->parent = target2Down;

		target2Down->value = target2Down->leftChild->value;
		target2Down->rightChild = tempTarget;
		PBSTNode leftNode2Delete = target2Down->leftChild;
		target2Down->leftChild = leftNode2Delete->leftChild;
		if (target2Down->leftChild != nullptr) {
			target2Down->leftChild->parent = target2Down;
		}
		free(leftNode2Delete);
	}
}
void eric::turnLeft(PBSTNode target2Down) {
	if (target2Down != nullptr && target2Down->rightChild != nullptr) {
		PBSTNode tempTarget = eric::initBinSearchTreeNode(target2Down->value);
		tempTarget->leftChild = target2Down->leftChild;
		if (tempTarget->leftChild != nullptr) {
			tempTarget->leftChild->parent = tempTarget;
		}
		tempTarget->rightChild = target2Down->rightChild->leftChild;
		if (tempTarget->rightChild != nullptr) {
			tempTarget->rightChild->parent = tempTarget;
		}
		tempTarget->parent = target2Down;

		target2Down->leftChild = tempTarget;
		target2Down->value = target2Down->rightChild->value;
		PBSTNode rightNode2Delete = target2Down->rightChild;
		target2Down->rightChild = rightNode2Delete->rightChild;
		if (target2Down->rightChild != nullptr) {
			target2Down->rightChild->parent = target2Down;
		}
		free(rightNode2Delete);
	}
}
void eric::turnRightLeft(PBSTNode targetBalanceError) {
	eric::turnRight(targetBalanceError->rightChild);
	eric::turnLeft(targetBalanceError);
}
void eric::turnLeftRight(PBSTNode targetBalanceError) {
	eric::turnLeft(targetBalanceError->leftChild);
	eric::turnRight(targetBalanceError);
}