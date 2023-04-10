#include "Cat.hpp"

Cat::Cat()
: Animal() {
	_type = "Cat";
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) {
	*this = other;
}

Cat::~Cat() {
	std::cout << "Cat destroyed" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
		_type = other._type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Cat sound" << std::endl;
}