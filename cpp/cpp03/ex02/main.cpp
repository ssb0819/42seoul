#include "FragTrap.hpp"

int	main() {

	std::cout << "======== test start ========\n" << std::endl;
	FragTrap	frag1("1111");

	frag1.attack("11");
	frag1.highFivesGuys();

	std::cout << "\n===========================\n" << std::endl;

	ClapTrap	clap2;
	clap2 = frag1;
	clap2.attack("55");
	// clap2.highFivesGuys();

	std::cout << "\n===========================\n" << std::endl;
}