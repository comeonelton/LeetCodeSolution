/*
 * LinkListCycle.h
 *
 *  Created on: 2014/5/15
 *      Author: comeonelton
 */

#ifndef LINKLISTCYCLE_H_
#define LINKLISTCYCLE_H_

#include "DataStructure/ListNode.h"

class LinkListCycle {
public:
	LinkListCycle();
	virtual ~LinkListCycle();


	static bool hasCycle(ListNode *head);
	static bool hasCycle_noExtraSpace(ListNode *head);
	static void execute();
};

#endif /* LINKLISTCYCLE_H_ */
