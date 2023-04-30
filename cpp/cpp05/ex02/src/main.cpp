#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){	
	Bureaucrat	me("seojo", 20);
	ShrubberyCreationForm	shrubbery("Home");
	RobotomyRequestForm		robotomy("robo");
	PresidentialPardonForm	pardon("pre");

	std::cout << me << std::endl;
	std::cout << std::endl;
	try
	{
		me.signForm(shrubbery);
		me.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		me.signForm(robotomy);
		me.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		me.signForm(pardon);
		me.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;

	std::cout << std::endl;
	return 0;
}