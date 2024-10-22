#include "Zombie.hpp"

Zombie*	zombieHorde(const int N, const std::string& name)
{
	Zombie*	zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombieHorde[i].set_name(name);
	}
	return (zombieHorde);
}