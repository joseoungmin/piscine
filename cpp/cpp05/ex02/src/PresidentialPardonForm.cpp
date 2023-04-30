#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon Form", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon Form", 25, 5) {
	setTarget(target);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (getSign() == false)
		throw (NotSignedException());
	if (getGradeForExecute() < executor.getGrade()){
		std::cout << "Execute failed beceause ";
		throw (GradeTooLowException());
	}
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}