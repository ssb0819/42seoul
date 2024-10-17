#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(const std::string& type) : type(type)
{
	std::cout << "weapon: " << type << " is created." << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "weapon: " << type << " is destroyed." << std::endl;
}

const std::string&	Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(const std::string& type)
{
	this->type = type;
	std::cout << "weapon: " << type << " has been set." << std::endl;
}
