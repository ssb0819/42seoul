#include "ScavTrap.hpp"

int	main() {

	std::cout << "======== test start ========\n" << std::endl;
	ScavTrap	scav1("1111");

	scav1.attack("11");
	scav1.guardGate();

	std::cout << "\n======= explicit conversion test ==========\n" << std::endl;

	ClapTrap	*clap;

	clap = (ClapTrap *)(new ScavTrap("222"));
	clap->attack("44");
	// clap->guarGate();
	delete clap;

	std::cout << "\n======== implicit conversion test =========\n" << std::endl;

	ClapTrap	clap2;
	clap2 = scav1;
	clap2.attack("55");
	// clap2.guardGate();

	std::cout << "\n======== test end ============\n" << std::endl;
}