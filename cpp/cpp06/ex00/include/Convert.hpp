#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

class Convert
{
	private:
		Convert();
		Convert(const Convert & obj);
		Convert& operator = (Convert & obj);
		~Convert();
		static double	numData;
		static char*	strData;
	public:
		static void	setData(char * input);
		static void	printChar();
		static void	printInt();
		static void	printFloat();
		static void	printDouble();
};

#endif
