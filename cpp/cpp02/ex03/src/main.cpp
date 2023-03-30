#include "Point.hpp"

int	main( void ) {
	const Point a(5, 5);
	const Point b(2, 9);
	const Point c(0, 5);

	const Point p(3, 7);

	if (bsp(a, b, c, p))
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is outside the triangle" << std::endl;
	return 0; 
}
