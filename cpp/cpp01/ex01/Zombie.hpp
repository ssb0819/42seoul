#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string	name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void	set_name(std::string name);
	void	announce();
};

Zombie*	zombieHorde(int N, std::string name);

#endif