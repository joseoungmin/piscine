#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destroyed" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat sound" << std::endl;
}
