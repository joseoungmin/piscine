#include "Convert.hpp"

int main(int ac, char** av){
	if (ac != 2)
		std::cout << "argument count error\n";
	else {
		Convert::setData(av[1]);
		Convert::printChar();
		Convert::printInt();
		Convert::printFloat();
		Convert::printDouble();
	}
	return (0);
}
