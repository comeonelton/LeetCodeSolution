/*
 * BinaryTreeInorderTraversal.cpp
 *
 *  Created on: 2014/3/23
 *      Author: comeonelton
 */

#include "BinaryTreeInorderTraversal.h"

using namespace std;

BinaryTreeInorderTraversal::BinaryTreeInorderTraversal() {
	// TODO Auto-generated constructor stub

}

BinaryTreeInorderTraversal::~BinaryTreeInorderTraversal() {
	// TODO Auto-generated destructor stub
}

void BinaryTreeInorderTraversal::inorderTraversal_recursive(TreeNode *root) {
	if (root == NULL)
		return;

	inorderTraversal_recursive(root->left);
	cout << root->val << " ";
	inorderTraversal_recursive(root->right);
}

void BinaryTreeInorderTraversal::inorderTraversal_iterative(stack<TreeNode *>& s) {

	while (!s.empty()) {
		TreeNode* p = s.top();
		s.pop();

		if (p->val < 0) {
			// This node is already processed, restore to origin value and output
			p->val = -(p->val);
			cout << p->val << " ";
			continue;
		}

		// Pitfall: stack[left subtree, right subtree], so push right-subtree first
		if (p->right != NULL)
			s.push(p->right);

		if (p->left == NULL) {
			cout << p->val << " ";
		} else {
			p->val = -(p->val);  // Trick: negative value indicate "processed"

			s.push(p);  // Push only when left subtree exist

			s.push(p->left);
		}
	}

	return;
}

void BinaryTreeInorderTraversal::execute() {
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

	inorderTraversal_recursive(&v1);
	cout << endl;

	stack<TreeNode *> s;
	s.push(&v1);
	inorderTraversal_iterative(s);
	cout << endl;
}
