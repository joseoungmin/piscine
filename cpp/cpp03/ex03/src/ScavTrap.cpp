#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	Name = "default";
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name){
	Name = name;
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other){
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other){
	if (this != &other){
		Name = other.Name;
		HitPoints = other.HitPoints;
		EnergyPoints = other.EnergyPoints;
		AttackDamage = other.AttackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(std::string const &target){
	if (!HitPoints)
		std::cout << "ClapTrap " << Name << " has no hit point" << std::endl;
	else if (!EnergyPoints)
		std::cout << "ClapTrap " << Name << " has no energy" << std::endl;
	else {
		std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
		EnergyPoints--;
	}
}

void	ScavTrap::guardGate(){
	if (!HitPoints)
		std::cout << "ClapTrap " << Name << " has no hit point" << std::endl;
	else if (!EnergyPoints)
		std::cout << "ClapTrap " << Name << " has no energy" << std::endl;
	else {
		std::cout << "ScavTrap " << Name << " has entered gate keeper mode" << std::endl;
		EnergyPoints--;
	}
}
