#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string Name;
		
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap(std::string name);
		~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap& other);

		void	whoAmI();
};

#endif