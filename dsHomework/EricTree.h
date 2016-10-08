#ifndef ERIC_TREE_H
#define ERIC_TREE_H

namespace eric {
	typedef struct treeNode
	{
		int value;
		struct treeNode* firstChild;
		struct treeNode* nextSibiling;
	} TreeNode;
	typedef TreeNode* PTreeNode;
	typedef TreeNode* Root;

	Root initTree();
}
#endif