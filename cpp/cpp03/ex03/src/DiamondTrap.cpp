#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): Name(ClapTrap::Name){
	ClapTrap::Name = Name + "_clap_name";
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other), Name(other.Name){
	std::cout << "DiamondTrap " << Name << " copy constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name){
	std::cout << "DiamondTrap constructor called" << std::endl;
	Name = name;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other){
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	if (this != &other){
		Name = other.Name;
		HitPoints = other.HitPoints;
		EnergyPoints = other.EnergyPoints;
		AttackDamage = other.AttackDamage;
	}
	return (*this);
}

void DiamondTrap::whoAmI(void){
	std::cout	<< "This DiamondTrap name is " << Name << " and This ClapTrap name is " << ClapTrap::Name << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor called" << std::endl;
}