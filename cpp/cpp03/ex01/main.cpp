#include "ScavTrap.hpp"

int	main() {

	std::cout << "======== test start ========" << std::endl;
	ScavTrap	scav1("1111");

	scav1.attack("11");
	scav1.guardGate();

	std::cout << "===========================" << std::endl;

	ScavTrap	scav2;

	scav2 = scav1;
	scav2.attack("33");

	std::cout << "===========================" << std::endl;

	ClapTrap	*clap;

	clap = (ClapTrap *)&scav1;
	clap->attack("44");
	// clap->guarGate();

	std::cout << "===========================" << std::endl;

	ClapTrap	clap2;
	clap2 = scav1;
	clap2.attack("55");

	std::cout << "===========================" << std::endl;
}