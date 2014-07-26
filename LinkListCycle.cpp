/*
 * LinkListCycle.cpp
 *
 *  Created on: 2014/5/15
 *      Author: comeonelton
 */

#include "LinkListCycle.h"
#include <iostream>
#include <vector>

using namespace std;

LinkListCycle::LinkListCycle() {
	// TODO Auto-generated constructor stub

}

LinkListCycle::~LinkListCycle() {
	// TODO Auto-generated destructor stub
}

// TODO: very slow and take extra space
bool LinkListCycle::hasCycle(ListNode *head) {
	vector<ListNode *> v;

	ListNode *p = head;
	while (p) {
		for (int i=0 ; i<v.size() ; i++) {
			if (p == v[i])
				return true;
		}
		v.push_back(p);

		p = p->next;
	}

	return false;
}

bool LinkListCycle::hasCycle_noExtraSpace(ListNode *head) {
	ListNode *p = head, *q = head;
	do {
		if (p == NULL || q == NULL)
			return false;

		p = p->next;  // advance one node
		if (q->next)
			q = q->next->next;  // advance two node
		else
			return false;
	} while (p != q);

	return true;
}

void LinkListCycle::execute() {
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	ListNode n6(6);
	ListNode n7(7);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n3;  // cycle

	cout << "Exepct 1, hasCycle() =  " << hasCycle(&n1) << ", hasCycle_noExtraSpace() = " << hasCycle_noExtraSpace(&n1) << endl;

	ListNode nn1(1);
	ListNode nn2(2);
	ListNode nn3(3);
	ListNode nn4(4);
	ListNode nn5(5);
	ListNode nn6(6);
	ListNode nn7(7);
	nn1.next = &nn2;
	nn2.next = &nn3;
	nn3.next = &nn4;
	nn4.next = &nn5;
	nn5.next = &nn6;
	nn6.next = &nn7;  // no cycle

	cout << "Exepct 0, hasCycle() =  " << hasCycle(&nn1) << ", hasCycle_noExtraSpace() = " << hasCycle_noExtraSpace(&nn1) << endl;
}
