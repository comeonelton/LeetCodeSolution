/*
 * BinaryTreePreorderTraversal.h
 *
 *  Created on: 2014/3/23
 *      Author: comeonelton
 */

#ifndef BINARYTREEPREORDERTRAVERSAL_H_
#define BINARYTREEPREORDERTRAVERSAL_H_

#include <iostream>
#include <vector>
#include <stack>

#include "DataStructure/TreeNode.h"


class BinaryTreePreorderTraversal {
public:
	BinaryTreePreorderTraversal();
	virtual ~BinaryTreePreorderTraversal();

	static void preorderTraversal_recursive(TreeNode *root);
	static void preorderTraversal_iterative(std::stack<TreeNode *> &s);

	static void execute();
};

#endif /* BINARYTREEPREORDERTRAVERSAL_H_ */
