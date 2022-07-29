#include "Vector2D.h"
#include <math.h>

using namespace std;

Vector2D::Vector2D(double aX, double aY) : fX(aX), fY(aY) {

}

void Vector2D::setX(double aX) {
	fX = aX;
}

double Vector2D::getX() const {
	return fX;
}
void Vector2D::setY(double aY) {
	fY = aY;
}
double Vector2D::getY() const {
	return fY;
}

Vector2D Vector2D::operator+(const Vector2D& aRHS) const {
	Vector2D temp = *this;
	return  Vector2D(temp.fX + aRHS.fX, temp.fY + aRHS.fY);
}

Vector2D Vector2D::operator-(const Vector2D& aRHS) const {
	Vector2D temp = *this;
	return  Vector2D(temp.fX - aRHS.fX, temp.fY - aRHS.fY);
}

double Vector2D::magnitude() const {
	return sqrt(pow(fX, 2) + pow(fY, 2));
}

double Vector2D::direction() const {
	return atan(fY / fX);
}

double Vector2D::dot(const Vector2D& aRHS) const {
	Vector2D temp = *this;
	return  temp.fX*aRHS.fX + temp.fY*aRHS.fY;
}

double Vector2D::cross(const Vector2D& aRHS) const {
	Vector2D temp = *this;
	return  temp.fY * aRHS.fX - temp.fX * aRHS.fY ;
}

double Vector2D::angleBetween(const Vector2D& aRHS) const {
	Vector2D temp = *this;
	return atan2(temp.fX * aRHS.fX + temp.fY * aRHS.fY, temp.fY * aRHS.fX - temp.fX * aRHS.fY);
}

ostream& operator<<(ostream& aOutStream, const Vector2D& aObject) {
	aOutStream << "[" << aObject.fX << "," << aObject.fY << "]" << endl;
	return aOutStream; 
}
istream& operator>>(istream& aInStream, Vector2D& aObject) {
	aInStream >> aObject.fX;
	aInStream >> aObject.fY;
	return aInStream;
}

