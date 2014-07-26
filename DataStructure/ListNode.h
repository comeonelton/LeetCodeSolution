/*
 * ListNode.h
 *
 *  Created on: 2014/3/23
 *      Author: comeonelton
 */

#ifndef LISTNODE_H_
#define LISTNODE_H_

#include <iostream>

class ListNode {
public:
    ListNode(int x);
	virtual ~ListNode();

    int val;
    ListNode *next;

    static ListNode* genList();
};

#endif /* LISTNODE_H_ */
