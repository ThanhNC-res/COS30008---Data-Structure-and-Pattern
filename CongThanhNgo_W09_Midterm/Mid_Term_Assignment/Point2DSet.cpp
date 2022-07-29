#include "Point2DSet.h"
#include <fstream>
#include <algorithm>

using namespace std;


static const double gEpsilon = 0.0001;
using Iterator = std::vector<Point2D>::const_iterator;

void Point2DSet::add(const Point2D& aPoint) {
	fPoints.push_back(aPoint);
}

void Point2DSet::add(Point2D&& aPoint) {
	fPoints.push_back(aPoint);
}

void Point2DSet::removeLast() {
	fPoints.pop_back();
}

bool Point2DSet::doesNotTurnLeft(const Point2D& aPoint) const {
	return aPoint.isClockwise(fPoints[size() - 2], fPoints[size() - 1]);
}

void Point2DSet::populate(const std::string& aFileName) {
	int lPointCount;
	Point2D lPoint2D;

	ifstream aInStream(aFileName, ifstream::in);
	aInStream >> lPointCount;
	for (int i = 0; i < lPointCount; i++)
	{
		aInStream >> lPoint2D;
		add(lPoint2D);
	}
}

bool orderByCoordinates(const Point2D& aLeft, const Point2D& aRight) {
	return aLeft < aRight;
}

bool orderByPolarAngle(const Point2D& aLHS, const Point2D& aRHS) {
	if (aLHS.isCollinear(aRHS)) {
		return aLHS.magnitude() - aRHS.magnitude() <= -gEpsilon;
	}

	return aLHS.direction() - aRHS.direction() <= -gEpsilon;
}

void Point2DSet::sort(Comparator aComparator) {
	stable_sort(fPoints.begin(), fPoints.end(), aComparator);
}

void Point2DSet::buildConvexHull(Point2DSet& aConvexHull) {
	//sort bt the coordinates 
	sort(orderByCoordinates);

	//Assign new value for new Origin
	for (Point2D& point2D : fPoints)
	{
		point2D.setOrigin(fPoints[0]);
	}

	//sort by polar angle
	sort(orderByPolarAngle);

	//add 3 first point 
	for (size_t i = 0; i < 3; i++)
	{
		aConvexHull.add(move(fPoints[i]));
	}

	//Graham Scan Iterator 
	for (size_t i = 3; i < size(); i++)
	{
		while (aConvexHull.doesNotTurnLeft(fPoints[i]))
			aConvexHull.removeLast();
		aConvexHull.add(move(fPoints[i]));
	}
}

size_t Point2DSet::size() const {
	return fPoints.size();
}

void Point2DSet::clear() {
	fPoints.clear();
}

const Point2D& Point2DSet::operator[](size_t aIndex) const {
	return fPoints[aIndex];
}

Iterator Point2DSet::begin() const {
	return fPoints.begin();
}

Iterator Point2DSet::end() const {
	return fPoints.end();
}