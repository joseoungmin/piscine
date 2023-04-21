#include "Cat.hpp"

Cat::Cat()
: Animal() {
	_type = "Cat";
	brain = new Brain();
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other) {
	*this = other;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destroyed" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other){
		_type = other._type;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Cat sound" << std::endl;
}