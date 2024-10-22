#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string	name;
public:
	Zombie(const std::string& name);
	~Zombie();
	void	announce();
};

Zombie*	newZombie(const std::string& name);
void	randomChump(const std::string& name);

#endif
