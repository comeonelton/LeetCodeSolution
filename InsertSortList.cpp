/*
 * InsertSortList.cpp
 *
 *  Created on: 2014/3/20
 *      Author: comeonelton
 */

#include "InsertSortList.h"

#include <iostream>
#include <stdlib.h>

#include "../tools.h"

using namespace std;

bool InsertSortList::debug = false;

InsertSortList::InsertSortList() {
	// TODO Auto-generated constructor stub

}

InsertSortList::~InsertSortList() {
	// TODO Auto-generated destructor stub
}

ListNode* InsertSortList::insertionSortList(ListNode *head)
{
	ListNode *p = NULL, *q = NULL, *ppre = NULL, *pnext = NULL, *qpre = NULL;
	if (head->next) {
		ppre = head;
		p = head->next;  // Begin from 2nd node
	} else {
		return head;
	}

	while (p != NULL) {
		pnext = p->next;
		qpre = NULL;
		q = head;

		while (q != p && q->val < p->val) {
			qpre = q;
			q = q->next;
		}
		if (q != p) {
			// Insert p into front of q
			ppre->next = p->next;
			p->next = q;
			if (qpre) {
				qpre->next = p;
			} else {
				head = p;
			}
			//printList(head);
		} else {
			ppre = p;  // Pitfall: in 'if' case(ie. insert p into front of q), ppre won't advance!
		}

		p = pnext;
	}

	return head;
}

ListNode* InsertSortList::newIntList()
{
	ListNode* head = new ListNode(rand() % 9999);
	ListNode* p = head;
	int count = rand() % 9999;
	while (1) {
		if (count--) {
			p->next = new ListNode(rand() % 9999);
			p = p->next;
		} else
			break;
	}

	return head;
}

void InsertSortList::deleteIntList(ListNode* head)
{
	ListNode* next = NULL;
	while (head) {
		next = head->next;
		delete head;
		head = next;
	}
}

bool InsertSortList::isListSorted(ListNode* head)
{
	while (head) {
		if (head->next && head->val > head->next->val)
			return false;
		head = head->next;
	}
	return true;
}

void InsertSortList::printList(ListNode* head)
{
	while (head) {
		cout << head->val;
		if (debug) {
			if (head->next)
				cout << "->" << head->next->val << " ";
			else
				cout << "->NULL ";
		} else {
			cout << " ";
		}
		head = head->next;
	}
	cout << endl;
}

void InsertSortList::execute()
{
	ListNode n1(5);
	ListNode n2(1);
	ListNode n3(3);
	ListNode n4(2);
	ListNode* sorted;
	n1.next = &n2; n2.next = &n3; n3.next = &n4, n4.next = NULL;

	printList(&n1);
	sorted = insertionSortList(&n1);
	printList(sorted);

	ListNode n5(4);
	ListNode n6(5);
	ListNode n7(6);
	ListNode n8(7);
	n5.next = &n6; n6.next = &n7; n7.next = &n8, n8.next = NULL;

	printList(&n5);
	sorted = insertionSortList(&n5);
	printList(sorted);

	random_init();
	bool success = true;
	for (int i=0 ; i<9999 ; i++) {
		cout << '\r' << i << flush;
		ListNode* l = newIntList();
		//cout << "unsorted: ";  printList(l);
		sorted = insertionSortList(l);
		//cout << "sorted:   ";  printList(sorted);
		if (!isListSorted(sorted)) {
			success = false;
			break;
		}
		deleteIntList(sorted);
	}
	cout << (success ? "\n[O] InsertSortList success" : "\n[X] InsertSortList failed") << endl;
}
