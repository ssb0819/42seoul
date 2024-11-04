#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << "FragTrap: default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << name << ": FragTrap: Constructor with name called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap) : ClapTrap(fragTrap) {
	std::cout << name << ": FragTrap: Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap) {
	name = fragTrap.name;
	hit_points = fragTrap.hit_points;
	energy_points = fragTrap.energy_points;
	attack_damage = fragTrap.attack_damage;
	std::cout << name << ": FragTrap: Copy assignment operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << name << ": FragTrap: Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys() const {
	if (check_points())
		std::cout << name << ": high five" << std::endl;
}