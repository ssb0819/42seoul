#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, const Weapon& weapon) : name(name), weapon(weapon)
{
	std::cout << "humanA: " << name << " is created." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "humanA: " << name << " is destroyed." << std::endl;
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}