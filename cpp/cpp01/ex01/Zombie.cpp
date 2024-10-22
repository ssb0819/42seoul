#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "zombie: created." << std::endl;
}

Zombie::Zombie(const std::string& name) : name(name)
{
	std::cout << "zombie: " << name << " is created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "zombie: " << name << " is destroyed." << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(const std::string& name)
{
	this->name = name;
}
