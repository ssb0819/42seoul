#include "Zombie.hpp"

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
