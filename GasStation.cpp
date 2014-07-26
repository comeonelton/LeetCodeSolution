/*
 * GasStation.cpp
 *
 *  Created on: 2014/5/26
 *      Author: comeonelton
 */

#include "GasStation.h"

#include <iostream>

using namespace std;

GasStation::GasStation() {
	// TODO Auto-generated constructor stub
}

GasStation::~GasStation() {
	// TODO Auto-generated destructor stub
}

int GasStation::canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
	for (int i=0 ; i<gas.size() ; i++) {
		bool canComplete = true;
		int gasInTank = 0;

		int j = i;
		do {
			cout << j << " ";

			gasInTank += gas[j];
			if (gasInTank > cost[j]) {
				gasInTank -= cost[j];
				j = (j+1) % gas.size();
			} else {
				canComplete = false;
				break;
			}

		} while (j != i);
		cout << endl;

		if (canComplete)
			return i;
	}

	return -1;
}

void GasStation::execute() {
	vector<int> gas;
	gas.push_back(4);
	gas.push_back(1);
	gas.push_back(3);
	gas.push_back(6);
	gas.push_back(1);

	vector<int> cost;
	cost.push_back(2);
	cost.push_back(4);
	cost.push_back(2);
	cost.push_back(2);
	cost.push_back(3);

	cout << "Expect 2, canCompleteCircute() = " << canCompleteCircuit(gas, cost) << endl;
}
