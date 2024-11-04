#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
	ScavTrap();
	ScavTrap(const ScavTrap& scavTrap);
	ScavTrap& operator=(const ScavTrap& scavTrap);
public:
	ScavTrap(const std::string& name);
	~ScavTrap();
};

#endif
