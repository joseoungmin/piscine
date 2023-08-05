#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& copy) {
	*this = copy;
}
RPN& RPN::operator=(const RPN& copy) {
	if (this != &copy)
		mStack = copy.mStack;
	return *this;
}

bool	RPN::isNumber(const char& ch) const {
	return ('0' <= ch && ch <= '9');
}

bool	RPN::isOperator(const char& ch) const {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void	RPN::calculate(const char & oper) {
	double	num1, num2;

	if (mStack.size() < 2)
		throw std::invalid_argument("Error: Invalid expression");
	num2 = mStack.top(); mStack.pop();
	num1 = mStack.top(); mStack.pop();
	switch (oper) {
		case '+':
			mStack.push(num1 + num2);
			break;
		case '-':
			mStack.push(num1 - num2);
			break;
		case '*':
			mStack.push(num1 * num2);
			break;
		case '/':
			if (num2 == 0)
				throw std::invalid_argument("Error: Division by zero");
			mStack.push(num1 / num2);
			break;
	}
}

void	RPN::run(std::string expression) {
	std::string		token;

	expression.erase(0, expression.find_first_not_of(" \n\r\t\f\v"));
	while(expression.size()) {
		token = expression.substr(0, expression.find_first_of(" \n\r\t\f\v"));
		expression.erase(0, expression.find_first_of(" \n\r\t\f\v"));
		expression.erase(0, expression.find_first_not_of(" \n\r\t\f\v"));
		if (token.size() > 1)
			throw std::invalid_argument("Error: Invalid token");
		if (isNumber(token[0]))
			mStack.push(token[0] - '0');
		else if (isOperator(token[0]))
			calculate(token[0]);
		else
			throw std::invalid_argument("Error: Invalid token");
	}
	if (mStack.size() != 1)
		throw std::invalid_argument("Error: Invalid expression");
	std::cout << mStack.top() << std::endl;
}
