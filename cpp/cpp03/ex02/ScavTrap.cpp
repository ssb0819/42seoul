#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap: default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << name << ": ScavTrap: Constructor with name called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) {
	*this = scavTrap;
	std::cout << name << ": ScavTrap: Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap) {
	name = scavTrap.name;
	hit_points = scavTrap.hit_points;
	energy_points = scavTrap.energy_points;
	attack_damage = scavTrap.attack_damage;
	std::cout << name << ": ScavTrap: Copy assignment operator called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << name << ": ScavTrap: Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (check_points()) {
		std::cout << "ScavTrap " << name << " attacks " << target
				<< ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--;
	}
}

void	ScavTrap::guardGate() const {
	if (check_points())
		std::cout << name << ": ScavTrap is now in Gate keeper mode" << std::endl;
}