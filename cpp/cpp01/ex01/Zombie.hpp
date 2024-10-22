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
	Zombie(const std::string& name);
	~Zombie();
	void	set_name(const std::string& name);
	void	announce();
};

Zombie*	zombieHorde(const int N, const std::string& name);

#endif