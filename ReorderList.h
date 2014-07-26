/*
 * ReorderList.h
 *
 *  Created on: 2014/5/14
 *      Author: comeonelton
 */

#ifndef REORDERLIST_H_
#define REORDERLIST_H_

#include <iostream>

#include "DataStructure/ListNode.h"

class ReorderList {
public:
	ReorderList();
	virtual ~ReorderList();

	static void reorderList(ListNode *head);
	static void execute();
};

#endif /* REORDERLIST_H_ */
