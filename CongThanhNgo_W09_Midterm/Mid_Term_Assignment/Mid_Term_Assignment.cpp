#include <iostream> 
#include "Point2DSet.h" 
using namespace std;
int main()
{
	Point2DSet lSet;
	lSet.populate("points.txt");
	cout << "Points:" << endl;
	for (const Point2D& p : lSet)
	{
		cout << p << endl;
	}
	Point2DSet lConvexHull;
	lSet.buildConvexHull(lConvexHull);
	cout << "Convex hull:" << endl;
	size_t lSize = lConvexHull.size();
	for (size_t i = 0; i < lSize; i++)
	{
		cout << lConvexHull[i].getId()
			<< " - "
			<< lConvexHull[(i + 1) % lSize].getId() << endl;
	}

	return 0;
}