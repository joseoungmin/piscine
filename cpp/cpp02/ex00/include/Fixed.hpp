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

	Fixed& operator=(const Fixed& obj);

	Fixed();
	Fixed(const Fixed& obj);
	~Fixed();
};

#endif
