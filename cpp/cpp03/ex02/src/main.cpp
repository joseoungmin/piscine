#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	Frag("frag");

	std::cout << "\n";
	Frag.attack("target");
	Frag.takeDamage(10);
	Frag.beRepaired(10);
	std::cout << "\n";
	Frag.highFivesGuys();

	std::cout << "\n";
	return (0);
}