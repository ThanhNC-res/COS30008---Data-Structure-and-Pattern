#pragma  once 
#include "Point2D.h" 
#include <vector> 
#include <iostream> 

class Point2DSet
{
private:

	using PointVector = std::vector<Point2D>;
	PointVector fPoints;
public:

	using Iterator = std::vector<Point2D>::const_iterator;
	using Comparator = bool (*)(const Point2D&, const Point2D&);

	// Add a 2D point to set 
	void add(const Point2D& aPoint);
	void add(Point2D&& aPoint);

	// Remove the last point in the set 
	void removeLast();
	// Tests aPoint, returns true if aPoint makes no left turn 
	bool doesNotTurnLeft(const Point2D& aPoint) const;

	// Load 2D points from file 
	void populate(const std::string& aFileName);

	// Run Graham's scan using out parameter aConvexHull 
	void buildConvexHull(Point2DSet& aConvexHull);

	// Returns numner of elements in set 
	size_t size() const;

	// Clears set 
	void clear();

	// Sort set using stable_sort on vectors 
	void sort(Comparator aComparator);

	// Indexer for set 
	const Point2D& operator[](size_t aIndex) const;
	// Iterator methods 
	Iterator begin() const;
	Iterator end() const;
};