#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	Diamond("diamond");

	std::cout << "\n";
	Diamond.attack("target");
	Diamond.takeDamage(10);
	Diamond.beRepaired(10);

	std::cout << "\n";
	Diamond.guardGate();
	std::cout << "\n";
	Diamond.highFivesGuys();
	std::cout << "\n";
	Diamond.whoAmI();
	std::cout << "\n";
	return (0);
}