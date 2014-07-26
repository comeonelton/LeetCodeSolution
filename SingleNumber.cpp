/*
 * SingleNumber.cpp
 *
 *  Created on: 2014/5/19
 *      Author: comeonelton
 */

#include "SingleNumber.h"
#include <iostream>

using namespace std;

SingleNumber::SingleNumber() {
	// TODO Auto-generated constructor stub

}

SingleNumber::~SingleNumber() {
	// TODO Auto-generated destructor stub
}


int SingleNumber::singleNumber(int A[], int n) {
	int ret = 0;
	for (int i=0 ; i<n ; i++)
		ret ^= A[i];

	return ret;
}

void SingleNumber::execute() {
	int A[7] = {1, 4, 2, 1, 2, 3, 4};
	cout << singleNumber(A, sizeof(A)/sizeof(int)) << endl;
}
