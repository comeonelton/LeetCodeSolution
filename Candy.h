/*
 * Candy.h
 *
 *  Created on: 2014/5/19
 *      Author: comeonelton
 */

#ifndef CANDY_H_
#define CANDY_H_

#include <vector>

class Candy {
public:
	Candy();
	virtual ~Candy();

	static int candy(std::vector<int> &ratings);
	static void execute();
};

#endif /* CANDY_H_ */
