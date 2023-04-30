#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
	private:
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
	
		void execute(Bureaucrat const &executor) const;
};

#endif