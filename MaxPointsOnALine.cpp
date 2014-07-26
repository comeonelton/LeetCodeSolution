/*
 * MaxPointsOnALine.cpp
 *
 *  Created on: 2014/3/20
 *      Author: comeonelton
 */

#include "MaxPointsOnALine.h"

using namespace std;

MaxPointsOnALine::MaxPointsOnALine() {
	// TODO Auto-generated constructor stub

}

MaxPointsOnALine::~MaxPointsOnALine() {
	// TODO Auto-generated destructor stub
}

void MaxPointsOnALine::printPoint(Point& p)
{
	cout << "(" << p.x << ", " << p.y << ") ";
}

bool MaxPointsOnALine::isSameLine(Point& a, Point& b, Point& c)
{
	// Pitfall: must calculate in float
	return (((float)(b.y-a.y) / (b.x-a.x)) == ((float)(c.y-a.y) / (c.x-a.x)));
}

// TODO: better algorithm in time complexity
int MaxPointsOnALine::maxPoints(vector<Point> &points)
{
	int max = 0;
	for (int i=0 ; i<points.size() ; i++) {
		for (int j=i+1 ; j<points.size() ; j++) {
			int count = 2;  // Pitfall: not '0'

			printPoint(points[i]);
			printPoint(points[j]);

			for (int k=j+1 ; k<points.size() ; k++) {
				if (isSameLine(points[i], points[j], points[k])) {
					count++;
					printPoint(points[k]);
				}
			}
			cout << endl;
			if (count > max)
				max = count;

			// Rest points are less than current max set.
			if (max > (points.size()-j-1))
				return max;

		}
	}
	return max;
}

void MaxPointsOnALine::execute()
{
	Point p[] = {Point(0, 0), Point(5, 5), Point(2, 4), Point(16, 8), Point(7, 14), Point(-3, -6), Point(-7, -7)};
	vector<Point> v(p, p+7);

	cout << "Max number of points on the same line: " << maxPoints(v) << endl;
}
