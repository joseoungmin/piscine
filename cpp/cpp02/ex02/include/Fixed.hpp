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

		bool	operator > (const Fixed& obj) const;
		bool	operator < (const Fixed& obj) const;
		bool	operator >= (const Fixed& obj) const;
		bool	operator <= (const Fixed& obj) const;
		bool	operator == (const Fixed& obj) const;
		bool	operator != (const Fixed& obj) const;

		Fixed	operator + (const Fixed& obj);
		Fixed	operator - (const Fixed& obj);
		Fixed	operator / (const Fixed& obj);
		Fixed	operator * (const Fixed& obj);

		Fixed&	operator ++ (void); // Prefix increment operator
		Fixed&	operator -- (void);
		Fixed	operator ++ (int);	// Postfix increment operator.
		Fixed	operator -- (int);

		Fixed& operator = (const Fixed& obj);

		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& obj);
		~Fixed();
};

std::ostream& operator << (std::ostream& out, const Fixed& obj);


#endif
