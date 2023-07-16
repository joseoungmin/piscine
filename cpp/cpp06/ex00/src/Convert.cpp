#include "Convert.hpp"

Convert::Convert() {}

Convert::~Convert() {}

double Convert::numData = 0;
char* Convert::strData = 0;
void	Convert::setData(char * input) {
	numData = strtod(input, &strData);
}

void	Convert::printChar() {
	if ((strData[0] != '\0' && strData[0] != 'f')
		|| numData < 0 || numData > 127 
		|| isnan(numData) || strlen(strData) > 1)
		std::cout << "char: impossible\n";
	else if (numData < 32 || numData > 126)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(numData) << "'\n";
}

void	Convert::printInt() {
	if ((strData[0] != '\0' && strData[0] != 'f') 
		|| isnan(numData) || strlen(strData) > 1)
		std::cout << "int: impossible\n";
	else if (numData > std::numeric_limits<int>::max())
		std::cout << "int: obverflow\n";
	else if (numData < std::numeric_limits<int>::min())
		std::cout << "int: underflow\n";
	else
		std::cout << "int: " << static_cast<int>(numData) << "\n";
}

void	Convert::printFloat() {
	if ((strData[0] != '\0' && strData[0] != 'f')
		|| strlen(strData) > 1)
		std::cout << "float: nanf\n";
	else if (numData > std::numeric_limits<float>::max())
		std::cout << "float: +inff\n";
	else if (numData < std::numeric_limits<float>::lowest())
		std::cout << "float: -inff\n";
	else
		std::cout << "float: " << static_cast<float>(numData) 
		<< (numData == static_cast<int>(numData) ? ".0f\n" : "f\n");
}

void	Convert::printDouble() {
	if ((strData[0] != '\0' && strData[0] != 'f')
		|| strlen(strData) > 1)
		std::cout << "double: nan\n";
	else if (numData > std::numeric_limits<double>::max())
		std::cout << "double: +inf\n";
	else if (numData < std::numeric_limits<double>::lowest())
		std::cout << "double: -inf\n";
	else
		std::cout << "double: " << static_cast<double>(numData) 
		<< (numData == static_cast<int>(numData) ? ".0\n" : "\n");
}
