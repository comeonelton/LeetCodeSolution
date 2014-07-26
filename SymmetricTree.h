/*
 * SymmetricTree.h
 *
 *  Created on: 2014/7/25
 *      Author: comeonelton
 */

#ifndef SYMMETRICTREE_H_
#define SYMMETRICTREE_H_

#include "DataStructure/TreeNode.h"

class SymmetricTree {
public:
	SymmetricTree();
	virtual ~SymmetricTree();

	static bool isSymmetric_iterative(TreeNode *root);
	static bool isSymmetric_recursive(TreeNode *root);
	static bool isCorrespondant(TreeNode *a, TreeNode *b);
	static void execute();
};

#endif /* SYMMETRICTREE_H_ */
