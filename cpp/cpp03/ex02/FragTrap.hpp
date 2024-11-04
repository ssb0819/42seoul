#ifndef SCAVTRAP_20COPY_HPP
#define SCAVTRAP_20COPY_HPP
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& scavTrap);
	FragTrap& operator=(const FragTrap& scavTrap);
	~FragTrap();
	void	highFivesGuys() const;
};

#endif


#endif
