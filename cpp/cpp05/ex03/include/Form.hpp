#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
	private:
		const std::string	name;
		bool				sign;
		const int			gradeForSign;
		const int			gradeForExecute;
		std::string			target;
		Form(const Form &other);
		Form& operator=(const Form& other);

	public:
		Form();
		Form(std::string name, int gradeForSign, int GradeForExecute);
		virtual ~Form();

		const std::string	getName() const;
		bool				getSign() const;
		int					getGradeForSign() const;
		int					getGradeForExecute() const;
		void				beSigned(const Bureaucrat &bureaucrat);

		bool 				checkExec(Bureaucrat const &executor);
		virtual void 		execute(Bureaucrat const &executor) const = 0;
		void 				setTarget(const std::string target);
		std::string 		getTarget() const;

		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class NotSignedException : public std::exception {
			public:
				const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form &obj);

#endif