/*
 * BinaryTreePostorderTraversal.cpp
 *
 *  Created on: 2014/3/23
 *      Author: comeonelton
 */

#include "BinaryTreePostorderTraversal.h"

using namespace std;

BinaryTreePostorderTraversal::BinaryTreePostorderTraversal() {
	// TODO Auto-generated constructor stub

}

BinaryTreePostorderTraversal::~BinaryTreePostorderTraversal() {
	// TODO Auto-generated destructor stub
}

vector<int>& BinaryTreePostorderTraversal::postorderTraversal_recursive(TreeNode *root) {
	static vector<int> v;  //TODO: better solution than return static vector?

	if (root == NULL)
		return v;

	postorderTraversal_recursive(root->left);
	postorderTraversal_recursive(root->right);

	v.push_back(root->val);
}

stack<int>& BinaryTreePostorderTraversal::postorderTraversal_iterative(stack<TreeNode *>& s) {
	static stack<int> result;

	while (!s.empty()) {
		TreeNode* p = s.top();
		s.pop();

		// Pitfall: push order! think! right subtree will be poped first!!!
		if (p->left != NULL)
			s.push(p->left);

		if (p->right != NULL)
			s.push(p->right);

		result.push(p->val);
	}

	return result;
}

void BinaryTreePostorderTraversal::execute() {
	//TreeNode* root = TreeNode::genTree();

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

	vector<int> result1 = postorderTraversal_recursive(&v1);
	for (int i = 0; i < result1.size(); i++) {
		cout << result1[i] << " ";
	}
	cout << endl;

	stack<TreeNode *> s;
	s.push(&v1);
	stack<int> result2 = postorderTraversal_iterative(s);
	while (!result2.empty()) {
		cout << result2.top() << " ";
		result2.pop();
	}
	cout << endl;
}
