/*
 * UndirectedGraphNode.h
 *
 *  Created on: 2014/7/25
 *      Author: comeonelton
 */

#ifndef UNDIRECTEDGRAPHNODE_H_
#define UNDIRECTEDGRAPHNODE_H_

#include <vector>

class UndirectedGraphNode {
public:
	UndirectedGraphNode();
    UndirectedGraphNode(int x) : label(x) {};
	virtual ~UndirectedGraphNode();

	void traverse();

    int label;
    std::vector<UndirectedGraphNode *> neighbors;
};

#endif /* UNDIRECTEDGRAPHNODE_H_ */
