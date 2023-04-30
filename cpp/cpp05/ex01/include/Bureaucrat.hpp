#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include <Form.hpp>

class Bureaucrat{
	private:
		const std::string	name;
		int					grade;
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat operator=(const Bureaucrat &other);

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();

		const std::string	getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		void				signForm(class Form &form);

		class GradeTooHighException : public std::exception {
			public:
				const char * what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char * what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj);

#endif