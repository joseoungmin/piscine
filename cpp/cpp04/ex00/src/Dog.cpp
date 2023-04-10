#include "Dog.hpp"

Dog::Dog()
: Animal() {
	_type = "Dog";
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other) {
	*this = other;
}

Dog::~Dog() {
	std::cout << "Dog destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other)
		_type = other._type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Dog sound" << std::endl;
}
