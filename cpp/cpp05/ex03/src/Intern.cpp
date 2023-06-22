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
			tmp = new ShrubberyCreationForm(target);
			break;
		case ROBOTOMY :
			tmp = new RobotomyRequestForm(target);
			break;
		case PARDON :
			tmp = new PresidentialPardonForm(target);
			break;
		default :
			std::cout << "Intren fails create form\n";
			return (NULL);
	}
	std::cout << "Intern creates " << tmp->getName() << std::endl;
	return (tmp);
}

const char * Intern::WrongFormException::what() const throw() {
	return ("Wrong Form");
}
