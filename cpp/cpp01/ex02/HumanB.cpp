#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name)
{
	std::cout << "humanB: " << name << " is created." << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "humanB: " << name << " is destroyed." << std::endl;
}

void	HumanB::setWeapon(const Weapon& weapon)
{
	this->weapon = weapon;
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}