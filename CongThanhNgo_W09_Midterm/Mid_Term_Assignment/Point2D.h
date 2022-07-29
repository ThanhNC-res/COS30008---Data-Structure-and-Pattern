#pragma once 

#include "Vector2D.h" 

#include <iostream> 
#include <string> 

class Point2D
{
private:
	std::string fId; // point id 
	Vector2D fPosition; // position in 2D 
	const Point2D* fOrigin; // coordinate reference point, initially (0,0) 
	 // Direction (angle) of point w.r.t. aOther 
	double directionTo(const Point2D& aOther) const;

	// Length (or magnitude) of point w.r.t. aOther 
	double magnitudeTo(const Point2D& aOther) const;

public:
	// constructors 
	Point2D();
	Point2D(const std::string& aId, double aX, double aY);
	explicit Point2D(std::istream& aIStream);
	// getters & setters 
	const std::string& getId() const;
	void setX(const double& aX);
	const double getX() const;
	void setY(const double& aY);
	const double getY() const;
	void setOrigin(const Point2D& aPoint);
	const Point2D& getOrigin() const;

	// 2D vector this – aRHS 
	Vector2D operator-(const Point2D& aRHS) const;
	// Direction (angle) of point w.r.t. origin 
	double direction() const;

	// Length (or magnitude) of point w.r.t. origin 
	double magnitude() const;

	// Are this point and aOther on the same line segment? 
	bool isCollinear(const Point2D& aOther) const;

	// Does line segment this-aP2 make a right turn at this point? 
	bool isClockwise(const Point2D& aP0, const Point2D& aP2) const;

	// Is this' y-coordinate less than aRHS's y-coordinate? 
	// If there is a tie, this' x-coordinate less than aRHS's x-coordinate? 
	bool operator<(const Point2D& aRHS) const;
	// I/O for 2D points 
	friend std::ostream& operator<<(std::ostream& aOStream,
		const Point2D& aObject);
	friend std::istream& operator>>(std::istream& aIStream,
		Point2D& aObject);
};
