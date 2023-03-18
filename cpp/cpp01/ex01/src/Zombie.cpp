#include "Zombie.hpp"

Zombie::Zombie()
: _name("Zombie") {
	std::cout << _name << "created\n";
}

Zombie::~Zombie() {
	std::cout << _name << " destructed\n";
}

void	Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}