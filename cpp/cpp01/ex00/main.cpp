#include "Zombie.hpp"

void	check_leaks()
{
	system("leaks -q test_00");
}

int	main()
{
	atexit(check_leaks);
	Zombie	first_zombie("zombie1");
	first_zombie.announce();

	Zombie	*second_zombie = newZombie("zombie2");
	second_zombie->announce();
	delete second_zombie;

	randomChump("zombie3");
}