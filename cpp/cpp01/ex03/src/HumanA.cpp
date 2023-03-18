#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
: _name(name), _weapon(weapon) {}

void	HumanA::setWeapon(Weapon &weapon) {
	_weapon = weapon;
}

void	HumanA::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << "\n";
}

HumanA::~HumanA() {
	std::cout << "Human A destroyed\n";
}