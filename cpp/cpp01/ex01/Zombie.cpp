#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "[ a zombie is created. ]" << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "[ " << name << " is created. ]" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "[ " << name << " is destroyed. ]" << std::endl;
}

void	Zombie::announce()
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}
