#include "Base.hpp"

int main(void) {
	Base*	base = generate();

	std::cout << "Pointer: ";
	identify(base);
	std::cout << "Reference: ";
	identify(*base);
	
	return (0);
}