#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), 
						hit_points(10), 
						energy_points(10), 
						attack_damage(0) {
	std::cout << "ClapTrap: Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), 
											hit_points(10), 
											energy_points(10), 
											attack_damage(0) {
	std::cout << name << ": ClapTrap: Constructor with name called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) : name(clapTrap.name), 
												hit_points(clapTrap.hit_points), 
												energy_points(clapTrap.energy_points), 
												attack_damage(clapTrap.attack_damage) {
	std::cout << name << ": ClapTrap: Copy constructor called" << std::endl;
	name = clapTrap.name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap) {
	name = clapTrap.name;
	hit_points = clapTrap.hit_points;
	energy_points = clapTrap.energy_points;
	attack_damage = clapTrap.attack_damage;
	std::cout << name << ": ClapTrap: Copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << name << ": ClapTrap: Destructor called" << std::endl;
}

bool	ClapTrap::check_points() {
	if (energy_points > 0 && hit_points > 0) {
		return true;
	} else {
		std::cout << "Hit points " << hit_points << " Energy points " << energy_points << ": Out of points" << std::endl;
		return false;
	}
}

void	ClapTrap::attack(const std::string& target) {
	if (check_points()) {
		std::cout << "ClapTrap " << name << " attacks " << target
			<< ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_points--; 
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= hit_points)
		hit_points = 0;
	else
		hit_points -= amount;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! " 
		<< hit_points << " points left." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (check_points())
	{
		hit_points += amount;
		std::cout << "ClapTrap " << name << " gets " << amount << " points back! "
			<< hit_points << " points left." << std::endl;
		energy_points--;
	}
}