#include "Fixed.hpp"

Fixed::Fixed() 
: mNum(0) {
}

Fixed::Fixed(const int num) {
	mNum = num << mBit;
}

Fixed::Fixed(const float num) {
	mNum = roundf(num * (1 << mBit));
}

Fixed::Fixed(const Fixed& obj) {
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed& obj) {
	mNum = obj.getRawBits();
	return (*this);
}

bool	Fixed::operator > (const Fixed& obj) const {
	return (this->getRawBits() > obj.getRawBits());
}

bool	Fixed::operator < (const Fixed& obj) const {
	return (this->getRawBits() < obj.getRawBits());
}

bool	Fixed::operator >= (const Fixed& obj) const {
	return (this->getRawBits() >= obj.getRawBits());
}

bool	Fixed::operator <= (const Fixed& obj) const {
	return (this->getRawBits() <= obj.getRawBits());
}

bool	Fixed::operator == (const Fixed& obj) const {
	return (this->getRawBits() == obj.getRawBits());
}

bool	Fixed::operator != (const Fixed& obj) const {
	return (this->getRawBits() != obj.getRawBits());
}

Fixed	Fixed::operator + (const Fixed& obj) {
	Fixed rt(this->toFloat() + obj.toFloat());
	return (rt);
}

Fixed	Fixed::operator - (const Fixed& obj) {
	Fixed rt(this->toFloat() - obj.toFloat());
	return (rt);
}

Fixed	Fixed::operator / (const Fixed& obj) {
	Fixed rt(this->toFloat() / obj.toFloat());
	return (rt);
}

Fixed	Fixed::operator * (const Fixed& obj) {
	Fixed rt(this->toFloat() * obj.toFloat());
	return (rt);
}

Fixed&	Fixed::operator ++ (void) {
	this->mNum++;
	return (*this);
} 		// Prefix increment operator

Fixed&	Fixed::operator -- (void) {
	this->mNum--;
	return (*this);
}

Fixed	Fixed::operator ++ (int) {
	Fixed	rt(*this);

	this->mNum++;
	return (rt);
}	// Postfix increment operator.
Fixed	Fixed::operator -- (int) {
	Fixed	rt(*this);

	this->mNum--;
	return (rt);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a <= b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a >= b)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a >= b)
		return (a);
	else
		return (b);
}

std::ostream& operator << (std::ostream &out, const Fixed& obj) {
	out << obj.toFloat();
	return (out);
}

Fixed::~Fixed() {
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
