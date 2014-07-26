/*
 * TreeNode.h
 *
 *  Created on: 2014/3/23
 *      Author: comeonelton
 */

#ifndef TREENODE_H_
#define TREENODE_H_

#include <iostream>

class TreeNode {
public:
    TreeNode(int x);
	virtual ~TreeNode();

    int val;
    TreeNode *left;
    TreeNode *right;

    static TreeNode* genTree();
};

#endif /* TREENODE_H_ */
