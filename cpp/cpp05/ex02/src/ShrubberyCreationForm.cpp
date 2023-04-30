#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137) {
	setTarget(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (getSign() == false)
		throw (NotSignedException());
	if (getGradeForExecute() < executor.getGrade()){
		std::cout << "Execute failed beceause ";
		throw (GradeTooLowException());
	}
	std::ofstream writeFile(this->getTarget() + "_shruberry");
	writeFile << 
	"        _-_\n "
	"    //~~  ~~\n "
	" //~~        ~~\n "
	"{              }\n "
	" \\  _-     -_ //\n "
	"   ~  \\ //  ~\n "
	"_- -   | | _- _\n "
	"  _ -  | |   -_\n "
	"      // \\\n ";

	writeFile.close();
}