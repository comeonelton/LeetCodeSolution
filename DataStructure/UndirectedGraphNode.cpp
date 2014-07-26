/*
 * UndirectedGraphNode.cpp
 *
 *  Created on: 2014/7/25
 *      Author: comeonelton
 */

#include "UndirectedGraphNode.h"
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

UndirectedGraphNode::UndirectedGraphNode() {
	// TODO Auto-generated constructor stub

}

UndirectedGraphNode::~UndirectedGraphNode() {
	// TODO Auto-generated destructor stub
}

void UndirectedGraphNode::traverse() {
	queue<UndirectedGraphNode *> queue;
	unordered_set<UndirectedGraphNode *> set;

	queue.push(this);

	while (!queue.empty()) {
		UndirectedGraphNode *n = queue.front();
		queue.pop();

		if (set.find(n) == set.end()) {
			set.insert(n);

			cout << n->label << " : ";
			for (int i=0 ; i<n->neighbors.size() ; i++) {
				UndirectedGraphNode *neighbor = n->neighbors[i];
				cout << neighbor->label << ", ";

				if (neighbor != n) {
					// Exclude self-loop
					queue.push(neighbor);
				}
			}
			cout << endl;
		} else {
			// Already processed, skip this node
		}
	}

	cout << endl;
}
