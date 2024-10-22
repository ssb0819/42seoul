#include "Zombie.hpp"

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
