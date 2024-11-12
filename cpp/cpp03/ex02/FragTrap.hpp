#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string name);
	FragTrap(const FragTrap& scavTrap);
	FragTrap& operator=(const FragTrap& scavTrap);
	~FragTrap();
	void	highFivesGuys() const;
};

#endif
