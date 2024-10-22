#include "Zombie.hpp"

void	check_leaks()
{
	system("leaks -q test");
}

int	main(int argc, char **argv)
{
	atexit(check_leaks);
	if (argc < 3)
	{
		std::cerr << "Please enter the number and names of the zombies." << std::endl;
		return (1);
	}
	const int	zombie_cnt = atoi(argv[1]);
	if (zombie_cnt < 1)
	{
		std::cerr << "Please enter the number and names of the zombies." << std::endl;
		return (1);
	}
	std::string	zombie_name = argv[2];

	Zombie	*zombies = zombieHorde(zombie_cnt, zombie_name);
	for (int i = 0; i < zombie_cnt; i++)
	{
		zombies[i].announce();
	}
	delete []zombies;
}