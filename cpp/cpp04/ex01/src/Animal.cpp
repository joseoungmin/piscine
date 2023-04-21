#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
}

Animal::~Animal() {
	std::cout << "Animal destroyed" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other)
		_type = other._type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const {
	return _type;
}
