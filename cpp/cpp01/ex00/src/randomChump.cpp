#include "Zombie.hpp"

void	randomChump(std::string name) {
	Zombie	newone = Zombie(name);

	newone.announce();
}