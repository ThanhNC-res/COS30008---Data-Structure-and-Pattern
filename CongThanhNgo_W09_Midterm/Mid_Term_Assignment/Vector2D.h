#pragma once 
#include <iostream> 
class Vector2D
{
private:
	double fX; // x coordinate 
	double fY; // y coordinate 
public:
	// 2D vector constructor; default is unit vector î 
	Vector2D(double aX = 1.0, double aY = 0.0);

	// getters & setters for x and y coordinates 
	void setX(double aX);
	double getX() const;
	void setY(double aY);
	double getY() const;

	// 2D vector addition: this + aRHS; returns a fresh 2D vector 
	Vector2D operator+(const Vector2D& aRHS) const;

	// 2D vector subtraction: this - aRHS; returns a fresh 2D vector 
	Vector2D operator-(const Vector2D& aRHS) const;

	// Length (or magnitude) of a 2D vector 
	double magnitude() const;

	// Direction (angle) of 2D vector 
	// The angle is the tangent of y divided by x (hint: atan2) 
	double direction() const;
	// Inner product (scalar product) of two 2D vectors 
   // Does not require angle between vectors 
	double dot(const Vector2D& aRHS) const;

	// In 2D, the cross product of two 2D vectors is 
	// the determinate of the matrix 
	// 
	// | x1 x2 | 
	// det | | = x1*y2 - x2*y1 
	// | y1 y2 | 
	// 
	double cross(const Vector2D& aRHS) const;

	// Angle between two 2D vectors 
	// The function must properly handle null vectors = [0,0] 
	// and return an angle consistent with the dot product. 
	double angleBetween(const Vector2D& aRHS) const;
	// I/O for 2D vectors 
	friend std::ostream& operator<<(std::ostream& aOutStream,
		const Vector2D& aObject);
	friend std::istream& operator>>(std::istream& aInStream,
		Vector2D& aObject);
};
