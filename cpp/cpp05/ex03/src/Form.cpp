#include "Form.hpp"

Form::Form() 
: name("no name"), sign(false), gradeForSign(0), gradeForExecute(0) {}

Form::Form(std::string name, int gradeForSign, int gradeForExecute)
: name(name), sign(false), gradeForSign(gradeForSign), gradeForExecute(gradeForExecute) {
	if (gradeForSign < 1 || gradeForExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeForSign > 150 || gradeForExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

const std::string	Form::getName() const {
	return (name);
}

bool				Form::getSign() const {
	return (sign);
}

int			Form::getGradeForSign() const {
	return (gradeForSign);
}

int			Form::getGradeForExecute() const {
	return (gradeForExecute);
}

void	Form::beSigned(const Bureaucrat& obj)
{
	if (obj.getGrade() > this->getGradeForSign())
	{
		std::cout << obj.getName() << " couldn't sign " << name << " because ";
		throw (GradeTooLowException());
	}
	else
		this->sign = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

const char* Form::NotSignedException::what() const throw() {
	return ("Not Signed Form");
}

bool Form::checkExec(Bureaucrat const &executor){
	if (gradeForExecute > executor.getGrade())
		throw GradeTooLowException();
	else
		return (true);
}

void Form::setTarget(const std::string target){
	this->target = target;
}

std::string Form::getTarget() const{
	return (target);
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName() << " needs grade " << obj.getGradeForSign() << " for sign and " << obj.getGradeForExecute() << " for execute. ";
	if (obj.getSign() == 1)
		std::cout << obj.getName() << " is signed" << std::endl;
	else
		std::cout << obj.getName() << " isn't signed " << std::endl;
	return (os);
}