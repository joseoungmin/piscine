#include "etc.hpp"

std::string get_input(std::string msg)
{
	std::string	str;

	std::string	white_space = " \n\r\t\f\v";
	std::cout << msg;
	std::getline(std::cin, str);
	str.erase(0, str.find_first_not_of(white_space));
	str.erase(str.find_last_not_of(white_space) + 1);
	return (str);
}
