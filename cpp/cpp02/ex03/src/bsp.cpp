#include "Point.hpp"

// outerProduct가 외적을 구하는 공식 
// 각 변마다 외적을 구해서 zero가 하나라도 있으면 변에 맞다은 부분이라 외부로 처리3개 값이 모두 음수거나 모두 양수로 동일하면 내부로 처리 

Fixed	outerProduct(Point const p1, Point const p2, Point const p3) {
	return ((p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
		- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY()));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	d1, d2, d3;
	bool	has_zero, has_neg, has_pos;

	d1 = outerProduct(point, a, b);
	d2 = outerProduct(point, b, c);
	d3 = outerProduct(point, c, a);
	has_zero = (d1 == 0) || (d2 == 0) || (d3 == 0);
	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	return (!has_zero && !(has_neg && has_pos));
}