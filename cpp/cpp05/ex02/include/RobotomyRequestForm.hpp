#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "Form.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
	
		void execute(Bureaucrat const &executor) const;
};

#endif