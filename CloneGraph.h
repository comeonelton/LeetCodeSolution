/*
 * CloneGraph.h
 *
 *  Created on: 2014/5/26
 *      Author: comeonelton
 */

#ifndef CLONEGRAPH_H_
#define CLONEGRAPH_H_

#include "DataStructure/UndirectedGraphNode.h"

class CloneGraph {
public:
	CloneGraph();
	virtual ~CloneGraph();

	static UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
	static void execute();
};

#endif /* CLONEGRAPH_H_ */
