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

		const std::string	getName() const;
		bool				getSign() const;
		const int			getGradeForSign() const;
		const int			getGradeForExecute() const;
		void				beSigned();

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form &obj);

#endif