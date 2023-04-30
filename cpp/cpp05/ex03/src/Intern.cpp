#include "Intern.hpp"

Intern::Intern() {
	this->form[0] = "shrubbery creation";
	this->form[1] = "robotomy request";
	this->form[2] = "presidential pardon";
}

Intern::~Intern() {}

Form* Intern::makeForm(std::string formName, std::string target)
{
	Form *tmp;
	int i = 0;

	while (form[i] != formName && i < 3)
		i++;

	switch (i)
	{
		case SHRUBBERY :
		{
			tmp = new ShrubberyCreationForm(target);
			std::cout << "Intern creates " << tmp->getName() << std::endl;
			return (tmp);
		}
		case ROBOTOMY :
		{
			tmp = new RobotomyRequestForm(target);
			std::cout << "Intern creates " << tmp->getName() << std::endl;
			return (tmp);
		}
		case PARDON :
		{
			tmp = new PresidentialPardonForm(target);
			std::cout << "Intern creates " << tmp->getName() << std::endl;
			return (tmp);
		}
	}
	std::cout << "Intren fails create form" << std::endl;
	return (NULL);
}

const char * Intern::WrongFormException::what() const throw() {
	return ("Wrong Form");
}
