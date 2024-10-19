#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(const std::string& type) : type(type) {}

Weapon::~Weapon() {}

const std::string&	Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(const std::string& type)
{
	this->type = type;
}
