#include "Form.hpp"

Form::Form() 
: name("no name"), sign(false), gradeForSign(0), gradeForExecute(0) {}

Form::Form(const Form &other)
: name("no name"), sign(false), gradeForSign(0), gradeForExecute(0) {
	*this = other;
}

Form& Form::operator=(const Form &other) {
	if (this != &other){
		const std::string	&N = name;
		const_cast<std::string&>(N) = other.name;
		sign = other.sign;
		const int	&gFS = gradeForSign;
		const_cast<int&>(gFS) = other.gradeForSign;
		const int	&gFE = gradeForExecute;
		const_cast<int&>(gFE) = other.gradeForExecute;
	}
	return *this;
}