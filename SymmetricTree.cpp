/*
 * SymmetricTree.cpp
 *
 *  Created on: 2014/7/25
 *      Author: comeonelton
 */

#include "SymmetricTree.h"
#include <queue>

using namespace std;

SymmetricTree::SymmetricTree() {
	// TODO Auto-generated constructor stub

}

SymmetricTree::~SymmetricTree() {
	// TODO Auto-generated destructor stub
}

bool SymmetricTree::isSymmetric_iterative(TreeNode *root) {
	if (root == NULL)
		return false; // TODO: or true?

	queue<TreeNode *> q1, q2;
	q1.push(root->left);
	q2.push(root->right);

	while (1) {
		if (q1.empty() && q2.empty())
			break;
		if (q1.empty() ^ q2.empty())  // TODO: xor ok?
			return false;

		TreeNode *n1 = q1.front();
		q1.pop();

		TreeNode *n2 = q2.front();
		q2.pop();

		if (n1 == NULL && n2 == NULL) {
			continue;
		} else if (n1 != NULL && n2 != NULL) {
			if (n1->val != n2->val)
				return false;

			q1.push(n1->left);
			q1.push(n1->right);

			// Reverse order!
			q2.push(n2->right);
			q2.push(n2->left);
		} else {
			return false;
		}
	}
	return true;
}

bool SymmetricTree::isSymmetric_recursive(TreeNode *root) {
	if (root == NULL)
		return false; // TODO: or true?

	return isCorrespondant(root->left, root->right);
}

bool SymmetricTree::isCorrespondant(TreeNode *a, TreeNode *b) {
	if (a == NULL && b == NULL)
		return true;

	if (a == NULL && b != NULL || a != NULL && b == NULL)
		return false;

	if (a->val != b->val)
		return false;
	else
		return isCorrespondant(a->left, b->right) && isCorrespondant(a->right, b->left);
}

void SymmetricTree::execute() {
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(2);
    TreeNode n4(3);
    TreeNode n5(4);
    TreeNode n6(4);
    TreeNode n7(3);
    n1.left = &n2; n1.right = &n3;
    n2.left = &n4;
    n3.right = &n7;
    //n2.left = &n4; n2.right = &n5;
    //n3.left = &n6; n3.right = &n7;

    cout << "Expect 1, result = " << SymmetricTree::isSymmetric_recursive(&n1) << endl;
    cout << "Expect 0, result = " << SymmetricTree::isSymmetric_recursive(&n2) << endl;
    cout << "Expect 1, result = " << SymmetricTree::isSymmetric_iterative(&n1) << endl;
    cout << "Expect 0, result = " << SymmetricTree::isSymmetric_iterative(&n2) << endl;
}
