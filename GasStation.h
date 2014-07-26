/*
 * GasStation.h
 *
 *  Created on: 2014/5/26
 *      Author: comeonelton
 */

#ifndef GASSTATION_H_
#define GASSTATION_H_

#include <vector>

class GasStation {
public:
	GasStation();
	virtual ~GasStation();

	static int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost);
	static void execute();
};

#endif /* GASSTATION_H_ */
