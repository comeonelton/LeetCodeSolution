/*
 * CopyListWithRandomPointer.cpp
 *
 *  Created on: 2014/5/19
 *      Author: comeonelton
 */

#include "CopyListWithRandomPointer.h"

#include <iostream>
#include <map>

using namespace std;

CopyListWithRandomPointer::CopyListWithRandomPointer() {
	// TODO Auto-generated constructor stub

}

CopyListWithRandomPointer::~CopyListWithRandomPointer() {
	// TODO Auto-generated destructor stub
}

RandomListNode *CopyListWithRandomPointer::copyRandomList(RandomListNode *head) {
	RandomListNode *p;
	RandomListNode *head2 = NULL;
	RandomListNode *prev = NULL;

	map<RandomListNode *, RandomListNode *> linkMap;

	p = head;
	while (p) {
		RandomListNode *n = new RandomListNode(p->label);
		n->random = p->random;

		linkMap.insert(pair<RandomListNode*, RandomListNode*>(p, n));

		if (head2 == NULL)
			head2 = n;
		else
			prev->next = n;

		prev = n;

		p = p->next;
	}

	p = head2;
	while (p) {
		p->random = (p->random) ? linkMap.find(p->random)->second : NULL;
		p = p->next;
	}

	return head2;
}

void CopyListWithRandomPointer::execute() {
	RandomListNode n1(1);
	RandomListNode n2(2);
	RandomListNode n3(3);
	RandomListNode n4(4);
	RandomListNode n5(5);
	RandomListNode n6(6);
	RandomListNode n7(7);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n1.random = &n7;
	n2.random = &n3;
	n3.random = &n5;
	n4.random = NULL;
	n5.random = &n1;
	n6.random = &n2;
	n7.random = &n3;

	RandomListNode *p = &n1;
	while (p) {
		cout << p->label << ", ";
		if (p->random)
			cout << p->random->label;
		else
			cout << "NULL";
		cout << endl;
		p = p->next;
	}
	cout << endl;

	p = copyRandomList(&n1);
	while (p) {
		cout << p->label << ", ";
		if (p->random)
			cout << p->random->label;
		else
			cout << "NULL";
		cout << endl;
		p = p->next;
	}
}
