#include "Intern.hpp"

int main(){	
	Intern	intern;
	Bureaucrat	me("seojo", 20);
	
	Form	*shrubbery;
	Form	*robotomy;
	Form	*pardon;

	shrubbery = intern.makeForm("shrubbery creation", "Home");
	robotomy = intern.makeForm("robotomy request", "robo");
	pardon = intern.makeForm("presidential pardon", "pardon");
	std::cout << std::endl;
	if (shrubbery)
	{
		try
		{
			me.signForm(*shrubbery);
			me.executeForm(*shrubbery);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	if (robotomy)
	{
		try
		{
			me.signForm(*robotomy);
			me.executeForm(*robotomy);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	if (pardon)
	{
		try
		{
			me.signForm(*pardon);
			me.executeForm(*pardon);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	if (shrubbery)
		delete shrubbery;
	if (robotomy)
		delete robotomy;
	if (pardon)
		delete pardon;

	system("leaks a.out | grep leaked");

	return 0;
}