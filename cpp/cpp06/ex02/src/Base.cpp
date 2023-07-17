#include "Base.hpp"

Base::~Base() {}

Base*	generate(void) {
	srand(time(NULL));
	int	randNum = rand() % 3;

	switch (randNum)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		default :
			return (new C);
	}
}

// pointer = NULL , reference = exception
void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void	identify(Base& p) {
	try {
		A&	a = dynamic_cast<A&>(p);
		std::cout << "A\n";
		static_cast<void>(a);
	}
	catch (std::exception& e) {}
	try {
		B&	b = dynamic_cast<B&>(p);
		std::cout << "B\n";
		static_cast<void>(b);
	}
	catch (std::exception& e) {}
	try {
		C&	c = dynamic_cast<C&>(p);
		std::cout << "C\n";
		static_cast<void>(c);
	}
	catch (std::exception& e) {}
}