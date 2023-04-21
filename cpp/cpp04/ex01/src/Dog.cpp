#include "Dog.hpp"

Dog::Dog()
: Animal() {
	_type = "Dog";
	brain = new Brain();
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(const Dog& other) {
	*this = other;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other){
		_type = other._type;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Dog sound" << std::endl;
}
