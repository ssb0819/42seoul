#include "Zombie.hpp"

int	main()
{
	Zombie	first_zombie("zombie1");
	first_zombie.announce();

	Zombie	*second_zombie = newZombie("zombie2");
	second_zombie->announce();
	delete second_zombie;

	randomChump("zombie3");
}