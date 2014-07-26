/*
 * MaxPointsOnALine.h
 *
 *  Created on: 2014/3/20
 *      Author: comeonelton
 */

#ifndef MAXPOINTSONALINE_H_
#define MAXPOINTSONALINE_H_

#include <iostream>
#include <vector>

struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
 };

class MaxPointsOnALine {
public:
	MaxPointsOnALine();
	virtual ~MaxPointsOnALine();

	static int maxPoints(std::vector<Point> &points);
	static void execute();

private:
	static bool isSameLine(Point& a, Point& b, Point& c);
	static void printPoint(Point& p);
};

#endif /* MAXPOINTSONALINE_H_ */
