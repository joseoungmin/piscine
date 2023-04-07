#include "FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap() {
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
: ClapTrap(name) {
	HitPoints = 100;
	EnergyPoints = 100;
	AttackDamage = 30;
	std::cout << "FragTrap " << name << " created" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	if (this != &other)
	{	
		AttackDamage = other.AttackDamage;
		EnergyPoints = other.EnergyPoints;
		HitPoints = other.HitPoints;
		Name = other.Name;
	}
	return (*this);
}

FragTrap::FragTrap(const FragTrap& other){
	*this = other;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << Name << " destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void){
	if (!HitPoints)
		std::cout << "ClapTrap " << Name << " has no hit point" << std::endl;
	else if (!EnergyPoints)
		std::cout << "ClapTrap " << Name << " has no energy" << std::endl;
	else
		std::cout << "FragTrap " << Name << " high five!\n";
}