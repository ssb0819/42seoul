#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure: public AMateria
{
public:
	Cure();
	Cure(const Cure& cure);
	virtual ~Cure();
	Cure&	operator=(const Cure& cure);
	
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif