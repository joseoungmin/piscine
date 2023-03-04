#include <iostream>
#include <string>

using namespace std;
int main(void)
{
	std::string str;
	std::string white_space(" \n\r\t\f\v");

	std::getline(std::cin, str);
	str.erase(0, str.find_first_not_of(white_space));
	std::cout << "[" << str << "]" << std::endl;
	str.erase(str.find_last_not_of(white_space)+1);
	std::cout << "[" << str << "]" << std::endl;
	return (0);
}
