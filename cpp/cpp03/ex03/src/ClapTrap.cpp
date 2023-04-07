#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: Name("defalult"), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << "ClapTrap " << name << " has created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << Name << " has destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		Name = other.Name;
		HitPoints = other.HitPoints;
		EnergyPoints = other.EnergyPoints;
		AttackDamage = other.AttackDamage;
	}
	return *this;
}

void ClapTrap::attack(std::string const &target) {
	if (!HitPoints)
		std::cout << "ClapTrap " << Name << " has no hit point" << std::endl;
	else if (!EnergyPoints)
		std::cout << "ClapTrap " << Name << " has no energy" << std::endl;
	else{
		std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
		EnergyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!HitPoints)
		std::cout << "ClapTrap " << Name << " has no hit point" << std::endl;
	else{
		HitPoints -= amount;
		std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
	}
	if (HitPoints < 0)
		HitPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!EnergyPoints)
		std::cout << "ClapTrap " << Name << " has no energy" << std::endl;
	if (!HitPoints)
		std::cout << Name << " has no hit point" << std::endl;
	else{
		std::cout << "ClapTrap " << Name << " is repaired " << amount << " points!" << std::endl;
		HitPoints += amount;
		EnergyPoints--;
	}
}