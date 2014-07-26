/*
 * CloneGraph.cpp
 *
 *  Created on: 2014/5/26
 *      Author: comeonelton
 */

#include "CloneGraph.h"
#include <iostream>
#include <map>
#include <queue>
#include <unordered_set>

using namespace std;

CloneGraph::CloneGraph() {
	// TODO Auto-generated constructor stub

}

CloneGraph::~CloneGraph() {
	// TODO Auto-generated destructor stub
}

UndirectedGraphNode* CloneGraph::cloneGraph(UndirectedGraphNode *node) {
	UndirectedGraphNode *cloneHead = NULL;
	map<UndirectedGraphNode*, UndirectedGraphNode*> map;
	queue<UndirectedGraphNode*> queue;  // Use queue to implement BFS

	if (node == NULL)
		return NULL;

	// Stage 1: clone all nodes and create mapping from origin node to cloned one
	queue.push(node);
	while (!queue.empty()) {
		UndirectedGraphNode* p = queue.front();
		queue.pop();

		UndirectedGraphNode* q = new UndirectedGraphNode(p->label);
		map.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(p, q));
		if (cloneHead == NULL)
			cloneHead = q;

		for (int i=0 ; i<p->neighbors.size() ; i++) {
			UndirectedGraphNode *neighbor = p->neighbors[i];
			if (map.find(neighbor) == map.end()) {
				// This check will eliminate the self-loop problem.
				UndirectedGraphNode* clonedNeighbor = new UndirectedGraphNode(neighbor->label);
				map.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(neighbor, clonedNeighbor));

				queue.push(neighbor);
			}
		}
	}

	// Stage 2: link cloned nodes according to the mapping created from stage 1
	unordered_set<UndirectedGraphNode *> processed;
	queue.push(node);
	while (!queue.empty()) {
		UndirectedGraphNode* p = queue.front();
		queue.pop();
		processed.insert(p);

		UndirectedGraphNode* q = map.find(p)->second;

		for (int i=0 ; i<p->neighbors.size() ; i++) {
			UndirectedGraphNode *neighbor = p->neighbors[i];
			if (processed.find(neighbor) == processed.end()) {
				// This check will eliminate the self-loop problem.
				processed.insert(neighbor);
				queue.push(neighbor);
			}

			// Link between two nodes
			q->neighbors.push_back(map.find(neighbor)->second);
		}
	}

	return cloneHead;
}

void CloneGraph::execute() {
	UndirectedGraphNode n1(1);
	UndirectedGraphNode n2(2);
	UndirectedGraphNode n3(3);
	UndirectedGraphNode n4(4);
	UndirectedGraphNode n5(5);
	UndirectedGraphNode n6(6);
	UndirectedGraphNode n7(7);
	UndirectedGraphNode n8(8);
	UndirectedGraphNode n9(9);
	UndirectedGraphNode n10(10);
	UndirectedGraphNode n11(11);
	UndirectedGraphNode n12(12);
	UndirectedGraphNode n13(13);

	n1.neighbors.push_back(&n7); n1.neighbors.push_back(&n13); n1.neighbors.push_back(&n5);
	n2.neighbors.push_back(&n13); n2.neighbors.push_back(&n9); n2.neighbors.push_back(&n2);
	n3.neighbors.push_back(&n8); n3.neighbors.push_back(&n10); n3.neighbors.push_back(&n6);
	n4.neighbors.push_back(&n11);
	n5.neighbors.push_back(&n1); n5.neighbors.push_back(&n13); n5.neighbors.push_back(&n12);
	n6.neighbors.push_back(&n7); n6.neighbors.push_back(&n13); n6.neighbors.push_back(&n3);
	n7.neighbors.push_back(&n1); n7.neighbors.push_back(&n6);
	n8.neighbors.push_back(&n3); n8.neighbors.push_back(&n13); n8.neighbors.push_back(&n11);
	n9.neighbors.push_back(&n2);
	n10.neighbors.push_back(&n3); n10.neighbors.push_back(&n12);
	n11.neighbors.push_back(&n4); n11.neighbors.push_back(&n8);
	n12.neighbors.push_back(&n5); n12.neighbors.push_back(&n10);
	n13.neighbors.push_back(&n2); n13.neighbors.push_back(&n1); n13.neighbors.push_back(&n5); n13.neighbors.push_back(&n6); n13.neighbors.push_back(&n8);

	UndirectedGraphNode *cloned = CloneGraph::cloneGraph(&n1);

	n1.traverse();
	cout << endl;
	cloned->traverse();
}
