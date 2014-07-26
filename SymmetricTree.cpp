/*
 * SymmetricTree.cpp
 *
 *  Created on: 2014/7/25
 *      Author: comeonelton
 */

#include "SymmetricTree.h"

using namespace std;

SymmetricTree::SymmetricTree() {
	// TODO Auto-generated constructor stub

}

SymmetricTree::~SymmetricTree() {
	// TODO Auto-generated destructor stub
}

bool SymmetricTree::isSymmetric(TreeNode *root) {
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
    n2.left = &n4; n2.right = &n5;
    n3.left = &n6; n3.right = &n7;

    cout << SymmetricTree::isSymmetric(&n1) << endl;
    cout << SymmetricTree::isSymmetric(&n2) << endl;
}
