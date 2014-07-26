/*
 * InsertSortList.h
 *
 *  Created on: 2014/3/20
 *      Author: comeonelton
 */

#ifndef INSERTSORTLIST_H_
#define INSERTSORTLIST_H_

#include <iostream>

#include "DataStructure/ListNode.h"

class InsertSortList {
public:
	InsertSortList();
	virtual ~InsertSortList();

	static void execute();

private:
	static ListNode* newIntList();
	static void deleteIntList(ListNode* head);
	static bool isListSorted(ListNode* head);
	static void printList(ListNode* head);
	static ListNode* insertionSortList(ListNode *head);

	static bool debug;
};

#endif /* INSERTSORTLIST_H_ */
