/*
 * BinaryTreePreorderTraversal.cpp
 *
 *  Created on: 2014/3/23
 *      Author: comeonelton
 */

#include "BinaryTreePreorderTraversal.h"

using namespace std;

BinaryTreePreorderTraversal::BinaryTreePreorderTraversal() {
	// TODO Auto-generated constructor stub

}

BinaryTreePreorderTraversal::~BinaryTreePreorderTraversal() {
	// TODO Auto-generated destructor stub
}

void BinaryTreePreorderTraversal::preorderTraversal_recursive(TreeNode *root) {
	if (root == NULL)
		return;

	cout << root->val << " ";

	preorderTraversal_recursive(root->left);
	preorderTraversal_recursive(root->right);
}

void BinaryTreePreorderTraversal::preorderTraversal_iterative(stack<TreeNode *>& s) {

	while (!s.empty()) {
		TreeNode* p = s.top();
		s.pop();

		cout << p->val << " ";

		// Pitfall: stack[left subtree, right subtree], so push right first
		if (p->right != NULL)
			s.push(p->right);

		if (p->left != NULL)
			s.push(p->left);
	}

	return;
}

void BinaryTreePreorderTraversal::execute() {
	//      1
	//    /   \
	//   2     3
	//   /\    /\
	//  4  5  6  7
	//    /    \
	//   8      9
	TreeNode v1(1);
	TreeNode v2(2);
	TreeNode v3(3);
	TreeNode v4(4);
	TreeNode v5(5);
	TreeNode v6(6);
	TreeNode v7(7);
	TreeNode v8(8);
	TreeNode v9(9);
	v1.left = &v2;
	v1.right = &v3;
	v2.left = &v4;
	v2.right = &v5;
	v3.left = &v6;
	v3.right = &v7;
	v5.left = &v8;
	v6.right = &v9;

	preorderTraversal_recursive(&v1);
	cout << endl;

	stack<TreeNode *> s;
	s.push(&v1);
	preorderTraversal_iterative(s);
	cout << endl;
}
