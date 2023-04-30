#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

enum {
	SHRUBBERY = 0,
	ROBOTOMY = 1,
	PARDON = 2,
};

class Intern
{
	private:
		std::string	form[3];
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);
	public:
		Intern();
		~Intern();

		Form	*makeForm(std::string formName, std::string target);

		class WrongFormException : public std::exception {
			public:
				const char* what() const throw();
		};
};

#endif