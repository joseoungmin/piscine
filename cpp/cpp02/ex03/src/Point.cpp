#include "Point.hpp"

Point::Point()
: x(0), y(0) {}

Point::Point(const Point &p)
: x(p.x), y(p.y) {}

Point::Point(const float x, const float y) 
: x(x), y(y) {}

Point &Point::operator=(const Point &p){
	if (this != &p)
	{
		const_cast<Fixed&>(x) = p.getX();
		const_cast<Fixed&>(y) = p.getY();
	}
	return *this;
}

Fixed	Point::getX() const{
	return x;
}

Fixed	Point::getY() const{
	return y;
}

Point::~Point(){
}