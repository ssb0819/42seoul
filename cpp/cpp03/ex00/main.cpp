#include "ClapTrap.hpp"

int	main() {
	ClapTrap clapTrap1("ct1");
	ClapTrap clapTrap2("ct2");

	std::cout << "==== attack & takeDamage test ====\n" << std::endl;
	clapTrap1.attack("ct2");
	clapTrap2.takeDamage(0);
	
	std::cout << "\n==== when energy point is 0 ====\n" << std::endl;
	for (size_t i = 0; i < 10; i++)
		clapTrap1.attack("ct2");
	
	std::cout << "\n==== when hit point is 0 ====\n" << std::endl;
	clapTrap2.takeDamage(20);
	clapTrap2.beRepaired(3);
}