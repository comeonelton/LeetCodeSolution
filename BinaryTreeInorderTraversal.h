/*
 * BinaryTreeInorderTraversal.h
 *
 *  Created on: 2014/3/23
 *      Author: comeonelton
 */

#ifndef BINARYTREEINORDERTRAVERSAL_H_
#define BINARYTREEINORDERTRAVERSAL_H_

#include <iostream>
#include <vector>
#include <stack>

#include "DataStructure/TreeNode.h"


class BinaryTreeInorderTraversal {
public:
	BinaryTreeInorderTraversal();
	virtual ~BinaryTreeInorderTraversal();

	static void inorderTraversal_recursive(TreeNode *root);
	static void inorderTraversal_iterative(std::stack<TreeNode *> &s);

	static void execute();
};

#endif /* BINARYTREEINORDERTRAVERSAL_H_ */
