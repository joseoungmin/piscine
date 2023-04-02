#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap Scav("Scav");

	std::cout << "\n";
	Scav.attack("target");
	Scav.takeDamage(10);
	Scav.beRepaired(10);
	std::cout << "\n";
	Scav.guardGate();
	std::cout << "\n";
	return (0);
}