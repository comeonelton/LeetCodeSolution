/*
 * Candy.cpp
 *
 *  Created on: 2014/5/19
 *      Author: comeonelton
 */

#include "Candy.h"
#include <iostream>

using namespace std;

Candy::Candy() {
	// TODO Auto-generated constructor stub

}

Candy::~Candy() {
	// TODO Auto-generated destructor stub
}

int Candy::candy(vector<int> &ratings) {
	int minimum = 1;
	int prev = 1;

	for (int i=1 ; i<ratings.size() ; i++) {
		if (ratings[i-1] < ratings[i]) {
			// This child gets 'one more' candy than previous child.
			prev++;
			minimum += prev;
			cout << "(" << i << ", " << prev << ")" << endl;
		} else if (ratings[i-1] > ratings[i]) {
			minimum++;  // Every child gets 'at least one' candy.

			if (prev == 1) {
				// This child gets 1 candy.
				// Previous child(with higher rating) need to get more than 1 candy.
				// To propagate to all left children.
				int j = i;
				cout << "[";
				while (j > 0 && ratings[j-1] > ratings[j]) {
					cout << j-1 << " ";
					minimum++;
					j--;
				}
				cout << "]" << endl;
			}
			prev = 1;
		} else {
			cout << "(" << i << ", 1)" << endl;
			// If two adjacent ratings are equal, we give only 'one' candy to next child.
			minimum++;
			prev = 1;
		}
	}

	return minimum;
}

void Candy::execute() {
	vector<int> ratings;
	ratings.push_back(2);
	ratings.push_back(7);
	ratings.push_back(6);
	ratings.push_back(5);
	ratings.push_back(5);
	ratings.push_back(4);
	ratings.push_back(4);
	ratings.push_back(3);
	ratings.push_back(1);

	cout << candy(ratings) << endl;
}
