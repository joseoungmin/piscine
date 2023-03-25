#include "Fixed.hpp"

Fixed::Fixed() 
: mNum(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	mNum = num << mBit;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	mNum = roundf(num * (1 << mBit));
}

Fixed::Fixed(const Fixed& obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed& obj) {
	std::cout << "Assignation operator called" << std::endl;
	mNum = obj.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const Fixed& obj) {
	out << obj.toFloat();
	return (out);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	return (mNum);
}

void	Fixed::setRawBits(int const raw) {
	mNum = raw;
}

int		Fixed::toInt(void) const {
	return (mNum >> mBit);
}

float	Fixed::toFloat(void) const {
	return ((float)mNum / (1 << mBit));
}
