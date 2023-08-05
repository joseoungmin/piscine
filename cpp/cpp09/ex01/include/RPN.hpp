#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>

class RPN {
	private:
		std::stack<double> mStack;
	public:
		RPN();
		~RPN();
		RPN(const RPN& copy);

		RPN& operator=(const RPN& copy);

		void	calculate(const char & oper);
		void	run(std::string expression);
		bool	isNumber(const char& ch) const;
		bool	isOperator(const char& ch) const;
};

#endif
