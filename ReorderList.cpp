/*
 * ReorderList.cpp
 *
 *  Created on: 2014/5/14
 *      Author: comeonelton
 */

#include "ReorderList.h"

using namespace std;

ReorderList::ReorderList() {
	// TODO Auto-generated constructor stub

}

ReorderList::~ReorderList() {
	// TODO Auto-generated destructor stub
}

void ReorderList::reorderList(ListNode *head) {
	int count = 0;
	ListNode *p = NULL, *head2 = NULL;

	// Traversal list and count it
	p = head;
	while (p) {
		count++;
		p = p->next;
	}

	count = (count%2) ? count/2 + 1 : count/2;

	// Break the list into two half
	// and reverse the second half
	p = head;
	while (p) {
		if (count > 0) {
			if (count == 1) {
				ListNode *prev = p;
				p = p->next;
				prev->next = NULL;  // make first-half list
			} else {
				p = p->next;
			}

			count--;
		} else {  // count == 0
			// Reverse link, p-->n to p<--n
			if (p->next) {
				ListNode *pnext = p->next;
				ListNode *pnextnext = p->next->next;
				p->next->next = p;
				p->next = head2;

				head2 = pnext;

				p = pnextnext;
			} else {
				p->next = head2;
				head2 = p;
				p = NULL;
			}
		}
	}

	// Combine two list interleavingly
	p = head;
	ListNode *q = head2;
	while (p && q) {
		ListNode *pnext = p->next;
		ListNode *qnext = q->next;
		p->next = q;
		if (pnext)
			q->next = pnext;

		p = pnext;
		q = qnext;
	}
}

void ReorderList::execute() {
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	ListNode n6(6);
	ListNode n7(7);
	ListNode n8(8);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n8;

	reorderList(&n1);

	ListNode* p = &n1;
	while (p) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
