#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		Fixed	getX() const;
		Fixed	getY() const;

		Point &operator=(const Point &p);
		
		Point();
		Point(const Point &p);
		Point(const float x, const float y);
		~Point();
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif