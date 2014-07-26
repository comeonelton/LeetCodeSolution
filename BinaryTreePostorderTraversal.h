/*
 * BinaryTreePostorderTraversal.h
 *
 *  Created on: 2014/3/23
 *      Author: comeonelton
 */

#ifndef BINARYTREEPOSTORDERTRAVERSAL_H_
#define BINARYTREEPOSTORDERTRAVERSAL_H_

#include <iostream>
#include <vector>
#include <stack>

#include "DataStructure/TreeNode.h"


class BinaryTreePostorderTraversal {
public:
	BinaryTreePostorderTraversal();
	virtual ~BinaryTreePostorderTraversal();

	static std::vector<int>& postorderTraversal_recursive(TreeNode *root);
	static std::stack<int>& postorderTraversal_iterative(std::stack<TreeNode *> &s);

	static void execute();
};

#endif /* BINARYTREEPOSTORDERTRAVERSAL_H_ */
