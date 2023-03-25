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
		int		toInt(void) const;
		float	toFloat(void) const;

		Fixed& operator=(const Fixed& obj);

		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& obj);
		~Fixed();
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif
