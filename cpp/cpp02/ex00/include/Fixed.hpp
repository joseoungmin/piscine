#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed
{
private:
	int					mNum;
	static const int	mBit = 8;
public:
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed();
	Fixed(const Fixed& obj);
	Fixed& operator=(const Fixed& obj);
	~Fixed();
};

Fixed::Fixed() 
: mNum(0) {
	std::cout << "Default constructor called" << std::endl;
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

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (mNum);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	mNum = raw;
}

#endif