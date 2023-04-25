#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string	name;
		bool				sign;
		const int			gradeForSign;
		const int			gradeForExecute;

	public:
		Form();
		Form(const Form &other);
		Form(std::string name, const int gradeForSign, const int GradeForExecute);
		~Form();

		Form& operator=(const Form& other);

};

#endif