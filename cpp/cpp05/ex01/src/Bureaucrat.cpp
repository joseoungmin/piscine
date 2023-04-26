#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: name("no name"), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) {
	*this = other;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
: name(name), grade(grade){
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other){
		const std::string	&N = name;
		const_cast<std::string&>(N) = other.name;
		this->grade = other.grade;
	}
	return *this;
}

const std::string Bureaucrat::getName() const {
	return (name);
}

int Bureaucrat::getGrade() const {
	return (grade);
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high...";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low...";
}

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
	std::cout << name << "'s grade is " << grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
	std::cout << name << "'s grade is " << grade << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}