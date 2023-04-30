#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request Form", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request Form", 72, 45) {
	setTarget(target);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (getSign() == false)
		throw (NotSignedException());
	if (getGradeForExecute() < executor.getGrade()){
		std::cout << "Execute failed beceause ";
		throw (GradeTooLowException());
	}
	srand(time(NULL));

	std::cout << "Makes some drilling noises" << std::endl;
	std::cout << getTarget();
	if (rand() % 2)
		std::cout << " has been robotomized successfully" << std::endl;
	else
		std::cout << "'s robotomy is failed" << std::endl;
}