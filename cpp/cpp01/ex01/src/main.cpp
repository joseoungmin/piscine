#include "Zombie.hpp"

int main(void){
	int			n;
	std::string	str;

	std::cout << "Enter the number of zombies to create: ";
	std::getline(std::cin, str);
	n = std::atoi(str.c_str());
	std::cout << "enter the name of the zombie: ";
	std::getline(std::cin, str);
	Zombie*	Zombie_swarm = zombieHorde(n, str);
	for (int i = 0; i < n; i++)
		Zombie_swarm[i].announce();
	delete[] Zombie_swarm;
	// system("Leaks MoarBrainz");
	return (0);
}