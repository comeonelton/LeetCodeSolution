/*
 * CopyListWithRandomPointer.h
 *
 *  Created on: 2014/5/19
 *      Author: comeonelton
 */

#ifndef COPYLISTWITHRANDOMPOINTER_H_
#define COPYLISTWITHRANDOMPOINTER_H_

#include <cstddef>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class CopyListWithRandomPointer {
public:
	CopyListWithRandomPointer();
	virtual ~CopyListWithRandomPointer();

	static RandomListNode *copyRandomList(RandomListNode *head);
	static void execute();
};

#endif /* COPYLISTWITHRANDOMPOINTER_H_ */
