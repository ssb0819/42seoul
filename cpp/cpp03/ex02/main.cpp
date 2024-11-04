#include "FragTrap.hpp"

int	main() {

	std::cout << "======== test start ========" << std::endl;
	FragTrap	frag1("1111");

	frag1.attack("11");
	frag1.highFivesGuys();

	std::cout << "===========================" << std::endl;

	FragTrap	frag2;

	frag2 = frag1;
	frag2.attack("33");

	std::cout << "===========================" << std::endl;

	ClapTrap	*clap;

	clap = (ClapTrap *)&frag1;
	clap->attack("44");
	// clap->guarGate();

	std::cout << "===========================" << std::endl;

	ClapTrap	clap2;
	clap2 = frag1;
	clap2.attack("55");

	std::cout << "===========================" << std::endl;
}